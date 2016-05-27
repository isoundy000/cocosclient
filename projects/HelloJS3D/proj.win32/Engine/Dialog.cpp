#include "Dialog.h"
#include "SceneMgr.h"

#define BTN_OK 1
#define BTN_CANCEL 2
#define BTN_QUIT 3

// only on Dialog
static Dialog *_dialog = NULL;

Dialog::Dialog(void)
{
}


Dialog::~Dialog(void)
{
}

bool Dialog::init()
{
	bool ret = BaseLayer::init();
	fogLayer = CCLayerColor::create(ccc4(0,0,0,255));
	addChild(fogLayer);
	fogLayer->setVisible(false);
	initWithJsonFile("Dialog/Dialog.json");
	return ret;
}

void Dialog::customizeGUI()
{
	GUI_ADD_BUTTON(BTN_OK,"btnOk",Dialog);
	GUI_ADD_BUTTON(BTN_CANCEL,"btnCancel",Dialog);
	GUI_ADD_BUTTON(BTN_QUIT,"btnQuit",Dialog);

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

}

void Dialog::onButtonRelease(unsigned int buttonID)
{
	switch (buttonID)
	{
	case BTN_OK:
		{
			if (listener)
			{
				listener->onDialogResult(this,kDialogAgree);
			}
			break;
		}
	case BTN_CANCEL:
		{
			if (listener)
			{
				listener->onDialogResult(this,kDialogCancel);
			}
			break;
		}
	case BTN_QUIT:
		{
			if (listener)
			{
				listener->onDialogResult(this,kDialogUnknown);
			}
			break;
		}
	default:
		break;
	}
	removeFromParentAndCleanup(true);
	_dialog = NULL;
}

Dialog *Dialog::showYesNoDialog(DialogListener *_listener,int TAG)
{
	if (_dialog)
	{
		_dialog->removeFromParentAndCleanup(true);
		_dialog = NULL;
	}

	_dialog = Dialog::create();
	SceneMgr::sharedSceneMgr()->getRunningScene()->addChild(_dialog);
	_dialog->setZOrder(100);

	if (_listener)
	{
		_dialog->setListener(_listener);
	}
	_dialog->setTag(TAG);
	_dialog->effectShow();
	return _dialog;
}

void Dialog::effectShow()
{
	fogLayer->setVisible(true);
	fogLayer->setOpacity(0);
	fogLayer->runAction(CCFadeTo::create(.3,100));
	m_LayerGUI->setScale(1.5);
	m_LayerGUI->runAction(CCEaseBackOut::create(CCScaleTo::create(.3,1)));
}