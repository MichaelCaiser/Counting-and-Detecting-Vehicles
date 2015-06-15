/*
 * Filtro.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Clase encargada de realizar tratamiento a las imagenes especificamente para la eliminacion de ruido,
 * por medio de ROI, Blur, Canny, etc. Tambien se encarga de la determinacion de los contornos en la imagen
 * aplicando un filtro de tamaño y posicion a los mismos.
 */

#ifndef FILTRO_HPP_
#define FILTRO_HPP_

//Bibliotecas
#include <opencv2/imgproc/imgproc.hpp>	//Biblioteca para el procesamiento de imagenes (canny, blur, findContours, etc)
#include <opencv2/highgui/highgui.hpp>	//Debe ser eliminado cuando se retiren las muestras de pantalla de la imagen
#include <vector>						//Manejo de vectores
#include "Region.hpp"	//Atributo mROI
#include "Linea.hpp"	//Atributos mLimiteDerecho y mLimiteIzquierdo

//Especificacion de clases por namespace
using std::vector;
using cv::Point;
using cv::Rect;
using cv::Mat;

class Filtro
{

public:

	//Constructor y Destructor
	Filtro();
	virtual ~Filtro();

	//Metodos
	Mat filtrarImagen(Mat rImagen);
	vector< vector<Point> >* filtrarContornos(Mat rImagen);

private:

	//Atributos
	Region* mROI;				//Region de Interes
	Linea* mLimiteDerecho;		//Limite derecho de la carretera
	Linea* mLimiteIzquierdo;	//Limite izquierdo de la carretera

	//Metodos
	bool filtrarContornoPorArea(vector<Point> rContorno);
	bool filtrarContornoPorLimites(vector<Point>* rContorno);
	float calcularPorcentaje(float rTotal, float rCantidad);
};

#endif /* FILTRO_HPP_ */
