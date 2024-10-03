#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <random>

using namespace cv;
using namespace std;

// 提取图像中所有非黑色点，作为目标轮廓点
vector<Point> extractNonBlackPoints(const Mat& img) {
    vector<Point> points;
    for (int y = 0; y < img.rows; ++y) {
        for (int x = 0; x < img.cols; ++x) {
            if (img.at<uchar>(y, x) > 0) {  // 只选择非黑色像素
                points.emplace_back(Point(x, y));
            }
        }
    }
    return points;
}

// 生成全屏的随机白色散点
vector<Point2f> generateRandomPoints(int width, int height, int numPoints) {
    vector<Point2f> points;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> disX(0, width);
    uniform_real_distribution<> disY(0, height);

    for (int i = 0; i < numPoints; ++i) {
        points.emplace_back(Point2f(disX(gen), disY(gen)));
    }
    return points;
}

int main() {
    // 读取目标图像 (轮廓)
    Mat img = imread("../projected_image.png", IMREAD_GRAYSCALE);
    if (img.empty()) {
        cout << "无法打开图像文件" << endl;
        return -1;
    }

    // 获取图像大小
    int width = img.cols;
    int height = img.rows;

    // 提取轮廓中的所有非黑色点
    vector<Point> targetPoints = extractNonBlackPoints(img);

    // 生成随机的初始散点
    vector<Point2f> randomPoints = generateRandomPoints(width, height, targetPoints.size());

    // 初始化视频输出
    VideoWriter video("output_video.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, Size(width, height));

    // 逐渐移动随机点到目标点，模拟汇聚效果
    int totalFrames = 100;  // 总帧数
    for (int frameIdx = 0; frameIdx < totalFrames; ++frameIdx) {
        // 初始化图像 (黑色背景)
        Mat frame(height, width, CV_8UC3, Scalar(0, 0, 0));

        // 逐帧将每个随机点向目标点移动
        for (size_t i = 0; i < randomPoints.size(); ++i) {
            // 计算当前帧点的位置，逐渐靠近目标点
            float alpha = (float)frameIdx / totalFrames;  // 插值系数
            float x = targetPoints[i].x - randomPoints[i].x;
            float y = targetPoints[i].y - randomPoints[i].y;
            Point2f diff;
            diff.x = x; diff.y = y;
            Point2f currentPoint = randomPoints[i] + alpha * diff;

            // 绘制点
            circle(frame, currentPoint, 2, Scalar(255, 255, 255), -1);
        }
        // 保存当前帧到视频
        video.write(frame);
    }

     int holdFrames = 60;  
    Mat finalFrame(height, width, CV_8UC3, Scalar(0, 0, 0));
    for (size_t i = 0; i < targetPoints.size(); ++i) {
        circle(finalFrame, targetPoints[i], 2, Scalar(255, 255, 255), -1);  // 最终轮廓
    }

    // 保存多帧静止的最终画面
    for (int i = 0; i < holdFrames; ++i) {
        video.write(finalFrame);
    }

    video.release();
    cout << "视频生成完成" << endl;

    return 0;
}
