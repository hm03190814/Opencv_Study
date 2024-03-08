#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {

    //用4个点表示三角形轮廓
    vector<Point> contour;
    contour.push_back(Point2f(0,0));
    contour.push_back(Point2f(10,0));
    contour.push_back(Point2f(10,10));
    contour.push_back(Point2f(5,5));
    //面积
    double area = contourArea(contour);
    cout<<"面积:"<<area<<endl;
    //闭合长度
    double len1 = arcLength(contour,true);
    cout<<"闭合长度:"<<len1<<endl;
    //不闭合长度
    double len0 = arcLength(contour,false);
    cout<<"不闭合长度:"<<len0<<endl;

    cout<<"--------------------------------------------"<<endl;

    //图像轮廓面积与长度
    Mat a = imread("../../7.2.6凸包检测/source/img.jpg",IMREAD_GRAYSCALE);
    GaussianBlur(a,a,Size(7,7),2,2);//平滑滤镜
    Mat binary;
    threshold(a,binary,170,255,THRESH_BINARY|THRESH_OTSU);//自适应二值化


    //轮廓检测
    vector<vector<Point>> contours; //轮廓
    vector<Vec4i> hierarchy; //存放轮廓结构变量
    findContours(binary,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point());
    //                   原图    轮廓     [,,,]         标志(提取所有轮廓)              标志

    //图像轮廓面积
    for(int t=0;t<contours.size();t++){
        double areal= contourArea(contours[t]);
        cout <<"第"<< t<<"轮廓面积："<<areal<<std::endl;
    }
    //图像轮廓长度
    for(int t=0;t<contours.size();t++){
        double length2= arcLength(contours[t],true);
        cout <<"第"<< t<<"轮廓长度："<<length2<<std::endl;
    }

    waitKey(0);
    return 0;
}