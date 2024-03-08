#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
    Mat img = imread("../../5.2.2高斯噪声/source/gaosihou.png");
    if (img.empty()) {
        return -1;
    }
    Mat high, low,resultG;

    //高阈值检测图像边缘
    Canny(img,high, 100,200,3);
                          //              弱阈值         强阈值       sobel算子直径
    imshow("high",high);

    //低阈值检测图像边缘
    Canny(img,low, 20,40,3);
    imshow("low",low);

    //高斯模糊后检测图像边缘
    GaussianBlur(img, resultG, Size(3, 3), 5);
    Canny(img,resultG, 20,40,3);
    imshow("resultG",resultG);

    waitKey(0);
    return 0;
}
