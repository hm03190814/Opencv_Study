#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
#include<iostream>
#include<vector>
using namespace std;
using namespace cv;
int main()
{
    Mat img = imread("../../3.2.2两张图像像素比较/Img/img.jpg");
    if (img.empty())
    {
        cout << "读取失败！" << endl;
        return -1;
    }

    Mat a0,a1,img1,img2;
    //方法一
    Point2f center(img.rows/2.0,img.cols/2.0);//设置旋转中心
    double angle=30;//设置旋转角度
    Size chicun(img.rows,img.cols);//设置输出图片尺寸与原图片尺寸相同
    a0= getRotationMatrix2D(center,angle,1);//仿射矩阵
    warpAffine(img,img1,a0,chicun);
    imshow("img1",img1);
    //方法二 根据三个点进行仿射变换
    Point2f src_points[3];//原始图像中的三个点
    Point2f dst_points[3];//仿射变换后图像中的三个点
    src_points[0]=Point2f (0,0);
    src_points[1]=Point2f (0,(float)(img.cols-1));
    src_points[2]=Point2f ((float)(img.rows-1),(float)(img.cols-1));
    dst_points[0]=Point2f ((float)(img.rows)*0.11,(float)(img.cols)*0.20);
    dst_points[1]=Point2f ((float)(img.rows)*0.15,(float)(img.cols)*0.70);
    dst_points[2]=Point2f ((float)(img.rows)*0.81,(float)(img.cols)*0.85);
    a1= getAffineTransform(src_points,dst_points);//仿射矩阵
    warpAffine(img,img2,a0,chicun);
    imshow("img2",img2);

    waitKey(0);
    return 0;
}
