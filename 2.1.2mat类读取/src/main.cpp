#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main(){
    //cols 列数
    //rows 行数
    //step 以字节为单位的矩阵的有效宽度
    //elemSize() 每个元素的字节数
    //total()  矩阵中的元素个数
    //channels()  矩阵的通道数

    Mat a =(Mat_<int>(3,3)<<1,2,3,4,5,6,7,8,9);
    cout<<a.at<int>(1,1)<<endl;  //5

    Mat c0 (5,5,CV_8UC1,Scalar(4,5,6));
    Mat c1 (5,5,CV_8UC2,Scalar(4,5,6));
    Mat c2 (5,5,CV_8UC3,Scalar(4,5,6));

    Vec2b vc = c1.at<Vec2b>(0,1);
    cout<<vc<<endl;  //[4,5]
    cout<<(int)vc[0]<<endl;  //4

    cout<<(double)(*(c2.data+c2.step[0]*2+c2.step[1]*2+3));  //4
    cout<<vc[1]<<endl;


    //用指针读取
    Mat b (3, 4, CV_8UC3, Scalar(1,2,3));
    for(int i = 0; i < b.rows; i++){
        uchar* p = b.ptr<uchar>(i);
        for(int j = 0; j < b.cols*b.channels(); j++){
            cout << (int)p[j] << " ";
        }
    }




    return 0;
}