#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main(){
    system("color F0");
    Mat a =(Mat_<int>(3,3)<<1,2,3,4,5,6,7,8,9);
    Mat b =(Mat_<int>(3,3)<<1,2,3,7,8,9,4,5,6);
    Mat c =(Mat_<double>(3,3)<<1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0);
    Mat d =(Mat_<double>(3,3)<<1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0);

    cout<<"两个矩阵的和:"<<endl<<a+b<<endl;
    cout<<"两个矩阵的差:"<<endl<<a-b<<endl;
    cout<<"矩阵数乘:"<<endl<<2*a<<endl;
    cout<<"矩阵数除:"<<endl<<d/2.0<<endl;
    cout<<"矩阵数减:"<<endl<<a-1<<endl;

    cout<<"两矩阵相乘:"<<endl<<c*d<<endl;
    cout<<"矩阵内积:"<<endl<<a.dot(b)<<endl;
    cout<<"矩阵对应位相乘:"<<endl<<a.mul(b)<<endl;
    cout<<"两矩阵最小值:"<<endl<<min(a,b)<<endl;


    return 0;
}