#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void drawLine(Mat &img, vector<Vec2f> lines, double rows, double cols, Scalar scalar, int n)
{
    Point p1, p2;
    for(size_t i = 0; i < lines.size(); i++)
    {
        float rho = lines[i][0]; //直线与坐标原点的距离
        float theta = lines[i][1]; //直线与坐标原点的垂线与x轴的夹角
        double a = cos(theta); //夹角的余弦
        double b = sin(theta); // 夹角的正弦
        double x0 = a*rho, y0 = b*rho; //直线与过坐标原点的垂线的交点
        double length = max(rows,cols); //图像高宽的最大值
        //计算直线上的一点
        p1.x = cvRound(x0 + length * (-b) );
        p1.y = cvRound(y0 + length * (a) );
        //计算直线上的另一点
        p2.x = cvRound(x0 + length * (-b) );
        p2.y = cvRound(y0 + length * (a) );
        //两点绘制一条直线
        std::cout << "p1: " << p1 << "p2: " << p2 << std::endl;
        line(img, p1, p2, scalar, n);
        imshow("drawLine", img);
    }
}

int main() {
    Mat img = imread("../../source/pingguo.jpg",IMREAD_GRAYSCALE);
    imshow("img",img);

    //边缘检测
    Mat edge;
    Canny(img,edge,80,160,3,false);
    imshow("edge",edge);

    //用不同累加器检测直线
    vector<Vec2f> line1;
    HoughLines(edge, line1, 1, CV_PI / 180, 50, 0, 0 );
    //            单通道二值图像   直线系数    分辨率         分辨率             阈值     标准霍夫变换

    for (const auto& l: line1) {
        std::cout << l << ", ";
    }
    std::cout << "\n";


    //在原图中绘制直线
    Mat img1;
    img.copyTo(img1);
    drawLine(img1, line1, edge.rows, edge.cols, Scalar(255), 2);

    waitKey(0);
    return 0;
}

