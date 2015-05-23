/*
 * Region.cpp
 *
 * Author: Alonso Loaiza Pereira
 * e-mail: hiyitsu@gmail.com
 * University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "Region.hpp"

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */

Region::Region(int rPosicionX, int rPosicionY,int rAncho,int rAlto)
{
	mPosicionX = rPosicionX;
	mPosicionY = rPosicionY;
	mAncho = rAncho;
	mAlto = rAlto;
}

Region::~Region()
{
	// TODO Auto-generated destructor stub
}


/*
 *********************************************************************************
 *                                 Setters                                       *
 *********************************************************************************
 */
void Region::setPosicion(int rPosicionX, int rPosicionY)
{
	mPosicionX = rPosicionX;
	mPosicionY = rPosicionY;
}

void Region::setAncho(int rAncho)
{
	mAncho = rAncho;
}

void Region::setAlto(int rAlto)
{
	mAlto = rAlto;
}

/*
 *********************************************************************************
 *                                 Getters                                       *
 *********************************************************************************
 */
int Region::getPosicionX()
{
	return mPosicionX;
}

int Region::getPosicionY()
{
	return mPosicionY;
}

int Region::getAlto()
{
	return mAlto;
}

int Region::getAncho()
{
	return mAncho;
}

/*
 *********************************************************************************
 *                                 Metodos                                       *
 *********************************************************************************
 */

/*
 * @name getArea
 * @param
 * @return
 * - int (Area de la region)
 * @Descrition
 * 		Metodo encargado de calcular el area de la region delimitada, el area se calcula
 * 		como la multiplicacion del alto por el ancho dado que la region es un rectangulo.
 */
int Region::getArea()
{
	int area = mAncho*mAlto;
	return area;
}

