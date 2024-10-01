#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;


//NOTFINISHED


// 函数：添加随机抖动
void jitterPoints(std::vector<cv::Point3f>& points, float maxJitter) {
    for (auto& point : points) {
        point.z += (rand() % 100) / 100.0f * maxJitter - maxJitter / 2.0f;
    }
}

// 函数：模拟相机移动
void simulateCameraMovement(std::vector<cv::Point3f>& points, cv::VideoWriter& videoWriter) {
    // 定义视频的FPS和大小
    int fps = 30;
    int frameCount = 360; // 总帧数
    cv::Mat image = cv::Mat::zeros(480, 640, CV_8UC3);

    for (int i = 0; i < frameCount; ++i) {
        float angle = i * CV_PI / 180.0f;
        // 这里只是简单地旋转X轴
        for (auto& point : points) {
            float zNew = point.z * cos(angle) - point.y * sin(angle);
            float yNew = point.z * sin(angle) + point.y * cos(angle);
            point.z = zNew;
            point.y = yNew;
        }
        // 重新绘制图像
        for (const auto& point : points) {
            cv::circle(image, cv::Point(point.x, point.y), 3, cv::Scalar(0, 255, 0), -1);
        }
        // 写入视频
        videoWriter.write(image);
    }
}

int main() {
    // 读取图像
    cv::Mat image = cv::imread("../img.png", cv::IMREAD_GRAYSCALE);
    if (image.empty()) {
        std::cout << "Image load failed." << std::endl;
        return -1;
    }

    // 提取轮廓
    std::vector<std::vector<cv::Point> > contours;
    cv::findContours(image, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // 存储轮廓点
    std::vector<cv::Point3f> contourPoints;
    for (const auto& contour : contours[0]) {
        contourPoints.push_back(cv::Point3f(contour.x, contour.y, 0.0f));
        cout<<"i"<<endl;
    }

    // 抖动Z值
    jitterPoints(contourPoints, 10.0f);

    // 创建视频写入对象
    cv::VideoWriter videoWriter;
    videoWriter.open("output_video.avi", cv::VideoWriter::fourcc('M','J','P','G'), 30, image.size());

    // 模拟相机移动并写入视频
    simulateCameraMovement(contourPoints, videoWriter);

    // 释放视频写入对象
    videoWriter.release();

    return 0;
}
