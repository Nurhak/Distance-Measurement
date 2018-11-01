#include <iostream>
#include "opencv2/opencv.hpp"
#include <ctime>
#include <math.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int px_distance(float x, float h, float teta, float alfa, int m);

int main(int, char**)
{
	clock_t begin = clock();
	char str[80];
	double elapsed_secs = 0;
	double first_secs = 0;
	VideoCapture vid(0);
	int height = vid.get(CV_CAP_PROP_FRAME_HEIGHT);
	int width = vid.get(CV_CAP_PROP_FRAME_WIDTH);
	if (!vid.isOpened()) {
		cout << "Camera couldn't opend!" << endl;
		system("pause");
	}
	//namedWindow("Nurhak", CV_WINDOW_AUTOSIZE);
	clock_t end = clock();
	first_secs = double(end - begin) / CLOCKS_PER_SEC;
	for (;;) {
		clock_t begin = clock();
		Mat frame;
		bool kontrol = vid.read(frame);
		if (!kontrol) {
			cout << "webcamden yeni frame okunamadý..." << endl;
			break;
		}
		string text = "Nurhak_Camera";
		int i = 0;
		int r[11];
		for (int j = 1; j <= 11; j++) {
			r[i] = px_distance(j, 0.77, 0.2, (3.14 /11), height);
			i++;
		}
		sprintf(str, "Time = %lf", elapsed_secs);
		int fontFace = FONT_HERSHEY_SIMPLEX;
		double fontScale = 0.5;
		int thickness = 1;
		Point textOrg(10, 42);		
		putText(frame, str, Point(10, 480), fontFace, fontScale, Scalar::all(255));
		char distance[60];
		i = 0;
		for (int j = 1; j <= 11; j++) {
			line(frame, Point(0, r[i]), Point(350, r[i]), Scalar(110, 220, 0), 1, 8);
			sprintf(distance, "%d m", j);
			putText(frame, distance, Point(355, r[i]), fontFace, fontScale, Scalar::all(255));
			i++;
		}

		imwrite("nurhak.jpg", frame);
		clock_t end = clock();
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		if (waitKey(30) == 27) {
			cout << "cikis yapildi" << endl;
			break;
		}

	}

	return 0;
}
int px_distance(float x, float h, float teta, float alfa, int m) {
	float rx;
	rx = (((((h - x*tan(teta)) / (h*tan(teta) + x)) / tan(alfa)) + 1) * ((m - 1) / 2)) + 1;
	return int(rx);
}
