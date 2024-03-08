#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    Mat a = imread("../../7.2.6凸包检测/source/img.jpg",IMREAD_GRAYSCALE);
    Mat img1,img2;
    a.copyTo(img1);
    a.copyTo(img2);
    imshow("a",a);

    //边缘检测
    Mat canny;
    Canny(a,canny,80,160,3,false);
    imshow("canny",canny);

    //膨胀运算,将细小缝隙填补
    Mat kernel = getStructuringElement(0,Size(3,3));
    dilate(canny,canny,kernel);

    //轮廓发现与绘制
    vector<vector<Point>> contours; //轮廓
    vector<Vec4i> hierarchy; //存放轮廓结构变量
    findContours(canny,contours,hierarchy,0,2,Point());

    //寻找轮廓的外接矩阵
    for (int n = 0; n < contours.size(); n++)
    {
        //最大外接矩阵
        Rect rect = boundingRect(contours[n]);
        rectangle(img1, rect, Scalar(255, 255, 255), 2, 8, 0);

        //最小外接矩阵
        RotatedRect rrect= minAreaRect(contours[n]);
        Point2f points[4];
        rrect.points(points);//读取最小外接矩阵的四个顶点
        Point2f cpt=rrect.center;//最小外接矩阵的中心
        //绘制旋转矩阵与中心位置
        for(int i=0;i<4;i++){
            if(i==3){
                line(img2,points[i],points[0],Scalar(255,255,255),2,8,0);
                break;
            }
            line(img2,points[i],points[i+1],Scalar(255,255,255),2,8,0);
        }
        //绘制矩阵中心
        circle(img2,cpt,2,Scalar(255,255,255),-1,8,0);

    }

    imshow("img1",img1);
    imshow("img2",img2);

    waitKey(0);
    return 0;
}