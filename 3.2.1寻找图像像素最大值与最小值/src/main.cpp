#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    float a[12] = {1,2,3,4,5,10,6,7,8,9,10,0};
    //单通道矩阵
    Mat img = Mat (3,4,CV_32FC1,a);
    //多通道矩阵
    Mat imgs = Mat (2,3,CV_32FC2,a);
    cout<<img<<endl<<imgs<<endl;

    //最大值与最小值
    double minVal,maxVal;
    Point minIdx,maxIdx;

    //寻找单通道矩阵的最值
    minMaxLoc(img,&minVal,&maxVal,&minIdx,&maxIdx);
    cout<<"img中的最小值："<<minVal<<" "<<"在矩阵中的位置："<<minIdx<<endl;
    cout<<"img中的最大值："<<maxVal<<" "<<"在矩阵中的位置："<<maxIdx<<endl;

    //寻找多通道矩阵的最值
    //将多通道矩阵变为单通道矩阵
    Mat imgs_re = imgs.reshape(1,4);
    cout<<imgs_re<<endl;
    minMaxLoc(imgs_re,&minVal,&maxVal,&minIdx,&maxIdx);
    cout<<"imgs中的最小值："<<minVal<<" "<<"在矩阵中的位置："<<minIdx<<endl;
    cout<<"imgs中的最大值："<<maxVal<<" "<<"在矩阵中的位置："<<maxIdx<<endl;

    return 0;
}

