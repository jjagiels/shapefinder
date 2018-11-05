#ifndef IMAGEINPUT
#define IMAGEINPUT
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>

namespace imageInput
{
    cv::Mat input(std::string, int);
    cv::Mat input(std::string);
}
#endif