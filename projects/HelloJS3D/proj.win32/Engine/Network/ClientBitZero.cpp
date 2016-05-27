#if (!defined(WP8) || !defined(_WP8))

#include "ClientBitZero.h"
#include "packet/PacketFactory.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32||CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID||CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "socket/DefaultSocket.h"
#endif

#define CONNECT_FAIL 0
#define CONNECT_SUCCESS 1
#define CONNECT_TING 2
#define DISCONNECT -1
static ClientBitZero *pClientBitZero = NULL;
 
ClientBitZero::ClientBitZero(){
	socket = NULL;
	createSocket();
	isSending = false;
	isReady = false;
	need_quit = false;
	_autoReconnect = false;
	_isDisconnect = false;
	_serverPort = 0;
	timer = 0;
	stateSocket = DISCONNECT;
	CCDirector::sharedDirector()->getScheduler()->scheduleSelector(
		schedule_selector(ClientBitZero::dispatchResponseCallbacks), this, 0.01, false);
}
ClientBitZero::~ClientBitZero(){
	need_quit = true;
	pClientBitZero = NULL;
}
void ClientBitZero::createSocket()
{
	if(socket)
		delete socket;
	//nen tang nao thi dung socket cho nen tang do
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32||CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID||CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		socket = new DefaultSocket();
	#endif	
}
ClientBitZero* ClientBitZero::getInstance()
{
	if (pClientBitZero == NULL) {
		pClientBitZero = new ClientBitZero();
		//pClientBitZero->initThread();
	}
	return pClientBitZero;
}
void ClientBitZero::destroyInstance()
{
	CC_ASSERT(pClientBitZero);
	CCDirector::sharedDirector()->getScheduler()->unscheduleSelector(schedule_selector(ClientBitZero::dispatchResponseCallbacks), pClientBitZero);
	delete  pClientBitZero;
	pClientBitZero = NULL;
	//pClientBitZero->release();
}
void ClientBitZero::setListener(BZListener* listener){
	this->listener = listener;
}
//khoi tao thread
bool ClientBitZero::initThread()
{   
	isDisconnectedHandler = false;
	pthread_mutex_init(&s_requestQueueMutex, NULL);
	pthread_mutex_init(&s_responseQueueMutex, NULL);

	pthread_create(&s_networkThread, NULL, ClientBitZero::networkThread, this);
	pthread_detach(s_networkThread);
	need_quit = false;
	buff = new BZPacket();
	return true;
}
// Worker thread
void* ClientBitZero::networkThread(void* arg){

	

	ClientBitZero *client = (ClientBitZero *)arg;
//	CCLog("************************* SERVER IP: %s PORT: %i",serverIP, serverPort);
	
	getInstance()->setTimeoutForConnect(5);
	bool result = client->socket->connectSocket(client->_serverIp.c_str(),client->_serverPort);
	//client->listener->onFinishConnect(result);

	client->stateSocket = result;
	client->isReady = true;
	bool connectState = result;
	if(result == true)
	{
		while (true) 
		{
			/*if(client->needConnect)
			{
				client->connect(client->_serverIp.c_str(), client->_serverPort);
				client->needConnect = false;
			}*/

			
			//CCLog("Thread network 1 ");
			if (client->need_quit)
			{
				//CCLog("Thread Break ");
				break;
			}
			if (!client->_isReconnecting)
			{
				//CCLog("Thread network 2 ");
				bool result = client->read();
				//error to reading from socket
				if(!result)
					{
						client->onConnectionClose();
						client->socket->closeSocket();
						break;
					}
			}
			
		}
	}
	
	if (client)
	{
		// cleanup
		client->emptyRequestQueue();
		//can thiet ko?
		//pthread_mutex_destroy(&client->s_requestQueueMutex);
		//pthread_mutex_destroy(&client->s_responseQueueMutex);
	}
	
	if(connectState)
		pthread_exit(NULL);
	return 0;
}
void ClientBitZero::connect(const char* serverIP, int serverPort){

	if(stateSocket == CONNECT_TING)
		disconnect();
	_serverIp = serverIP;
	_serverPort = serverPort;
	_isReconnecting = false;
	getInstance()->initThread();
	
}
void ClientBitZero::disconnect()
{
	isReady = false;
	emptyRequestQueue();
	socket->closeSocket();
}
void ClientBitZero::send(CPacket* packet){
	int dataLength = 0;
	const char* data = PacketFactory::packPacket(packet,dataLength);
	if(dataLength == 0)
	{
		CCAssert(false,"Du lieu trong");
	}
	send(data,dataLength);
}
//Gui yeu cau
void ClientBitZero::send(const char* data, int length){

		BZPacket pk;
		for (int i =0;i<length;i++)
		{
			pk.vectorBuffer.push_back(data[i]);
		}
		//pk.vectorBuffer.assign(data, length);
		//memcpy(pk.vectorBuffer.data(), data, length);
		pk.size = length;

	//	CCLOG(">> OUT: [%s]", (byte_2_str(data, length)).c_str());

		if(stateSocket == DISCONNECT)
			return;

		pthread_mutex_lock(&s_requestQueueMutex);
		s_requestQueue.push(pk);
		pthread_mutex_unlock(&s_requestQueueMutex);
		isSending = false;
		if (!isSending)
		{
			processSending();
		}
		else
		{
			printf("push to queue\n");
		}
}

