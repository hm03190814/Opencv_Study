#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main() {
    Mat img = imread("../../source/pingguo.jpg");
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    if (img.empty() || gray.empty()) {
        cout << "请确认输入的路径是否正确" << endl;
        return -1;
    }
    //生成与原始图像尺寸，数据类型和通道数相同的矩阵
    Mat imggg = Mat::zeros(img.rows,img.cols,img.type());
    Mat grayyy = Mat::zeros(img.rows,img.cols,gray.type());

    imshow("imgqian", img);
    imshow("grayqian", gray);

    RNG rng;
    rng.fill(imggg,RNG::NORMAL,10,20);//生成三通道的高斯分布随机数
    rng.fill(grayyy,RNG::NORMAL,15,30);//生成单通道的高斯分布随机数

    imshow("imggg", imggg);
    imshow("grayyy", grayyy);

    img=img+imggg;
    gray=gray+grayyy;

    imshow("imghou", img);

    imshow("grayhou", gray);
    imwrite("../source/gaosihou.png",gray);

    waitKey(0);
    return 0;
}
