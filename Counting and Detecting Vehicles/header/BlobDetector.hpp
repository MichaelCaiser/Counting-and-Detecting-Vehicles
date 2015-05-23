/*
 * BlobDetector.hpp
 *
 *  Created on: 1/5/2015
 *      Author: alonso
 */

//Bibliotecas
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>	//Utilizacion de funciones de procesamiento de opencv
#include <vector>						//Utilizacion de Vectores
#include <cmath> 						//Utilizacion de funcionces matematicas (sqrt)
using namespace cv;
using namespace std;

//Constantes
#define NOT_FOUND -1	//Indica que no fue encontrado

#ifndef BLOBDETECTOR_HPP_
#define BLOBDETECTOR_HPP_

class BlobDetector
{

public:

	//Constructor y Destructor
	BlobDetector();
	virtual ~BlobDetector();

	//Metodos
	vector<Rect> obtenerBlobsDeContornos(vector< vector<Point> > rContornos);

private:

	vector<Rect>* mBlobList;

	//Metodos
	int buscarFiguraTraslapada(Rect rRectangulo, vector< vector<Point> > rContornos);
	int buscarBlobPorCercania(Rect rRectangulo, vector<Rect> rListaBlob);
	float calcularDistanciaMinRectangulos(Rect rRect1, Rect rRect2);
	Rect combinarRectangulos(Rect rRect1, Rect rRect2);
	bool estanTraslapados(Rect rRect1, Rect rRect2);
	vector<Rect>* unirBlobsTraslapados(vector< vector<Point> > rContornos);
	vector<Rect>* unirBlobsPorCercania(vector< Rect >* rListaBlobs);

	//vector<Rect> detectarBlobsTraslapados(vector< vector<Point> > rContornos);
};

#endif /* BLOBDETECTOR_HPP_ */
