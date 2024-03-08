#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
//直方图均衡化
void drawHist(Mat &hist,int type,string name){
    int w = 512;//宽
    int h = 400;//高
    int width=2;//矩形宽度
    //创建黑色画布
    Mat histImage = Mat::zeros(h, w, CV_8UC3);

    normalize(hist,hist,1,0,type,-1,Mat());
    for (int i=0; i<=hist.rows; i++)
    {
        rectangle(histImage,Point(width*(i-1),h-1),Point(width*i-1,h- cvRound(30*h*hist.at<float>(i-1))-1), Scalar (255,255,255),-1);
    }
    imshow(name,histImage);
}
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

    Mat hist1,hist2;//用来统计直方图计算结果
    Mat equalImg;//均衡化后的图像
    equalizeHist(gray,equalImg);

    int channels[1] ={0};//通道索引
    float inRange[2] = {0,255};
    const float* ranges[] = {inRange};//像素灰度值范围
    const int bins [1] = {256};//直方图的维度(像素灰度的最大值)

    //计算图像直方图
    calcHist(&gray, 1, channels, Mat(), hist1, 1, bins, ranges, true, false);
    calcHist(&equalImg, 1, channels, Mat(), hist2, 1, bins, ranges, true, false);

    drawHist(hist1,NORM_INF,"hist1");
    drawHist(hist2,NORM_INF,"hist2");

    //显示
    imshow("qian",gray);
    imshow("hou",equalImg);
    waitKey(0);
    return 0;
}
