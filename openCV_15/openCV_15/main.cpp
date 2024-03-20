//
//  main.cpp
//  openCV_15
//
//  Created by Daeyeong Park on 3/20/24.
//

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_15/openCV_15/pepper.bmp", IMREAD_COLOR);
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return -1;
    }
    
    Mat src_ycrcb;
    cvtColor(src, src_ycrcb, COLOR_BGR2YCrCb);
    
    vector<Mat> ycrcb_planes;
    split(src_ycrcb, ycrcb_planes);
    
    equalizeHist(ycrcb_planes[0], ycrcb_planes[0]);
    
    Mat dst_ycrcb;
    merge(ycrcb_planes, dst_ycrcb);
    
    Mat dst;
    cvtColor(dst_ycrcb, dst, COLOR_YCrCb2BGR);
    
    imshow("src", src);
    imshow("dst", dst);
    
    waitKey();
    destroyAllWindows();
    
    return 0;
}
