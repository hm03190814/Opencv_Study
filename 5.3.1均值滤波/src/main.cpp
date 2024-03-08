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

    //调用均值滤波函数blur()进行滤波
    blur(img,result,Size(9,9));//滤波器尺寸为9

    imshow("img", img);
    imshow("result", result);
    waitKey(0);
    destroyAllWindows();
    return 0;
}