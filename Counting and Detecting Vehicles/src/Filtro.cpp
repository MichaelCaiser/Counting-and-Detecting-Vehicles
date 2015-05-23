/*
 * Filtro.cpp
 *
 * Author: Alonso Loaiza Pereira
 * e-mail: hiyitsu@gmail.com
 * University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "Filtro.hpp"

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */

Filtro::Filtro()
{
	// Hay que cambiarlo por el factory cuidado
	mROI = new Region(220,400,700,300);
	mLimiteDerecho = new Linea(515,0,698,263);
	mLimiteIzquierdo = new Linea(165,0,13,203);
}

Filtro::~Filtro()
{
	//Libera la memoria de los punteros de los atributos
	delete mROI;
	delete mLimiteDerecho;
	delete mLimiteIzquierdo;
}

/*
 *********************************************************************************
 *                                 Metodos                                       *
 *********************************************************************************
 */

/*
 * @name filtrarImagen
 * @param
 * rImagen : Mat (Matriz que representa una imagen)
 * @return
 * Mat (Imagen filtrada)
 * @Descrition
 * 		Metodo encargado de dada una imagen filtrarla por medio diversos tipos de filtros como lo son
 * 		region de intereres(ROI), escala de grises, blur y Canny.
 */
Mat Filtro::filtrarImagen(Mat rImagen)
{

	//Aplica Region de Interes
	Rect roi(mROI->getPosicionX(), mROI->getPosicionY(), mROI->getAncho(), mROI->getAlto());	//Rectangulo que contiene la ROI
	Mat roi_img;
	roi_img = rImagen(roi);	//Se calcula la ROI


	//Aplica Escala de Grises
	Mat gray_img;
	cvtColor(roi_img, gray_img, CV_BGR2GRAY);	//Se calcula la escala de grises

	//Aplica un filtro Blur
	Mat blur_img;
	blur(gray_img, blur_img, Size(3,3));	//Se aplica el filtro blur con un kernel de 3

	//Aplica Algoritmo de Canny
	Mat canny_img;
	Canny(blur_img, canny_img, 70, 180, 3, true);	//Se aplica el canny con un threshold de 70-180

	//Mostrar en pantalla
	int thickness = 1;
	int lineType = 8;
	line( roi_img, Point(515,0),Point(698,263), Scalar( 0, 0, 255 ), thickness, lineType );
	line( roi_img, Point(165,0),Point(13,203), Scalar( 0, 0, 255 ), thickness, lineType );
	imshow("ROI", roi_img);
	//imshow("Gray Scale", gray_img);
	//imshow("Blur", blur_img);
	//imshow("Canny", blur_img);

	return canny_img;
}

/*
 * @name filtrarContornos
 * @param
 * rImagen : Mat (Matriz que representa una imagen)
 * @return
 * vecotr< vector<Poin> > (Lista de contornos de la imagen)
 * @Descrition
 * 		Metodo encargado de determinar los contornos de una imagen, y ademas de filtrar dichos contornos
 * 		segun sea su jerarquia, tamano y area.
 */
