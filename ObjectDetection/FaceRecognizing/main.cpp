#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;



int main(){

	CascadeClassifier face;
	vector<Rect> detection;
	face.load("haarcascade_frontalface_default.xml");
	Mat img = imread("face.png");
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	face.detectMultiScale(gray, detection);
	for (int i = 0; i < detection.size(); i++) {

		rectangle(img, detection[i], Scalar(0, 0, 255),3);
	}
	imshow("face detection: ", img);
	waitKey(0);

	return 0;
		
}
