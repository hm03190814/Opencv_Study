#include "../include/quickdemo.h"
#include<iostream>
#include<vector>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
void Quickdemo::colorspace_demo(Mat &image)
{
    Mat gray,hsv;
    cvtColor(image,hsv,COLOR_BGR2HSV);
    cvtColor(image,gray,COLOR_BGR2GRAY);
    imshow("灰度",gray);
    imshow("HSV",hsv);
}
void Quickdemo::creation_demo(Mat &image){
    Mat m1,m2,m3;
    //克隆
    m1=image.clone();
    //复制
    image.copyTo(m2);
    //赋值
    m3=image;
    //创建空白图像
    Mat m4;
    m4=Mat::zeros(Size(256,256),CV_8UC3);
    m4=Scalar(0,0,255);
    cout<<m4.rows<<m4.cols<<m4.channels()<<endl;
    cout<<m4<<endl;
    //克隆或者复制可以理解为深拷贝，重新创建一个内存地址，赋值只是指向同一个内存地址
    Mat m5;
    m4.copyTo(m5);
    m5=Scalar(0,255,0);
    imshow("m5",m5);
    imshow("m4",m4);
}
void Quickdemo::pixel_demo(Mat&image){ 
    int w=image.cols;
    int h=image.rows;
    int dims=image.channels();
    for(int row=0;row<h;row++){
        for(int col=0;col<w;col++){
            if(dims==3){
                Vec3b bgr=image.at<uchar>(row,col);    
                image.at<Vec3b>(row,col)[0]=255-bgr[0]; 
                image.at<Vec3b>(row,col)[1]=255-bgr[1]; 
                image.at<Vec3b>(row,col)[2]=255-bgr[2]; 
            }                         
            }
        }
    imshow("输出",image); 
} 
void Quickdemo::operators_demo(Mat &image){
    Mat m1;
    //加减乘除都可以，重载运算符
    m1=image+Scalar(100,100,100);
    imshow("m1",m1);
    //两个图像进行相加
    Mat m2=Mat::zeros(image.size(),image.type());
    m2=Scalar(2,2,2);
    Mat dst;
    //乘法 其他重载运算符使用类似
    multiply(m2,image,dst);
    imshow("dst",dst);
     int w=image.cols;
    int h=image.rows;
    int dims=image.channels();
    //add函数的本质,其他函数类似
    //subtract减法   divide除法  multiply乘法
    for(int row=0;row<h;row++){
        for(int col=0;col<w;col++){
            Vec3b p1=image.at<Vec3b>(row,col);
            Vec3b p2=m2.at<Vec3b>(row,col);
//saturate_cast,控制范围，防止溢出
            dst.at<Vec3b>(row,col)[0]=saturate_cast<uchar>(p1[0]+p2[0]);
            dst.at<Vec3b>(row,col)[1]=saturate_cast<uchar>(p1[1]+p2[1]);
            dst.at<Vec3b>(row,col)[2]=saturate_cast<uchar>(p1[2]+p2[2]);
        }
    }
}
static void back_assist(int lights,void* userdata){
    //解出userdata中的数据
    Mat image = *((Mat*)(userdata));
    //进行亮度调整
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
    dst=Scalar(lights,lights,lights);
    multiply(image,dst,m);
    imshow("1",m);

}
void Quickdemo::bar_demo(Mat &image){
    int lights=50;
    namedWindow("调整窗口",WINDOW_AUTOSIZE);
    createTrackbar("调整亮度","调整窗口", &lights,100,back_assist,(void*)(&image));

}
void Quickdemo::click_demo(Mat &image){  
    Mat dst=Mat::zeros(image.size(),image.type());
    while(true){
     

        int c=waitKey(100);
        if(c==27){
            cout<<"结束"<<endl;
            break;
        }
        else if(c==49){// 1  亮度加五十
            cout<<"亮度调整"<<endl;
            dst=Scalar(50,50,50);
            multiply(image,dst,dst);
        }
        else if(c==50){// 2 转换为灰度图
            cout<<"转化为灰度图"<<endl;
            cvtColor(image,dst,COLOR_BGR2GRAY);
        }
        imshow("1",dst);
    }
}
void Quickdemo::create_rectangle(Mat &image){
    
    Mat dst=Mat::zeros(Size(256,256),CV_8UC3); 
    Mat dst2=Mat::zeros(Size(256,256),CV_8UC3); 
    //绘制矩形  两种方法  第一种是两个对角点   另一个是左上角的点和矩形长宽
    rectangle(dst,Point(1,1),Point(50,50),Scalar(255,0,0),-1,LINE_8,0);
    rectangle(dst2,Rect(20,20,50,50),Scalar(0,255,0),-1,LINE_8,0);
    imshow("1",dst);
    imshow("2",dst2);
    Mat dst3;
    //与 或 非 异或
    //运算的方法自己查
    bitwise_and(dst,dst2,dst3);
    // bitwise_or(dst,dst2,dst3);
    // bitwise_not(dst,dst3);
    // bitwise_xor(dst,dst2,dst3);
    imshow("3",dst3);
}
void Quickdemo::channels_demo(Mat &image){
    //用vector容器是可以的，同时用数组也是可以的
    //分离通道
    vector<Mat> arr1;
    split(image,arr1);
    imshow("单1",arr1[0]);
    imshow("单2",arr1[1]);
    imshow("单3",arr1[2]);
    //融合
    Mat dst;
    merge(arr1,dst);
    imshow("融合",dst);
}
void Quickdemo::videocapture(){
    VideoCapture video(0);
    Mat frame;
    while(1){
        video>>frame;
        if(frame.empty()){
            cout<<"失败"<<endl;
            break;
        }
        imshow("1",frame);
        int c=waitKey(0);
        if(c==49){
            cout<<"结束"<<endl;
            break;
        }
    }   
}
void Quickdemo::computer_demo(Mat &image){
    float a[12]={1,2,3,4,5,6,12,11,10,10,2,1};
    //求最大值 最小值 位置 平均值   标准差
    Mat i1=Mat(3,4,CV_32FC1,a);
    double valmax,valmin;
    Point addr1,addr2;
    Scalar val1;
    // 求最大值 最小值 位置传入的必须是单通道的矩阵数据
    minMaxLoc(i1,&valmin,&valmax,&addr1,&addr2);
    //用mean求平均值可以是多通道
    val1= mean(i1);
    cout<<"最大值"<<valmax<<"最小值"<<valmin<<addr1<<addr2<<val1<<endl;
    //用meanstddev求平均值标准差可以是多通道
    Mat mymean ,mystddv;
    Mat i2=Mat{2,3,CV_32FC2,a};
    meanStdDev(i2,mymean,mystddv);
    cout<<mymean<<mystddv<<endl;
    //求最大值....多通道需要转换为单通道
    Mat i2_re=i2.reshape(1,4);
    minMaxLoc(i2_re,&valmin,&valmax,&addr1,&addr2);
    cout<<"最大值"<<valmax<<"最小值"<<valmin<<addr1<<addr2<<endl;

}
void Quickdemo::compareimage(Mat & image,Mat & image2){
    //对两个单通道进行比较
    float a[12]={1,2,3,4,0,6,12,11,10,10,2,1};
    float b[12]={1,2,10,4,5,6,12,11,5,10,2,1};
    Mat imga,imgb,img1,img2;
    imga=Mat(3,4,CV_32FC1,a);
    imgb=Mat(3,4,CV_32FC1,b);
    max(imga,imgb,img1);
    min(imga,imgb,img2);
    imshow("max",img1);
    imshow("min",img2);
//对多通道进行比较
    Mat imgas,imgbs,img3,img4;
    imgas=Mat(2,3,CV_32FC2,a);
    imgbs=Mat(2,3,CV_32FC2,b);
    max(imgas,imgbs,img1);
    min(imgas,imgbs,img2);
    // 对两个彩色图进行比较
    //////
    //这边用resize需要进行图像尺寸的转换
    //////
    Mat myimage1,myimage2;
    resize(image,image,Size(512,512),0,0,INTER_AREA);//插值方法,缩小图像一般用INTER_AREA,放大图像一般用INTER_CUBIC
    resize(image2,image2,Size(512,512),0,0,INTER_AREA);
    max(image,image2,myimage1);
    min(image,image2,myimage2);
    imshow("对比1",myimage1);
    imshow("对比2",myimage2);
    //与掩摸进行比较
    //生成掩摸(掩摸的大小需要和比对的对象大小一样)
    Mat src1=Mat::zeros(image2.size(),CV_8UC3),src2;
    Rect rect(100,100,300,300);
    src1(rect)=Scalar(255,255,255);
    imshow("遮罩",src1);
    min(image2,src1,src2);
    imshow("遮罩2",src2);
    //与红色通道的淹摸进行比较
    Mat redsrc=Mat(image2.size(),CV_8UC3,Scalar(0,0,255));
    Mat src3;
    max(image2,redsrc,src3);
    imshow("遮罩2",src3);  
}
void Quickdemo::imagethreshold(Mat &image ,Mat &myimage){
    Mat src1,src2,src3,src4,src6,src5;
    threshold(image,src1,125,255,THRESH_BINARY);
    threshold(image,src2,125,255,THRESH_BINARY_INV);
    threshold(image,src3,125,255,THRESH_TRUNC);
    threshold(image,src4,125,255,THRESH_TOZERO);
    imshow("1",src1);
    imshow("2",src2);
    imshow("3",src3);
    imshow("4",src4);
    //自适应二值化,传入的图像，必须是CV_8UC1,有分布均值法和高斯法
    adaptiveThreshold(myimage,src6,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,55,0);
    imshow("adapt",src6);
}
void Quickdemo::LUTimage_demo(Mat &image){
    uchar lutfirst[256];
    for(int i=0;i<256;i++){
        if(i<=100){
            lutfirst[i]=0;
        }
        else if(i>100 && i<=200){
            lutfirst[i]=1;
        }
        else{
            lutfirst[i]=255;
        }
    }
    Mat Firstlut=Mat(1,256,CV_8UC1,lutfirst);
    uchar lutsecond[256];
    for(int i=0;i<256;i++){
        if(i<=100){
            lutfirst[i]=0;
        }
        else if(i>100 && i<=150){
            lutfirst[i]=100;
        }
        else if(i>150 && i<=200){
            lutfirst[i]=150;
        }
        else{
            lutfirst[i]=255;
        }
    }
    Mat Secondlut=Mat(1,256,CV_8UC1,lutsecond);
    char lutthird[256];
    for(int i=0;i<256;i++){
        if(i<=100){
            lutfirst[i]=100;
        }
        else if(i>100 && i<=200){
            lutfirst[i]=200;
        }
        else{
            lutfirst[i]=255;
        }
    }
    Mat Thirdlut=Mat(1,256,CV_8UC1,lutthird);
    //拥有三通道的lut矩阵
    vector<Mat> m;
    Mat MYLUT,src,src2,src3,gray;
    m.push_back(Firstlut);
    m.push_back(Secondlut);
    m.push_back(Thirdlut);
    merge(m,MYLUT);
    //用一层lut进行比较
    LUT(image,Firstlut,src);
    //灰度图比较
    cvtColor(image,gray,COLOR_BGR2GRAY);
    LUT(gray,Firstlut,src3);

    //用三层lut进行比较
    LUT(image, MYLUT,src2);
    imshow("输出1",src2);
    imshow("输出",src);
    imshow("gray",src3);
}
void  Quickdemo::createpyramid_demo(Mat &  image){
    //创建高斯金字塔
    vector<Mat> Gauss,Lap;
    int level=3;
    Gauss.push_back(image);
    for(int i=0;i<level;i++){
        Mat gauss;
        pyrDown(Gauss[i],gauss);
        Gauss.push_back(gauss);
    }
    // 创建拉普拉斯金字塔
    for(int m=level;m>0;m--){
        cout<<"开始"<<endl;
        cout<<m<<endl;
        Mat lap ,uplap;
        if(m=Gauss.size()-1){
            Mat downlap;
            pyrDown(Gauss[m],downlap);
            pyrUp(downlap,uplap);
            // cout<<Gauss[m].size()<<"_____"<<uplap.size()<<endl;
            resize(uplap,uplap,Gauss[m].size());
            lap=Gauss[m]-uplap;
            Lap.push_back(lap);
        }
        pyrUp(Gauss[m],uplap);
        // cout<<Gauss[m-1].size()<<"_____"<<uplap.size()<<endl; 
        resize(uplap,uplap,Gauss[m-1].size());
        // cout<<Gauss[m-1].size()<<"_____"<<uplap.size()<<endl; 
        lap = Gauss[m-1]-uplap;
        // cout<<"one"<<endl;
        Lap.push_back(lap);  
        cout<<"完成"<<endl;
    }
    cout<<"one"<<endl;
    for(int j=0;j<level+1;j++){
        string name=to_string(j);
        imshow("q"+name,Gauss[j]);
     
    }
    for(int p=level-1;p>=0;p--){
        string name1=to_string(p);
        imshow("p"+name1,Lap[p]);
    }
}

