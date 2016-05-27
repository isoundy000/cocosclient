#include "BaseLayer.h"


using namespace cocos2d::ui;
BaseLayer::BaseLayer(void) :
	m_LayerGUI(NULL),
	m_RootPanel(NULL),
	m_Fog(NULL)
{
}



bool BaseLayer::init()
{
	return CCLayer::init();
}


void BaseLayer::onButtonEvent(CCObject *sender,TouchEventType typeEvent)
{
	switch (typeEvent)
	{
	case TOUCH_EVENT_BEGAN:
		onButtonTouch(((CCNode *)sender)->getTag());
		break;
	case TOUCH_EVENT_ENDED:
		onButtonRelease(((CCNode *)sender)->getTag());
		break;
	default:
		break;
	}
}

BaseLayer *BaseLayer::createWithBinaryFile(const char *file)
{
	BaseLayer *ret = new BaseLayer();
	if (ret->init())
	{
		ret->autorelease();
		ret->initWithBinaryFile(file);
		return ret;
	}
	else
	{
		return NULL;
	}
}

BaseLayer *BaseLayer::createWithJsonFile(const char *file)
{
	BaseLayer *ret = new BaseLayer();
	if (ret->init())
	{
		ret->autorelease();
		ret->initWithJsonFile(file);

		return ret;
	}
	else
	{
		return NULL;
	}
}

bool BaseLayer::initWithBinaryFile(const char *file)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	m_LayerGUI = UILayer::create();
	m_RootPanel = (UIPanel *)GUIReader::shareReader()->widgetFromBinaryFile(file);

	m_LayerGUI->addWidget(m_RootPanel);
	m_RootPanel->setSize(winSize);
	addChild(m_LayerGUI);

	customizeGUI();
	return true;
}


bool BaseLayer::initWithJsonFile(const char *file)
{

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	m_LayerGUI = UILayer::create();
	m_RootPanel = (UIPanel *)GUIReader::shareReader()->widgetFromJsonFile(file);

	m_LayerGUI->addWidget(m_RootPanel);
	m_RootPanel->setSize(winSize);
	addChild(m_LayerGUI);

	customizeGUI();


	return true;
}

void BaseLayer::setFog(bool fog)
{
	// todo
}

void BaseLayer::needFullBackground(bool full)
{
	ImageView *bg = (ui::ImageView *)UIHelper::seekWidgetByName(m_RootPanel,"bg");
	if (!bg)
		return;
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCSize bgSize = bg->getContentSize();
	if (full)
	{
		bg->setScaleX(winSize.width / bgSize.width);
		bg->setScaleY(winSize.height/bgSize.height);
	}
	else
	{
		bg->setScale(1);
	}
}

void BaseLayer::onEnter()
{
	CCLayer::onEnter();
}

void BaseLayer::onExit()
{
	CCLayer::onExit();
}