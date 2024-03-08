#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
#include<iostream>
#include<vector>
using namespace std;
using namespace cv;
int main()
{
    Mat img = imread("../../3.2.2两张图像像素比较/Img/img.jpg");
    if (img.empty())
    {
        cout << "读取失败！" << endl;
        return -1;
    }

    //lut第一层
    uchar Lutfirst[256];//lut矩阵的第一个通道的数组值
    for (int i = 0; i < 256; i++) {
        if (i <= 100) {
            Lutfirst[i] = 0;
        }
        if (i > 100 && i <= 200) {
            Lutfirst[i] = 100;
        }
        if (i > 200) {
            Lutfirst[i] = 255;
        }
    }
    //通过数组的方式构造Mat矩阵
    Mat lutOne(1, 256, CV_8U, Lutfirst);

    //lut第二层
    //lut矩阵的第二个通道的数组值
    uchar Lutsecond[256];
    for (int i = 0; i < 256; i++){
        if (i <= 100){
            Lutfirst[i] = 0;
        }if (i > 100 && i <= 200){
            Lutfirst[i] = 100;
        }if (i > 200){
            Lutfirst[i] = 255;
        }
    }
    //通过数组的方式构造Mat矩阵
    Mat lutTwo(1, 256, CV_8U, Lutsecond);

    //lut第三层
    //lut矩阵的第三个通道的数组值
    uchar Lutthrid[256];
    for (int i = 0; i < 256; i++){
        if (i <= 100){
            Lutfirst[i] = 100;
        }if (i > 100 && i <= 200){
            Lutfirst[i] = 200;
        }if (i > 200){
            Lutfirst[i] = 255;
        }
    }
    //通过数组的方式构造Mat矩阵
    Mat lutThree(1, 256, CV_8U, Lutthrid);

    //有三个通道的LUT矩阵
    vector<Mat> mergeMats;
    mergeMats.push_back(lutOne);
    mergeMats.push_back(lutTwo);
    mergeMats.push_back(lutThree);
    Mat mergeTree;
    merge(mergeMats, mergeTree);//Mat类合并

    //映射
    Mat gary,out0,out1,out2;
    cvtColor(img, gary, COLOR_BGR2GRAY);
    LUT(gary, lutOne, out0);//灰度图与单通道进行映射
    LUT(img, lutOne, out1);//原图与单通道进行映射
    LUT(img, mergeTree, out2);//原图与多通道进行映射
    imshow("out0", out0);
    imshow("out1", out1);
    imshow("out2", out2);

    waitKey(0);
    return 0;
}