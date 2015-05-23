//============================================================================
// Name        : Counting.cpp
// Author      : Alonso Loaiza Pereira
// Version     :
// Copyright   : GNU GPL 3.0
// Description : Hello World in C++, Ansi-style
//============================================================================


//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include <stdlib.h>
//#include <stdio.h>
//
//using namespace cv;
//
///// Global variables
//
//Mat src, src_gray;
//Mat dst, detected_edges;
//
//int edgeThresh = 1;
//int lowThreshold;
//int const max_lowThreshold = 100;
//int ratio = 3;
//int kernel_size = 3;
//char* window_name = "Edge Map";
//
///**
// * @function CannyThreshold
// * @brief Trackbar callback - Canny thresholds input with a ratio 1:3
// */
//void CannyThreshold(int, void*)
//{
//  /// Reduce noise with a kernel 3x3
//  blur( src_gray, detected_edges, Size(3,3), Point(-1,-1) );
//
//  /// Canny detector
//  Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
//
//  /// Using Canny's output as a mask, we display our result
//  dst = Scalar::all(0);
//
//  src.copyTo( dst, detected_edges);
//  imshow( window_name, dst );
// }
//
//
///** @function main */
//int main()
//{
//  /// Load an image
//  src = imread("Data/shape.jpg");
//
//  if( !src.data )
//  { return -1; }
//
//  /// Create a matrix of the same type and size as src (for dst)
//  dst.create( src.size(), src.type() );
//
//  /// Convert the image to grayscale
//  cvtColor( src, src_gray, CV_BGR2GRAY );
//
//  /// Create a window
//  namedWindow( window_name, CV_WINDOW_AUTOSIZE );
//
//  /// Create a Trackbar for user to enter threshold
//  createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold );
//
//  /// Show the image
//  CannyThreshold(0, 0);
//
//  /// Wait until user exit program by pressing a key
//  waitKey(0);
//
//  return 0;
//}
#include <fstream>
#include <iostream>
#include "Manager.hpp"
#include "FileReader.hpp"
#include "Filtro.hpp"
#include "Tracker.hpp"
#include "BlobDetector.hpp"
#include "ConfiguracionConexion.hpp"
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;

void imprimirVector(vector<int>* lista)
{
	for(int i = 0; i < lista->size(); i++)
	{
		cout<<"posicion: "<<i<<", numero: "<<lista->at(i)<<endl;
	}
}

void borrarElemento(vector<int>* rLista)
{
	rLista->erase(rLista->begin());
}