vector< vector<Point> > Filtro::filtrarContornos(Mat rImagen)
{
	//Lista con los contornos(lista de puntos que describen una figura) de la imagen
	vector<vector<Point> > contornos;

	//Lista con la jerarquia de los contornos de la imagen
	//Formato de la jerarquia de un contorno {siguiente, anterior, hijo, padre}
	vector<Vec4i> jerarquia;

	//Metodo calcula los contornos de la imagen, y la jerarquia de dichos contornos
	findContours(rImagen, contornos, jerarquia, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

	//Mostrar en pantalla
	Mat drawing = Mat::zeros(rImagen.size(), CV_8UC3 );
	Mat drawing_filter = Mat::zeros(rImagen.size(), CV_8UC3 );
	RNG rng(12345);

	//Mostrar en pantalla
	for(unsigned int i = 0; i < contornos.size(); i++)
	{
		Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
		drawContours( drawing, contornos, i, color, CV_FILLED, 8, jerarquia, 0, Point() );
		//Rect bounding_rect = boundingRect(contornos[i]);
		//rectangle(drawing, bounding_rect,  Scalar(0,255,0),2, 8,0);
	}

	//Mostrar pantalla
	cout<<"----------------------------------------------------------------------------------------"<<endl;
	cout<<"Contornos totales: "<<contornos.size()<<endl;
	int total = 0;

	//Necesario
	vector< vector<Point> > contornos_filtrados;	//Lista con los contornos que pasen el filtro
	int indice = 0;
	int cant_contornos = contornos.size();
	cout<<"============================================================================================"<<endl;
	while(indice < cant_contornos)
	{
		vector<Point> contorno = contornos[indice];
		cout<<"CONTORNO NUM = "<<indice<<endl;
		if(filtrarContornoPorArea(contorno) && filtrarContornoPorLimites(&contorno))	//Filtra el contorno por area y limites
		{
			contornos_filtrados.push_back(contorno);
			Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
			drawContours( drawing_filter, contornos, indice, color, CV_FILLED, 8, jerarquia, 0, Point() );

			//Mostrar pantalla
			total++;
		}

		//Calcula el indice siguiente a partir de la jerarquia buscando al siguiente contorno
		//al mismo nivel que el contorno actual.
		indice = jerarquia[indice][0];

		if(indice == -1)	//Si el indice es igual a -1 indica que no hay mas contornos al mismo nivel
		{
			break;			//Termina el ciclo
		}
	}
	cout<<"============================================================================================"<<endl;

	//Mostrar en pantalla
	cout<<"Contornos que pasaron el filtro: "<<total<<endl;
	cout<<"----------------------------------------------------------------------------------------"<<endl;

	//Mostrar en pantalla
	imshow("Contornos", drawing);
	imshow("Contornos Filtrados", drawing_filter);
	return contornos_filtrados;
}

/*
 * @name filtrarContornoPorArea
 * @param
 * rContorno : vector<Point> (es un contorno, lista de puntos que describen una figura)
 * @return
 * bool (indicando si el contorno paso el filtro de area)
 * @Descrition
 * 		Metodo encargado filtrar un contorno por el tamano de su area, comparando el tamano de la figura con
 * 		el tamano total de la imagen, en caso que el contorno un tamano demasiado grande se envia un retorna
 * 		un valor booleano de falso.
 */
bool Filtro::filtrarContornoPorArea(vector<Point> rContorno)
{
	Rect rectangulo_limite_contorno = boundingRect(rContorno);	//Calcula el rectangulo limite del contorno
	int area_contorno = rectangulo_limite_contorno.area();		//Calcula el area del rectangulo limite
	int area_imagen = mROI->getArea();							//Obtiene el area de la imagen

	//Calcula el porcentaje del tamano del rectangulo limite con el tamano de la imagen
	float porcentaje_contorno = calcularPorcentaje(area_imagen, area_contorno);
	if(porcentaje_contorno < 20)	//Verifica que el porcentaje sea menor al 20
	{
		return true;
	}
	return false;
}

/*
 * @name filtrarContornosPorLimites
 * @param
 * rContorno : vector<Point> (es un contorno, lista de puntos que describen una figura)
 * @return
 * bool (indicando si el contorno paso el filtro de limites)
 * @Descrition
 * 		Metodo encargado filtrar un contorno por sus limites, es decir su posicion, especificamente si se encuentra
 * 		dentro de la linea de la carretera, para ello se hace uso de las lineas limite de la carretera tanto derecha
 * 		como izquierda.
 */
bool Filtro::filtrarContornoPorLimites(vector<Point>* rContorno)
{
	int cant_punt_fuera_lim_der = 0;		//Cantidad de puntos del contorno fuera de la linea derecha
	int cant_punt_fuera_lim_izq = 0;		//Cantidad de puntos del contorno fuera de la linea izquierda
	int cant_puntos = rContorno->size();	//Cantidad de puntos totales del contorno

	cout<<"Puntos totales: "<<cant_puntos<<endl;
	for(int i = 0; i < cant_puntos; i++)
	{

		Point punto = (*rContorno)[i];
		cout<<"Punto, X: "<<punto.x<<" Y: "<<punto.y<<endl;
		int pos_y_rect_der = mLimiteDerecho->calcularImagen(punto.x);	//calcula el valor y de la linea derecha de la carretera
		int pos_y_rect_izq = mLimiteIzquierdo->calcularImagen(punto.x);	//calcula el valor y de la linea izquierda de la carretera
		if(pos_y_rect_der >= punto.y)		//Verifica que el punto este dentro de la linea derecha
		{
			cant_punt_fuera_lim_der++;
		}
		if(pos_y_rect_izq >= punto.y)		//Verifica que el punto este dentro de la linea izquierda
		{
			cant_punt_fuera_lim_izq++;
		}
	}

	float porcentaje_lim_der = calcularPorcentaje(cant_puntos, cant_punt_fuera_lim_der);	//Calula el porcentaje de los puntos fuera de la linea derecha respecto al total de puntos
	float porcentaje_lim_izq = calcularPorcentaje(cant_puntos, cant_punt_fuera_lim_izq);	//Calula el porcentaje de los puntos fuera de la linea izquierda respecto al total de puntos

	if(porcentaje_lim_der < 20 && porcentaje_lim_izq < 20)	//Verifica que el porcentaje de puntos fuera de las lineas no sea mayor al 20%
	{
		return true;
	}
	if((porcentaje_lim_der < 100 && porcentaje_lim_der >= 20) ||
	   (porcentaje_lim_izq < 100 && porcentaje_lim_izq >= 20))	//Verifica que el porcentaje de puntos fuera de las lineas no sea mayor al 95%
	{
		int indice = 0;
		int cant_puntos = rContorno->size();
		while(indice < cant_puntos)
		{
			Point punto = (*rContorno)[indice];
			int pos_y_rect_der = mLimiteDerecho->calcularImagen(punto.x);	//calcula el valor y de la linea derecha de la carretera
		    int pos_y_rect_izq = mLimiteIzquierdo->calcularImagen(punto.x);	//calcula el valor y de la linea izquierda de la carretera
			if(pos_y_rect_der >= punto.y || pos_y_rect_izq >= punto.y)		//Verifica que el punto este dentro de la linea derecha
			{
				rContorno->erase(rContorno->begin()+indice);
				cant_puntos--;
			}
			else
			{
				indice++;
			}
		}
		return true;
	}
	return false;
}

/*
 * @name calcularPorcentaje
 * @param
 * rTotal : float (cantidad total)
 * rCantidad : float (cantidad sobre la que se calcula el porcentaje)
 * @return
 * float (calculo del porcentaje de la cantidad sobre el total)
 * @Descrition
 * 		Metodo encargado de calcular el porcentaje que representa una cantidad respecto a un valor total.
 */
float Filtro::calcularPorcentaje(float rTotal, float rCantidad)
{
	float porcentaje = (rCantidad/rTotal)*100;	//Calculo del porcentaje
	return porcentaje;
}

