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

    //尺寸变换
    Mat small,big0,big1,big2;
    resize(img,small,Size(15,15),0,0,INTER_AREA);//缩小
    resize(img,big0,Size(30,30),0,0,INTER_NEAREST);//最近邻插值
    resize(img,big1,Size(30,30),0,0,INTER_LINEAR);//双线性插值
    resize(img,big2,Size(30,30),0,0,INTER_CUBIC);//双三次插值
    namedWindow("samll",0);//图像尺寸太小，要设置成可以调节大小的窗口
    imshow("samll",small);

    //矩阵数组的拼接
    Mat arr[]= {
            Mat(1, 2, CV_32FC1, Scalar(1)),
            Mat(1, 2, CV_32FC1, Scalar(2)),
            Mat(1, 2, CV_32FC1, Scalar(3))
    };
    Mat heng,zong;
    vconcat(arr,2,zong);
    hconcat(arr,2,heng);
    cout<<"纵向拼接："<<endl<<zong<<endl;
    cout<<"横向拼接："<<endl<<heng<<endl;

    //矩阵的拼接
    Mat a = (Mat_<float>(1, 2)<<1,2,3,4);
    Mat b = (Mat_<float>(1, 2)<<5,6,7,8);
    Mat v,h;
    vconcat(a,b,v);
    hconcat(a,b,h);

    //图像拼接
    /*
    Mat img1= imread("路径");
    Mat img2= imread("路径");
    Mat img3,img4;
    vconcat(img1,img2,img3);
    hconcat(img1,img2,img4);
    */

    //图像翻转
    Mat img_x,img_y,img_xy;
    flip(img,img_x,0);//以x为对称轴
    flip(img,img_y,1);//以y为对称轴
    flip(img,img_xy,-1);//先以x为对称轴，再以y为对称轴

    waitKey(0);
    return 0;
}