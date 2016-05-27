/**
 * @module engine
 */
var engine = engine || {};

/**
 * @class HandlerListener
 */
engine.HandlerListener = {

/**
 * @method getHandler
 * @return A value converted from C/C++ "Handler*"
 */
getHandler : function () {},

/**
 * @method getData
 * @return A value converted from C/C++ "std::string"
 */
getData : function () {},

/**
 * @method onResponse
 * @param {Handler*}
 * @param {std::string}
 */
onResponse : function () {},

/**
 * @method autorelease
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 */
autorelease : function () {},

};

/**
 * @class Handler
 */
engine.Handler = {

/**
 * @method addListener
 * @param {HandlerListener*}
 */
addListener : function () {},

/**
 * @method getID
 * @return A value converted from C/C++ "std::string"
 */
getID : function () {},

/**
 * @method cleanup
 */
cleanup : function () {},

/**
 * @method setTimeOut
 * @param {float}
 * @param {bool}
 */
setTimeOut : function () {},

/**
 * @method clearListener
 */
clearListener : function () {},

};

/**
 * @class HandlerManager
 */
engine.HandlerManager = {

/**
 * @method addHandler
 * @return A value converted from C/C++ "Handler*"
 * @param {std::string}
 * @param {HandlerListener*}
 */
addHandler : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method forceRemoveHandler
 * @param {std::string}
 */
forceRemoveHandler : function () {},

/**
 * @method stopHandler
 * @param {std::string}
 * @param {std::string}
 */
stopHandler : function () {},

/**
 * @method getHandler
 * @return A value converted from C/C++ "Handler*"
 * @param {std::string}
 */
getHandler : function () {},

/**
 * @method destroyInstance
 */
destroyInstance : function () {},

/**
 * @method getInstance
 * @return A value converted from C/C++ "HandlerManager*"
 */
getInstance : function () {},

/**
 * @method localizedString
 * @return A value converted from C/C++ "std::string"
 * @param {std::string}
 */
localizedString : function () {},

/**
 * @method HandlerManager
 * @constructor
 */
HandlerManager : function () {},

};

/**
 * @class CCAvatar
 */
engine.CCAvatar = {

/**
 * @method setImage
 * @param {const char*}
 * @param {const char*}
 */
setImage : function () {},

/**
 * @method finishDownload
 * @param {cocos2d::CCNode*}
 * @param {void*}
 */
finishDownload : function () {},

/**
 * @method checkAndSetTexture
 * @param {cocos2d::CCTexture2D*}
 */
checkAndSetTexture : function () {},

/**
 * @method loadingNCallBack
 * @param {cocos2d::CCObject*}
 */
loadingNCallBack : function () {},

/**
 * @method updateImage
 */
updateImage : function () {},

/**
 * @method filePathFromUrl
 * @return A value converted from C/C++ "std::string"
 * @param {const char*}
 * @param {const char*}
 */
filePathFromUrl : function () {},

/**
 * @method createWithSpriteFrame
 * @return A value converted from C/C++ "CCAvatar*"
 * @param {const char*}
 */
createWithSpriteFrame : function () {},

/**
 * @method CCAvatar
 * @constructor
 */
CCAvatar : function () {},

};

/**
 * @class UIAvatar
 */
engine.UIAvatar = {

/**
 * @method setTexture
 * @param {cocos2d::CCTexture2D*}
 */
setTexture : function () {},

/**
 * @method finishDownload
 * @param {cocos2d::CCNode*}
 * @param {void*}
 */
finishDownload : function () {},

/**
 * @method asyncExecuteWithUrl
 * @param {std::string}
 * @param {std::string}
 */
asyncExecuteWithUrl : function () {},

/**
 * @method setDefaultImage
 */
setDefaultImage : function () {},

/**
 * @method setImage
 * @param {std::string}
 */
setImage : function () {},

/**
 * @method getImageSize
 * @return A value converted from C/C++ "cocos2d::CCSize"
 */
getImageSize : function () {},

/**
 * @method asyncExecute
 */
asyncExecute : function () {},

/**
 * @method createWithMask
 * @return A value converted from C/C++ "UIAvatar*"
 * @param {std::string}
 * @param {std::string}
 * @param {std::string}
 */
createWithMask : function () {},

/**
 * @method UIAvatar
 * @constructor
 */
UIAvatar : function () {},

};

