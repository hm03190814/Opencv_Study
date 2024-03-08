#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {

    // 自定义矩阵
    Mat a = (Mat_<uchar>(5, 5) <<
            1,1,1,1,1,
            1,1,1,1,1,
            1,1,0,1,1,
            1,1,1,1,1,
            1,1,1,1,1
    );
    Mat distL1, distL2, distC;
    distanceTransform(a, distL1, DIST_L1, 3, CV_8U);
    distanceTransform(a, distL2, DIST_L2, 5, CV_8U);
    distanceTransform(a, distC, DIST_C, 3, CV_8U);

    cout << "街区距离" << endl << distL1 << endl;
    cout << "欧氏距离" << endl << distL2 << endl;
    cout << "棋盘距离" << endl << distC << endl;

    //对图像进行距离变换
    Mat im = imread("../../6.1.2连通域分析/source/mili.jpg", IMREAD_GRAYSCALE);
    if (im.empty()) {
        return -1;
    }
    // 转为二值图像
    Mat im1, im2;
    threshold(im, im1, 125 ,255, THRESH_BINARY);//黑底
    threshold(im, im2, 125, 255, THRESH_BINARY_INV);//白底

    Mat dist1, dist2;
    distanceTransform(im1, dist1, DIST_L1, 3, CV_32F);
    distanceTransform(im2, dist2, DIST_L1, 3, CV_8U);

    imshow("im1", im1);
    imshow("dist1", dist1);
    imshow("im2", im2);
    imshow("dist2", dist2);

    waitKey(0);
    return 0;
}
