#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
    Mat img = imread("../image/erweima.png",IMREAD_GRAYSCALE);
    if (img.empty()) {
        cout << "空";
        return -1;
    }
    Mat xinma;
    QRCodeDetector q1;
    vector<Point> points;
    string zifu;

    bool is = q1.detect(img, points); //识别二维码
    if (is) {
        //解码二维码
        zifu = q1.decode(img, points, xinma);
        std::cout << "result:" << zifu << std::endl;
        if (xinma.empty()) {
            std::cout << "No\n";
            return -1;
        }
        cout << "二维码4个顶点的坐标:" << points << endl;
    } else {
        cout << "无法识别" << endl;
        return -1;
    }

    imshow("img",img);
//    namedWindow("xinma",WINDOW_NORMAL);
    imshow("xinma",xinma);

    waitKey(0);

//    //绘制二维码的边框
//    for(int i = 0; i < points.size(); i++)
//    {
//        if(i == points.size(); i++)
//        {
//            line(img, points[i], points[0], Scalar(0,0,0),2,8);
//            break;
//        }
//        line(img, points[i], points[i + 1], Scalar(0,0,0),2,8);
//
//    }
//
//    //讲解码内容输出到图片上
//    putText(img, zifu.c_str(), Point(20,30), 0, 1.0, Scalar(255,255,255), 2, 8);
//
//
//    //利用函数直接定位二维码并解码
//    string zifu2;
//    vector<Point> points2;
//    zifu2 = q1.detectAndDecode(img,points2);
//    cout << "二维码4个顶点的坐标:" << points2 << endl;
//    putText(img, zifu2.c_str(), Point(20,55), 0, 1.0, Scalar(255,255,255), 2, 8);
//
//    //输出结果
//    imshow("img",img);
//    namedWindow("xinma",WINDOW_NORMAL);
//    imshow("xinma",xinma);
//
//    waitKey(0);
    return 0 ;
}
