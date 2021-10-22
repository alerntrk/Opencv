#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;
int main(){
	Mat x(700, 700, CV_8UC3, Scalar::all(0));
	while (1)
	{
		for (int i = 0; i < 200; i++) {
			circle(x, Point(x.rows / 2, x.cols / 2), 10 + i, Scalar(10 + i, 20 + i, 50 + i));
			imshow("animation", x);
			waitKey(50);
		}

		for (int i = 200; i > 0; i--) {
			circle(x, Point(x.rows / 2, x.cols / 2), 10 + i, Scalar(0,0,0));
			imshow("animation", x);
			waitKey(50);
		}
	}
	return 0;
		
}
