
#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void callBack(int, void*);

int main() {
    cv::Mat img = imread("../../source/pingguo.jpg");
    if (img.empty()) {
        cout << "路径不对" << endl;
        return -1;
    }
    int value = 1;
    cv::namedWindow("windows");
    cv::createTrackbar("test", "windows", &value, 255, callBack, &img);
    cv::imshow("windows", img);
    waitKey(0);
    while (true);
    return 0;
}

void callBack(int pos, void* user_data) {
    auto img_new = *static_cast<cv::Mat*>(user_data) * pos;
    cv::imshow("windows", img_new);
}
