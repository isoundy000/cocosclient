#ifndef CLIENT_BITZERO_H
#define CLIENT_BITZERO_H

#if defined(WP8) && defined(_WP8)
#include <mutex>
#include <thread>
#else
	#include <pthread.h>
#endif
#include <queue>
#include "socket/CommonSocket.h"
#include "cocos2d.h"
#include "packet/CPacket.h"
#include <string>
#include "packet/BZPacket.h"
using namespace std;
USING_NS_CC;

class BZListener : public CCNode{
public:
	BZListener(){
		stateResponse = 0;		// 0 : connect, 1 ; disconnect, 2 : onReceive
	}
	virtual void onFinishConnect(bool isSuccess){stateResponse = 0;success = isSuccess;onEnter();};
	virtual void onDisconnected(){stateResponse = 1;onEnter();};
	virtual void onReceived(CPacket* packet){this->packet = packet;stateResponse = 2;this->packet->parseHeader();onEnter();};

	CCObject *autorelease(){return this;};

	int getState(){return stateResponse;}
	bool getSuccess(){return success;}
	CPacket *getPacket(){return packet;}

public:
	int stateResponse;
	bool success;
	CPacket *packet;
};
class ClientBitZero:
	public CCObject{
public:
	ClientBitZero();
	~ClientBitZero();
private:
	CommonSocket* socket;
	bool isSending;
	bool isReady;
	int _timeoutForConnect;
	int _timeoutForRead;
	bool _autoReconnect;
	bool _isReconnecting;
	bool need_quit;
	bool isDisconnectedHandler;
	time_t timer;
	int stateSocket;
	
#if defined(WP8) && defined(_WP8)
	std::mutex   s_requestQueueMutex;
	std::mutex   s_responseQueueMutex;
	std::thread* s_networkThread;
#else
	pthread_t        s_networkThread;
	pthread_mutex_t  s_requestQueueMutex;
	pthread_mutex_t  s_responseQueueMutex;
#endif

	queue<BZPacket> s_requestQueue;
	queue<BZPacket> s_responseQueue;

	BZListener* listener;
	bool read();
	void processSending();
	std::string byte_2_str(const char* bytes, int size);
	//
	void send(const char* data, int length);
	void emptyRequestQueue();
	void onConnectionClose();
	void onDisconnected();
	BZPacket* buff;
	std::string _serverIp;
	int _serverPort;
	bool _isDisconnect;
	bool needConnect;
public:
	void createSocket();

	/** Return the shared instance **/
	static ClientBitZero *getInstance();
	/** Release the shared instance **/
	static void destroyInstance();
	/** ket noi**/
	void connect(const char* serverIP, int serverPort);
	/** ngat ket noi**/
	void disconnect();
	/** Gui goi tin**/
	void send(CPacket* packet);
	/** Poll function called from main thread to dispatch callbacks when http requests finished **/
	void dispatchResponseCallbacks(float delta);
	bool initThread();
	void setListener(BZListener* listener);
	static void* networkThread(void *arg);
	void networkLoop();
	void joinSubThread();

	//timeout
	inline void setTimeoutForConnect(int value) {_timeoutForConnect = value;};
	inline int getTimeoutForConnect() {return _timeoutForConnect;}
	inline void setTimeoutForRead(int value) {_timeoutForRead = value;};
	inline int getTimeoutForRead() {return _timeoutForRead;};
	void setAutoReconnect(bool autoReconnect);
	bool isDoConnection();
	bool reconnect();

	void setIsDisconnectHandler(bool value);
	bool getIsDisconnectHandler();
	void setNeedConnect(bool value, string serverIP, int port);
	bool getIsReady();
	void clearQueue();
};
#endif // !1
