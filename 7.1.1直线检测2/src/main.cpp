#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
    Mat img =  imread("../../7.2.6凸包检测/source/img.jpg",IMREAD_GRAYSCALE);
    imshow("img",img);

    //边缘检测图像并二值化
    Mat edge;
    Canny(img,edge,80,180,3,false);
    threshold(edge, edge, 170, 255, THRESH_BINARY);
    imshow("edge",edge);

    //利用渐近概率式霍夫变换提取直线
    vector<Vec4i> line1;
    HoughLinesP(edge, line1, 1, CV_PI / 180, 150, 30, 10);
    //            单通道二值图像  两个端点坐标  分辨率       分辨率                阈值        直线最小长度   相邻两点间的最大距离


    //绘制直线检测结果
    Mat img1;
    img.copyTo(img1);

    for(size_t i = 0; i < line1.size(); i++)
    {
        line(img1,
             Point(line1[i][0],line1[i][1]),
             Point(line1[i][2],line1[i][3]),
             Scalar(255),3);
    }

    imshow("img1",img1);

    waitKey(0);
    return 0 ;


}
