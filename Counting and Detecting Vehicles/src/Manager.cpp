/*
 * Manager.cpp
 *
 *  Created on: 7/4/2015
 *      Author: alonso
 */

#include "Manager.hpp"

Manager::Manager()
{
	// TODO Auto-generated constructor stub
}

Manager::~Manager()
{
	// TODO Auto-generated destructor stub
}

int Manager::iniciarPrograma(int pIdCamara)
{
	//_VideoCamara = new VideoCapture(pIdCamara);
	_VideoCamara = new VideoCapture("Data/traffic_road.mp4");
	if(!_VideoCamara->isOpened())
	{
		return -1; //Error de conexion
	}

	namedWindow("stream",WINDOW_NORMAL);
	namedWindow("filter",WINDOW_NORMAL);
	namedWindow("contour",WINDOW_NORMAL);
	namedWindow("blob",WINDOW_NORMAL);

	int iteracion = 0;
	Mat image;
	Rect roi = Rect(220,400,700,300);
	//roi.area();
	while(true)
	{
		double area_total = roi.area();
		_VideoCamara->read(image);

		//Aplica Region de Interes
		Mat roiImg;
		roiImg = image(roi);



		// Show blobs
		//imshow("blob", im_with_keypoints );

		//Aplica Escala de Grises
		Mat gray_scale;
		cvtColor(roiImg, gray_scale, CV_BGR2GRAY);

		//Aplica un filtro Blur
		Mat blur_filter;
		blur(gray_scale, blur_filter, Size(3,3));

		//Aplica Algoritmo de Canny
		Mat canny_img;
		Canny(blur_filter, canny_img, 70, 180, 3, true);
		imshow("filter", canny_img);

		//Algoritmo de contornos
		vector<vector<Point> > contours;
		vector<Vec4i> hierarchy;
		RNG rng(12345);
		findContours(canny_img, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
	    Mat drawing = Mat::zeros(canny_img.size(), CV_8UC3 );

	    cout << "iteracion: "<< iteracion << " cantidad contornos: " << contours.size() << endl;
	    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	    for( int i = 0; i< contours.size(); i++ )
	    {

	    	if(contours[i].size() != 0)
	    	{
	    		double area =contourArea( contours[i],false);
	    		Rect rectangulo_limite = boundingRect(contours[i]);
	    		float porcentaje = calcularPorcentaje(area_total,rectangulo_limite.area());
	    		if(porcentaje < 6)
	    		{
	    			int x_center = rectangulo_limite.x + rectangulo_limite.width/2;
	    			int y_center = rectangulo_limite.y + rectangulo_limite.height/2;
					cout << "indice: "<< i << ", puntos : " << contours[i].size() << ", area : " << area << ", punto cero x: "<< contours[i][0].x << " y: "<< contours[i][0].y <<endl;
					Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
					//circle( drawing, Point( x_center, y_center ), 5, color, 1, 8 );
					drawContours( drawing, contours, i, color, CV_FILLED, 8, hierarchy, 0, Point() );
					//Rect bounding_rect = boundingRect(contours[i]);
					//rectangle(drawing, bounding_rect,  Scalar(0,255,0),2, 8,0);
	    		}
	    	}
	    }

	    cout << "                                                                     " << endl;
	    imshow("contour", drawing );

		//Dibuja el ROI en la imagen original
		rectangle(image, roi,  Scalar(0,255,0),2, 8,0);

		int thickness = 2;
		int lineType = 8;
		line( image, Point(380,402),Point(220,611), Scalar( 0, 0, 255 ), thickness, lineType );
		line( image, Point(742,405),Point(918,648), Scalar( 0, 0, 255 ), thickness, lineType );
		imshow("stream", image);

	    iteracion++;
		int key = waitKey(33);
		if(key == 27)
		{
			break;
		}
		if(key == 112)
		{
			waitKey();
		}
	}

	_VideoCamara->release();
	return 0;
}

int Manager::calcularPorcentaje(double pTotal, double pCantidad)
{
	float total = (float)pTotal;
	float cantidad = (float)pCantidad;
	float porcentaje = (cantidad/total)*100;
	return porcentaje;
}

bool Manager::filtrarTamano(double pAreaContorno, double pAreaTotal)
{

	return true;
}


