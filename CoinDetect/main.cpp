#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;
void makeDarkBack(Mat& resim) {
	int b, g, r;
	for (int i = 0; i < resim.rows; i++)
	{
		for (int j = 0; j < resim.cols; j++)
		{
			b = resim.at<Vec3b>(i, j)[0];
			g = resim.at<Vec3b>(i, j)[1];
			r = resim.at<Vec3b>(i, j)[2];
			if (b >= 254 && g >= 254 && r >= 254)
			{   
				resim.at<Vec3b>(i, j)[0] = 0;
				resim.at<Vec3b>(i, j)[1] = 0;
				resim.at<Vec3b>(i, j)[2] = 0;

			}
		}
	}
}

int main() {
	

	Mat resim = imread("madeniPara.jpg");
	makeDarkBack(resim);
	Mat out;
	cvtColor(resim, out, COLOR_BGR2GRAY);
	const char* texts[] = { "1 krs","5 krs","10 krs","25 krs","50 krs","1 tl" };

	GaussianBlur(out, out, Size(3,3), 1);//get rid of noise
	Canny(out, out, 120, 255);//convert to binary
	vector<Vec3f> circ;
	HoughCircles(out, circ, HOUGH_GRADIENT, 1, 100);
	cout << circ.size();
	for (int i = 0; i < circ.size(); i++)
	{
		string prnt;
		Point center(cvRound(circ[i][0]), cvRound(circ[i][1]));
		int r = cvRound(circ[i][2]);
		cout << r << endl;
		circle(resim, center, r, Scalar(255,0,0), 4);
		if (r >= 91 & r <= 95) prnt = texts[5];
		else if (r >= 86 & r <= 89) prnt = texts[4];
		else if (r >= 73 & r <= 76) prnt = texts[3];
		else if (r >= 69 & r <= 70) prnt = texts[2];
		else if (r ==62  | r ==64) prnt = texts[1];
		else if (r ==63) prnt = texts[0];
		putText(resim, prnt, Point(cvRound(circ[i][0]) - 20, cvRound(circ[i][1])), FONT_HERSHEY_TRIPLEX, 1, Scalar(0, 0, 0), 3);

	}
	
	
	imshow("procceded", out);
	
	imshow("binary", resim);
	//imshow("kahve",resim);
	
	waitKey(0);
	
	return 0;
	}
