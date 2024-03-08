#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main(){
    //用于验证形态学应用的二值化矩阵
    Mat src = (Mat_<uchar>(6,6)<<
            0,0,0,0,255,0,
            0,255,255,255,255,255,
            0,255,255,255,255,0,
            0,255,255,255,255,0,
            0,255,255,255,255,0,
            0,0,0,0,0,0);
    imshow("src",src);

    //3*3结构单元
    Mat kernel = getStructuringElement(0,Size(3,3));

    Mat open,close,gradient,tophat,blackhat,hitmiss;

    //开运算
    morphologyEx(src,open,MORPH_OPEN,kernel);
    //闭运算
    morphologyEx(src,close,MORPH_CLOSE,kernel);
    //梯度运算
    morphologyEx(src,gradient,MORPH_GRADIENT,kernel);
    //顶帽运算
    morphologyEx(src,tophat,MORPH_TOPHAT,kernel);
    //黑帽运算
    morphologyEx(src,blackhat,MORPH_BLACKHAT,kernel);
    //击中击不中运算
    morphologyEx(src,hitmiss,MORPH_HITMISS,kernel);


    //用图像验证形态学操作效果
    Mat key = imread("../../source/pingguo.jpg",IMREAD_GRAYSCALE);
    threshold(key,key,80,255,THRESH_BINARY);

    //开运算
    Mat open_key;
    morphologyEx(key,open_key,MORPH_OPEN,kernel);
    imshow("open_key",open_key);

    //图像细化  有误
    Mat thin;
    // cv::ximgproc::thinning(key,thin,0);

    waitKey(0);
    return 0;
}