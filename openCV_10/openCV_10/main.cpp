//
//  main.cpp
//  openCV_10
//
//  Created by Daeyeong Park on 3/19/24.
//

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void affine_transform();
void affine_translation();
void affine_shear();
void affine_scale();
void affine_rotation();
void affine_flip();

int main() {
    affine_transform();
    affine_translation();
    affine_shear();
    affine_scale();
    affine_rotation();
    affine_flip();
    
    return 0;
}

void affine_transform() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_10/openCV_10/tekapo.bmp");
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return;
    }
    
    Point2f srcPts[3], dstPts[3];
    srcPts[0] = Point2f(0, 0);
    srcPts[1] = Point2f(src.cols - 1, 0);
    srcPts[2] = Point2f(src.cols - 1, src.rows - 1);
    dstPts[0] = Point2f(50, 50);
    dstPts[1] = Point2f(src.cols - 100, 100);
    dstPts[2] = Point2f(src.cols - 100, src.rows - 100);
    
    Mat M = getAffineTransform(srcPts, dstPts);
    // 어파인 변환 행렬 추출
    
    Mat dst;
    warpAffine(src, dst, M, Size());
    // 어파일 변환 결과 영상
    
    vector<Point2f> src1 = { Point2f(100, 20), Point2f(200, 50)};
    vector<Point2f> dst1;
    
    transform(src1, dst1, M);
    // 일정 좌표의 어파인 변환 행렬의 결과 좌표
    
    cout << src1 << " -> " << dst1 << endl;
    
    imshow("src", src);
    imshow("dst", dst);
    
    waitKey();
    
    destroyAllWindows();
}

void affine_translation() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_10/openCV_10/tekapo.bmp");
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return;
    }
    
    Mat M = Mat_<double>({2, 3}, {1, 0, 150, 0, 1, 100});
    
    Mat dst;
    warpAffine(src, dst, M, Size());
    
    imshow("src", src);
    imshow("dst", dst);
    
    waitKey();
    
    destroyAllWindows();
}
void affine_shear() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_10/openCV_10/tekapo.bmp");
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return;
    }
    
    double mx = 0.3;
    Mat M = Mat_<double>({2, 3}, {1, mx, 0, 0, 1, 0});
    
    Mat dst;
    warpAffine(src, dst, M, Size(cvRound(src.cols + src.rows * mx), src.rows));
    
    imshow("src", src);
    imshow("dst", dst);
    
    waitKey();
    
    destroyAllWindows();
}

void affine_scale() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_10/openCV_10/roseC.bmp");

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat dst1, dst2, dst3, dst4;
    resize(src, dst1, Size(), 4, 4, INTER_NEAREST);
    resize(src, dst2, Size(1920, 1280));
    resize(src, dst3, Size(1920, 1280), 0, 0, INTER_CUBIC);
    resize(src, dst4, Size(1920, 1280), 0, 0, INTER_LANCZOS4);

    imshow("src", src);
    imshow("dst1", dst1(Rect(400, 500, 400, 400)));
    imshow("dst2", dst2(Rect(400, 500, 400, 400)));
    imshow("dst3", dst3(Rect(400, 500, 400, 400)));
    imshow("dst4", dst4(Rect(400, 500, 400, 400)));

    waitKey();
    destroyAllWindows();
}

void affine_rotation() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_10/openCV_10/tekapo.bmp");

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    Point2f cp(src.cols / 2.f, src.rows / 2.f);
    Mat M = getRotationMatrix2D(cp, 20, 1);

    Mat dst;
    warpAffine(src, dst, M, Size());
    
    Mat dst1;
    rotate(src, dst1, ROTATE_90_CLOCKWISE);

    imshow("src", src);
    imshow("dst", dst);
    imshow("dst1", dst1);

    waitKey();
    destroyAllWindows();
}

void affine_flip() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_10/openCV_10/eastsea.bmp");

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return;
    }

    imshow("src", src);

    Mat dst;
    int flipCode[] = { 1, 0, -1 };
    for (int i = 0; i < 3; i++) {
        flip(src, dst, flipCode[i]);

        std::string desc = "flipCode: " + to_string(flipCode[i]);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 0, 0), 1, LINE_AA);

        imshow("dst", dst);
        waitKey();
    }

    destroyAllWindows();
}
