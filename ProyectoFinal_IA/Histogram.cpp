#include "stdafx.h"
#include "Histogram.h"

//using namespace std;
//using namespace cv;

Histograma::Histograma() {
	fon.resize(1000);
	obj.resize(1000);
	font = 0;
	objt = 0;
	llenarfondo();
	llenarobjeto();
}
void Histograma::llenarfondo() {
	Mat img;

	for (int i = 1; i < 6; i++) {
		string name = "fondo" + to_string(i) + ".bmp";
		img = imread(name, CV_LOAD_IMAGE_COLOR);
		for (int y = 0; y < img.rows; y++)
		{
			for (int x = 0; x < img.cols; x++)
			{
				Vec3b color = img.at<Vec3b>(Point(x, y));
				if (color[0] != 0 && color[1] != 0 && color[2] != 0) {
					int B = (int)(color[0] / 26);
					int G = (int)(color[1] / 26);
					int R = (int)(color[2] / 26);
					fon[(B * 100) + (G * 10) + R]++;
					font++;
				}
			}
		}
	}
	cout << font << endl;
}

void Histograma::llenarobjeto() {
	Mat img;

	for (int i = 1; i < 6; i++) {
		string name = "objeto" + to_string(i) + ".bmp";
		cout << name << endl;
		img = imread(name, CV_LOAD_IMAGE_COLOR);
		for (int y = 0; y < img.rows; y++)
		{
			for (int x = 0; x < img.cols; x++)
			{
				Vec3b color = img.at<Vec3b>(Point(x, y));
				if (color[0] != 0 && color[1] != 0 && color[2] != 0) {
					int B = (int)(color[0] / 26);
					int G = (int)(color[1] / 26);
					int R = (int)(color[2] / 26);
					obj[(B * 100) + (G * 10) + R]++;
					//cout << obj[(B * 100) + (G * 10) + R]++;
					objt++;
				}
			}
		}
	}
	cout << "objeto" << objt << "objeto" << endl;
}

bool Histograma::isBack(Vec3b color) {
	int B = (int)(color[0] / 26);
	int G = (int)(color[1] / 26);
	int R = (int)(color[2] / 26);

	double pfon = (double)(fon[(B * 100) + (G * 10) + R]) / (double)(font);
	//cout << pfon;
	double pobj = (double)(obj[(B * 100) + (G * 10) + R]) / (double)(objt);
	if (pfon == 0 && pobj == 0)
		return false;
	if (pfon > pobj)
		return true;
	else
		return false;
}