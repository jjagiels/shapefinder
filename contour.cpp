#include "contour.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>

using namespace std;
using namespace cv;

void contour::drawContours(Mat origImage, Mat binaryImage, unsigned int shape, string outputName, unsigned int blue, unsigned int green, unsigned int red){
    /* Resource Used: https://docs.opencv.org/3.2.0/df/d0d/tutorial_find_contours.html */
    Mat cannyOut;
    
    vector< vector<Point> > contours;
    vector<Point> approx;
    vector<Vec4i> hierarchy;
    
    Canny( binaryImage, cannyOut, 100, 200, 3 );
    
    findContours(cannyOut, contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));
    
    cv::Scalar color = cv::Scalar(blue,green,red);
    
    for(size_t i = 0; i< contours.size(); i++){
        approxPolyDP(Mat(contours.at(i)), approx, arcLength(Mat(contours.at(i)), true)*0.02, true);
        
        if(shape == 0){ //This is for all shapes in photo that are identifiable.
            drawContours(origImage, contours, (int)i, color, 2, 8, hierarchy, 0, Point(0,0));
        }
        else if(approx.size() == shape){ // This is for specific to how many shapes.
            drawContours(origImage, contours, (int)i, color, 2, 8, hierarchy, 0, Point(0,0));
        }
        if (shape == 99){
            double area = cv::contourArea(contours[i]);
			cv::Rect r = cv::boundingRect(contours[i]);
			int radius = r.width / 2;

			if (abs(1 - ((double)r.width / r.height)) <= 0.2 && abs(1 - (area / (CV_PI * pow(radius, 2)))) <= 0.03){
			    drawContours(origImage, contours, (int)i, color, 2, 8, hierarchy, 0, Point(0,0));
			}
        }
    }
    
    imwrite(outputName,origImage);
}