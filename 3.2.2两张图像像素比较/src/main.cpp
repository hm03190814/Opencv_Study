#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    //读取图片
    Mat img = imread("../Img/img.jpg");
    Mat baidi = imread("../Img/baidi.jpg");
    Mat heidi = imread("../Img/heidi.jpg");
    //图像像素比较
    Mat minhhh,maxhhh;
    min(img,heidi,minhhh);
    max(img,baidi,maxhhh);
    //把彩色图像转化为单通道的灰色图像
    Mat gray,gray1;
    cvtColor(img,gray,COLOR_BGR2GRAY);
    //掩码矩阵gray1
    cvtColor(baidi,gray1,COLOR_BGR2GRAY);
    //寻找图像最大值与最小值
    double minVal,maxVal;
    Point minLoc,maxLoc;
    minMaxLoc(gray,&minVal,&maxVal,&minLoc,&maxLoc,gray1);

    //显示
    namedWindow("img",0);
    namedWindow("baidi",0);
    namedWindow("heidi",0);
    namedWindow("minhhh",0);
    namedWindow("maxhhh",0);
    namedWindow("gray",0);
    namedWindow("gray1",0);
    imshow("img",img);
    imshow("baidi",baidi);
    imshow("heidi",heidi);
    imshow("minhhh",minhhh);
    imshow("maxhhh",maxhhh);
    imshow("gray",gray);
    imshow("gray1",gray1);
    waitKey(0);
    return 0;
}