LOCAL_PATH :=$(call my-dir)


include $(CLEAR_VARS)
OpenCV_INSTALL_MODULES:=on
OPENCV_CAMERA_MODULES:=off
APP_STL := gnustl_static
OPENCV_LIB_TYPE:=STATIC
NDK_APP_DST_DIR := ../src/main/jniLibs/$(TARGET_ARCH_ABI)

#ifeq ("$(wildcard $(OPENCV_MK_PATH))","")
include C:/WORK/OpenCV-2.4.10-android-sdk/sdk/native/jni/OpenCV.mk
#else
#include $(OPENCV_MK_PATH)
#endif

LOCAL_MODULE :=jni-input
LOCAL_CFLAGS =  -DANDROID_NDK_BUILD -D__STDC_FORMAT_MACROS -D__STDC_INT64__
LOCAL_LDLIBS +=  -llog -ldl
LOCAL_LDLIBS += -L$(SYSROOT)/usr/lib -llog
LOCAL_C_INCLUDES += $(LOCAL_PATH)
JSONCPP_PATH := ../JSON
LOCAL_C_INCLUDES += ${JSONCPP_PATH}
STATE_MODEL_PATH := ../stateModel
LOCAL_C_INCLUDES += ${STATE_MODEL_PATH}

LOCAL_SRC_FILES :=com_orbbec_NativeNI_NativeGestureDetect.cpp\
                  Htime.cpp\
                  projectorCamera.cpp\
                  sendEvent.cpp\
                  touchInfo.cpp\
                  ${JSONCPP_PATH}/json_reader.cpp\
                  ${JSONCPP_PATH}/json_value.cpp\
                  ${JSONCPP_PATH}/json_writer.cpp\
                  ${STATE_MODEL_PATH}/role.cpp\
                  ${STATE_MODEL_PATH}/state.cpp\
                  ${STATE_MODEL_PATH}/idle.cpp\
                  ${STATE_MODEL_PATH}/singleActive.cpp\
                  ${STATE_MODEL_PATH}/doubleOneHandActive.cpp\
                  ${STATE_MODEL_PATH}/doubleTwoHandActive.cpp\


include $(BUILD_SHARED_LIBRARY)