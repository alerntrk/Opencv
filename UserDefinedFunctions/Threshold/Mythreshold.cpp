#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;

void Mythreshold(Mat inp, Mat& outp, int thresh, int max=255) {
	cvtColor(inp, outp, COLOR_BGR2GRAY);
	for (int i = 0; i < outp.rows; i++) {
		for (int j = 0; j < outp.cols; j++) {
			if (max > thresh) {
				if (thresh > outp.at<uchar>(i, j)) outp.at<uchar>(i, j) = 0;
				else outp.at<uchar>(i, j) = 255;
			}
			else outp.at<uchar>(i, j) = 0;
		}
	}
}

int main(){
	Mat out;
	Mat resim = imread("kahve.jpg");
	Mythreshold(resim, out, 140);
	imshow("binary: ", out);
	waitKey(0);

	return 0;
		
}
