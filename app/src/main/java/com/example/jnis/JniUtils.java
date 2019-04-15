package com.example.jnis;

public class JniUtils {
    static {
        System.loadLibrary("jniLib");
    }
    public static native String getString();

    public static native int getAddResult(int a,int b);
    public static native String encode(String msg);
}
