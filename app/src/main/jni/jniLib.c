//
// Created by mayn on 2019/4/11.
//

#include <com_example_jnis_JniUtils.h>
#include <stdio.h>
#include <stdlib.h>

#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)



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

    JNIEXPORT jintArray JNICALL Java_com_example_jnis_JniUtils_changeToArray
      (JNIEnv *env, jobject obj, jintArray jarr){
        //jsize       (*GetArrayLength)(JNIEnv*, jarray);
        	jsize len= (*env)->GetArrayLength(env, jarr);
        	jintArray new_arr=(*env)->NewIntArray(env,len);
        	//jint*       (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
        	jint * cint = (*env)->GetIntArrayElements(env, jarr, NULL);
        	int i = 0;
        	int j = 0;
        	int temp = 0;

        	//cint[i] <=> *(cint + i)

        	for(i = 0;i < len - 1;i++){
        		for(j = 0;j < len - i - 1;j++){
        			if(cint[j] > cint[j + 1]){
        				temp = cint[j];
        				cint[j] = cint[j + 1];
        				cint[j + 1] = temp;
        			}

        		}

        	}
        	for(i = 0;i<len;i++){
        	    LOGD("*cint == %d",(*(cint+1)));
        	}
        	(*env)->ReleaseIntArrayElements(env,new_arr,cint,0);
            return new_arr;

      }