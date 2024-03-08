#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    Mat img = imread("../../3.2.2两张图像像素比较/Img/img.jpg");
    if(img.empty()){
        cout<<"请确认名称是否正确";
        return -1;
    }
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    Mat img_B, img_B_V, gray_B, gray_B_V, gray_T, gray_T_V, gray_TRUNC;

    //彩色图像二值化
    //每个通道分别进行阈值化之后进行组合
    //有2*2*2种颜色
    threshold(img, img_B, 125, 255, THRESH_BINARY);
    threshold(img, img_B_V, 125, 255, THRESH_BINARY_INV);
    imshow("img_B", img_B);
    imshow("img_B_V", img_B);

    //灰度图BINARY二值化
    threshold(gray, gray_B, 125, 255, THRESH_BINARY);
    threshold(gray, gray_B_V, 125, 255, THRESH_BINARY_INV);
    imshow("gray_B",gray_B);
    imshow("gray_B_V", gray_B_V);

    //灰度图像TOZERO变换
    threshold(gray, gray_T, 125, 255, THRESH_TOZERO);
    threshold(gray, gray_T_V, 125, 255, THRESH_TOZERO_INV);
    imshow("gray_T", gray_T);
    imshow("gray_T_V", gray_T_V);

    //灰度图像TRUNC变换
    threshold(gray, gray_TRUNC, 125, 255, THRESH_TRUNC);
    imshow("gray_TRUNC", gray_TRUNC);

    //灰度图像大律法和三角形法二值化
    //此时第三个参数无用
    Mat img_Thr = imread("../../3.2.2两张图像像素比较/Img/img.jpg"); //将图像转换成单通道灰度图像
    cvtColor(img_Thr, img_Thr, COLOR_BGR2GRAY);
    Mat img_Thr_O, img_Thr_T;
    threshold(img_Thr, img_Thr_O, 100, 255, THRESH_BINARY | THRESH_OTSU);  //大律法
    threshold(img_Thr, img_Thr_T, 125, 255, THRESH_BINARY | THRESH_TRIANGLE);  //三角形法
    imshow("img_Thr", img_Thr);
    imshow("img_Thr_O", img_Thr_O);
    imshow("img_Thr_T", img_Thr_T);

    //灰度图像自适应二值化
    Mat adaptive_mean, adaptive_gauss;
    adaptiveThreshold(img_Thr, adaptive_mean, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);
    adaptiveThreshold(img_Thr, adaptive_gauss, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 55, 0);
    imshow("adaptive_mean", adaptive_mean);
    imshow("adaptive_gauss", adaptive_gauss);

    waitKey(0);
    return 0;
}


