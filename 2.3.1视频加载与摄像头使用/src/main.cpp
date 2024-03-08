#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    VideoCapture video;
    //1:打开视频
    video.open("../source/shipin.mp4");
    //2:打卡摄像头
    //video.open(0);

    // 验证视频是否正常读取
    //如果读取成功  video.isOpened()会返回true
    if(!video.isOpened()){
        cout<<"请检查文件路径"<<endl;
        return -1;
    }

    //输出数据
    cout<<"视频帧率"<<video.get(CAP_PROP_FPS)<<endl;
    cout<<"视频宽度"<<video.get(CAP_PROP_FRAME_WIDTH)<<endl;

    //显示视频
    //通过每一帧的读取，显示每一帧
    while(1){
        Mat frame;  //存贮帧的Mat类
        video>>frame;
        if(frame.empty()){
            break;
        }
        imshow("hhh",frame);//窗口叫做hhh
        uchar c = waitKey(1000/video.get(CAP_PROP_FPS));
        //按q按键退出
        if(c=='q'){
            break;
        }
    }
    return 0;
}