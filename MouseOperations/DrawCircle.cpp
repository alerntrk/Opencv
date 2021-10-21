#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;
Mat resim;
void mouse(int cmd, int x, int y, int flag, void* userData) {

	if (cmd == EVENT_LBUTTONDOWN)circle(resim, Point(x, y), 35, Scalar(0, 0, 255));
}

int main(){

	resim = imread("Resim.jpg");
	namedWindow("window");
	
	setMouseCallback("window", mouse, NULL);
	
	while (1) {
		imshow("window", resim);
		if(waitKey(20)==27)break;

	}
	return 0;
		
}
