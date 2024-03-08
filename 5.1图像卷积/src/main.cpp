#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
    //待卷积矩阵
    uchar points[25] = {
            1,2,3,4,5,
            6,7,8,9,10,
            16,17,18,19,20,
            21,22,23,24,25
    };
    Mat img(5,5,CV_8UC1, points);
    //卷积模板
    Mat kernel1 = (Mat_<float>(3,3)<<
            1,2,1,
            2,0,2,
            1,2,1
            );
    //卷积模板归一化
    Mat kernel2= kernel1/12;


    Mat result1,result2;
    //未归一化卷积结果
    filter2D(img,result1,CV_32F,kernel1,Point(-1,-1),2,BORDER_CONSTANT);
    //归一化卷积结果
    filter2D(img,result2,CV_32F,kernel2,Point(-1,-1),2,BORDER_CONSTANT);

    cout<<result1<<endl<<result2<<endl;

    //图像卷积
    Mat src = imread("../../source/pingguo.jpg");
    Mat srccc;
    filter2D(src,srccc,-1,kernel2,Point(-1,-1),2,BORDER_CONSTANT);
    imshow("src", src);
    imshow("srccc", srccc);

    waitKey(0);
    return 0;
}
