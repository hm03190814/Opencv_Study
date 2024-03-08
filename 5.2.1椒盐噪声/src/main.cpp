#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace cv;
using namespace std;
//椒盐噪声函数
void saltAndPepper(Mat image, int n)
{
    int i = 0, j = 0, write_black = 0;
    for (int k = 0; k < n; ++k)
    {
        //随机确定图像中位置
        i = rand() % image.cols;//取余数运算，保证在图像的列数内
        j = rand() % image.rows;//取余数运算，保证在图像的行数内
        write_black = 1;// rand() % 2;//判定为白色噪声还是黑色噪声的变量
        if (write_black == 0) //添加白色噪声
        {
            if (image.type() == CV_8UC1)
            {//处理灰度图像
                image.at<uchar>(j, i) = 255;//白色噪声
            }
            else if (image.type() == CV_8UC3) {//处理彩色图像
                image.at<Vec3b>(j, i)[0] = 255;//Vec3b为opencv定义的3个值的向量类型
                image.at<Vec3b>(j, i)[1] = 255;//[]制定通道，B:0,G:1,R:2
                image.at<Vec3b>(j, i)[2] = 255;
            }
        }
        else //添加黑色噪声
        {
            if (image.type() == CV_8UC1)
            {
                image.at<uchar>(j, i) = 0;
            }
            if (image.type() == CV_8UC3)
            {
                image.at<Vec3b>(j, i)[0] = 0;//Vec3b为opencv定义的3个值的向量类型
                image.at<Vec3b>(j, i)[1] = 0;//[]制定通道，B:0,G:1,R:2
                image.at<Vec3b>(j, i)[2] = 0;
            }
        }
    }
}

int main() {
    Mat img = imread("../../source/pingguo.jpg");
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    if (img.empty() || gray.empty()) {
        cout << "请确认输入的路径是否正确" << endl;
        return -1;
    }
    imshow("img", img);
    imshow("gray", gray);

    saltAndPepper(img, 1000);//彩色图像添加椒盐噪声
    saltAndPepper(gray, 1000);//灰度图像添加椒盐噪声

    imshow("imggg", img);
    imshow("grayyy", gray);
    waitKey(0);
    destroyAllWindows();
    return 0;
}