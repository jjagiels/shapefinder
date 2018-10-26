#ifndef IMAGEINPUT
#define IMAGEINPUT
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace imageInput
{
    cv::Mat input(char*, int);
    cv::Mat input(char*);
}
#endif