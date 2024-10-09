#include <iostream>

#include <fstream>
#include <cassert>
#include <vector>
#include <string>

#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>


// 效果不是很好，大体上可以实现了


// 读取视频文件
std::vector<cv::Mat> readfile(const std::string& filename) 
{
    cv::VideoCapture file(filename);
    cv::Mat frame;  
    std::vector<cv::Mat> frames;
    
    if (!file.isOpened())
    {
        std::cerr << "Error: file not found" << std::endl;
        return frames;
    }

    int frame_count = 0;
    while (true)
    {
        file >> frame;
        if (frame.empty())
        {
            break;
        }
        frames.push_back(frame.clone()); // 使用 clone() 确保每一帧都是独立的
        frame_count++;
        std::cout << "Read frame " << frame_count << std::endl;
    }

    file.release();
    std::cout << "Total frames read: " << frame_count << std::endl;
    return frames;
}

int main()
{
    auto scenes = readfile("../armor.mp4");

    for (auto& image : scenes)
    {
        assert(image.channels() == 3);

        // 转换为HSV颜色空间
        cv::Mat hsv;
        cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV);

        // 橙色的HSV范围
        cv::Scalar lower_orange(5, 100, 100);
        cv::Scalar upper_orange(15, 255, 255);

        // 颜色过滤
        cv::Mat mask;
        cv::inRange(hsv, lower_orange, upper_orange, mask);

        // 轮廓检测
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(mask, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

        // 筛选灯条
        std::vector<cv::Rect> bounding_boxes;
        for (size_t i = 0; i < contours.size(); i++) 
        {
            cv::Rect bounding_box = cv::boundingRect(contours[i]);
            double area = cv::contourArea(contours[i]);
            double aspect_ratio = static_cast<double>(bounding_box.height) / bounding_box.width;
            if (aspect_ratio > 2.0 ) 
            {   // 只考虑长宽比大于2的轮廓
                bounding_boxes.push_back(bounding_box);
                // 绘制筛选出的灯条框
                cv::rectangle(image, bounding_box, cv::Scalar(0, 255, 0), 2);
            }
        }

        // 标记相邻的灯条
        for (size_t i = 0; i < bounding_boxes.size(); i++) 
        {
            for (size_t j = i + 1; j < bounding_boxes.size(); j++) 
            {
                cv::Rect box1 = bounding_boxes[i];
                cv::Rect box2 = bounding_boxes[j];
                int center_x1 = box1.x + box1.width / 2;
                int center_x2 = box2.x + box2.width / 2;
                int center_y1 = box1.y + box1.height / 2;
                int center_y2 = box2.y + box2.height / 2;

                // 判断两个轮廓是否相邻
                if (std::abs(center_x1 - center_x2) < 50 && std::abs(center_y1 - center_y2) < 50) 
                {
                    // 绘制框
                    cv::rectangle(image, box1, cv::Scalar(0, 255, 0), 2);
                    cv::rectangle(image, box2, cv::Scalar(0, 255, 0), 2);

                    // 绘制包含两个轮廓的框
                    int x = std::min(box1.x, box2.x);
                    int y = std::min(box1.y, box2.y);
                    int width = std::max(box1.x + box1.width, box2.x + box2.width) - x;
                    int height = std::max(box1.y + box1.height, box2.y + box2.height) - y;
                    cv::rectangle(image, cv::Rect(x, y, width, height), cv::Scalar(255, 0, 0), 2);
                }
            }
        }

        // 调整图像大小
        cv::Mat resized_image;
        cv::resize(image, resized_image, cv::Size(800, 600)); 

        cv::imshow("Detected", resized_image);
        int key = cv::waitKey(20);
        if (key >= 0) 
        {
            std::cout << "Key pressed: " << key << std::endl;
            break;
        }
    }

    cv::destroyAllWindows();
    return 0;
}