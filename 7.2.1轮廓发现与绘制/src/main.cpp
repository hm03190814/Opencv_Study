#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    Mat a = imread("../../7.2.6凸包检测/source/img.jpg",IMREAD_GRAYSCALE);
    GaussianBlur(a,a,Size(7,7),4,4);//平滑滤镜
    Mat binary;
    threshold(a,binary,170,255,THRESH_BINARY|THRESH_OTSU);//自适应二值化

    //轮廓发现与绘制
    vector<vector<Point>> contours; //轮廓
    vector<Vec4i> hierarchy; //存放轮廓结构变量
    findContours(binary,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point());
    //                   原图    轮廓     [,,,]         标志(提取所有轮廓)              标志


    //输出轮廓结构描述
    for(int i = 0; i < hierarchy.size(); i++){
        cout << hierarchy[i] << endl;
    }

    //绘制轮廓
    for(int t = 0; t < contours.size(); t++) {
        drawContours(a, contours, t, Scalar(0, 0, 255), 2, 8);
        //                 原图   轮廓             轮廓数             颜色                          线条粗细   边界线连接类型

        imshow("lunkuo",a);
        waitKey(0);
    }

    waitKey(0);
    return 0;
}