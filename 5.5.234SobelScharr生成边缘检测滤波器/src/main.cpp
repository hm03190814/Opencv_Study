#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    Mat gray = imread("../../3.1.1图像颜色空间转换/source/gray.png",IMREAD_ANYCOLOR);

    //Sobel
    Mat Sobel_x, Sobel_y, Sobel_xy;
    //x方向一阶边缘
    Sobel(gray, Sobel_x, CV_16S, 2,0,1);
                                       //  x方向差分阶数，y方向差分阶数，核大小
    convertScaleAbs(Sobel_x, Sobel_x);     //求绝对值函数
    imshow("Sobel_x", Sobel_x);
    //y方向一阶边缘
    Sobel(gray, Sobel_y, CV_16S, 0,1,3);
    convertScaleAbs(Sobel_y, Sobel_y);
    imshow("Sobel_y", Sobel_y);
    //整幅图的一阶边缘
    Sobel_xy = Sobel_x + Sobel_y;
    imshow("Sobel_xy", Sobel_xy);

    //Scharr
    Mat Scharr_X, Scharr_Y, Scharr_XY;
    //X方向一阶边缘
    Scharr(gray, Scharr_X, CV_16S, 1, 0);
    convertScaleAbs(Scharr_X, Scharr_X);
    imshow("Scharr_X", Scharr_X);
    //Y方向一阶边缘
    Scharr(gray, Scharr_Y, CV_16S, 0, 1);
    convertScaleAbs(Scharr_Y, Scharr_Y);
    imshow("Scharr_Y", Scharr_Y);
    //整幅图像的一阶边缘
    Scharr_XY = Scharr_X + Scharr_Y;
    imshow("Scharr_XY", Scharr_Y);

    //生成边缘检测滤波器
    //存放分离的Sobel算子
    Mat Sobel_x1, Sobel_y1, Sobel_x2, Sobel_y2,Sobel_x3, Sobel_y3;
    //存放最终算子
    Mat Sobel1, Sobel2, Sobel3;
    //一阶x方向Sobel算子
    getDerivKernels(Sobel_x1, Sobel_y1,1,0,3);
    Sobel_x1=Sobel_x1.reshape(CV_8U,1);
    Sobel1 = Sobel_y1*Sobel_x1;
    cout<<"Sobel1"<<Sobel1<<endl;
    //二阶x方向Sobel算子
    getDerivKernels(Sobel_x2, Sobel_y2,2,0,5);
    Sobel_x2=Sobel_x2.reshape(CV_8U,1);
    Sobel2 = Sobel_y2*Sobel_x2;
    cout<<"Sobel2"<<Sobel2<<endl;
    //三阶x方向Sobel算子
    getDerivKernels(Sobel_x3, Sobel_y3,3,0,7);
    Sobel_x3=Sobel_x3.reshape(CV_8U,1);
    Sobel3 = Sobel_y3*Sobel_x3;
    cout<<"Sobel3"<<Sobel3<<endl;

    //生成边缘检测滤波器
    //存放分离的Scharr算子
    Mat Scharr_x1, Scharr_y1;
    //存放最终算子
    Mat Scharr1;
    //x方向Scharr算子
    getDerivKernels(Scharr_x1, Scharr_y1,1,0,FILTER_SCHARR);
    Scharr_x1 = Scharr_x1.reshape(CV_8U,1);
    Scharr1 = Scharr_y1*Scharr_x1;
    cout<<"Scharr1"<<Scharr1<<endl;

    waitKey(0);
    return 0;
}