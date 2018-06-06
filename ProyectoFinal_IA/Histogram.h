#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace cv;

class Histograma {
	vector<int> fon, obj;
	int font, objt;

private:
	void llenarfondo();
	void llenarobjeto();
public:
	bool isBack(Vec3b color);
	Histograma();
};