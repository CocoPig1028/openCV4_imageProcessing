//
//  main.cpp
//  openCV_07
//
//  Created by Daeyeong Park on 3/19/24.
//

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void blurring_mean();
void blurring_gausian();

int main() {
    blurring_mean();
    blurring_gausian();
    
    return 0;
}

void blurring_mean() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_07/openCV_07/rose.bmp", IMREAD_GRAYSCALE);
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return;
    }
    
    imshow("src", src);
    
    Mat dst;
    for (int ksize = 3; ksize <= 7; ksize += 2) {
        blur(src, dst, Size(ksize, ksize));
        //blur(src, dst, 블러링 커널 크기, anchor, borderType)
        
//        String desc = format("Mean: %dx%d", ksize, ksize);
        std::string desc = "Mean: " + std::to_string(ksize) + "x" + std::to_string(ksize);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
        
        imshow("dst", dst);
        waitKey();
    }
    
    destroyAllWindows();
}

void blurring_gausian() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_07/openCV_07/rose.bmp", IMREAD_GRAYSCALE);
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return;
    }
    
    imshow("src", src);
    
    Mat dst;
    for (int sigma = 1; sigma <= 5; sigma++) {
        GaussianBlur(src, dst, Size(), (double)sigma);
        // GaussianBlur(src, dst, ksize, sigmaX, sigmaY, borderType)
        // getGaussianKernel(ksize, sigma, ktype)
        
        std::string text = "Sigma: " + std::to_string(sigma);
        putText(dst, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
        
        imshow("dst", dst);
        waitKey();
    }
    
    destroyAllWindows();
}
