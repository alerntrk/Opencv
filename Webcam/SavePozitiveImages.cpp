#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;



int main(){

	VideoCapture p(0);
	if (!p.isOpened()) return -1;
	int i = 0;
	Mat buff;
	bool control;
	while (1) {
		control = p.read(buff);
		cvtColor(buff, buff, COLOR_BGR2GRAY);
		resize(buff, buff, Size(500, 500));
		if (!control) {
			cout << "invalid frame";
			break;
			}
		imshow("webcam ", buff);
		if (waitKey(20) == 27) break;
		imwrite("p" + to_string(i) + ".jpg", buff);
		waitKey(0);
		i++;
	}

	return 0;
		
}
