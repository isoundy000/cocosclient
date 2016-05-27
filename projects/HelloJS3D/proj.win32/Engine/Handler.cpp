#include "Handler.h"


Handler::Handler(string _id):
	id(_id),userData(NULL),needStop(false),jData(""),callback(NULL),_timeElapsed(0),_timeOut(0),needTimeOut(false)
{
}


Handler::~Handler(void)
{
}

void Handler::set(SEL_callbackHandler _callback)
{
	callback = _callback;
}

void Handler::setTimeOut(float t,bool needTOut)
{
	_timeOut = t;
	needTimeOut = needTOut;
}

static HandlerManager* instance = NULL;
HandlerManager::HandlerManager()
{

}

HandlerManager::~HandlerManager()
{

}

HandlerManager* HandlerManager::getInstance()
{
	if (instance == NULL)
	{
		instance = new HandlerManager();
	}
	return instance;
}

void HandlerManager::destroyInstance()
{
	CC_SAFE_DELETE(instance);
}

void HandlerManager::update(float dt)
{
	map<string,Handler*>::iterator iter = handlers.begin();

	vector<string> needRemoves;

	for (;iter !=handlers.end();iter++)
	{
		if (iter->second->needTimeOut && !iter->second->needStop)
		{
			iter->second->_timeElapsed += dt;
			if (iter->second->_timeElapsed >= iter->second->_timeOut)
			{
				for(int j=0;j<iter->second->listeners.size();j++)

					iter->second->listeners[j]->onResponse(iter->second,iter->second->jData);
				needRemoves.push_back(iter->first);
				continue;
			}
		}
		if (iter->second->needStop)
		{
			for(int j=0;j<iter->second->listeners.size();j++)
			{
				iter->second->listeners[j]->onResponse(iter->second,iter->second->jData);	
			}
			needRemoves.push_back(iter->first);

		}
	}

	for (int i=0;i<needRemoves.size();i++)
	{
		forceRemoveHandler(needRemoves[i]);
	}
}

Handler* HandlerManager::getHandler(string id)
{
	return handlers.find(id)->second;
}

Handler* HandlerManager::addHandler(string id,HandlerListener *listener)
{
	Handler* _handler = new Handler(id);
	_handler->addListener(listener);

	if (handlers.find(_handler->id) != handlers.end())
	{
		CCLOG("this handler %s has in handler manager , return ...",_handler->id.c_str());
	}
	else
	{
		handlers.insert(std::pair<string,Handler*>(_handler->id,_handler));
	}
	return _handler;
}

void HandlerManager::stopHandler(string id,string jdata)
{
	if (handlers.find(id) != handlers.end())
	{
		handlers.at(id)->jData = jdata;
		handlers.at(id)->needStop = true;
	}
}

void HandlerManager::forceRemoveHandler(string id)
{
	if (handlers.find(id) != handlers.end())
	{
		handlers.find(id)->second->cleanup();
		handlers.erase(id);
	}
}