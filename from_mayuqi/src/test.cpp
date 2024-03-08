#include<iostream>
#include "../include/quickdemo.h"
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    Mat src = imread("/home/mayuqi/桌面/code/image/1.JPG");
    Mat src2=imread("/home/mayuqi/桌面/code/image/1.JPG");
    Mat src3=imread("/home/mayuqi/桌面/code/image/1.JPG",IMREAD_GRAYSCALE);
    if (src.empty()||src2.empty()) {
        std::cout << "Not open file: " << "/home/mayuqi/公共的/1.JPG";
        return -1;
    }
    // cout<<"src"<<src.type()<<"src2"<<src2.type()<<endl;
    // imshow("1",src);
    Quickdemo qb;
    qb.mouserespone(src);
    // qb.createpyramid_demo(src);
    waitKey(0);
    destroyAllWindows();
    return 0;
}