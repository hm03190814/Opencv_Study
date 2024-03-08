#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main(){
    //生成用于腐蚀的原图
    Mat src = (Mat_<uchar>(6,6)<<
            0,0,0,0,255,0,
            0,255,255,255,255,255,
            0,255,255,255,255,0,
            0,255,255,255,255,0,
            0,255,255,255,255,0,
            0,0,0,0,0,0);
    imshow("src",src);

    Mat struct1 , struct2 ;
    struct1 = getStructuringElement(0,Size(3,3));//矩形结构元素
    struct2 = getStructuringElement(1,Size(3,3));//十字结构元素

    Mat fushi;//存放腐蚀后的图像
    erode(src,fushi,struct2);//腐蚀
    imshow("fushi",fushi);

    Mat pengzhang;//存放膨胀后的图像
    dilate(src,pengzhang,struct2);//膨胀
    imshow("pengzhang",pengzhang);

    //图片的腐蚀与膨胀
    Mat heidi = imread("../source/heidi.jpg",IMREAD_GRAYSCALE);//灰色读取
    imshow("heidi",heidi);

    //图像腐蚀
    Mat heidi1;
    erode(heidi,heidi1,struct1);//腐蚀
    imshow("heidifushi",heidi1);

    //图像膨胀
    Mat heidi2 ;
    dilate(heidi,heidi2,struct1);//膨胀
    imshow("heidipengzhang",heidi2);


    waitKey(0);
    return 0;
}