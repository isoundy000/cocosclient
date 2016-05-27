#pragma once
#include <string>
#include <vector>
#include <map>
#include "cocos2d.h"
#include "CCLocalizedString.h"

USING_NS_CC;
using namespace std;
typedef void (*SEL_callbackHandler)(std::string);		// callback when finish handler

class Handler;
class HandlerListener : public CCNode
{
public:
	void onResponse(Handler *handler,std::string _jData) {_handler = handler;jData = _jData;onEnter();};
	CCObject* autorelease(){return this;}
	std::string getData(){return jData;};
	Handler *getHandler(){return _handler;}

	Handler *_handler;
	std::string jData;
};


class Handler : public CCObject
{
public:
	Handler(){};
	Handler(string _id);
	~Handler(void);

	void set(SEL_callbackHandler _callback);
	void setTimeOut(float t,bool needTOut);

	std::string getID(){return this->id;}

	void addListener(HandlerListener *lis){
		listeners.push_back(lis);
	}

	void clearListener(){
		for(int i=0;i<listeners.size();i++)
		{
			delete listeners[i];
		}
		listeners.clear();
	}
	void cleanup(){
		this->clearListener();
		delete this;
	}

public :
	std::vector<HandlerListener *> listeners;
	std::string id;
	std::string jData;
	bool needStop;
	void *userData;
	SEL_callbackHandler callback;
	float _timeElapsed;
	float _timeOut;
	bool needTimeOut;
};

class HandlerManager : public CCObject
{
public:
	HandlerManager();
	~HandlerManager();

	map<string,Handler*> handlers;
	virtual void update(float dt);

	static HandlerManager *getInstance();
	static void destroyInstance();

	Handler* addHandler(string id,HandlerListener *listener);

	Handler* getHandler(string id);

	void stopHandler(string id,string jdata);
	void forceRemoveHandler(string id);

	static string localizedString(string key)
	{
		return CCLocalizedString(key.c_str());
	}
};