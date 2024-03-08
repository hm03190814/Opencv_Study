#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    /*
    //利用数组分离，利用数组合并，利用vector模板类尾插法合并
    Mat img = imread("../../source/pingguo.jpg");
    Mat img_arr0, img_arr1, img_arr2;//存放数组类型的结果
    Mat result0,result1;//多通道合并的结果
    //创建窗口
    namedWindow("B通道", 0);
    namedWindow("G通道", 0);
    namedWindow("R通道", 0);
    namedWindow("result0", 0);
    namedWindow("result1", 0);

    //利用数组  Mat[]  分离
    Mat imgs[3];
    split(img, imgs);//第一个参数是需要分离的图，第二参数是用来接受的数组的名称
    //用数组接收
    img_arr0 = imgs[0];
    img_arr1 = imgs[1];
    img_arr2 = imgs[2];
    imshow("B通道", img_arr0);
    imshow("G通道", img_arr1);
    imshow("R通道", img_arr2);

    //利用数组  Mat[]  合并
    //创建一张与该图大小一样的图片（像素点全为0）
    Mat zero = Mat::zeros(img.rows, img.cols, CV_8UC1);
    imgs[0] = zero;//将B通道全部变为0
    merge(imgs, 3, result0);//第一个参数是数组名，第二个参数是数组元素个数，第三个参数是输出图像名
    imshow("result0", result0);//最后显示的是只有GR通道有色彩的图像

    //利用vector模板类  vector<Mat>  合并
    vector <Mat> imgv;//创建一个名为imgv的模板类vector
    imgv.push_back(img_arr0);
    imgv.push_back(zero);
    imgv.push_back(img_arr2);
    merge(imgv, result1);
    imshow("result1", result1);
*/


   //利用vector模板类  vector<Mat>  分离与合并
    Mat img = imread("../../source/pingguo.jpg");
    Mat HSV;
    cv::cvtColor(img, HSV, COLOR_BGR2HSV);
    Mat img_v0, img_v1, img_v2;//用于存放vector类型的结果
    Mat result1;//多通道合并的结果
    //创建窗口
    namedWindow("H通道", 0);
    namedWindow("S通道", 0);
    namedWindow("V通道", 0);
    namedWindow("result1", 0);
    //分离
    vector<Mat>imgv;//创建一个名为imgv的模板类vector;
    split(HSV, imgv);
    //用vector接收
    img_v0 = imgv.at(0);
    img_v1 = imgv.at(1);
    img_v2 = imgv.at(2);//在vecter中检索的顺序也是从0开始
    imshow("H通道", img_v0);
    imshow("S通道", img_v1);
    imshow("V通道", img_v2);
    //合并
    //创建一张与该图大小一样的图片（像素点全为0）
    Mat zero = Mat::zeros(img.rows, img.cols, CV_8UC1);
    imgv.at(2) = zero;//将亮度调为0
    merge(imgv, result1);
    imshow("result1", result1);

    waitKey(0);
    return 0;
}