/**
 * @class MessageBuffer
 */
engine.MessageBuffer = {

/**
 * @method putInt
 * @return A value converted from C/C++ "MessageBuffer*"
 * @param {int}
 */
putInt : function () {},

/**
 * @method getString
 * @return A value converted from C/C++ "std::string"
 */
getString : function () {},

/**
 * @method putBytes
 * @return A value converted from C/C++ "MessageBuffer*"
 * @param {const char*}
 * @param {int}
 */
putBytes : function () {},

/**
 * @method getShort
 * @return A value converted from C/C++ "int"
 */
getShort : function () {},

/**
 * @method putByteArray
 * @return A value converted from C/C++ "MessageBuffer*"
 * @param {const char*}
 * @param {int}
 */
putByteArray : function () {},

/**
 * @method putShort
 * @return A value converted from C/C++ "MessageBuffer*"
 * @param {int}
 */
putShort : function () {},

/**
 * @method getCapacity
 * @return A value converted from C/C++ "int"
 */
getCapacity : function () {},

/**
 * @method rewind
 */
rewind : function () {},

/**
 * @method getLimit
 * @return A value converted from C/C++ "int"
 */
getLimit : function () {},

/**
 * @method putByte
 * @return A value converted from C/C++ "MessageBuffer*"
 * @param {int}
 */
putByte : function () {},

/**
 * @method getByte
 * @return A value converted from C/C++ "int"
 */
getByte : function () {},

/**
 * @method getBool
 * @return A value converted from C/C++ "bool"
 */
getBool : function () {},

/**
 * @method putString
 * @return A value converted from C/C++ "MessageBuffer*"
 * @param {std::string}
 */
putString : function () {},

/**
 * @method initData
 * @param {int}
 */
initData : function () {},

/**
 * @method autorelease
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 */
autorelease : function () {},

/**
 * @method getInt
 * @return A value converted from C/C++ "int"
 */
getInt : function () {},

/**
 * @method getPosition
 * @return A value converted from C/C++ "int"
 */
getPosition : function () {},

/**
 * @method getDouble
 * @return A value converted from C/C++ "double"
 */
getDouble : function () {},

/**
 * @method putDouble
 * @return A value converted from C/C++ "MessageBuffer*"
 * @param {double}
 */
putDouble : function () {},

/**
 * @method reload
 * @param {const char*}
 * @param {int}
 */
reload : function () {},

/**
 * @method getUnsignedShort
 * @return A value converted from C/C++ "int"
 */
getUnsignedShort : function () {},

};

/**
 * @class CPacket
 */
engine.CPacket = {

/**
 * @method getCmdID
 * @return A value converted from C/C++ "int"
 */
getCmdID : function () {},

/**
 * @method getError
 * @return A value converted from C/C++ "int"
 */
getError : function () {},

/**
 * @method parseHeader
 */
parseHeader : function () {},

/**
 * @method getSize
 * @return A value converted from C/C++ "int"
 */
getSize : function () {},

/**
 * @method cleanup
 */
cleanup : function () {},

/**
 * @method getControllerID
 * @return A value converted from C/C++ "int"
 */
getControllerID : function () {},

/**
 * @method getData
 * @return A value converted from C/C++ "const char*"
 */
getData : function () {},

/**
 * @method pack
 */
pack : function () {},

/**
 * @method getCmdId
 * @return A value converted from C/C++ "short"
 * @param {const char*}
 */
getCmdId : function () {},

/**
 * @method isBigSize
 * @return A value converted from C/C++ "bool"
 * @param {const char*}
 */
isBigSize : function () {},

};

