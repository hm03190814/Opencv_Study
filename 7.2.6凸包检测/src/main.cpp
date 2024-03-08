#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    Mat a = imread("../../7.2.6凸包检测/source/img.jpg",IMREAD_GRAYSCALE);

    //二值化
    Mat binary;
    threshold(a, binary, 105 ,255, THRESH_BINARY);

    //膨胀运算,讲细小缝隙填补
    Mat k = getStructuringElement(MORPH_RECT,Size(3,3),Point(-1,-1));
    morphologyEx(binary,binary,MORPH_OPEN,k);
    imshow("binary",binary);

    //轮廓发现与绘制
    vector<vector<Point>> contours; //轮廓
    vector<Vec4i> hierarchy; //存放轮廓结构变量
    findContours(binary,contours,hierarchy,0,2,Point());

    //
    for (int n = 0; n < contours.size(); n++)
    {
        //计算凸包
        vector<Point> hull;
        convexHull(contours[n],hull);
        //绘制凸包
        for(int i = 0; i < hull.size(); i++)
        {
            //绘制凸包顶点
            circle(a,hull[i],4,Scalar(255,255,255),2,8,0);
            //连接凸包
            if(i == hull.size( )- 1)
            {
                line(a,hull[i],hull[0],Scalar(255,255,255),2,8,0);
                break;
            }
            line(a,hull[i],hull[i+1],Scalar(255,255,255),2,8,0);
        }

    }

    imshow("a",a);

    waitKey(0);
    return 0;
}
