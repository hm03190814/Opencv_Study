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
    Mat result1;//存放滤波结果(进行归一化)
    Mat result2;//存放滤波结果(未进行归一化)

    //调用方框滤波函数boxFilter()进行滤波
    boxFilter(img,result1,-1,Size(3,3),Point(-1,-1),true);//进行归一化
    boxFilter(img,result2,-1,Size(3,3),Point(-1,-1), false);//未进行归一化

    imshow("img", img);
    imshow("result1", result1);
    imshow("result2", result2);
    waitKey(0);
    destroyAllWindows();
    return 0;
}