#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;
Mat resim;
typedef struct  {
	int firstx, firsty, lastx, lasty,flag;
	Rect croppedRegion;
	Mat buff;
}region;
region R;
void mouse(int cmd, int x, int y, int flag, void* userData) {

	if (cmd == EVENT_LBUTTONDOWN) {
		R.firstx = x;
		R.firsty = y;
		R.flag = 0;

	}
	if (cmd == EVENT_LBUTTONUP) {
		R.lastx = x;
		R.lasty = y;
		R.flag = 1;
		cout << "*" << endl;
	}
	if (cmd == EVENT_MOUSEMOVE) {

		R.lastx = x;
		R.lasty = y;
		R.croppedRegion = Rect(R.firstx, R.firsty, R.lastx, R.lasty);
	}
}

int main(){
	Mat resim = imread("Resim.jpg");
	R.flag = 0;
	namedWindow("window", WINDOW_AUTOSIZE);
	while (1) {
		setMouseCallback("window", mouse, NULL);
		if (R.flag != 0) {
			rectangle(resim, Rect(R.firstx, R.firsty, (R.lastx - R.firstx), (R.lasty - R.firsty)), Scalar(100, 100, 100), 2);
			R.flag = 0;
		}
		imshow("window", resim);
		waitKey(250);
	}

	
	return 0;
		
}
