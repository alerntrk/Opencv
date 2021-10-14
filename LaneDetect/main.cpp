#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;

Point2f noktalar[] = { Point2f(180,297),Point2f(441,297),Point2f(580,363),Point2f(32,363)};
Point2f pers[] = { Point2f(0,0),Point2f(640,0),Point2f(640,480),Point2f(0,480) };
vector<int> lane;
Mat relatedRegion;
Mat x, y;
int leftP, RightP,pid;
void convert(Mat input) {
	
	cvtColor(input, input, COLOR_BGR2GRAY);
	threshold(input, y, 130, 255, THRESH_BINARY);
	Canny(input, input, 70, 175);
	add(input, y, x);
	imshow("added", x);
	}
void FindLane() {
	lane.resize(640);	//column number
	lane.clear();
	for (int i = 0; i < 640; i++)
	{
		relatedRegion = x(Rect(i, 150, 1, 100));
		divide(255, relatedRegion, relatedRegion);
		lane.push_back((int)(sum(relatedRegion)[0]));
		
	}


}
void DetectLane(Mat last)
{
	vector<int>::iterator left;
	left = max_element(lane.begin(), lane.begin() + 150);
	leftP = distance(lane.begin(), left);
	vector<int>::iterator right;
	right = max_element(lane.begin() + 350, lane.end());
	RightP = distance(lane.begin(), right);
	line(last, Point(leftP, 0), Point(leftP, 480), Scalar(0, 165, 168), 3);
	line(last, Point(RightP, 0), Point(RightP, 480), Scalar(0, 165, 168), 3);

	imshow("detection of lane: ", last);
	}
void centerOfLane(Mat last)
{
	int calib = last.cols / 2 - 3;
	int Lcenter = (RightP - leftP) / 2 + leftP;
	pid = Lcenter - calib;
	line(last, Point(Lcenter, 0), Point(Lcenter, 480), Scalar(0, 0, 255), 3);
	line(last, Point(calib, 0), Point(calib, 480), Scalar(255, 0, 0),1);
	imshow("updated: ", last);
	}
int main() {
	
	Mat resim = imread("serit.png");
	Mat persp = getPerspectiveTransform(noktalar, pers);
	Mat last(480, 640, CV_8UC3);
	warpPerspective(resim, last, persp, last.size());
	convert(last);
	FindLane();
	DetectLane(last);
	cout << RightP << endl << leftP << endl;
	centerOfLane(last);
	stringstream text;
	text.str(" ");
	text << "PID value is: " << pid;
	putText(resim, text.str(), Point(150, 150), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 125, 225), 2);

	imshow("original", resim);
	
	waitKey(0);
	
	return 0;
		
}
