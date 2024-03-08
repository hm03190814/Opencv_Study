#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
    Mat img = imread("../../source/pingguo.jpg");
    Mat temp = imread("../../2.2图像读取显示保存/source/jietu.jpg");

    Mat result;
    matchTemplate(img,temp,result,TM_CCOEFF_NORMED);//模板匹配

    double minVal,maxVal;
    Point minLoc,maxLoc;
    //寻找匹配结果中最大值与最小值以及位置坐标
    minMaxLoc(result,&minVal,&maxVal,&minLoc,&maxLoc);
    //绘制最佳匹配区域
    rectangle(img,Rect(maxLoc.x,maxLoc.y,temp.cols,temp.rows),Scalar(0,0,255),2);
    //显示
    imshow("temp",temp);
    imshow("img", img);
    imshow("result", result);
    waitKey(0);
    return 0;
}
