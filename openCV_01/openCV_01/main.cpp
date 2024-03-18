//
//  main.cpp
//  openCV_01
//
//  Created by Daeyeong Park on 3/13/24.
//

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void brightness1();
void brightness2();
void brightness3();
void brightness4();
void on_brightness(int pos, void* userdata);

int main(void) {
    brightness1();
    brightness2();
    brightness3();
    brightness4();
    
    return 0;
}

void brightness1() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_01/openCV_01/lenna.bmp", IMREAD_GRAYSCALE);
    // GrayScale로 이미지 호출
    
    if (src.empty()) { // 이미지 유효성 검사
        cerr << "Image load failed" << endl;
        return;
    }
    
    Mat dst = src + 100; // 밝기 100 증가
    
    imshow("src", src);
    imshow("dst", dst);
    waitKey();
    
    destroyAllWindows();
}

void brightness2() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_01/openCV_01/lenna.bmp", IMREAD_GRAYSCALE);
    
    if (src.empty()) { // 이미지 유효성 검사
        cerr << "Image load failed" << endl;
        return;
    }
    
    Mat dst(src.rows, src.cols, src.type());
    // 크기와 타입을 지정하여야 오류를 피할 수 있음
    
//    for (int i = 0; i < src.rows; i++) {
//        for (int j = 0; j < src.cols; j++) {
//            dst.at<uchar>(i, j) = src.at<uchar>(i, j) + 100;
//            //.at을 이용하여 문자열 호출
//        }
//    }
    // 이는 포화연산을 생각하지 않았기 때문에 이미지가 이상함
    
    // 포화연산을 적용한 반복문
    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            int v = src.at<uchar>(i, j) + 100;
            dst.at<uchar>(i, j) = v > 255 ? 255 : v < 0 ? 0 : v;
            // v > 255 -> 255, v < 0 -> 0 그렇지 않으면 v를 대입
        }
    }
    
    imshow("src", src);
    imshow("dst", dst);
    waitKey();
    
    destroyAllWindows();
}

void brightness3() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_01/openCV_01/lenna.bmp", IMREAD_GRAYSCALE);
    // GrayScale로 이미지 호출
    
    if (src.empty()) { // 이미지 유효성 검사
        cerr << "Image load failed" << endl;
        return;
    }
    
    Mat dst(src.rows, src.cols, src.type());
    
    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            dst.at<uchar>(i, j) = saturate_cast<uchar>(src.at<uchar>(i, j) + 100);
            //.at을 이용하여 문자열 호출
        }
    }
    
    imshow("src", src);
    imshow("dst", dst);
    waitKey();
    
    destroyAllWindows();
}

void brightness4() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_01/openCV_01/lenna.bmp", IMREAD_GRAYSCALE);
    // GrayScale로 이미지 호출
    
    if (src.empty()) { // 이미지 유효성 검사
        cerr << "Image load failed" << endl;
        return;
    }
    
    namedWindow("dst");
    createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&src);
    on_brightness(0, (void*)&src);
    
    waitKey();
    destroyAllWindows();
}

void on_brightness(int pos, void* userdata) {
    Mat src = *(Mat*)userdata;
    Mat dst = src + pos;

    imshow("dst", dst);
}
