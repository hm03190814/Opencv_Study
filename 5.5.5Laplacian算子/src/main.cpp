#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main() {
    Mat im = imread("../../5.2.2高斯噪声/source/gaosihou.png");
    if (im.empty()) {
        cerr << "image file read error" << endl;
        return -1;
    }
    Mat result1, resultGauss, result2;

    // 未使用高斯滤波进行边缘检测
    Laplacian(im, result1, CV_16S , 3, 1,0);
    convertScaleAbs(result1, result1);//求取绝对值
    imshow("result1", result1);

    // 先用高斯滤波器进行滤波,再进行边缘检测
    GaussianBlur(im, resultGauss, Size(3, 3), 5,0);
    Laplacian(resultGauss, result2, CV_16S , 3, 1,0);
    convertScaleAbs(result2, result2);
    imshow("result2", result2);

    waitKey(0);
    return 0;
}