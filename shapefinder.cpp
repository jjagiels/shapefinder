#include "imageInput.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>


using namespace std;
using namespace cv;


int main( int argc, char* argv[] ) {
    /* Unnecessary prints, uncomment if needed later 
    int counter; 
    cout << "Program Name Is: " << argv[0] << endl; 
    if(argc==1) 
        cout << "\nNo Extra Command Line Argument Passed Other Than Program Name" << endl; 
    if(argc>=2) 
    { 
        cout << "\nNumber Of Arguments Passed: " << argc << endl; 
        cout << "\n----Following Are The Command Line Arguments Passed----" << endl; 
        for(counter = 0; counter < argc; counter++) 
            cout << "\nargv[" << counter << "]: " << argv[counter] << endl; 
    }
    */
    Mat image;
    /*
    * TODO: Make sure the input to this function is a correct, non-empty, and non malicious image file, argv[1] is too trusting, and requires the user to input the image first. This is not ideal
    *       Also, make sure to replace the second argument (debug flag) with something else, ideally a flag from the command line
    */
    image = imageInput::input(argv[1], 1);
    return 0;
}