#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main(){

    Mat a (3,3,CV_8UC1);
    //          行数    列数      数据类型


    Mat b (Size(4,4),CV_8UC1);
    //              尺寸                     数据类型


    Mat c0 (5,5,CV_8UC1,Scalar(4,5,6));
    Mat c1 (5,5,CV_8UC2,Scalar(4,5,6));
    Mat c2 (5,5,CV_8UC3,Scalar(4,5,6));
    //           行数   列数      数据类型            像素值


    //创建一个1*5的矩阵存放int型的数据
    Mat d =(Mat_<int>(1,5)<<1,2,3,4,5);


    Mat e = Mat::diag(d);   //构建对角矩阵  参数为Mat类的一维变量
    Mat h = Mat::ones(3,3,CV_8UC1);   //构建全为1的矩阵
    Mat i = Mat::zeros(3,3,CV_8UC1);  //构建全为0的矩阵
    Mat m = Mat::eye(3,3,CV_8UC1);  //构建单位矩阵



    Mat f =Mat(e,Range(2,4),Range(2,4));
    //           母类                截取[)                            截取[)


    //循环法赋值
    Mat g = Mat_<int>(3,3);
    for(int i = 0; i < g.rows; i++)
    {
        for(int j = 0; j < g.cols; j++)
        {
            g.at<int>(i, j) = i + j;
        }

    }


    //利用数据进行赋值
    float s[8] = {5,6,7,8,1,2,3,4,};
    Mat z = cv::Mat(2,4,CV_32FC1,s);






    cout<<"a:"<<a<<endl;
    cout<<"b"<<b<<endl;
    cout<<c0<<endl;
    cout<<c1<<endl;
    cout<<c2<<endl;
    cout<<d<<endl;
    cout<<e<<endl;
    cout<<f<<endl;
    return 0;
}