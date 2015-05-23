/*
 * Linea.cpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "Linea.hpp"

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */

Linea::Linea(float rPosicionX1, float rPosicionY1, float rPosicionX2, float rPosicionY2)
{
	// rX1 y rY1 corresponde a un punto, rX2 y rY2 cooresponde al otro punto
	mPendiente = (rPosicionY2-rPosicionY1)/(rPosicionX2-rPosicionX1);	//Calcula la pendiente de la recta
	mInterseccionY = rPosicionY1-(rPosicionX1*mPendiente);				//Calcula la interseccion con el eje y
}

Linea::~Linea()
{
	// TODO Auto-generated destructor stub
}

/*
 *********************************************************************************
 *                                 Getters                                       *
 *********************************************************************************
 */
float Linea::getPendiente()
{
	return mPendiente;
}

float Linea::getInterseccionY()
{
	return mInterseccionY;
}

/*
 *********************************************************************************
 *                                 Metodos                                       *
 *********************************************************************************
 */

/*
 * @name calcularImagen
 * @param
 * - rPreimgaen : float (Preimagen a la cual se le desea calcular su imagen)
 * @return
 * - float (imagen)
 * @Descrition
 * 		Metodo encargado de calcular la imagen de la funcion lineal dada una preimagen,
 * 		la funcion lineal corresponde a la descrita por la linea recta.
 */
float Linea::calcularImagen(float rPreimagen)
{
	float coordenada_y = (rPreimagen*mPendiente) + mInterseccionY;	//Calcula la imagen a partir de la preimagen
	return coordenada_y;
}

/*
 * @name calcularPreimagen
 * @param
 * - rImgaen : float (Imagen a la cual se le desea calcular su preimagen)
 * @return
 * - float (Preimagen)
 * @Descrition
 * 		Metodo encargado de calcular la preimagen de la funcion lineal dada una imagen,
 * 		la funcion lineal corresponde a la descrita por la linea recta.
 *
 */
float Linea::calcularPreimagen(float rImagen)
{
	float coordenada_x = (rImagen-mInterseccionY)/mPendiente;	//Calcula la preimagen a partir de la imagen
	return coordenada_x;
}
