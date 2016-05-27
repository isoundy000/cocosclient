#pragma once
#include "BaseLayer.h"


class Dialog;
class DialogListener
{
public:
	virtual void onDialogResult(Dialog *dialog,int result) = 0;
};

class Dialog : public BaseLayer
{
public:
	Dialog(void);
	~Dialog(void);

	enum 
	{
		kDialogAgree = 0,
		kDialogCancel,
		kDialogUnknown
	};

	CREATE_FUNC(Dialog);

	virtual bool init();
	virtual void customizeGUI();
	virtual void onButtonRelease(unsigned int buttonID);

	CC_SYNTHESIZE(DialogListener *,listener,Listener);
	void effectShow();
protected:
	CCLayerColor *fogLayer;

public:
	static Dialog *showYesNoDialog(DialogListener *_listener,int TAG);
	void setTypeOneButtonOK();
	void setTypeOneButtonCancel();
	void setButtonQuit(bool enable = true);

};

