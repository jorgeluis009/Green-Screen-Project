// pruebaOpencv.cpp: define el punto de entrada de la aplicación de consola.
//
//http://stackoverflow.com/questions/23001512/c-and-opencv-get-and-set-pixel-color-to-mat

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Histograma.h"

using namespace std;
using namespace cv;

int main()
{
	//variables necesarias
	int cont = 1;
	Histograma hist;
	//calcular();
	Mat image;
	image = imread("fondo.jpg", CV_LOAD_IMAGE_COLOR);
	Vec3b aux = image.at<Vec3b>(Point(1, 1));
	cout << image.size();

	//Camara
	VideoCapture cap(0);

	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	namedWindow("video");
	//video
	while (char(waitKey(1)) != 'q' && cap.isOpened()) {

		if (char(waitKey(1)) == 'w') {
			cont++;
			switch (cont) {
			case 1: image = imread("fondo.jpg", CV_LOAD_IMAGE_COLOR);
				break;
			case 2: image = imread("arboles.jpg", CV_LOAD_IMAGE_COLOR);
				break;
			case 3: image = imread("nuevayork.jpg", CV_LOAD_IMAGE_COLOR);
				break;
			case 4: image = imread("pelotas.jpg", CV_LOAD_IMAGE_COLOR);
				break;
			default: cap >> image;
			}
			if (cont > 5)
				cont = 1;

		}

		/*Histograma hist;*/
		Mat frame;
		Mat img;

		cap >> frame;
		frame.copyTo(img);
		for (int y = 0; y < img.rows; y++)
		{
			for (int x = 0; x < img.cols; x++)
			{
				Vec3b color = img.at<Vec3b>(Point(x, y));
				if (hist.isBack(color)) {
					img.at<Vec3b>(Point(x, y)) = image.at<Vec3b>(Point(x, y));
					/*color[0] = 0;
					color[1] = 0;
					color[2] = 0;
					image.at<Vec3b>(Point(x, y)) = color;*/
				}
				//if (!hist.isBack(color)) {
				//	img.at<Vec3b>(Point(x, y)) = image.at<Vec3b>(Point(x, y));
				//	/*color[0] = 0;
				//	color[1] = 0;
				//	color[2] = 0;
				//	  image.at<Vec3b>(Point(x, y)) = color;*/
				//}
			}
		}
		//156, 178, 78 RGB formato de opencv BGR
		//ellipse(coso, Point(posx,  posy), Size(100, 70), rotate, 0, 360, white, 4, 8, 0);
		if (img.empty()) {
			cout << "video over" << endl;
			break;
		}
		imshow("video", img);
	}
	return 0;
}