int main()
{
	time_t t = time(0);
	cout<<t<<endl;
//	Tracker* track = new Tracker();
//	Rect rect1(100,100,100,100);
//	Rect rect2(210,0,90,90);
//	//track->estanTraslapados();
//	float distance = track->calcularDistanciaRectangulos(rect1, rect2);
//	cout<<"Distancia total: "<<distance<<endl;
//	return 0;

//	VideoCapture* video = new VideoCapture("Data/traffic_road.mp4");
//	Filtro* filtro = new Filtro();
//	BlobDetector* blob_detector = new BlobDetector();
//	Tracker* track = new Tracker();
//	if(!video->isOpened())
//	{
//		cout<<"Error in load video"<<endl;
//		return -1;
//	}
//	while(true)
//	{
//		Mat image;
//		video->read(image);
//
//		Rect roi(220,400,700,300);
//		Mat img_roi ;
//		Mat img_roi2;
//		Mat img_roi3;
//		img_roi = image(roi).clone();
//		img_roi2 = image(roi).clone();
//		img_roi3 = image(roi).clone();
//		namedWindow("stream",WINDOW_NORMAL);
//		namedWindow("ROI",WINDOW_NORMAL);
//		//namedWindow("Gray Scale",WINDOW_NORMAL);
//		//namedWindow("Blur",WINDOW_NORMAL);
//		//namedWindow("Canny",WINDOW_NORMAL);
//		namedWindow("Contornos",WINDOW_NORMAL);
//		namedWindow("Contornos Filtrados",WINDOW_NORMAL);
//		namedWindow("BLOB",WINDOW_NORMAL);
//		namedWindow("BLOB2",WINDOW_NORMAL);
//		namedWindow("BLOB3",WINDOW_NORMAL);
//
//		Mat imagen_filtrada = filtro->filtrarImagen(image);
//		vector< vector<Point> > contornos = filtro->filtrarContornos(imagen_filtrada);
//		vector<Rect> blob = track->detectarBloques(contornos);
//		vector<Rect> blob3 = blob_detector->obtenerBlobsDeContornos(contornos);
//		RNG rng(12345);
//		for(int i = 0; i < contornos.size(); i++)
//		{
//			Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
//			Rect recn = boundingRect(contornos[i]);
//			int thickness = -1;
//			int lineType = 8;
//			float pos_x = recn.x + (float)recn.width/2;
//			float pos_y = recn.y + (float)recn.height/2;
//			circle( img_roi, Point(pos_x, pos_y), 5, color, thickness, lineType );
//			rectangle(img_roi, recn,  color ,2, 8,0);
//		}
//
//		for(int i = 0; i < blob.size(); i++)
//		{
//			Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
//			Rect recn = blob[i];
//			int thickness = -1;
//			int lineType = 8;
//			float pos_x = recn.x + (float)recn.width/2;
//			float pos_y = recn.y + (float)recn.height/2;
//			//circle( img_roi2, Point(pos_x, pos_y), 5, color, thickness, lineType );
//			rectangle(img_roi2, recn,  color ,2, 8,0);
//		}
//
//		for(int i = 0; i < blob3.size(); i++)
//		{
//			Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
//			Rect recn = blob3[i];
//			int thickness = -1;
//			int lineType = 8;
//			float pos_x = recn.x + (float)recn.width/2;
//			float pos_y = recn.y + (float)recn.height/2;
//			//circle( img_roi2, Point(pos_x, pos_y), 5, color, thickness, lineType );
//			rectangle(img_roi3, recn,  color ,2, 8,0);
//		}
//
//		//Dibuja el ROI en la imagen original
//		//Rect roi = Rect(220,400,700,300);
//		rectangle(image, roi,  Scalar(0,255,0),2, 8,0);
//		int thickness = 2;
//		int lineType = 8;
//		imshow("BLOB", img_roi);
//		imshow("BLOB2", img_roi2);
//		imshow("BLOB3", img_roi3);
//		line( image, Point(380,402),Point(220,611), Scalar( 0, 0, 255 ), thickness, lineType );
//		line( image, Point(742,405),Point(918,648), Scalar( 0, 0, 255 ), thickness, lineType );
//		imshow("stream", image);
//
//
//		int key = waitKey(33);
//		if(key == 27)
//		{
//			break;
//		}
//		if(key == 112)
//		{
//			waitKey();
//		}
//	}
//
//	video->release();
//	return 0;



//	FileReader* file_access = new FileReader();
//	vector<int> lista;
//	for(int i = 0; i < 10; i++)
//		lista.push_back(i);
//
//	cout << "Test" << endl;
//	cout << lista.size() << endl;
//	borrarElemento(&lista);
//	cout << lista.size() << endl;
//	//cout << file_access->buscarValor("LL") <<endl;
//	cout << "FIN" << endl;
//	return 0;
	//con->setDireccionIP("900.20.20");
	//vector<int>* lista = new vector<int>();
	//cout<< "tamano: "<<lista->size()<<endl;
	//lista->at(0) = 0;
	//lista->at(1) = 1;
	//lista->at(2) = 2;
	//lista->at(3) = 3;
	//imprimirVector(lista);
	//FileReader* reader = new FileReader();
	//vector<string>* split_list = reader->splitString("como==como==teta==vagi","==");
	//cout<<"Tamano: "<<split_list->size()<<endl;
	//for(int i = 0; i < (int)split_list->size(); i++)
	//{
	//	cout<<split_list->at(i)<<endl;
	//}
	//delete split_list;
//	Manager* man = new Manager();
//	int resultado = man->iniciarPrograma(1);
//	cout << resultado << endl;
	return 0;
}



//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <iostream>
//using namespace cv;
//using namespace std;
//
//int main( )
//{
//    Mat image;
//    image = imread("Data/shape.jpg", 1);
//    namedWindow( "Display window", CV_WINDOW_AUTOSIZE );
//    imshow( "Display window", image );
//    Mat gray;
//    cvtColor(image, gray, CV_BGR2GRAY);
//    Canny(gray, gray, 100, 200, 3);
//    /// Find contours
//    vector<vector<Point> > contours;
//    vector<Vec4i> hierarchy;
//    RNG rng(12345);
//    findContours( gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
//    /// Draw contours
//    Mat drawing = Mat::zeros( gray.size(), CV_8UC3 );
//    for( int i = 0; i< contours.size(); i++ )
//    {
//    	vector<Point> cant_point = contours[i];
//    	double area = contourArea(contours[i], false);
//    	cout << "Indice: "<< i << ", puntos: "<< cant_point.size()<< " area: "<< area  <<endl;
//    	if(cant_point.size() > 100)
//    	{
//			Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
//			drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
//    	}
//    }
//
//    imshow( "Result window", drawing );
//    waitKey(0);
//    return 0;
//}
