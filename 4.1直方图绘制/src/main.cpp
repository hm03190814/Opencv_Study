#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
    Mat src = imread("../../source/pingguo.jpg");
    if (src.data==NULL)
    {
        cout << "fail to load image." << endl;
        return 0;
    }
    Mat gray;
    cvtColor(src,gray,COLOR_BGR2GRAY);

    Mat hist;//用来统计直方图计算结果
    int channels[1] ={0};//通道索引
    float inRange[2] = {0,255};
    const float* ranges[] = {inRange};//像素灰度值范围

    const int bins [1] = {256};//直方图的维度(像素灰度的最大值)
    //计算图像直方图
    calcHist(&src, 1, channels, Mat(), hist, 1, bins, ranges, true, false);


    int w = 512;//宽
    int h = 500;//长
    int width=2;//矩形宽度
    //创建黑色画布
    Mat hist_img = Mat::zeros(h, w, CV_8UC3);
    //绘制矩形
    for (int i=0; i<hist.rows; i++)
    {
        cv::rectangle(hist_img,Point(width*(i-1),h-1),Point(width*i-1,h- cvRound(hist.at<float>(i-1)/15)), CV_RGB(255,255,255),-1);
    }

    //显示
    namedWindow("RGB Histogram", 1);
    imshow("RGB Histogram", hist_img);
    namedWindow("source", 1);
    imshow("source", src);
    waitKey(0);
    return 0;
}
 