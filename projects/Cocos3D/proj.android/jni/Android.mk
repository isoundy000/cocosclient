LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp \
../../proj.win32/Classes/GameScene/Layer3D.cpp \
../../proj.win32/Classes/GameScene/GameLogic/GameLogic.cpp \
../../proj.win32/Classes/GameScene/GameLogic/GameObject.cpp \
../../proj.win32/Classes/GameScene/GameLogic/Hau.cpp \
../../proj.win32/Classes/GameScene/GameLogic/Ma.cpp \
../../proj.win32/Classes/GameScene/GameLogic/Player.cpp \
../../proj.win32/Classes/GameScene/GameLogic/Tinh.cpp \
../../proj.win32/Classes/GameScene/GameLogic/Tot.cpp \
../../proj.win32/Classes/GameScene/GameLogic/Tuong.cpp \
../../proj.win32/Classes/GameScene/GameLogic/Xe.cpp 

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes  $(LOCAL_PATH)/../../proj.win32/Classes

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos3dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
$(call import-module,external/libcocos3dx)
