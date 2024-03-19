//
//  main.cpp
//  openCV_11
//
//  Created by Daeyeong Park on 3/19/24.
//

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

Mat src;
Point2f srcQuad[4], dstQuad[4];

void on_mouse(int event, int x, int y, int flags, void* userdata);

int main() {
    src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_11/openCV_11/card.bmp");
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return -1;
    }
    
    namedWindow("src");
    setMouseCallback("src", on_mouse);
    
    imshow("src", src);
    waitKey();
    
    return 0;
}

void on_mouse(int event, int x, int y, int flags, void*) {
    static int cnt = 0; // 마우스 클릭 횟수
    
    if (event == EVENT_LBUTTONDOWN) {
        if (cnt < 4) {
            srcQuad[cnt++] = Point2f(x, y);
            
            circle(src, Point(x, y), 5, Scalar(0, 0, 255), -1);
            imshow("src", src);
            
            if (cnt == 4) {
                int w = 200, h = 300;
                
                dstQuad[0] = Point2f(0, 0);
                dstQuad[1] = Point2f(w - 1, 0);
                dstQuad[2] = Point2f(w - 1, h - 1);
                dstQuad[3] = Point2f(0, h - 1);
                
                Mat pers = getPerspectiveTransform(srcQuad, dstQuad);
                
                Mat dst;
                warpPerspective(src, dst, pers, Size(w, h));
                
                imshow("dst", dst);
            }
        }
    }
}
