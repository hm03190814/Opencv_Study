#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {

    Vec4f lines;//存放拟合后的直线
    vector<Point2f> pt; //待检测是否存在直线的所有点

    const static float Points[20][2] ={
            {0.0f,0.0f},{10.0f,11.0f},{21.0f,20.0f},{30.0f,30.0f},
            {40.0f,42.0f},{50.0f,50.0f},{60.0f,60.0f},{720.0f,70.0f},
            {80.0f,80.0f},{90.0f,92.0f},{100.0f,100.0f},{110.0f,110.0f},
            {120.0f,120.0f},{136.0f,130.0f},{138.0f,140.0f},{150.0f,150.0f},
            {160.0f,163.0f},{175.0f,170.0f},{181.0f,180.0f},{200.0f,190.0f}
    };

    //将所有点存放在vector中，用于输入函数
    for(int i = 0; i < 20; i++)
    {
        pt.push_back(Point2f (Points[i][0], Points[i][1]) );
    }

    //参数设置
    fitLine(pt, lines, DIST_L1, 0, 0.01, 0.01);
    //            点集 输出描述直线的参数       标志      一般为0        0.01        0.01

    double  k = lines[1] / lines[0];
    cout << "直线斜率" << k << endl;
    cout << "直线上一点坐标 x=" << lines[2] << " y=" << lines[3] << endl;
    cout << "直线解析式： y=" << k << "(x-" << lines[2] << ")+" << lines[3] << endl;

    return 0 ;
}
