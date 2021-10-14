#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;


int main() {
	
	Mat resim = imread("Resim.jpg");
	int angle = 0;
	Rect2f bbox;
	Mat out;
	Point2f coord(resim.rows / 2 - 1, resim.cols / 2 - 1);
	while (1) {
		out = getRotationMatrix2D(coord, angle, 1);
		 bbox = RotatedRect(Point2f(), resim.size(), angle).boundingRect2f();
		cout << out.at<double>(0, 2) << endl;
		out.at<double>(0, 2) += bbox.width / 2 - resim.cols / 2;
		out.at<double>(1, 2) += bbox.height / 2 - resim.rows / 2;
		cout << out.at<double>(0, 2) << endl;

		Mat last;
		warpAffine(resim, last, out, bbox.size());
		imshow("rotated without crop: ", last);
		angle += 15;
		waitKey(100);
	}
	return 0;
		}
