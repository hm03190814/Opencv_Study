#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    //生成一个黑色图像
    Mat img = Mat::zeros(Size(512,512),CV_8UC3);

    //绘制圆形
    //                   圆心(50,50)        半径25          白色                                 实心
    circle(img,Point(50,50),25,Scalar(255,255,255),-1);
    //                   圆心(100,50)        半径20         白色                                 宽度为4
    circle(img,Point(100,50),20,Scalar(255,255,255),4);

    //绘制直线
    //               点(100,100)              点(200,100)                白色                                  宽度     边界类型    小数位数
    line(img,Point(100,100),Point(200,100),Scalar(255,255,255),2,LINE_4,0);

    //绘制椭圆
    //                     点(300,255)                     长半轴     短半轴    旋转角度    起始角度       终止角度           白色                                 实心
    ellipse(img,Point(300,255),Size(100,70),0,0,100,Scalar(255,255,255),-1);

    //绘制矩形
    //                       点(50,400)               点(100,450)                 白色                          实心
    rectangle(img,Point(50,400),Point(100,450),Scalar(255,255,255),-1);
    //                       点(40,450)       长60      宽50                 白色                       宽度为2
    rectangle(img,Rect(400,450,60,50),Scalar(255,255,255),2);

    //生成文字
    //                                                          字体类型   字体大小
    putText(img,"hello word",Point(100,400),2,1,Scalar(255,255,255));

    //绘制多边形
    Point pp[2][6];
    Point pp2[5];
    pp[0][0] = Point (72.0,200.0);
    pp[0][1] = Point (142.0,204.0);
    pp[0][2] = Point (226.0,263.0);
    pp[0][3] = Point (172.0,310.0);
    pp[0][4] = Point (117.0,319.0);
    pp[0][5] = Point (15.0,260.0);
    pp[1][0] = Point (359.0,339.0);
    pp[1][1] = Point (447.0,350.0);
    pp[1][2] = Point (500.0,349.0);
    pp[1][3] = Point (484.0,433.0);
    pp[1][4] = Point (418.0,449.0);
    pp[1][5] = Point (354.0,400.0);
    pp2[0]=Point (350,83);
    pp2[1]=Point (463,90);
    pp2[2]=Point (500,171);
    pp2[3]=Point (421,194);
    pp2[4]=Point (338,141);
    //存放3个多边形的二维数组pts
    const Point* pts[3] = {pp[0],pp[1],pp2};
    //每个多边形的顶点数npts
    int npts[] = {6,6,5};
    //                       多边形个数        颜色                             小数位数
    fillPoly(img,pts,npts,3,Scalar(125,125,125),8);


    imshow("img",img);
    waitKey(0);
    return 0;
}