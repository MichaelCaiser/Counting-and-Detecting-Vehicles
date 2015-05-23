/*
 * Tracker.hpp
 *
 *  Created on: 24/4/2015
 *      Author: alonso
 */

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <cmath> //Para lenguaje C++
using namespace cv;
using namespace std;

const int NOT_FOUND = -1;

#ifndef TRACKER_HPP_
#define TRACKER_HPP_

class Tracker
{

public:

	Tracker();
	virtual ~Tracker();
	vector<Rect> detectarBloques(vector< vector<Point> > rContornos);
	bool estanTraslapados(Rect rRect1, Rect rRect2);
	int buscarFiguraTraslapada(Rect rRectangulo, vector< vector<Point> > rContornos);
	Rect combinarRectangulos(Rect rRect1, Rect rRect2);
	float calcularDistanciaRectangulos(Rect rRect1, Rect rRect2);
	float calcularDistancia(int rPosX1, int rPosY1, int rPosX2, int rPosY2);

private:

	vector<Rect>* mBloques;

};

#endif /* TRACKER_HPP_ */
