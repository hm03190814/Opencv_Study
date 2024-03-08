#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main() {
    //a是0-255
    Mat a = imread("../source/pingguo.jpg");
    Mat b;
    //图像数据类型转换a->b
    //b是0-1
    a.convertTo(b,CV_32F,1/255.0,0);

    //转换BGR为HSV
    Mat HSVa,HSVb;
    cvtColor(a,HSVa,COLOR_BGR2HSV);
    cvtColor(b,HSVb,COLOR_BGR2HSV);

    //转换BGR为GRAY
    Mat gray0,gray1;
    cvtColor(a,gray0,COLOR_BGR2GRAY);
    //转换RGB为GRAY
    cvtColor(a,gray0,COLOR_RGB2GRAY);

    waitKey(0);
    return 0;
}