//doc du lieu
bool ClientBitZero::read(){
	if (isReady)
	{
		//char szBuffer[MAX_BUFFER] ;
		vector <char> szBuffer(5000);
		int nLength ;
		nLength = socket->readData(szBuffer, szBuffer.size());
		if ( nLength > 0 )
		{
			szBuffer.resize(nLength);
			// xu ly slow connection
			buff->append(szBuffer,nLength);
			while(true){

				int validSize = PacketFactory::getValidSize(buff->vectorBuffer.data(), buff->vectorBuffer.size());
				if(validSize < 0 || validSize > buff->vectorBuffer.size())

					break;
				BZPacket pk;
				pk.size = validSize;
				buff->split(pk);
				pthread_mutex_lock(&s_responseQueueMutex);
				s_responseQueue.push(pk);
				pthread_mutex_unlock(&s_responseQueueMutex);
			}
		}else{
			return false;
		}
	}
	return true;
}
void ClientBitZero::emptyRequestQueue()
{
	// cleanup
	if(stateSocket != DISCONNECT)
	{
		pthread_mutex_lock(&s_requestQueueMutex);
		s_requestQueue.empty();
		pthread_mutex_unlock(&s_requestQueueMutex);
	}
	stateSocket = DISCONNECT;
}
void ClientBitZero::onConnectionClose()
{
	if(_autoReconnect)
	{
		
	}
	else
	{
		if(isReady)
			_isDisconnect = true;
			//onDisconnected();
	}
}
void ClientBitZero::onDisconnected()
{
	//ngat ket noi
	isReady = false;
	emptyRequestQueue();
	listener->onDisconnected();
}
//thuc hien gui tin
void ClientBitZero::processSending()
{
	if(!isReady)
		return;
	int nCntSend;
	isSending = true;
	while (!s_requestQueue.empty() && isReady)
	{
		if(!isReady){
			isSending = false;
			return;
		}
		BZPacket pk = s_requestQueue.front();
		int n = socket->sendData(pk.vectorBuffer.data(), pk.vectorBuffer.size());
		if(n>=0)
		{
			s_requestQueue.pop();
		}else
		{
			//send error
			onConnectionClose();
		}
		//CCLOG("<< SENT:%d: [%s]",pk.vectorBuffer.size(),byte_2_str(pk.vectorBuffer.data(), pk.vectorBuffer.size()).c_str());
	}
	isSending = false;
}
// thuc hien khi nhan dc tin
void ClientBitZero::dispatchResponseCallbacks(float delta){

	if(stateSocket == 0 || stateSocket == 1)
	{
		if(listener)
			listener->onFinishConnect(stateSocket);

		if(stateSocket == 0)
			stateSocket = DISCONNECT;
		else
		{
			stateSocket = CONNECT_TING;
		}
	}

	if (_isDisconnect)
	{
		onDisconnected();
		_isDisconnect = false;
	}
	if(s_responseQueue.empty())
		return;
	pthread_mutex_lock(&s_responseQueueMutex);
	BZPacket pk = s_responseQueue.front();
	s_responseQueue.pop();
	pthread_mutex_unlock(&s_responseQueueMutex);
	//CCLOG("<< IN:%d: [%s]",pk.size,byte_2_str(pk.vectorBuffer.data(),pk.size).c_str());
	CPacket* packet = PacketFactory::analyzeData(pk.vectorBuffer.data(), pk.vectorBuffer.size());
	//CCLOG("<< IN:%d: [%s]",packet->getCapacity(),byte_2_str(packet->getData(),packet->getCapacity()).c_str());
	if(listener)
		listener->onReceived(packet);

}

std::string ClientBitZero::byte_2_str(const char* bytes, int size){
	char const hex[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	std::string str;
	for (int i = 0;i<size; ++i)
	{
		const char ch = bytes[i];
		str.append(&hex[(ch & 0xF0)>>4],1);
		str.append(&hex[ch & 0xF],1);
		str.append(" ");
	}
	return str;
}

void ClientBitZero::setAutoReconnect( bool autoReconnect )
{
	 _autoReconnect = autoReconnect;
}
bool ClientBitZero::isDoConnection()
{
	return _serverPort != 0;
}
bool ClientBitZero::reconnect()
{
	if (_serverPort == 0)
	{
		return false;
	}
	//_isReconnecting = true;
	if(stateSocket != DISCONNECT)
		disconnect();
//	createSocket();
	initThread();
	return true;
}

void ClientBitZero::setIsDisconnectHandler( bool value )
{
	isDisconnectedHandler = value;
}

bool ClientBitZero::getIsDisconnectHandler()
{
	return isDisconnectedHandler;
}

void ClientBitZero::setNeedConnect( bool value, string serverIP, int port)
{
	needConnect = value;
	_serverIp = serverIP;
	this->_serverPort = port;
}

bool ClientBitZero::getIsReady()
{
	return stateSocket == CONNECT_TING;
}

#endif