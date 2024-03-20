//
//  main.cpp
//  openCV_14
//
//  Created by Daeyeong Park on 3/20/24.
//

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void color_inverse();
void color_grayscale();
void color_split();

int main() {
    color_inverse();
    color_grayscale();
    color_split();
    
    return 0;
}

void color_inverse() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_14/openCV_14/butterfly.jpg", IMREAD_COLOR);
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return;
    }
    
    Mat dst(src.rows, src.cols, src.type());
    
    // 방법 1
//    for (int i = 0; i < src.rows; i++) {
//        for (int j = 0; j < src.cols; j++) {
//            Vec3b& p1 = src.at<Vec3b>(i, j);
//            Vec3b& p2 = dst.at<Vec3b>(i, j);
//            
//            p2[0] = 255 - p1[0];
//            p2[1] = 255 - p1[1];
//            p2[2] = 255 - p1[2];
//        }
//    }
    
    // 방법 2
//    for (int i = 0; i < src.rows; i++) {
//        for (int j = 0; j < src.cols; j++) {
//            dst.at<Vec3b>(i, j) = Vec3b(255, 255, 255) - src.at<Vec3b>(i, j);
//        }
//    }
    
    // 방법 3 (가장많이 쓰는 방법)
    dst = Scalar(255, 255, 255) - src;
    
    imshow("src", src);
    imshow("dst", dst);
    
    waitKey();
    destroyAllWindows();
}

void color_grayscale() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_14/openCV_14/butterfly.jpg", IMREAD_COLOR);
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return;
    }
    
    Mat dst;
    cvtColor(src, dst, COLOR_BGR2GRAY);
    
    imshow("src", src);
    imshow("dst", dst);
    
    waitKey();
    destroyAllWindows();
}

void color_split() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_14/openCV_14/candies.png", IMREAD_COLOR);
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return;
    }
    
    vector<Mat> bgr_planes;
    split(src, bgr_planes);
    
    imshow("src", src);
    imshow("B_plane", bgr_planes[0]);
    imshow("G_plane", bgr_planes[1]);
    imshow("R_plane", bgr_planes[2]);
    
    waitKey();
    destroyAllWindows();
}
