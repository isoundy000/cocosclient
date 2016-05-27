/*
 * CDialog.cpp
 *
 *  Created on: Jul 23, 2013
 *      Author: kienvn
 */

#include "CDialog.h"
#include "cocos2d.h"
#if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#include "platform/CCCommon.h"
#endif
#include "CCLocalizedString.h"
USING_NS_CC;
static bool _isFirstRun = true;
CDialog* CDialog::_dialog = NULL;

CDialog::CDialog()
{
	listener = NULL;
}
CDialog::~CDialog()
{

}

CDialog* CDialog::shared() {
	if(_isFirstRun)
	{
		_dialog = new CDialog();
		_isFirstRun = false;
	}
	return _dialog;
}
void CDialog::purge() {
	_isFirstRun = true;
	CC_SAFE_DELETE(_dialog);
}

void CDialog::setListener(CDialogListener *lis)
{
	listener = lis;
}
//bang thong bao khi mat ket noi
void CDialog::showDialogConnectionError()
{
	showYesNoDialog(DIALOG_CONNECTION_ERROR,"",CCLocalizedString("txt_cant_connect_to_server").c_str(),CCLocalizedString("text_try_cmd").c_str(),CCLocalizedString("text_exit_game_cmd").c_str());
}
//bang thong bao khi thoat game
void CDialog::showDialogExitGame()
{
	showYesNoDialog(DIALOG_ASK_EXIT_GAME,"Dong y thoat game?","","OK","Cancel");
}
void CDialog::showDialogUpdateVersion()
{
	showYesNoDialog(DIALOG_UPDATE_VERSION,"",CCLocalizedString("text_update_version_alert").c_str(),CCLocalizedString("text_update").c_str(),CCLocalizedString("text_exit_game_cmd").c_str());
}
void CDialog::showDialogMaintain(const char* msg)
{
	showOKDialog(DIALOG_MAINTAIN,"",msg,"OK");
}
void CDialog::showOKDialog(int type, const char* titleTxt,const char* messageTxt, const char* okTxt)
{
#if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)

	cocos2d::JniMethodInfo t;
	if (cocos2d::JniHelper::getStaticMethodInfo(t,
		"gsn/zingplay/utils/UIHelper",
		"showOkDialog",
		"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;J)V"))
	{
		jlong arg1 = type;
		t.env->CallStaticVoidMethod(t.classID, t.methodID, t.env->NewStringUTF(titleTxt),t.env->NewStringUTF(messageTxt), t.env->NewStringUTF(okTxt), arg1);
		t.env->DeleteLocalRef(t.classID);
	}
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	MessageBoxA(NULL, messageTxt, titleTxt, MB_OKCANCEL);
#endif
}
//xu ly 
void CDialog::processDialogCallback(int type, int result) {
	if (listener)
	{
		listener->onCDialogResult(type,result);
	}
	switch(type)
	{
	case DIALOG_ASK_EXIT_GAME:
		if (result == 1)
		{
			//GameManager::exitGame();
		}
		break;
	case DIALOG_MAINTAIN:{
			CCDirector::sharedDirector()->end();
		}
		break;
	}
}
void CDialog::showToastWithLongTime(const char* messageTxt)
{
#if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)


	cocos2d::JniMethodInfo t;
	if (cocos2d::JniHelper::getStaticMethodInfo(t,
		"com/gsn/linklink/UtilityHelper",
		"showLongToast",
		"(Ljava/lang/String;)V"))
	{
		t.env->CallStaticVoidMethod(t.classID, t.methodID, t.env->NewStringUTF(messageTxt));
		t.env->DeleteLocalRef(t.classID);
	}
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	MessageBoxA(NULL, messageTxt, messageTxt, MB_OKCANCEL);
#endif
}
void CDialog::showToastWithShortTime(const char* messageTxt)
{
#if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)


	cocos2d::JniMethodInfo t;
	if (cocos2d::JniHelper::getStaticMethodInfo(t,
		"com/gsn/linklink/UtilityHelper",
		"showShortToast",
		"(Ljava/lang/String;)V"))
	{
		t.env->CallStaticVoidMethod(t.classID, t.methodID, t.env->NewStringUTF(messageTxt));
		t.env->DeleteLocalRef(t.classID);
	}
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	MessageBoxA(NULL, messageTxt, messageTxt, MB_OK);
#endif
}
//Android
void CDialog::showYesNoDialog(int type,const char* titleTxt, const char* messageTxt, const char* okTxt,
		const char* noTxt) {
			listener = NULL;
	#if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)

	CCLOG("+++++++++++++CDialog::showYesNoDialog++++++++++++");
	cocos2d::JniMethodInfo t;
	  if (cocos2d::JniHelper::getStaticMethodInfo(t,
	                                                "gsn/zingplay/utils/UIHelper",
	                                                "showYesNoDialog",
	                                                "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;J)V"))
	    {
			CCLOG("----------------CDialog::showYesNoDialog-------------");
	        jlong arg1 = type;
	        t.env->CallStaticVoidMethod(t.classID, t.methodID, t.env->NewStringUTF(titleTxt),t.env->NewStringUTF(messageTxt), t.env->NewStringUTF(okTxt), t.env->NewStringUTF(noTxt), arg1);
	        t.env->DeleteLocalRef(t.classID);
	    }
	  #endif
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	   MessageBoxA(NULL, messageTxt, titleTxt, MB_OKCANCEL);
	#endif
}

void CDialog::openLink(const char* link)
{
#if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo t;
	if (cocos2d::JniHelper::getStaticMethodInfo(t,
		"com/gsn/linklink/UtilityHelper",
		"openLink",
		"(Ljava/lang/String;)V"))
	{
		t.env->CallStaticVoidMethod(t.classID, t.methodID, t.env->NewStringUTF(link));
		t.env->DeleteLocalRef(t.classID);
	}
#endif
}
#if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)
extern "C"
{
	void Java_gsn_zingplay_utils_UIHelper_nativeOnDialogResponse(JNIEnv* env,
                                                                                 jobject thiz,
                                                                                 jint type,
                                                                                 jint result)
	{
		CDialog::shared()->processDialogCallback((int)type,(int)result);
	}

};
#endif