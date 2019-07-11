//
// Created by jjj on 7/11/19.
//

#include "com_example_demo_MainActivity.h"

extern "C" JNIEXPORT jstring JNICALL Java_com_example_demo_MainActivity_stringFromJNI
        (JNIEnv *env, jobject) {
    return env->NewStringUTF("Hello from C++");
}
