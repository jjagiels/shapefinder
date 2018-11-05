#ifndef CONTOUR
#define CONTOUR
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>

namespace contour
{
    void drawContours(cv::Mat, cv::Mat, unsigned int, std::string, unsigned int, unsigned int, unsigned int);
}
#endif