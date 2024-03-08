#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    //彩色读取
    Mat a = imread("../source/pingguo.jpg",IMREAD_ANYCOLOR);
    //灰色读取
    Mat b = imread("../source/pingguo.jpg",IMREAD_GRAYSCALE);
    //窗口不可以调整大小
    namedWindow("a1",WINDOW_AUTOSIZE);
    //namedWindow("a1",1);同上一行
    //窗口可以调整大小
    namedWindow("b1",WINDOW_NORMAL);
    //namedWindow("b1",0);同上一行
    //显示
    imshow("a1",a);
    imshow("b1",b);
    //存储
    imwrite("../source/new.png",a);

    waitKey(0);
    return 0;
}
