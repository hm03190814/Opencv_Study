#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    Mat img = imread("../../source/pingguo.jpg");

    Point2f src_points[4];
    Point2f dst_points[4];
    //原始图像四个点坐标
    src_points[0] = Point2f (94.0,377.0);
    src_points[1] = Point2f (500.0,380.0);
    src_points[2] = Point2f (1.0,620.0);
    src_points[3] = Point2f (627.0,627.0);
    //透视变换后四个点坐标
    dst_points[0] = Point2f (0.0,0.0);
    dst_points[1] = Point2f (627.0,0.0);
    dst_points[2] = Point2f (1.0,620.0);
    dst_points[3] = Point2f (627.0,627.0);

    //
    Mat a,imgs;
    a= getPerspectiveTransform(src_points,dst_points); //计算透视矩阵
    warpPerspective(img,imgs,a,img.size());
    imshow("img",img);
    imshow("imgs",imgs);
    waitKey(0);
    return 0;
}