#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui.hpp>
#include<opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;/*
int main(){
    Mat img = imread("/home/yin/opencv/opencv0000/6.1.2连通域分析/mili.jpg");
    if (img.empty()) {
        return -1;
    }
    //转为二值图像
    Mat rice,riceBW;
    cvtColor(img,rice,COLOR_BGR2GRAY);
    threshold(rice,riceBW,50,255,THRESH_BINARY);
    //生成随机颜色，用于区分不同连通域
    RNG rng(10086);
    Mat out;//存放输出结果的矩阵
    int number = connectedComponents(riceBW,out,8,CV_16U);//统计图像中连通域的个数
    vector <Vec3b> colors;
    for(int i=0;i<number;i++){
        //使用均匀分布的随机数确定颜色
        Vec3b vec3 = Vec3b(rng.uniform(0,256),rng.uniform(0,256),rng.uniform(0,256));
        colors.push_back(vec3);
    }
    //以不同颜色标记不同连通域
    Mat result = Mat::zeros(rice.size(),img.type());
    int w = result.cols;
    int h = result.rows;
    for(int row = 0 ; row < h ; row++ ) {
        for (int col = 0; col < w; col++) {
            int label = out.at<uint16_t>(row,col);
            if (label==0){//背景的黑色不改变
                continue;
            }
            result.at<Vec3b>(row,col) = colors[label];
        }
    }

    //显示结果
    imshow("img",img);
    imshow("result",result);

    waitKey(0);
    return 0;
}
*/

int main(){
    Mat img = imread("/home/yin/opencv/opencv0000/6.1.2连通域分析/mili.jpg");
    if (img.empty()) {
        return -1;
    }
    imshow("imgqian",img);
    //转为二值图像
    Mat rice,riceBW;
    cvtColor(img,rice,COLOR_BGR2GRAY);
    threshold(rice,riceBW,50,255,THRESH_BINARY);
    //生成随机颜色，用于区分不同连通域
    RNG rng(10086);
    Mat out;//存放输出结果的矩阵
    Mat stats,centroids;
    //统计图像中连通域的数目
    int number = connectedComponentsWithStats(riceBW,out,stats,centroids,8,CV_16U);
    vector <Vec3b> colors;
    for(int i=0;i<number;i++){
        //使用均匀分布的随机数确定颜色
        Vec3b vec3 = Vec3b(rng.uniform(0,256),rng.uniform(0,256),rng.uniform(0,256));
        colors.push_back(vec3);
    }
    //以不同颜色标记不同连通域
    Mat result = Mat::zeros(rice.size(),img.type());
    int w = result.cols;
    int h = result.rows;
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
        cout<<"number"<<i<<",area:"<<area<<endl;
    }

    //显示结果
    imshow("imghou",img);

    waitKey(0);
    return 0;
}














