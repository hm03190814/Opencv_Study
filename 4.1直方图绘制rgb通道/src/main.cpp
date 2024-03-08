//绘制 RGB 图像分离通道后的每一单通道的直方图
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
    //
    Mat hist_r, hist_g, hist_b;//用来统计直方图计算结果

    float inRange[2] = {0,255};
    const float* ranges[] = {inRange};//像素灰度值范围

    int bin = 256;
    const int bins [1] = {256};//直方图的维度(像素灰度的最大值)

    int channels_r[1] ={0};//通道索引
    cv::calcHist(&src, 1, channels_r, Mat(), hist_r, 1, bins, ranges, true, false);

    int channels_g[1] = {1};//通道索引
    cv::calcHist(&src, 1, channels_g, Mat(), hist_g, 1, bins, ranges, true, false);

    int channels_b[1] = {2};//通道索引
    cv::calcHist(&src, 1, channels_b, Mat(), hist_b, 1, bins, ranges, true, false);


    double max_val_r, max_val_g, max_val_b;
    double min_val_r, min_val_g, min_val_b;
    minMaxLoc(hist_r, &min_val_r, &max_val_r, 0, 0);
    minMaxLoc(hist_g, &min_val_g, &max_val_g, 0, 0);
    minMaxLoc(hist_b, &min_val_b, &max_val_b, 0, 0);


    int scale = 1;
    int hist_height = 256;
    //创建黑色画布
    Mat hist_img = Mat::zeros(hist_height, bin*3, CV_8UC3);

    for (int i=0; i<bin; i++)
    {
        float bin_val_r = hist_r.at<float>(i);
        float bin_val_g = hist_g.at<float>(i);
        float bin_val_b = hist_b.at<float>(i);

        int intensity_r = cvRound(bin_val_r*hist_height/max_val_r); //要绘制的高度
        int intensity_g = cvRound(bin_val_g*hist_height/max_val_g);
        int intensity_b = cvRound(bin_val_b*hist_height/max_val_b);

        //绘制矩形
        cv::rectangle(hist_img, cv::Point(i*scale, hist_height-1), cv::Point((i+1)*scale-1,hist_height-intensity_r), CV_RGB(255,0,0));
        cv::rectangle(hist_img, cv::Point((i+bin)*scale, hist_height-1), cv::Point((i+bin+1)*scale-1,hist_height-intensity_g), CV_RGB(0,255,0));
        cv::rectangle(hist_img, cv::Point((i+bin*2)*scale, hist_height-1), cv::Point((i+bin*2+1)*scale, hist_height-intensity_b), CV_RGB(0,0,255));
    }

    //显示
    namedWindow("RGB Histogram", 1);
    imshow("RGB Histogram", hist_img);
    namedWindow("source", 1);
    imshow("source", src);
    waitKey(0);
    return 0;
}
 