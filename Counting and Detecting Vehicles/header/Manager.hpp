/*
 * Manager.hpp
 *
 *  Created on: 7/4/2015
 *      Author: alonso
 */

#ifndef MANAGER_HPP_
#define MANAGER_HPP_

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

class Manager
{

public:

	Manager();
	virtual ~Manager();
	int iniciarPrograma(int pIdCamara);


private:

	VideoCapture* _VideoCamara;
	int calcularPorcentaje(double pTotal, double pCantidad);
	bool filtrarTamano(double pAreaContorno, double pAreaTotal);
};

#endif /* MANAGER_HPP_ */
