#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
#include "BaseScene.h"
#include "CDialog.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

#define GUI_ADD_BUTTON(idbtn,nameinpanel,classtarget) \
	UIButton *btn##idbtn = (UIButton *)UIHelper::seekWidgetByName(m_RootPanel,nameinpanel);\
	if (btn##idbtn != NULL)\
{\
	btn##idbtn->setPressedActionEnabled(true);\
	btn##idbtn->setTag(idbtn);\
	btn##idbtn->addTouchEventListener(this, toucheventselector(classtarget::onButtonEvent));\
}\

#define GUI_ADD_BUTTON_IN_WIDGET(idbtn,rootWidget,nameinpanel,classtarget) \
	UIButton *btn##idbtn = (UIButton *)UIHelper::seekWidgetByName(rootWidget,nameinpanel);\
	if (btn##idbtn != NULL)\
{\
	btn##idbtn->setPressedActionEnabled(true);\
	btn##idbtn->setTag(idbtn);\
	btn##idbtn->addTouchEventListener(this, toucheventselector(classtarget::onButtonEvent));\
}\

class BaseScene;
class BaseLayer : public CCLayer
{
public:
	BaseLayer(void);

	// Create empty Layer
	CREATE_FUNC(BaseLayer);

	// Create layer with reources GUI
	static BaseLayer* createWithBinaryFile(const char *file);
	static BaseLayer* createWithJsonFile(const char *file);

	virtual void onEnter();
	virtual void onExit();

public:
	virtual bool init();
	virtual bool initWithBinaryFile(const char *file);
	virtual bool initWithJsonFile(const char *file);

	/************************************************************************/
	/* override meeeeeee                                                                     */
	/************************************************************************/
	virtual void customizeGUI() {};

	virtual void customizeButton(int btnID,const char *btnName){};
public:
	// button handler
	virtual void onButtonEvent(CCObject *sender,cocos2d::ui::TouchEventType typeEvent);
	virtual void onButtonTouch(unsigned int buttonID) {};
	virtual void onButtonRelease(unsigned int buttonID) {};

	virtual void setFog(bool fog);
public:
	UILayer *m_LayerGUI;
	UIPanel *m_RootPanel; 

	CCLayerColor *m_Fog;
	void needFullBackground(bool full = true);
};

