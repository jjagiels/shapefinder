#include "imageInput.h"
#include "contour.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <sstream>

using namespace std;
using namespace cv;


int main( int argc, char* argv[] ) {
    /*
    * TODO: Make sure the input to this function is a correct, non-empty, and non malicious image file, argv[1] is too trusting, 
    *       and requires the user to input the image first. This is not ideal. Also, make sure to replace the second argument 
    *       (debug flag) with something else, ideally a flag from the command line.
    */
    unsigned int sides;
    unsigned int red;
    unsigned int blue;
    unsigned int green;
    string shape = "rectangle";
    string color = "ff00ff";
    string input = "";
    string output = "output.ppm";
    for(int i = 1; i < argc ;i++){
        if(strcmp(argv[i],"-s") == 0 || strcmp(argv[i],"--shape") == 0){
            shape = argv[i+1];
            i++;
        }
        else if(strcmp(argv[i],"-c") == 0 || strcmp(argv[i],"--color") == 0){
            color = argv[i+1];
            i++;
        }
        else if(strcmp(argv[i],"-o") == 0){
            output = argv[i+1];
            i++;
        }
        else if(input == ""){
            input = argv[i];
        }
        else{
            cout << "Incorrect arguments, try again." << endl;
            exit(0);
        }
    }
    
    if(fopen(input.c_str(), "r") == NULL){
        cout << "Incorrect or no file input." << endl;
        exit(0);
    }
    transform(shape.begin(), shape.end(), shape.begin(), ::tolower);
    
    stringstream ss(color);
    int num;
    ss >> hex >> num;
    
    red = num / 0x10000;
    green = (num / 0x100) % 0x100;
    blue = num % 0x100;

    if(shape == "triangle"){
        sides = 3;
    }
    else if(shape == "rectangle"){
        sides = 4;
    }
    else if(shape == "pentagon"){
        sides = 5;
    }
    else if(shape == "hexagon"){
        sides = 6;
    }
    else if(shape == "polygon"){
        sides = 20;
    }
    else if(shape == "circle"){
        sides = 99;
    }
    else if(shape == "all"){
        sides = 0;
    }
    else{
        cout << "Invalid/Unsupported shape selected, try again." << endl;
        exit(0);
    }
    
    Mat origImage;
    Mat binaryImage;
    
    origImage = imread(input, CV_LOAD_IMAGE_COLOR);
    binaryImage = imageInput::input(input, 0);
    contour::drawContours(origImage, binaryImage, sides, output, blue, green, red);
    
    origImage.release();
    binaryImage.release();
    return 0;
}