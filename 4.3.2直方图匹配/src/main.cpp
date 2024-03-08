#include<iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace cv;
using namespace std;
//归一化并且绘制直方图
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
    Mat image1, img1, hist1, image2, img2, hist2, result,hist3;
    //定义修改图像，灰度修改图像, 修改图像直方图，目标图像，灰度目标图像，目标图像直方图, 匹配后图像,匹配后图像直方图
    image1 = imread("../../3.2.2两张图像像素比较/Img/img.jpg");
    image2 = imread("../../source/pingguo.jpg");
    if (image1.empty()||image2.empty())
    {
        cout << "读取错误" << endl;
        return -1;
    }
    cvtColor(image1, img1, COLOR_BGR2GRAY);  //灰度化
    cvtColor(image2, img2, COLOR_BGR2GRAY);  //灰度化

    //获取两个均衡化图像的直方图
    int channels[1] ={0};//通道索引
    float inRange[2] = {0,255};
    const float* ranges[] = {inRange};//像素灰度值范围
    const int bins [1] = {256};//直方图的维度(像素灰度的最大值)
    calcHist(&img1, 1, channels, Mat(), hist1, 1, bins, ranges, true, false);
    calcHist(&img2, 1, channels, Mat(), hist2, 1, bins, ranges, true, false);

    //归一化两个图像直方图
    drawHist(hist1,NORM_L1,"hist1");
    drawHist(hist2,NORM_L1,"hist2");

    //计算两个均衡化图像直方图的累积概率
    float hist1_cdf[256] = { hist1.at<float>(0) };
    float hist2_cdf[256] = { hist2.at<float>(0) };
    for (int i = 1; i < 256; i++)
    {
        hist1_cdf[i] = hist1_cdf[i - 1] + hist1.at<float>(i);
        hist2_cdf[i] = hist2_cdf[i - 1] + hist2.at<float>(i);
    }

  /*  for (int i = 0; i < 256; i++)
    {
        hist1_cdf[i] = hist1_cdf[i] / (img1.rows * img1.cols);
        hist2_cdf[i] = hist2_cdf[i] / (img2.rows * img2.cols);
    }
*/
    // 两个累计概率之间的差值，用于找到最接近的点
    //构建累计概率误差矩阵
    float diff_cdf[256][256];
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++)
        {
            diff_cdf[i][j] = fabs(hist1_cdf[i] - hist2_cdf[j]);
        }
    }
    //生成lut
    Mat lut(1, 256, CV_8U);
    for (int i = 0; i < 256; i++)
    {
        //查找源灰度级为i的映射灰度和i的累积概率差最小(灰度接近)的规定化灰度
        float min = diff_cdf[i][0];
        int index = 0;
        //寻找累计概率误差矩阵中每一行中的最小值
        for (int j = 0; j < 256; j++) {
            if (min > diff_cdf[i][j]) {
                min = diff_cdf[i][j];
                index = j;
            }
        }
        lut.at<uchar>(i) = index;
    }

    LUT(img1, lut, result);  //图像中进行映射
    imshow("daipipeituxiang", img1);
    imshow("mubantuxiang", img2);
    imshow("jieguo",result);
    calcHist(&result, 1, channels, Mat(), hist3, 1, bins, ranges, true, false);
    drawHist(hist3,NORM_L1,"hist3");
    waitKey(0);  //暂停，保持图像显示，等待按键结束
    return 0;
}
