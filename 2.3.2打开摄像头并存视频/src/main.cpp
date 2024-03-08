#include <iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {

    VideoCapture video(0);//使用某个摄像头
    //判断摄像头是否调用成功
    if(!video.isOpened()){
        cout<<"打开摄像头失败"<<endl;
        return -1;
    }

    //把视频输入给一个Mat类图像，判断图像是否为空
    Mat img;
    video>>img;  //获取图像
    if(img.empty()){
        cout<<"没有获取到图像"<<endl;
        return -1;
    }

    //定义写入视频的对象
    VideoWriter writer;
    string filename = "live.avi";//保存视频文件名称
    int codec = VideoWriter::fourcc('M','J','P','G');//选择编码格式
    double fps = 25.0; //设置视频帧率
    bool isColor = (img.type()==CV_8UC3);//判断是否为彩色
    writer.open(filename,codec,fps,img.size(),isColor);//创建保存视频文件的视频流

    //判断视频流是否创建成功
    if(!writer.isOpened()){
        cout<<"打卡视频文件失败，请确认是否为合法输入"<<endl;
        return -1;
    }

    //把所有帧数读取出来
    while(1){
        //检测是否执行完毕
        if(!video.read(img)){
            cout<<"视频读取完成"<<endl; //判断都能继续从摄像头或者视频文件中读出一帧图像
            break;
        }
        writer.write(img);//把图像写入视频流write<<img
        imshow("hhhhh",img);//显示图像//没有此行的话摄像头正常开启并工作，但是没有显示界面
        char c = waitKey(50);
        if(c==27){ //按ESC按键退出视频流
            break;
        }
    }

    //退出程序时自动关闭视频流
    //video.release();
    //writer.release();

    return 0;
}