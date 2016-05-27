#ifndef __engine_h__
#define __engine_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_HandlerListener_class;
extern JSObject *jsb_HandlerListener_prototype;

JSBool js_engine_HandlerListener_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_engine_HandlerListener_finalize(JSContext *cx, JSObject *obj);
void js_register_engine_HandlerListener(JSContext *cx, JSObject *global);
void register_all_engine(JSContext* cx, JSObject* obj);
JSBool js_engine_HandlerListener_getHandler(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_HandlerListener_getData(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_HandlerListener_onResponse(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_HandlerListener_autorelease(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Handler_class;
extern JSObject *jsb_Handler_prototype;

JSBool js_engine_Handler_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_engine_Handler_finalize(JSContext *cx, JSObject *obj);
void js_register_engine_Handler(JSContext *cx, JSObject *global);
void register_all_engine(JSContext* cx, JSObject* obj);
JSBool js_engine_Handler_addListener(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_Handler_getID(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_Handler_cleanup(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_Handler_setTimeOut(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_Handler_clearListener(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_Handler_Handler(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_HandlerManager_class;
extern JSObject *jsb_HandlerManager_prototype;

JSBool js_engine_HandlerManager_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_engine_HandlerManager_finalize(JSContext *cx, JSObject *obj);
void js_register_engine_HandlerManager(JSContext *cx, JSObject *global);
void register_all_engine(JSContext* cx, JSObject* obj);
JSBool js_engine_HandlerManager_addHandler(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_HandlerManager_update(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_HandlerManager_forceRemoveHandler(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_HandlerManager_stopHandler(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_HandlerManager_getHandler(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_HandlerManager_destroyInstance(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_HandlerManager_getInstance(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_HandlerManager_localizedString(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_HandlerManager_HandlerManager(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_CCAvatar_class;
extern JSObject *jsb_CCAvatar_prototype;

JSBool js_engine_CCAvatar_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_engine_CCAvatar_finalize(JSContext *cx, JSObject *obj);
void js_register_engine_CCAvatar(JSContext *cx, JSObject *global);
void register_all_engine(JSContext* cx, JSObject* obj);
JSBool js_engine_CCAvatar_setImage(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CCAvatar_finishDownload(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CCAvatar_checkAndSetTexture(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CCAvatar_loadingNCallBack(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CCAvatar_updateImage(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CCAvatar_create(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CCAvatar_filePathFromUrl(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CCAvatar_createWithSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CCAvatar_CCAvatar(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_UIAvatar_class;
extern JSObject *jsb_UIAvatar_prototype;

JSBool js_engine_UIAvatar_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_engine_UIAvatar_finalize(JSContext *cx, JSObject *obj);
void js_register_engine_UIAvatar(JSContext *cx, JSObject *global);
void register_all_engine(JSContext* cx, JSObject* obj);
JSBool js_engine_UIAvatar_setTexture(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_UIAvatar_finishDownload(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_UIAvatar_asyncExecuteWithUrl(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_UIAvatar_setDefaultImage(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_UIAvatar_setImage(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_UIAvatar_getImageSize(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_UIAvatar_asyncExecute(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_UIAvatar_create(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_UIAvatar_createWithMask(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_UIAvatar_UIAvatar(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_MessageBuffer_class;
extern JSObject *jsb_MessageBuffer_prototype;

JSBool js_engine_MessageBuffer_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_engine_MessageBuffer_finalize(JSContext *cx, JSObject *obj);
void js_register_engine_MessageBuffer(JSContext *cx, JSObject *global);
void register_all_engine(JSContext* cx, JSObject* obj);
JSBool js_engine_MessageBuffer_putInt(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_getString(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_putBytes(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_getShort(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_putByteArray(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_putShort(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_getCapacity(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_rewind(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_getLimit(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_putByte(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_getByte(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_getBool(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_putString(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_initData(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_autorelease(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_getInt(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_getPosition(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_getDouble(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_putDouble(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_reload(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_getUnsignedShort(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_MessageBuffer_MessageBuffer(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_CPacket_class;
extern JSObject *jsb_CPacket_prototype;

JSBool js_engine_CPacket_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_engine_CPacket_finalize(JSContext *cx, JSObject *obj);
void js_register_engine_CPacket(JSContext *cx, JSObject *global);
void register_all_engine(JSContext* cx, JSObject* obj);
JSBool js_engine_CPacket_getCmdID(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CPacket_getError(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CPacket_parseHeader(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CPacket_getSize(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CPacket_cleanup(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CPacket_getControllerID(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CPacket_getData(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CPacket_pack(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CPacket_getCmdId(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CPacket_isBigSize(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_CPacket_CPacket(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_InPacket_class;
extern JSObject *jsb_InPacket_prototype;

JSBool js_engine_InPacket_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_engine_InPacket_finalize(JSContext *cx, JSObject *obj);
void js_register_engine_InPacket(JSContext *cx, JSObject *global);
void register_all_engine(JSContext* cx, JSObject* obj);
JSBool js_engine_InPacket_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_InPacket_InPacket(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_OutPacket_class;
extern JSObject *jsb_OutPacket_prototype;

JSBool js_engine_OutPacket_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_engine_OutPacket_finalize(JSContext *cx, JSObject *obj);
void js_register_engine_OutPacket(JSContext *cx, JSObject *global);
void register_all_engine(JSContext* cx, JSObject* obj);
JSBool js_engine_OutPacket_setControllerId(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_OutPacket_setCmdId(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_OutPacket_OutPacket(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_BZListener_class;
extern JSObject *jsb_BZListener_prototype;

JSBool js_engine_BZListener_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_engine_BZListener_finalize(JSContext *cx, JSObject *obj);
void js_register_engine_BZListener(JSContext *cx, JSObject *global);
void register_all_engine(JSContext* cx, JSObject* obj);
JSBool js_engine_BZListener_onReceived(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_BZListener_getState(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_BZListener_getSuccess(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_BZListener_autorelease(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_BZListener_onFinishConnect(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_BZListener_onDisconnected(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_BZListener_getPacket(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_BZListener_BZListener(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_ClientBitZero_class;
extern JSObject *jsb_ClientBitZero_prototype;

JSBool js_engine_ClientBitZero_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_engine_ClientBitZero_finalize(JSContext *cx, JSObject *obj);
void js_register_engine_ClientBitZero(JSContext *cx, JSObject *global);
void register_all_engine(JSContext* cx, JSObject* obj);
JSBool js_engine_ClientBitZero_setTimeoutForConnect(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_createSocket(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_getIsDisconnectHandler(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_getTimeoutForConnect(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_connect(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_reconnect(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_disconnect(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_initThread(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_setTimeoutForRead(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_send(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_setListener(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_dispatchResponseCallbacks(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_setNeedConnect(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_getTimeoutForRead(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_isDoConnection(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_setAutoReconnect(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_getIsReady(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_setIsDisconnectHandler(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_destroyInstance(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_networkThread(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_getInstance(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_engine_ClientBitZero_ClientBitZero(JSContext *cx, uint32_t argc, jsval *vp);
#endif