Point prePoint;
Point one;
Point two;
Point three;
Mat temp;
void mouse(int event,int x, int y,int flags,void* userdata){
    Mat image=*((Mat*)(userdata));
    Mat src1;
    src1=image.clone();
    // image.copyTo(src1);
    if(event==EVENT_LBUTTONDOWN){ 
        one.x=x;
        one.y=y;
        cout<<"初始位置x"<<one.x<<"初始位置y"<<one.y<<endl;
    }
    if(event==EVENT_LBUTTONUP){
        two.x=x;
        two.y=y;
        cout<<"末位置x"<<two.x<<"末始位置y"<<two.y<<endl;
        Rect rect(one,two);
        rectangle(image,rect,Scalar(0,0,255),2,8,0);
        imshow("鼠标窗口",image);
        
    }
    else if( event==EVENT_MOUSEMOVE){
        if(one.x>0 && one.y>0){
            three.x=x;
            three.y=y;
            Rect rect1(one,three);
            temp.copyTo(image);
            rectangle(image,rect1,Scalar(0,0,255),2,8,0);
            imshow("鼠标窗口",image);
        }
    }
}
void Quickdemo::mouserespone(Mat &image){
    image.copyTo(temp);
    imshow("鼠标窗口",image);
    setMouseCallback("鼠标窗口",mouse,(void*)(&image));
    waitKey(0);
    destroyAllWindows();

   
}
// Point prePoint;
// Point one;
// Point two;
// void mouse(int event,int x, int y,int flags,void* userdata){
//     Mat image=*((Mat*)(userdata));
//     if(event=EVENT_LBUTTONDOWN){
//         one=Point(x,y);
//     }
//     if(event=EVENT_LBUTTONUP){
//         two=Point(x,y);
//         rectangle(image,one,two,-1,LINE_8);
        
//     }
// //     if(){
        
//     }
//     if(){
        
//     }
// }
















