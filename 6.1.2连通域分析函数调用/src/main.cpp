#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void hhh(Mat &img,int number,Mat centroids,Mat stats,String str);

int main(){
    Mat img = imread("../..//6.1.2连通域分析/source/mili.jpg");
    imshow("img",img);
    //转为二值图像，用于统计连通域
    Mat rice,riceBW;
    cvtColor(img,rice,COLOR_BGR2GRAY);
    threshold(rice,riceBW,50,255,THRESH_BINARY);

    Mat out,stats,centroids;
    //统计图像中连通域的数目
    int number = connectedComponentsWithStats(riceBW,out,stats,centroids,8,CV_16U);

    hhh(img,number,centroids,stats,"hhhdiaoyonghou");

    waitKey(0);
    return 0;
}


void hhh(Mat &img,int number,Mat centroids,Mat stats,String str){

    //生成随机颜色，用于区分不同连通域
    RNG rng(10086);
    vector <Vec3b> colors;

    for(int i=0;i<number;i++){
        //使用均匀分布的随机数确定颜色
        Vec3b vec3 = Vec3b(rng.uniform(0,256),rng.uniform(0,256),rng.uniform(0,256));
        colors.push_back(vec3);
    }

    for ( int i = 0 ; i < number ; i++ ) {
        //中心位置
        int center_x = centroids.at<double>(i,0);
        int center_y = centroids.at<double>(i,1);
        //矩形边框
        int x = stats.at<int> (i,CC_STAT_LEFT);
        int y = stats.at<int> (i,CC_STAT_TOP);
        int w = stats.at<int> (i,CC_STAT_WIDTH);
        int h = stats.at<int> (i,CC_STAT_HEIGHT);
        int area = stats.at<int> (i,CC_STAT_AREA);
        //中心位置绘制
        circle(img,Point(center_x,center_y),2,Scalar(0,255,0),2,8,0);
        //外接矩形
        Rect rect(x,y,w,h);
        rectangle(img,rect,colors[i],1,8,0);
        putText(img, format("%d",i),Point(center_x,center_y),
                FONT_HERSHEY_SIMPLEX,0.5,Scalar(0,0,255),1);
    }

    //显示结果
    imshow(str,img);

}










