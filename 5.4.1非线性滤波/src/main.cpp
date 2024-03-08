#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main() {
    Mat img = imread("../../source/pingguo.jpg");

    Mat  result;
    //进行中值滤波
    //滤波模板为3*3
    medianBlur(img,result,3);

    //显示
    imshow("img", img);
    imshow("result", result);

    waitKey(0);
    destroyAllWindows();
    return 0;
}