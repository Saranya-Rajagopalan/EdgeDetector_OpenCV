// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\highgui.hpp"
#include "opencv\cv.hpp"
using namespace cv;

int main(int argc, char** argv) {
	char* WINDOW_NAME = "Input image";
	char* WIN_LAP = "Laplacian Transform";
	char* WIN_CANNY = "Canny Transform";
	char* WIN_SOBEL = "Sobel Transform";
	cvNamedWindow(WINDOW_NAME, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(WIN_LAP, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(WIN_SOBEL, CV_WINDOW_AUTOSIZE);

	const IplImage* src = cvLoadImage("bird.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	IplImage* laplacian = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
	IplImage* canny = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
	IplImage* sobel = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);

	//Display Image
	cvShowImage(WINDOW_NAME, src);
	//Laplace transform
	cvLaplace(src, laplacian, 1);
	cvShowImage(WIN_LAP, laplacian);

	//Canny transform
	cvCanny(src, canny, 20, 100, 3);
	cvShowImage(WIN_CANNY, canny);

	//Sobel transform
	cvSobel(src, sobel, 1, 1, 3);
	cvShowImage(WIN_SOBEL, sobel);

	cvSaveImage("Laplacian.png", laplacian);
	cvSaveImage("Canny.png", canny);
	cvSaveImage("Sobel.png", sobel);
	waitKey(0);
	cvDestroyWindow(WINDOW_NAME);
	cvDestroyWindow(WIN_LAP);
	cvDestroyWindow(WIN_CANNY);
}
