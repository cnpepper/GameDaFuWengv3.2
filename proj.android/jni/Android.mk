LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp \
				   ../../Classes/public/CocosToast.cpp \
				   ../../Classes/map/GameBaseScene.cpp \
				   ../../Classes/map/eventfactory/GameElement.cpp \
				   ../../Classes/public/GameManager.cpp \
				   ../../Classes/slider/MapChooseScene.cpp \
				   ../../Classes/menu/MenuScene.cpp \
				   ../../Classes/public/PlayerManager.cpp \
				   ../../Classes/public/PopupLayer.cpp \
				   ../../Classes/map/SeaScene.cpp \
				   ../../Classes/animation/SplashScene.cpp 

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos2d
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos2d/extensions
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/menu
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/map
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/slider
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/public
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/animation
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/map/eventfactory







LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static

# LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocosbuilder_static
# LOCAL_WHOLE_STATIC_LIBRARIES += spine_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocostudio_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocos_network_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static


include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-module,audio/android)

# $(call import-module,Box2D)
# $(call import-module,editor-support/cocosbuilder)
# $(call import-module,editor-support/spine)
# $(call import-module,editor-support/cocostudio)
# $(call import-module,network)
$(call import-module,extensions)
