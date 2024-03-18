//
//  main.cpp
//  openCV_03
//
//  Created by Daeyeong Park on 3/18/24.
//

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

Mat calcGrayHist(const Mat& img);
Mat getGrayHistImage(const Mat& hist);

void histogram_stretching();
void histogram_equalization();

int main(int argc, const char * argv[]) {
    histogram_stretching();
    histogram_equalization();
    
    return 0;
}

Mat calcGrayHist(const Mat& img) {
    CV_Assert(img.type() == CV_8UC1); // 그레이스케일 영상인지 확인
    
    Mat hist; // 히스토그램 정보를 저장할 Mat 타입 변수 선언
    int channels[] = {0}; // 히스토그램을 구할 채널 번호를 담은 channels 배열 선언, 그레이스케일의 경우 한개의 채널을 가지고 있음
    int dims = 1; // 하나의 채널에 대해서만 히스토그램을 구하기 때문에 1, 결과로 구해지는 hist행렬이 1차원 행렬임을 나타냄
    const int histSize[] = {256}; // 빈의 개수
    float graylevel[] = {0, 256}; // 최소값과 최대값을 지정
    const float* ranges[] = {graylevel}; // graylevel의 배열 이름을 원소로 갖는 배열
    
    calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);
    // 영상 히스토그램 구하기 (입력 영상 주소, 입력 영상 개수, 채널, 마스크 영상, 출력 히스토그램, 출력 히스토그램 차원수, 히스토그램 배열 크기를 나타내는 배열, 히스토그램 범위
    
    return hist;
}

Mat getGrayHistImage(const Mat& hist) {
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.size() == Size(1, 256));
    // 256개의 빈으로 구성된 히드토그램 행렬인지 검사

    double histMax;
    minMaxLoc(hist, 0, &histMax); // hist 행렬의 최대값을 histMax에 저장

    Mat imgHist(100, 256, CV_8UC1, Scalar(255)); // 흰색으로 초기화된 256x100 크기의 새 영상 imgHist를 생성
    for (int i = 0; i < 256; i++) { // 각 빈에 대한 히스토그램 그래프를 그리기 위한 반복문
        line(imgHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));
        // 현재 빈의 높이를 계산하여 그래프를 그림
    }

    return imgHist;
}

void histogram_stretching() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_03/openCV_03/hawkes.bmp", IMREAD_GRAYSCALE);
    
    if (src.empty()) {
        cerr << "Image load failed" << endl;
        
        return;
    }
    
    double gmin, gmax;
    minMaxLoc(src, &gmin, &gmax);
    
    Mat dst = (src - gmin) *255 / (gmax - gmin);
    
    imshow("src", src);
    imshow("srcHist", getGrayHistImage(calcGrayHist(src)));
    
    imshow("dst", dst);
    imshow("dstHist", getGrayHistImage(calcGrayHist(dst)));
    
    waitKey();
    destroyAllWindows();
}

void histogram_equalization() {
    Mat src = imread("/Users/park/Desktop/XCodeFolder/imageProcessing/openCV_03/openCV_03/hawkes.bmp", IMREAD_GRAYSCALE);
    
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        
        return;
    }
    
    Mat dst;
    equalizeHist(src, dst);
    // 히스토그램 평활화 함수
    
    imshow("src", src);
    imshow("srcHist", getGrayHistImage(calcGrayHist(src)));
    
    imshow("dst", dst);
    imshow("dstHist", getGrayHistImage(calcGrayHist(dst)));
    
    waitKey();
    destroyAllWindows();
}
