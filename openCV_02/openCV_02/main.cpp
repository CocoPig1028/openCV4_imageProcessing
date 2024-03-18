//
//  main.cpp
//  openCV_02
//
//  Created by Daeyeong Park on 3/18/24.
//

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void contrast1();
void contrast2();

int main() {
    contrast1();
    contrast2();
    
    return 0;
}

void contrast1() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_02/openCV_02/lenna.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    float s = 2.f;
    Mat dst = s * src;

    imshow("src", src);
    imshow("dst", dst);
    waitKey();

    destroyAllWindows();
}

void contrast2()
{
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_02/openCV_02/lenna.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    float alpha = 1.f;
    Mat dst = src + (src - 128) * alpha;

    imshow("src", src);
    imshow("dst", dst);
    waitKey();

    destroyAllWindows();
}
