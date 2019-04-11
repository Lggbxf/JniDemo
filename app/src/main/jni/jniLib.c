//
// Created by mayn on 2019/4/11.
//

#include <com_example_jnis_JniUtils.h>

JNIEXPORT jstring JNICALL Java_com_example_jnis_JniUtils_getString(JNIEnv *env, jobject obj){
//jstring     (*NewStringUTF)(JNIEnv*, const char*); 把C字符串转化为java中字符串
// 把C字符串转化为java中字符串
			return (*env)->NewStringUTF(env, "args in jni");
  }

JNIEXPORT jint JNICALL Java_com_example_jnis_JniUtils_getAddResult
  (JNIEnv *env, jobject obj, jint x, jint y){
  return x+y;
  }