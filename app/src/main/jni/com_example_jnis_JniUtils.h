/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_example_jnis_JniUtils */

#ifndef _Included_com_example_jnis_JniUtils
#define _Included_com_example_jnis_JniUtils
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_jnis_JniUtils
 * Method:    getString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jnis_JniUtils_getString
  (JNIEnv *, jclass);

/*
 * Class:     com_example_jnis_JniUtils
 * Method:    getAddResult
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_example_jnis_JniUtils_getAddResult
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_example_jnis_JniUtils
 * Method:    encode
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jnis_JniUtils_encode
  (JNIEnv *, jclass, jstring);

#ifdef __cplusplus
}
#endif
#endif
