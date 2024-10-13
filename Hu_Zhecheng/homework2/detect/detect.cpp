#include <iostream>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/Dense>
#include <opencv2/videoio.hpp>
#include <utility>
#include <vector>

using namespace std;
using namespace cv;
using namespace Eigen;

int main(){
    VideoCapture capture;
    VideoWriter writer;
    Mat frame;
    frame = capture.open("../armor.mp4");
    writer.open("../detect.mp4", VideoWriter::fourcc('m', 'p', '4', 'v'), capture.get(CAP_PROP_FPS), Size(capture.get(CAP_PROP_FRAME_WIDTH),capture.get(CAP_PROP_FRAME_HEIGHT)), true);
    
    Mat gray,th,mor;
    vector< vector<Point> > contours;
    vector< Vec4i > hierarchy;
    while (capture.read(frame)){
        //选出灯条轮廓
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        threshold(gray, th, 220, 255, THRESH_BINARY);
        morphologyEx(th, mor, MORPH_OPEN, getStructuringElement(MORPH_RECT, Size(7, 7)));
        findContours(th,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
        
        vector<pair<Point,Point>> corners;
        vector<Point> centers;
        for (int index{0};index>=0; index = hierarchy[index][0]){
            Rect bRect = boundingRect(contours[index]);
            RotatedRect rRect = minAreaRect(contours[index]);

            if (bRect.height / bRect.width > 1 && rRect.size.height*rRect.size.width > 100){ //简单做个筛选
                vector<Point2f> points;
                vector<Point> corner;
                rRect.points(points);
                for (int i{0};i< points.size();i++){
                    if (abs(points[i].y-points[i-1].y) < abs(points[i-1].y-points[i-2].y) && abs(points[i].y-points[i-1].y)<33){ //取出四角
                        corner.push_back((points[i]+points[i-1])/2);
                    }
                    if (corner.size() == 2){
                        corners.push_back(pair(corner[0],corner[1]));
                        centers.push_back((corner[0]+corner[1])/2);
                        corner.clear();
                    }
                }
            }
        }

        for (int j{0};j< corners.size();j++){
            if (abs(centers[j].y-centers[j-1].y) <=15 &&  abs(centers[j].x-centers[j-1].x) <=100){ //判断出隶属于同一装甲板的角点
                vector<Point> armorPoints;
                if (abs(corners[j].first.y - corners[j-1].first.y)<=5){ //按照顺序构建四边形
                    armorPoints = {corners[j].first,corners[j].second,corners[j-1].second,corners[j-1].first};
                }
                else {
                    armorPoints = {corners[j].first,corners[j].second,corners[j-1].first,corners[j-1].second};
                }
                
                circle(frame, (centers[j]+centers[j-1])/2, 5, Scalar(0,0,255),5);
                polylines(frame,armorPoints,true,Scalar(255,0,0),5);
            }
        }
        
        writer.write(frame);
    }
}
