LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := scriptingcore-spidermonkey

LOCAL_MODULE_FILENAME := libscriptingcore-spidermonkey

LOCAL_SRC_FILES := ScriptingCore.cpp \
                   cocos2d_specifics.cpp \
                   jsb_cocos2dx_extension_manual.cpp \
                   jsb_cocos2dx_studio_manual.cpp \
                   js_manual_conversions.cpp \
                   cocosjs_manual_conversions.cpp \
                   js_bindings_chipmunk_manual.cpp \
                   js_bindings_chipmunk_functions.cpp \
                   js_bindings_chipmunk_auto_classes.cpp \
                   js_bindings_chipmunk_registration.cpp \
                   js_bindings_system_functions.cpp \
                   js_bindings_system_registration.cpp \
                   js_bindings_ccbreader.cpp \
                   js_bindings_core.cpp \
                   js_bindings_opengl.cpp \
                   jsb_opengl_functions.cpp \
                   jsb_opengl_manual.cpp \
                   jsb_opengl_registration.cpp \
                   generated/jsb_cocos2dx_auto.cpp \
				   generated/jsb_cocos3dx_auto.cpp \
				   generated/jsb_engine_auto.cpp \
                   generated/jsb_cocos2dx_extension_auto.cpp \
                   generated/jsb_cocos2dx_studio_auto.cpp \
                   XMLHTTPRequest.cpp \
                   jsb_websocket.cpp \
				                      ../../../projects/HelloJS3D/proj.win32/Engine/BaseLayer.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/BaseScene.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/CAvatar.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/CCLocalizedString.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/CDialog.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/CShake.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/CStringUtils.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/Dialog.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/Handler.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/SceneMgr.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/UIAvatar.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/Utility.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/Network/ClientBitZero.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/Network/download/AsyncDownloadFile.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/Network/packet/CPacket.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/Network/packet/MessageBuffer.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/Network/packet/PacketFactory.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/Network/socket/DefaultSocket.cpp \
../../../projects/HelloJS3D/proj.win32/Engine/Network/socket/DefaultWP8Socket.cpp 

LOCAL_CFLAGS := -DCOCOS2D_JAVASCRIPT

LOCAL_EXPORT_CFLAGS := -DCOCOS2D_JAVASCRIPT

LOCAL_C_INCLUDES := $(LOCAL_PATH) \
                    $(LOCAL_PATH)/../../../CocosDenshion/include  \
					$(LOCAL_PATH)/../../../external/libcocos3dx \
					$(LOCAL_PATH)/../../../projects/HelloJS3D/proj.win32/Engine \
					$(LOCAL_PATH)/../../../projects/HelloJS3D/proj.win32/Engine/Network \
					$(LOCAL_PATH)/../../../projects/HelloJS3D/proj.win32/Engine/Network/packet 

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH) \
                           $(LOCAL_PATH)/generated

LOCAL_WHOLE_STATIC_LIBRARIES := spidermonkey_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos3dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static

LOCAL_LDLIBS := -landroid
LOCAL_LDLIBS += -llog

include $(BUILD_STATIC_LIBRARY)

$(call import-module,scripting/javascript/spidermonkey-android)
$(call import-module,cocos2dx)
$(call import-module,extensions)
$(call import-module,external/chipmunk)
$(call import-module,external/libcocos3dx)
