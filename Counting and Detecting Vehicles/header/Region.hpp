/*
 * Region.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Es una clase simple contenedora de informacion (POJO), dicha informacion corresponde a la de una
 * region, para ello almacenando atributos como lo son su posicion por medio de las coordenadas X y Y, así
 * como su altura y ancho. Implementa metodos simple de acceso a los datos por medio de getters y setters.
 */

#ifndef REGION_HPP_
#define REGION_HPP_

class Region
{

public:
	//Constructor y Destructor
	Region(int rPosicionX, int rPosicionY,int rAncho,int rAlto);
	~Region();

	//Setters
	void setPosicion(int rPosicionX, int rPosicionY);
	void setAncho(int rAncho);
	void setAlto(int rAlto);

	//Getters
	int getPosicionX();
	int getPosicionY();
	int getAncho();
	int getAlto();

	//Metodos
	int getArea();

private:

	//Atributos
	int mPosicionX;	//Posicion X inicial de la region
	int mPosicionY;	//Posicion Y inicial de la region
	int mAncho;		//Ancho de la region
	int mAlto;		//Alto de la region
};

#endif /* REGION_HPP_ */
