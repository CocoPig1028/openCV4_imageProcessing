//
//  main.cpp
//  openCV_06
//
//  Created by Daeyeong Park on 3/19/24.
//

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void filter_embossing();

int main() {
    filter_embossing();
    
    return 0;
}

void filter_embossing() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_06/openCV_06/rose.bmp", IMREAD_GRAYSCALE);
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return;
    }
    
    float data[] = { -1, -1, 0, -1, 0, 1, 0, 1, 1};
    Mat emboss(3, 3, CV_32FC1, data);
    
    Mat dst;
    filter2D(src, dst, -1, emboss, Point(-1, -1), 128);
    
    imshow("src", src);
    imshow("dst", dst);
    
    waitKey();
    
    destroyAllWindows();
}
