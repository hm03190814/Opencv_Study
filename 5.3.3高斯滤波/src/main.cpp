#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main() {
    Mat img = imread("../../source/pingguo.jpg");
    if (img.empty()) {
        cout << "请确认输入的路径是否正确" << endl;
        return -1;
    }
    Mat result;//存放滤波结果
    //调用高斯滤波函数GaussianBlur()进行滤波
    GaussianBlur(img,result,Size(3,3),10,20);

    imshow("img", img);
    imshow("result", result);
    waitKey(0);
    destroyAllWindows();
    return 0;
}