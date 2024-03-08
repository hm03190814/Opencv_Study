#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
/*
Mat img1,img2;
Point p1;
void mouse(int event,int x,int y,int flags,void*);

int main() {
    Mat img1 = imread("/home/yin/opencv/opencv0000/4.图像读取显示保存/pingguo.jpg",IMREAD_ANYCOLOR);
    if(img1.empty()){
        cout<<"请确认输入的图片路径是否正确"<<endl;
        return -1;
    }
    img1.copyTo(img2);
    namedWindow("窗口1");
    namedWindow("窗口2");
    imshow("窗口1", img1);
    imshow("窗口1", img1);
    //鼠标响应
    setMouseCallback("窗口1",mouse,0);
    waitKey(0);
    while (true);
    return 0;
}
void mouse(int event,int x,int y,int flags,void*){
    if(event==EVENT_RBUTTONDOWN){
        cout<<"请勿按下右键";
    }
    if(event==EVENT_LBUTTONDOWN){
        p1=Point (x,y);
    }
    if(event==EVENT_MOUSEMOVE&&event==EVENT_FLAG_LBUTTON){
        //通过改变图像像素显示鼠标移动轨迹
        img2.at<Vec3b>(y,x)=Vec3b(0,0,255);
        img2.at<Vec3b>(y,x-1)=Vec3b(0,0,255);
        img2.at<Vec3b>(y,x+1)=Vec3b(0,0,255);
        img2.at<Vec3b>(y+1,x)=Vec3b(0,0,255);
        img2.at<Vec3b>(y-1,x)=Vec3b(0,0,255);
        imshow("窗口2",img2);
        //通过绘制直线显示鼠标移动轨迹
        Point p2(x,y);
        line(img1,p1,p2,Scalar(0,0,255),2,5,0);
        p1=p2;
        imshow("窗口1",img1);
    }
}*/


Mat img1,img2;
Point p1;
void mouse(int event,int x,int y,int flags,void*);

int main() {
    img1 = imread("../../source/pingguo.jpg",IMREAD_ANYCOLOR);
    img1.copyTo(img2);
    imshow("窗口1", img1);
    imshow("窗口2", img2);
    //鼠标响应
    setMouseCallback("窗口1",mouse,0);
    waitKey(0);
    while (true);
    return 0;
}

void mouse(int event, int x, int y, int flags, void *) {
    if (event == EVENT_RBUTTONDOWN) {
        cout << "请勿按下右键";
    }
    if (event == EVENT_LBUTTONDOWN) {
        p1 = Point(x, y);
    }
    if (event == EVENT_MOUSEMOVE && event == EVENT_FLAG_LBUTTON) {
        //通过改变图像像素显示鼠标移动轨迹
        img2.at<Vec3b>(y, x) = Vec3b(0, 0, 255);
        img2.at<Vec3b>(y, x - 1) = Vec3b(0, 0, 255);
        img2.at<Vec3b>(y, x + 1) = Vec3b(0, 0, 255);
        img2.at<Vec3b>(y + 1, x) = Vec3b(0, 0, 255);
        img2.at<Vec3b>(y - 1, x) = Vec3b(0, 0, 255);
        imshow("窗口2", img2);
        //通过绘制直线显示鼠标移动轨迹
        Point p2(x, y);
        line(img1, p1, p2, Scalar(0, 0, 255), 2, 5, 0);
        p1 = p2;
        imshow("窗口1", img1);
    }
}
