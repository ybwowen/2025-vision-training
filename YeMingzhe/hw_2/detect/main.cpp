#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
#include <iostream>

int main() {
    cv::VideoCapture cap("/home/ymz/Codes/2025-vision-training/YeMingzhe/hw_2/detect/armor.mp4");
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open video." << std::endl;
        return -1;
    }

    int frameWidth = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int frameHeight = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(cv::CAP_PROP_FPS);

    cv::VideoWriter writer;
    writer.open("/home/ymz/Codes/2025-vision-training/YeMingzhe/hw_2/detect/output.mp4", 
                 cv::VideoWriter::fourcc('M','J','P','G'), 
                 fps, 
                 cv::Size(frameWidth, frameHeight), 
                 true);

    if (!writer.isOpened()) {
        std::cerr << "Error: Could not open the output video file." << std::endl;
        return -1;
    }

    cv::Mat frame, gray, mask;
    while (true) {
        cap >> frame;
        if (frame.empty()) break; 

        // 转换为灰度图像
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        // 使用阈值过滤亮度较高的点
        cv::threshold(gray, mask, 150, 255, cv::THRESH_BINARY);

        // 寻找轮廓
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        std::vector<cv::Rect> validBoxes;

        for (const auto& contour : contours) {
            // 获取轮廓的边界框
            cv::Rect boundingBox = cv::boundingRect(contour);

            // 计算宽高差
            int width = boundingBox.width;
            int height = boundingBox.height;

            // 检查高度差是否大于1.8倍的宽度
            if (height > 1.8 * width) {
                validBoxes.push_back(boundingBox); 
                cv::rectangle(frame, boundingBox, cv::Scalar(0, 0, 255), 2);
            }
        }

        // 合并满足条件的区域
        for (size_t i = 0; i < validBoxes.size(); ++i) {
            for (size_t j = i + 1; j < validBoxes.size(); ++j) {
                // 检查两个区域的水平差距是否小于自身高度差的两倍
                if (abs(validBoxes[i].x - validBoxes[j].x) < 3 * abs(validBoxes[i].height) && 
                    abs(validBoxes[i].y - validBoxes[j].y) < 0.5 * abs(validBoxes[i].height)) {
                    // 计算合并后的矩形区域
                    int x_min = std::min(validBoxes[i].x, validBoxes[j].x);
                    int y_min = std::min(validBoxes[i].y, validBoxes[j].y);
                    int x_max = std::max(validBoxes[i].x + validBoxes[i].width, validBoxes[j].x + validBoxes[j].width);
                    int y_max = std::max(validBoxes[i].y + validBoxes[i].height, validBoxes[j].y + validBoxes[j].height);

                    cv::Rect mergedBox(x_min, y_min, x_max - x_min, y_max - y_min);

                    // 用绿色标记合并后的区域
                    cv::rectangle(frame, mergedBox, cv::Scalar(0, 255, 0), 2);

                    // 连接对角线
                    cv::line(frame, mergedBox.tl(), mergedBox.br(), cv::Scalar(255, 0, 0), 2);
                    cv::line(frame, cv::Point(mergedBox.x + mergedBox.width, mergedBox.y), 
                             cv::Point(mergedBox.x, mergedBox.y + mergedBox.height), cv::Scalar(255, 0, 0), 2);

                    // 计算对角线的中点
                    cv::Point midPoint((mergedBox.x + mergedBox.x + mergedBox.width) / 2,
                                       (mergedBox.y + mergedBox.y + mergedBox.height) / 2);
                    
                    // 用红色标出中点
                    cv::circle(frame, midPoint, 5, cv::Scalar(0, 0, 255), -1); 
                }
            }
        }

        writer.write(frame);

        cv::imshow("Processed Frame", frame);  
        if (cv::waitKey(30) >= 0) break; 
    }

    cap.release();
    writer.release(); 
    cv::destroyAllWindows();
    return 0;
}

