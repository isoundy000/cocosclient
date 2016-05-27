#if defined(WP8) && defined(_WP8)
#include "DefaultSocket.h"
#include "cocos2d.h"
USING_NS_CC;
DefaultSocket::DefaultSocket()
{
}

DefaultSocket::~DefaultSocket()
{
}
//khoi tao cho win32
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
bool DefaultSocket::initWinSock2_0()
{
	WSADATA wsaData ;
	WORD wVersion = MAKEWORD( 2, 0 ) ;
	if ( ! WSAStartup( wVersion, &wsaData ) )
		return true ;
	return false ;
}
#endif
//Mo ket noi
bool DefaultSocket::connectSocket(const char* serverIP, int serverPort)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	if(!initWinSock2_0())
		return false;
#endif	
	hClientSocket = socket(AF_INET, SOCK_STREAM,0);
	if ( hClientSocket <0 )
	{
		CCLog("Unable to init socket");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
		// Cleanup the environment initialized by WSAStartup()
		WSACleanup( ) ;
#endif	
		return false ;
	}
	struct hostent *server;
	server = gethostbyname(serverIP);
	if (server == NULL) {
		CCLog("ERROR, no such host\n");
		return false;
	}
	// Create the structure describing various Server parameters
	struct sockaddr_in serverAddr ;

	serverAddr . sin_family = AF_INET ;     // The address family. MUST be AF_INET
	serverAddr . sin_addr . s_addr = inet_addr( serverIP ) ;
	serverAddr . sin_port = htons( serverPort ) ;

	// Connect to the server
	if ( connect( hClientSocket, ( struct sockaddr * ) &serverAddr, sizeof( serverAddr ) ) < 0 )
	{
		CCLog("Unable to connect to server ");

		closeSocket();
		return false ;
	}
	peerSocket = hClientSocket;
	return true;
}
//Gui du lieu
int DefaultSocket::sendData(const char* data, int nLength)
{
	//for(int i = 0;i<nLength;i++){
	//	CCLOG("byte: %d",data[i]);
	//}
	return send( peerSocket, data, nLength, 0);
}
//Doc du lieu
//int	 DefaultSocket::readData(char* buffer,int len)
//{
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//	return recv(peerSocket, buffer, len, 0 ) ;
//#else
//	return read(peerSocket,buffer,len);
//#endif
//}

int	DefaultSocket::readData(vector <char> &vectorBuffer, int len)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	//char *test = reinterpret_cast<char*>(&vectorBuffer[0]);
	return recv(peerSocket, &vectorBuffer[0], len, 0);
#else
	return read(peerSocket,vectorBuffer.data(), len);
#endif
}

void DefaultSocket::closeSocket(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	closesocket( hClientSocket ) ;
	WSACleanup( ) ;
#else
	close(hClientSocket);
#endif
}

#endif