/*
 * Linea.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Clase encargada de almacenar la informacion de una linea ademas permite el calculo de imagenes y
 * preimagenes de dicha recta.
 */

#ifndef LINEA_HPP_
#define LINEA_HPP_

class Linea
{
	public:
		//Constructor y Destructor
		Linea(float rPosicionX1, float rPosicionY1, float rPosicionX2, float rPosicionY2);
		virtual ~Linea();

		//Getters
		float getPendiente();
		float getInterseccionY();

		//Metodos
		float calcularImagen(float rPreimagen);
		float calcularPreimagen(float rImagen);

	private:

		//Atributos
		float mPendiente;		//Pendiente de la linea recta
		float mInterseccionY;	//Interseccion con el eje y de la recta
};

#endif /* LINEA_HPP_ */
