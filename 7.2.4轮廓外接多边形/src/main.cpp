#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//绘制轮廓函数
void drawapp(Mat result,Mat img2){
    for(int i=0;i<result.rows;i++){
        //最后一个坐标点与第一个坐标点连接
        if(i==result.rows-1){
            Vec2i point1 = result.at<Vec2i>(i);
            Vec2i point2 = result.at<Vec2i>(0);
            line(img2,point1,point2,Scalar(0,0,255,255),4,8,0);
            break;
        }
        Vec2i point1=result.at<Vec2i>(i);
        Vec2i point2=result.at<Vec2i>(i+1);
        line(img2,point1,point2,Scalar(0,0,255,255),4,8,0);
    }
}

int main() {
    Mat a = imread("../../7.2.6凸包检测/source/img.jpg",IMREAD_GRAYSCALE);
    imshow("a",a);

    //边缘检测
    Mat canny;
    Canny(a,canny,80,160,3,false);
    imshow("canny",canny);

    //膨胀运算,讲细小缝隙填补
    Mat kernel = getStructuringElement(0,Size(3,3));
    dilate(canny,canny,kernel);

    //轮廓发现与绘制
    vector<vector<Point>> contours; //轮廓
    vector<Vec4i> hierarchy; //存放轮廓结构变量
    findContours(canny,contours,hierarchy,0,2,Point());

    //绘制轮廓外接多边形
    for (int n = 0; n < contours.size(); n++)
    {
        //用最小外接矩形求取轮廓中心
        RotatedRect rrect= minAreaRect(contours[n]);
        Point2f center=rrect.center;//最小外接矩阵的中心
        circle(a,center,2,Scalar(0,0,255,255),2,8,0);

        Mat result;
        approxPolyDP(contours[n],result,4,true);//多边形拟合
        drawapp(result,a);
        cout<<"corners:"<<result.rows<<endl;

        //判断形状和绘制轮廓
        if(result.rows == 3){
            putText(a,"triangle",center,0,1,Scalar(255,255,255),1,8);
        }
        if(result.rows == 4){
            putText(a,"rectangle",center,0,1,Scalar(255,255,255),1,8);
        }
        if(result.rows == 8){
            putText(a,"poly-8",center,0,1,Scalar(255,255,255),1,8);
        }
        if(result.rows > 12){
            putText(a,"circle",center,0,1,Scalar(255,255,255),1,8);
        }

    }

    imshow("result",a);

    waitKey(0);
    return 0;
}












