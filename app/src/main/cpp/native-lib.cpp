#include <jni.h>
#include <opencv2/opencv.hpp>
#include <android/asset_manager_jni.h>

using namespace cv;
using namespace std;

extern "C"
JNIEXPORT void JNICALL
Java_com_opencv_gohn_android_1opencv_MainActivity_loadImage(JNIEnv *env, jobject instance,
                                                            jstring imageFileName_, jlong img) {
    const char *imageFileName = env->GetStringUTFChars(imageFileName_, 0);

    // TODO

    Mat &img_input = *(Mat *) img;

    const char *nativeFileNameString = env->GetStringUTFChars(imageFileName_, JNI_FALSE);

    string baseDir("/storage/emulated/0/");
    baseDir.append(nativeFileNameString);
    const char *pathDir = baseDir.c_str();

    img_input = imread(pathDir, IMREAD_COLOR);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_opencv_gohn_android_1opencv_MainActivity_imageprocessing(JNIEnv *env, jobject instance,
                                                                  jlong inputImage,
                                                                  jlong outputImage) {

    // TODO
    Mat &img_input = *(Mat *) inputImage;
    Mat &img_output = *(Mat *) outputImage;

    cvtColor( img_input, img_input, CV_BGR2RGB);
    cvtColor( img_input, img_output, CV_RGB2GRAY);
    blur( img_output, img_output, Size(5,5) );
    Canny( img_output, img_output, 50, 150, 5 );

}