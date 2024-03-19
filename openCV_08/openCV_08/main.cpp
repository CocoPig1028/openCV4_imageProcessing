//
//  main.cpp
//  openCV_08
//
//  Created by Daeyeong Park on 3/19/24.
//
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void unsharp_mask();

int main(int argc, const char * argv[]) {
    unsharp_mask();
    
    return 0;
}

void unsharp_mask() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_08/openCV_08/rose.bmp", IMREAD_GRAYSCALE);
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return;
    }
    
    imshow("src", src);
    
    for (int sigma = 1; sigma <= 5; sigma++) {
        Mat blurred;
        GaussianBlur(src, blurred, Size(), sigma);
        
        float alpha = 1.f;
        Mat dst = (1 + alpha) * src - alpha * blurred;
        
        std::string desc = "Sigma: " + to_string(sigma);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
        
        imshow("dst", dst);
        waitKey();
    }
    
    destroyAllWindows();
}
