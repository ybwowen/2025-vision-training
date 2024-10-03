#include <opencv2/opencv.hpp>

// 函数声明
cv::Mat preprocessImage(const cv::Mat& src);
std::vector<cv::Point> findLargestContour(const cv::Mat& binary);
cv::Mat extractAppleBoundary(const cv::Mat& binary, const std::vector<cv::Point>& contour);
cv::Mat overlayBoundaryAndRectOnOriginal(const cv::Mat& original, const cv::Mat& boundary, const std::vector<cv::Point>& contour);

int main(int argc, char** argv)
{
    cv::Mat src = cv::imread("../apple.png");

    cv::Mat preprocessed = preprocessImage(src);
    std::vector<cv::Point> largestContour = findLargestContour(preprocessed);
    cv::Mat boundary = extractAppleBoundary(preprocessed, largestContour);
    cv::Mat result = overlayBoundaryAndRectOnOriginal(src, boundary, largestContour);

    cv::imshow("Result", result);
    cv::waitKey(0);

    return 0;
}

cv::Mat preprocessImage(const cv::Mat& src)
{
    cv::Mat channels[3];
    cv::split(src, channels);
    
    cv::Mat red_sub_blue = 2 * channels[2] - channels[0] - channels[1];
    
    cv::Mat normalized;
    cv::normalize(red_sub_blue, normalized, 0., 255., cv::NORM_MINMAX);
    // cv::imshow("Normalized", normalized);

    cv::Mat binary;
    cv::threshold(normalized, binary, 115, 255, cv::THRESH_BINARY);
    // cv::imshow("Binary", binary);

    cv::Mat opened;
    cv::morphologyEx(binary, opened, cv::MORPH_OPEN, cv::Mat(), cv::Point(-1, -1), 2);
    // cv::imshow("Opened", opened);

    return opened;
}

std::vector<cv::Point> findLargestContour(const cv::Mat& binary)
{
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binary, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    
    if (contours.empty()) {
        return std::vector<cv::Point>();
    }

    return *std::max_element(contours.begin(), contours.end(),
        [](const std::vector<cv::Point>& c1, const std::vector<cv::Point>& c2) {
            return cv::contourArea(c1) < cv::contourArea(c2);
        });
}

cv::Mat extractAppleBoundary(const cv::Mat& binary, const std::vector<cv::Point>& contour)
{
    cv::Mat contourMat = cv::Mat::zeros(binary.size(), CV_8UC1);
    cv::drawContours(contourMat, std::vector<std::vector<cv::Point>>{contour}, 0, cv::Scalar(255), cv::FILLED);
    // cv::imshow("Contour", contourMat);

    cv::Mat opened;
    cv::morphologyEx(contourMat, opened, cv::MORPH_OPEN, cv::Mat(), cv::Point(-1, -1), 4);
    // cv::imshow("Opened", opened);

    cv::Mat gradient;
    // cv::morphologyEx(contourMat, gradient, cv::MORPH_GRADIENT, cv::Mat(), cv::Point(-1, -1), 1);
    cv::morphologyEx(opened, gradient, cv::MORPH_GRADIENT, cv::Mat(), cv::Point(-1, -1), 1);
    // cv::imshow("Gradient", gradient);

    return gradient;
}

cv::Mat overlayBoundaryAndRectOnOriginal(const cv::Mat& original, const cv::Mat& boundary, const std::vector<cv::Point>& contour)
{
    cv::Mat result = original.clone();
    
    cv::Mat colorBoundary;
    cv::cvtColor(boundary, colorBoundary, cv::COLOR_GRAY2BGR);
    cv::addWeighted(result, 1.0, colorBoundary, 0.5, 0, result);

    if (!contour.empty()) {
        cv::Rect boundingRect = cv::boundingRect(contour);
        cv::rectangle(result, boundingRect, cv::Scalar(255, 0, 0), 2);
    }
    
    return result;
}