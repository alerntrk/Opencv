#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;

void triangle(Mat inp, Point2f p1, Point2f p2, Point2f p3) {
	line(inp, p1, p2, Scalar(0, 0, 255), 3);
	line(inp, p1, p3, Scalar(0, 0, 255), 3);
	line(inp, p2, p3, Scalar(0, 0, 255), 3);
	Point2f centroid((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3);
	circle(inp, centroid, 2, Scalar::all(255), 3);



}

int main(){
	Mat x(500, 500, CV_8UC3, Scalar::all(0));
	triangle(x, Point2f(200, 10), Poaint2f(86, 100), Point2f(200, 300));
	
	imshow("triangle ", x);
	waitKey(0);

	return 0;
		
}
