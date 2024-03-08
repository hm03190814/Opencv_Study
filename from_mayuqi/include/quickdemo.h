#pragma once
#include<opencv2/opencv.hpp>
using namespace cv;

class Quickdemo
{public:
    void colorspace_demo(Mat &image);
    void creation_demo(Mat &image);
    void pixel_demo(Mat &image);
    void operators_demo(Mat &image);
    void click_demo(Mat &image);
    void bar_demo(Mat &image);
    void create_rectangle(Mat &image);
    void channels_demo(Mat &image);
    // void mixChannels_demo(Mat &image);
    void videocapture();
    void computer_demo(Mat &image);
    void compareimage(Mat & image,Mat & image2);
    void imagethreshold(Mat &image,Mat &myimage);
    void LUTimage_demo(Mat &image);
    void createpyramid_demo(Mat &image);
    void mouserespone(Mat &image);
};