#include "imageInput.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace cv;


/*Read the image passed in from the command line, any color data is preserved in order to display later*/
/*Resource used: http://opencv-tutorials-hub.blogspot.com/2015/06/rgb-to-grayscale-conversion-opencv-code-color-image-2-gray-convert-cvloadimagegrayscale-arjun-toshniwal.html */
Mat imageInput::input(char* input, int debugFlag){
    Mat image;
    image = imread(input,CV_LOAD_IMAGE_COLOR);
    //If image not found  
    if (!image.data) 
        {  
            cout << "No image data \n";  
            exit(1); 
        }
    /*Convert to grayscale for easier manipulation*/
    /*Resource used: http://answers.opencv.org/question/42204/converting-image-from-grayscale-to-binary/ */
    Mat img_gray;
    cvtColor(image, img_gray, CV_BGR2GRAY);
    /*Convert to binary black/white*/
    Mat thr;
    threshold(img_gray, thr, 230, 255, THRESH_BINARY);
    
    /*Save the images for viewing if debug flag set*/
    if(debugFlag){
        imwrite("./gray.png",img_gray);
        imwrite("./binary.png",thr);
    }
    return thr;
}

/*Same function as above, but overloaded to have the debugFlag default to 0*/
Mat imageInput::input(char* input){
    Mat image;
    image = imread(input,CV_LOAD_IMAGE_COLOR);
    //If image not found  
    if (!image.data) 
        {  
            cout << "No image data \n";  
            exit(1); 
        }
    /*Convert to grayscale for easier manipulation*/
    /*Resource used: http://answers.opencv.org/question/42204/converting-image-from-grayscale-to-binary/ */
    Mat img_gray;
    cvtColor(image, img_gray, CV_BGR2GRAY);
    /*Convert to binary black/white*/
    Mat thr;
    threshold(img_gray, thr, 230, 255, THRESH_BINARY);
    int x;
    return thr;
}