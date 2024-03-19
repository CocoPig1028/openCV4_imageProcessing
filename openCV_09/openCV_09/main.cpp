//
//  main.cpp
//  openCV_09
//
//  Created by Daeyeong Park on 3/19/24.
//

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void noise_gaussian();
void filter_bilateral();
void filter_median();

int main() {
    noise_gaussian();
    filter_bilateral();
    filter_median();
    
    return 0;
}

void noise_gaussian() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_09/openCV_09/lenna.bmp", IMREAD_GRAYSCALE);
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return;
    }
    
    imshow("src", src);
    
    for(int stddev = 10; stddev <= 30; stddev += 10) {
        Mat noise(src.size(), CV_32SC1);
        randn(noise, 0, stddev);
        
        Mat dst;
        add(src, noise, dst, Mat(), CV_8U);
        
        std::string desc = "stddev = " + std::to_string(stddev);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
        
        imshow("dst", dst);
        waitKey();
    }
    
    destroyAllWindows();
}

void filter_bilateral() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_09/openCV_09/lenna.bmp", IMREAD_GRAYSCALE);
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return;
    }
    
    Mat noise(src.size(), CV_32SC1);
    randn(noise, 0, 5);
    add(src, noise, src, Mat(), CV_8U);
    
    Mat dst1;
    GaussianBlur(src, dst1, Size(), 5);
    
    Mat dst2;
    bilateralFilter(src, dst2, -1, 10, 5);
    
    imshow("src", src);
    imshow("dst1", dst1);
    imshow("dst2", dst2);
    
    waitKey();
    destroyAllWindows();
}

void filter_median() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_09/openCV_09/lenna.bmp", IMREAD_GRAYSCALE);
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return;
    }
    
    int num = (int)(src.total() * 0.1);
    for (int i = 0; i < num; i++) { // 랜덤한 난수로 위치를 추출하여 소금 후추 잡음 생성
        int x = rand() % src.cols;
        int y = rand() % src.rows;
        src.at<uchar>(y, x) = (i % 2) * 255;
    }
    
    Mat dst1;
    GaussianBlur(src, dst1, Size(), 1);
    
    Mat dst2;
    medianBlur(src, dst2, 3);
    // medianBlur(src, dst, ksize);
    
    imshow("src", src);
    imshow("dst1", dst1);
    imshow("dst2", dst2);
    
    waitKey();
    
    destroyAllWindows();
}
