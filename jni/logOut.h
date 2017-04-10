/********************************************************************
Projection time:	2017/04/06   10:55
File Name: 	logOut.h
@author:	<hzzhouzhimin@corp.netease.com>
Copyright (c) 2017, NetEase Inc. All rights reserved.

note:       control android log out file
*********************************************************************/


#ifndef _LOG_OUT_
#define _LOG_OUT_

#define WINDOWS 0
#if WINDOWS 
#include <android/log.h>


#define OUT_PUT_INFOR 1

#if OUT_PUT_INFOR 

//LOG DEFINITIONS
#define LOG_TAG_FLOW "ProjectorCamera/ProcessingFlow"
#define LOGF(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG_FLOW, __VA_ARGS__))

#define LOG_TAG "ProjectorCamera/DebugInformation"
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))

#define LOG_TAG_CALB "ProjectorCamera/CalibrationInformation"
#define LOGC(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG_CALB, __VA_ARGS__))

#define LOG_TAG_WARN "ProjectorCamera/WarningInformation"
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG_WARN, __VA_ARGS__))

#else

#define LOG_TAG_FLOW "ProjectorCamera/ProcessingFlow"
#define LOGF(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG_FLOW, ""))

#define LOG_TAG "ProjectorCamera/DebugInformation"
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, ""))

#define LOG_TAG_CALB "ProjectorCamera/CalibrationInformation"
#define LOGC(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG_CALB, ""))

#define LOG_TAG_WARN "ProjectorCamera/WarningInformation"
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG_WARN, ""))
#endif

#else 

#define LOGF printf
#define LOGD printf
#define LOGC printf
#define LOGW printf
#endif


#endif