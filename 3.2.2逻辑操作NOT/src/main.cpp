#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    Mat a =(Mat_<uchar>(1,2)<<0,5);
    Mat b =(Mat_<uchar>(1,2)<<0,6);
    Mat nothh,andhh,orhh,xorhh;
    bitwise_not(a,nothh);
    bitwise_and(a,b,andhh);
    bitwise_or(a,b,orhh);
    bitwise_xor(a,b,xorhh);
    cout<<nothh<<endl<<andhh<<endl<<orhh<<endl<<xorhh<<endl;
    //读取图片
    Mat img = imread("../Img/img.jpg");
    Mat baidi = imread("../Img/baidi.jpg");
    Mat heidi = imread("../Img/heidi.jpg");
    //与
    Mat imgheidiand;
    bitwise_and(img,heidi,imgheidiand);
    //非
    Mat heidinot;
    bitwise_not(heidi,heidinot);

    //test
    Mat imgnot;
    cvtColor(heidi,heidi,COLOR_BGR2GRAY);
    bitwise_not(img,imgnot,heidi);
    Mat jieguo;
    Mat imgbaidimin;
    min(img,baidi,imgbaidimin);
    jieguo=imgbaidimin+imgnot;

    namedWindow("img",0);
    namedWindow("baidi",0);
    namedWindow("heidi",0);
    namedWindow("imgheidiand",0);
    namedWindow("imgnot",0);
    namedWindow("jieguo",0);
    namedWindow("imgbaidimin",0);
    namedWindow("heidinot",0);
    imshow("img",img);
    imshow("baidi",baidi);
    imshow("heidi",heidi);
    imshow("imgheidiand",imgheidiand);
    imshow("imgnot",imgnot);
    imshow("jieguo",jieguo);
    imshow("imgbaidimin",imgbaidimin);
    imshow("heidinot",heidinot);
    
    waitKey(0);
    return 0;
}