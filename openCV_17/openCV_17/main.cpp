//
//  main.cpp
//  openCV_17
//
//  Created by Daeyeong Park on 3/20/24.
//

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main() {
    Mat ref, ref_ycrcb, mask;
    ref = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_17/openCV_17/ref.png", IMREAD_COLOR);
    mask = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_17/openCV_17/mask.bmp", IMREAD_GRAYSCALE);
    cvtColor(ref, ref_ycrcb, COLOR_BGR2YCrCb);
    
    Mat hist;
    int channels[] = {1, 2};
    int cr_bins = 123, cb_bins = 128;
    int histSize[] = {cr_bins, cb_bins};
    float cr_range[] = {0, 256};
    float cb_range[] = {0, 256};
    const float* ranges[] = {cr_range, cb_range};
    
    calcHist(&ref_ycrcb, 1, channels, mask, hist, 2, histSize, ranges);
    
    Mat src, src_ycrcb;
    src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_17/openCV_17/kids.png", IMREAD_COLOR);
    cvtColor(src, src_ycrcb, COLOR_BGR2YCrCb);
    
    Mat backproj;
    calcBackProject(&src_ycrcb, 1, channels, hist, backproj, ranges, 1, true);
    
    imshow("src", src);
    imshow("backproj", backproj);
    
    waitKey();
    
    return 0;
}
