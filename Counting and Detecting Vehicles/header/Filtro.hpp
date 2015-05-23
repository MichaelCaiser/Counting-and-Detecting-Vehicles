/*
 * Filtro.hpp
 *
 * Author: Alonso Loaiza Pereira
 * e-mail: hiyitsu@gmail.com
 * University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * Description: Clase encargada de aplicar filtros a imagenes.
 */

//Bibliotecas
#include "Region.hpp"	//Atributo mROI
#include "Linea.hpp"	//Atributos mLimiteDerecho y mLimiteIzquierdo

#include <opencv2/imgproc/imgproc.hpp>	//Biblioteca para el procesamiento de imagenes (canny, blur, findContours, etc)
#include <opencv2/highgui/highgui.hpp>	//Debe ser eliminado cuando se retiren las muestras de pantalla de la imagen
#include <vector>	//Manejo de vectores
#include <iostream>	//Debe ser eliminado cuando se retiren los prints
using namespace cv;
using namespace std;

#ifndef FILTRO_HPP_
#define FILTRO_HPP_

class Filtro
{

public:

	//Constructor y Destructor
	Filtro();
	virtual ~Filtro();

	//Metodos
	Mat filtrarImagen(Mat rImagen);
	vector< vector<Point> > filtrarContornos(Mat rImagen);

private:

	//Atributos
	Region* mROI;
	Linea* mLimiteDerecho;
	Linea* mLimiteIzquierdo;

	//Metodos
	bool filtrarContornoPorArea(vector<Point> rContorno);
	bool filtrarContornoPorLimites(vector<Point>* rContorno);
	float calcularPorcentaje(float rTotal, float rCantidad);
};

#endif /* FILTRO_HPP_ */
