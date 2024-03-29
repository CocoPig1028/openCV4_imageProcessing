# openCV4_imageProcessing
repository for imageProcessing using openCV4

## File Name and subject
1. openCV_01: brightness control
2. openCV_02: contrast control -> 사물의 구분을 증가시키는 방법
3. openCV_03: histogram control -> 히스토그램 스트레칭, 히스토그램 평활화, 히스토그램 계산, 히스토그램 출력
4. openCV_04: arithmetic operation -> add, addWeighted, subtract, absdiff
5. openCV_05: logical operation -> bitwise_and, bitwise_or, bitwise_xor, bitwise_not
6. openCV_06: image embossing -> filter2D
7. openCV_07: image blurring -> blur(평균값 필터), GaussianBlur(가우시안 필터), getGaussianKernal
8. openCV_08: sharpening -> unsharp mask filter
9. openCV_09: noise filtering -> randn, bilateralFilter(픽셀값에 따른 평탄화), medianBlur(자기 주변을 포함한 픽셀값 중 중간값을 이용하여 잡음 제거)
10. openCV_10: affine transformation -> getAffineTransform(어파인 변환 행렬 계산), warpAffine(어파인 변환 영상), 이동 변환, 전단 변환, 크기 변환, 회전 변환, 대칭 변환
11. openCV_11: perspective transformation -> getPerspectiveTransform(투시 변환 행렬 계산), warpPerspective(투시 변환 영상), 지정한 점을 이용한 행렬 계산
12. openCV_12: edge detection -> derivate, 마스크 기반 엣지 검출(sobel filters, scharr filter), canny(가우시안 필터링, 그레디언트 계산, 비최대 억제, 이중 임계값을 이용한 히스테리시스 엣지 트래킹)
13. openCV_13: hough transform -> 허프 직선 변환 houghLines(), 허프 변환 원 검출 houghCircles()
14. openCV_14: 색상 변환, 색상 분리 -> cvtColor(), split()
15. openCV_15: 컬러 히스토그램 평활화 -> BGR에서 YCrCb로 변환 후 Y값에 대한 히스토그램 평활화
16. openCV_16: 색상 범위 지정에 의한 영역 분할 -> inRange();
17. openCV_17: 히스토그램 역투영을 이용한 영역 검출 -> calcBackProject(), calcHist()를 이용하여 마스크에 해당하는 히스토그램 추출후 역산)

## Summary
1 - 3 : 영상의 밝기와 명암비 조절 (밝기, 명암비, 히스토그램)

4 - 5 : 영상의 산술 및 논리 연산

6 - 9 : 필터링 (엠보싱, 블러링, 샤프닝, 잡음 제거 필터링)

10 - 11 : 영상의 기하학적 변환 (어파인 변환, 투시 변환)

12 - 13 : 에지 검출과 응용 (마스크 기반 엣지 검출, 캐니 검출, 허프 변환)

14 - 17 : 컬러 영상 처리 (색상 변환, 컬러 히스토그램 평활화, 색상 범위 지정에 의한 영역 분할, 히스토그램 역투영)

## Reference
The contents of this repository contain information studied by referring to the books below.
1. "openCV4로 배우는 컴퓨터 비전과 머신러닝" 길벗
2. "Learning! OpenCV3" O'REILLY'
