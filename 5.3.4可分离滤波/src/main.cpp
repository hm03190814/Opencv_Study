#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main() {
    float points[] = {
            1, 2, 3, 4, 5,
            6, 7, 8, 9, 10,
            11, 12, 13, 14, 15,
            16, 17, 18, 19, 20,
            21, 22, 23, 24, 25
    };
    Mat data(5, 5, CV_32FC1, points);

    // 验证高斯滤波器可分离
    //getGaussianKernel生成高斯滤波器(尺寸为3标准差为1)
    Mat gaussX = getGaussianKernel(3, 1);
    cout << "gaussX" << gaussX << endl;
    Mat gaussDstData, gaussDataXY;
    //高斯滤波
    GaussianBlur(data, gaussDstData, Size(3, 3), 1, 1, BORDER_CONSTANT);
    //双方向滤波
    sepFilter2D(data, gaussDataXY, -1, gaussX, gaussX, Point(-1, -1), 0, BORDER_CONSTANT);
    //显示
    cout << "gaussDstData" << gaussDstData << endl;
    cout << "gaussDataXY" << gaussDataXY << endl;
    cout << "######################################" << endl;

    // Y方向上滤波
    Mat a = (Mat_<float>(3, 1) << -1, 3, -1);
    // X方向上滤波
    Mat b = a.reshape(1, 1);//把3行1列的矩阵变为1行3列1通道的矩阵
    // XY联合滤波
    Mat ab = a * b;

    //线性滤波的可分离性
    Mat dataYX, dataY, dataXY, dataXY_sep;
    filter2D(data, dataY, -1, a,Point(-1,-1),0,BORDER_CONSTANT);
    filter2D(dataY, dataYX, -1, b,Point(-1,-1),0,BORDER_CONSTANT);
    filter2D(data, dataXY, -1, ab,Point(-1,-1),0,BORDER_CONSTANT);
    sepFilter2D(data, dataXY_sep, -1, b, b,Point(-1,-1),0,BORDER_CONSTANT);

    //输出可分离滤波和联合滤波的计算结果
    cout << "dataY" << dataY << endl;
    cout << "dataYX" << dataYX << endl;
    cout << "dataXY" << dataXY << endl;
    cout<< "dataXY_sep" << dataXY_sep <<endl;

    //对图像进行分离操作
    Mat im = imread("../../source/pingguo.jpg");

    Mat  imY, imYX, imXY;
    filter2D(im, imY, -1, b);
    filter2D(imY, imYX, -1, a);
    sepFilter2D(im, imXY, -1, a, b);
    //显示
    imshow("im", im);
    imshow("imY", imY);
    imshow("imYX", imYX);
    imshow("imXY", imXY);

    waitKey(0);
    destroyAllWindows();
    return 0;
}