/**
 * @class InPacket
 */
engine.InPacket = {

/**
 * @method init
 * @param {CPacket*}
 */
init : function () {},

};

/**
 * @class OutPacket
 */
engine.OutPacket = {

/**
 * @method setControllerId
 * @param {int}
 */
setControllerId : function () {},

/**
 * @method setCmdId
 * @param {int}
 */
setCmdId : function () {},

};

/**
 * @class BZListener
 */
engine.BZListener = {

/**
 * @method onReceived
 * @param {CPacket*}
 */
onReceived : function () {},

/**
 * @method getState
 * @return A value converted from C/C++ "int"
 */
getState : function () {},

/**
 * @method getSuccess
 * @return A value converted from C/C++ "bool"
 */
getSuccess : function () {},

/**
 * @method autorelease
 * @return A value converted from C/C++ "cocos2d::CCObject*"
 */
autorelease : function () {},

/**
 * @method onFinishConnect
 * @param {bool}
 */
onFinishConnect : function () {},

/**
 * @method onDisconnected
 */
onDisconnected : function () {},

/**
 * @method getPacket
 * @return A value converted from C/C++ "CPacket*"
 */
getPacket : function () {},

/**
 * @method BZListener
 * @constructor
 */
BZListener : function () {},

};

/**
 * @class ClientBitZero
 */
engine.ClientBitZero = {

/**
 * @method setTimeoutForConnect
 * @param {int}
 */
setTimeoutForConnect : function () {},

/**
 * @method createSocket
 */
createSocket : function () {},

/**
 * @method getIsDisconnectHandler
 * @return A value converted from C/C++ "bool"
 */
getIsDisconnectHandler : function () {},

/**
 * @method getTimeoutForConnect
 * @return A value converted from C/C++ "int"
 */
getTimeoutForConnect : function () {},

/**
 * @method connect
 * @param {const char*}
 * @param {int}
 */
connect : function () {},

/**
 * @method reconnect
 * @return A value converted from C/C++ "bool"
 */
reconnect : function () {},

/**
 * @method disconnect
 */
disconnect : function () {},

/**
 * @method initThread
 * @return A value converted from C/C++ "bool"
 */
initThread : function () {},

/**
 * @method setTimeoutForRead
 * @param {int}
 */
setTimeoutForRead : function () {},

/**
 * @method send
 * @param {CPacket*}
 */
send : function () {},

/**
 * @method setListener
 * @param {BZListener*}
 */
setListener : function () {},

/**
 * @method dispatchResponseCallbacks
 * @param {float}
 */
dispatchResponseCallbacks : function () {},

/**
 * @method setNeedConnect
 * @param {bool}
 * @param {std::string}
 * @param {int}
 */
setNeedConnect : function () {},

/**
 * @method getTimeoutForRead
 * @return A value converted from C/C++ "int"
 */
getTimeoutForRead : function () {},

/**
 * @method isDoConnection
 * @return A value converted from C/C++ "bool"
 */
isDoConnection : function () {},

/**
 * @method setAutoReconnect
 * @param {bool}
 */
setAutoReconnect : function () {},

/**
 * @method getIsReady
 * @return A value converted from C/C++ "bool"
 */
getIsReady : function () {},

/**
 * @method setIsDisconnectHandler
 * @param {bool}
 */
setIsDisconnectHandler : function () {},

/**
 * @method destroyInstance
 */
destroyInstance : function () {},

/**
 * @method networkThread
 * @return A value converted from C/C++ "void*"
 * @param {void*}
 */
networkThread : function () {},

/**
 * @method getInstance
 * @return A value converted from C/C++ "ClientBitZero*"
 */
getInstance : function () {},

/**
 * @method ClientBitZero
 * @constructor
 */
ClientBitZero : function () {},

};
