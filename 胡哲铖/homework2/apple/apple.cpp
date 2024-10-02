#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

int main(){
    Mat src = imread("../apple.png");
    
    //Laplace图像增强
    Mat dst1(src.size(), CV_32FC3),dst2(src.size(), CV_32FC3);
    Mat kernel = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(src, dst1, src.depth(), kernel);


    Mat hsv1,hsv2,hsvPart1,hsvPart2,hsvPart3,hsvPart4;
    
    //对红黄两种颜色进行不同的二值化操作
    cvtColor(dst1,hsv1,COLOR_BGR2HSV);
    inRange(hsv1, Scalar(0, 43, 46), Scalar(15, 255, 255), hsvPart1);
    inRange(hsv1, Scalar(156, 43, 46), Scalar(180, 255, 255), hsvPart2);
    
    cvtColor(src,hsv2,COLOR_BGR2HSV);
    inRange(hsv2, Scalar(10, 200, 80), Scalar(20, 255, 120), hsvPart3);
    inRange(hsv2, Scalar(20, 200, 80), Scalar(26, 255, 120), hsvPart4);
    Mat onesMat = Mat::ones(Size(src.cols, src.rows), CV_8UC1);
    Mat hsvResult1 = 255 * (onesMat - (onesMat - hsvPart1 /255).mul(onesMat - hsvPart2 / 255));
    // 对1、2的结果取并集
    Mat hsvResult2 = 255 * (onesMat - (onesMat - hsvPart3 /255).mul(onesMat - hsvPart4 / 255));
    // 对3、4的结果取并集

    //分别进行形态学操作以符合两种颜色的特点
    Mat mor1;
    morphologyEx(hsvResult1, mor1, MORPH_OPEN, getStructuringElement(MORPH_RECT, Size(7,7)));
    morphologyEx(mor1, mor1, MORPH_CLOSE, getStructuringElement(MORPH_CROSS, Size(7,7)));
    Mat mor2;
    morphologyEx(hsvResult2, mor2, MORPH_OPEN, getStructuringElement(MORPH_RECT, Size(3,3)));
    morphologyEx(mor2, mor2, MORPH_CLOSE, getStructuringElement(MORPH_RECT, Size(5,5)));
    cv::Mat res = 255 * (onesMat - (onesMat - mor1 /255).mul(onesMat - mor2 / 255));
    // 对结果取并集
    
    // 画出轮廓
    vector< vector<cv::Point> > contour;
    vector< Vec4i > hierarchy;
    findContours(res, contour, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);
    int index = 0;
    for (; index>=0; index = hierarchy[index][0]) {
        double lenth = arcLength(contour[index], true);
        if (lenth >= 200) {
            drawContours(src, contour, index, Scalar(255,255,255),  1, 8, hierarchy);
            rectangle(src, boundingRect(contour[index]),Scalar(255,255,255),2);
        }        
    }
    
    imwrite("../apple_detected.png", src);
    return 0;
}