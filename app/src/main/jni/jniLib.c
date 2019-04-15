//
// Created by mayn on 2019/4/11.
//

#include <com_example_jnis_JniUtils.h>
#include <stdio.h>
#include <stdlib.h>


char *encode(char *s){
    char *p = s;
    char *q = s;
    char temp;
    while(*q != '\0'){
        q++;
    }
    q--;

    while(p < q){
        temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
    return s;
}

JNIEXPORT jstring JNICALL Java_com_example_jnis_JniUtils_getString(JNIEnv *env, jobject obj){
//jstring     (*NewStringUTF)(JNIEnv*, const char*); 把C字符串转化为java中字符串
// 把C字符串转化为java中字符串
        return (*env)->NewStringUTF(env, "args in jni");
  }

JNIEXPORT jint JNICALL Java_com_example_jnis_JniUtils_getAddResult
  (JNIEnv *env, jobject obj, jint x, jint y){
        return x+y;
  }

JNIEXPORT jstring JNICALL Java_com_example_jnis_JniUtils_encode
    (JNIEnv *env, jobject obj, jstring str){
        char *cstr = NULL;
        jsize len = 0;
        jstring new_str;
        len = (*env)->GetStringLength(env,str);
        cstr = (char *)malloc(len+1);
        (*env)->GetStringUTFRegion(env,str,0,len,cstr);
        cstr = encode(cstr);
        new_str = (*env)->NewStringUTF(env,cstr);
        free(cstr);
        return new_str;
    }