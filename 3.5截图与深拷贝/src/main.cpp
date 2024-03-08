#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    Mat a = imread("../../3.2.2两张图像像素比较/Img/img.jpg");
    Mat b = imread("../../source/pingguo.jpg");
    if(a.empty()||b.empty()){
        cout<<"请检查路径"<<endl;
        return -1;
    }
    Mat xiaob;//b的缩小版
    resize(b,xiaob,Size(200,200));

    //浅拷贝
    Mat aa,jie1,jie2;
    //深拷贝
    Mat a1,a2,jie22;

    //浅拷贝
    aa=a;
    //深拷贝的两种方式
    a.copyTo(a1);
    copyTo(a,a2,a);
    //两种在图中截取ROI的方式
    Rect rect(206,206,200,200);
    jie1=a(rect);
    jie2=a(Range(300,500),Range(300,500));
    //用深拷贝截取
    a(Range(300,500),Range(300,500)).copyTo(jie22);

    imshow("aaaaa",a);//此时a为未改变

    //把xiaob的内容深拷贝给jie1
    xiaob.copyTo(jie1);//此时a,aa,jie1,jie2都改变

    //绘制一个圆形  //此时a,aa,jie1,jie2继续改变
    circle(a,Point(300,300),20,Scalar(0,0,255),-1);

    imshow("a",a);
    imshow("b",b);
    imshow("aa",aa);
    imshow("a1",a1);
    imshow("a2",a2);
    imshow("xiaob",xiaob);
    imshow("jie1",jie1);
    imshow("jie2",jie2);
    imshow("jie22",jie22);

    waitKey(0);
    return 0;
}