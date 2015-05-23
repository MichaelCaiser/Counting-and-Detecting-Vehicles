/*
 * BlobDetector.cpp
 *
 *  Created on: 1/5/2015
 *      Author: alonso
 */

#include "BlobDetector.hpp"

BlobDetector::BlobDetector()
{
	// TODO Auto-generated constructor stub
	mBlobList = new vector<Rect>();
}

BlobDetector::~BlobDetector()
{
	// TODO Auto-generated destructor stub
	mBlobList->clear();
	delete mBlobList;
}

vector<Rect> BlobDetector::obtenerBlobsDeContornos(vector< vector<Point> > rContornos)
{
	vector<Rect>* lista_blobs = unirBlobsTraslapados(rContornos);
	vector<Rect>* lista_blobs_cercanos = unirBlobsPorCercania(lista_blobs);
	delete lista_blobs;
	return *lista_blobs_cercanos;
}

vector<Rect>* BlobDetector::unirBlobsTraslapados(vector< vector<Point> > rContornos)
{
	vector<Rect>* lista_blobs = new vector<Rect>();
	while(rContornos.size() != 0)
	{
		vector<Point> contorno_base = rContornos.at(0);			//Obtiene el primer contorno de la lista
		Rect rectangulo_contorno = boundingRect(contorno_base);	//Calcula el rectangulo del contorno
		rContornos.erase(rContornos.begin());					//Elimina el contorno de la lista
		int indice_fig_traslapada;								//Indice de la figura que se traslapa con el contorno
		do
		{
			indice_fig_traslapada = buscarFiguraTraslapada(rectangulo_contorno, rContornos);	//Busca el indice de la figura que se traslapa con el contorno
			if(indice_fig_traslapada != NOT_FOUND)		//Verifica que el indice no sea -1
			{
				vector<Point> contorno_traslapado = rContornos.at(indice_fig_traslapada);		//Contorno que se traslapa con el contorno inicial
				Rect rectangulo_traslapado = boundingRect(contorno_traslapado);					//Rectangulo del contorno traslapado
				rectangulo_contorno = combinarRectangulos(rectangulo_contorno, rectangulo_traslapado);	//Une ambos rectangulos
				rContornos.erase(rContornos.begin()+indice_fig_traslapada);						//Elmina el contorno traslapado de la lista
			}
		}while(indice_fig_traslapada != NOT_FOUND);	//Verifica que el indice sea diferente de -1
		lista_blobs->push_back(rectangulo_contorno);	//Agrega el rectangulo del contorno al vector de blob
	}
	return lista_blobs;
}

vector<Rect>* BlobDetector::unirBlobsPorCercania(vector< Rect >* rListaBlobs)
{
	vector<Rect>* lista_blobs_cercanos = new vector<Rect>();
	vector<Rect>* lista_blobs_temporales = new vector<Rect>();
	while(rListaBlobs->size() != 0)
	{
		Rect rectangulo_base = rListaBlobs->at(0);
		int indice_blob_cercano;

		rListaBlobs->erase(rListaBlobs->begin());
		lista_blobs_temporales->clear();

		do
		{
			indice_blob_cercano = buscarBlobPorCercania(rectangulo_base, *rListaBlobs);
			if(indice_blob_cercano != NOT_FOUND)
			{
				Rect blob_cercano = rListaBlobs->at(indice_blob_cercano);
				lista_blobs_temporales->push_back(blob_cercano);
				rListaBlobs->erase(rListaBlobs->begin()+indice_blob_cercano);
			}
		}
		while(indice_blob_cercano != NOT_FOUND);

		for(int indice = 0; indice < lista_blobs_temporales->size(); indice++)
		{
			rectangulo_base = combinarRectangulos(rectangulo_base, lista_blobs_temporales->at(indice));
		}

		lista_blobs_cercanos->push_back(rectangulo_base);
	}
	return lista_blobs_cercanos;
}

int BlobDetector::buscarBlobPorCercania(Rect rRectangulo, vector< Rect > rListaBlob)
{
	for(unsigned int i = 0; i < rListaBlob.size(); i++)
	{
		Rect rectangulo_blob = rListaBlob.at(i);
		float distancia = calcularDistanciaMinRectangulos(rRectangulo, rectangulo_blob);

		if(distancia <= 15)
		{
			return i;
		}
	}
	return NOT_FOUND;
}


/*
 * @name buscarFiguraTraslapada
 * @param
 * - rRectangulo : Rect (Rectangulo de la libreria opencv)
 * - rContornos : vector< vector<Point> > (Una lista de contornos, los contornos a su vez son una lista de puntos)
 * @return
 * - int (Entero que indica la posicion dentro la lista de con)
 * @Descrition
 * 		Este Metodo se encarga de buscar dentro de la lista de contornos alguno cuyo rectangulo delimitador
 * 		se traslape con el rectangulo que se encuentra como parametro, en dado caso retornara un entero que
 * 		corresponde a la posicion de dicho contorno. En caso de no hayar algun contorno cuyo rectangulo
 * 		delimitador se traslape se retornara un valor de -1 para indicar dicha condicion.
 */
int BlobDetector::buscarFiguraTraslapada(Rect rRectangulo, vector< vector<Point> > rContornos)
{
	for(unsigned int i = 0; i < rContornos.size(); i++)
	{
		vector<Point> figura = rContornos.at(i);		//obtiene el contorno ubicado en la posicion del contador
		Rect rectangulo_figura = boundingRect(figura);	//calcula el rectangulo delimitador del contorno

		if(estanTraslapados(rRectangulo, rectangulo_figura))	//verifica si el rectangulo parametro y el del contorno se traslapan
		{
			return i;	//retorna la posicion del contorno en la lista
		}
	}
	return NOT_FOUND;	//retorna un valor de -1 indicando que no encontro nada
}


/*
 * @name estanTraslapados
 * @param
 * - rRect1 : Rect (Rectangulo de la libreria opencv)
 * - rRect2 : Rect (Rectangulo de la libreria opencv)
 * @return
 * - bool (Booleano que indica si los rectangulos se encuetran traslapados)
 * @Descrition
 * 		Este Metodo se encarga de determinar si dados dos rectangulos los mismos se traslapan entre si,
 * 		es decir si uno de los rectangulos cuenta con una parte de el sobre puesta sobre el otro
 * 		rectangulo.  En caso que los rectangulos se encuentren traslapados entre si el metodo devuelve un
 * 		valor booleano de verdad.
 */
bool BlobDetector::estanTraslapados(Rect rRect1, Rect rRect2)
{
	//Posiciones del Rectangulo 1 con los que es posible calcular sus 4 vertices
	int rect1_pos_x1 = rRect1.x;					//Posicion x inicial del rectangulo 1
	int rect1_pos_x2 = rRect1.x + rRect1.width;		//Posicion x final del rectangulo 1
	int rect1_pos_y1 = rRect1.y;					//Posicion y inicial del rectangulo 1
	int rect1_pos_y2 = rRect1.y + rRect1.height;	//Posicion y final del rectangulo 1

	//Posiciones del Rectangulo 2 con los que es posible calcular sus 4 vertices
	int rect2_pos_x1 = rRect2.x;					//Posicion x inicial del rectangulo 2
	int rect2_pos_x2 = rRect2.x + rRect2.width;		//Posicion x final del rectangulo 2
	int rect2_pos_y1 = rRect2.y;					//Posicion y inicial del rectangulo 2
	int rect2_pos_y2 = rRect2.y + rRect2.height;	//Posicion y final del rectangulo 2

	if((rect2_pos_x1 <= rect1_pos_x1 && rect1_pos_x1 <= rect2_pos_x2) ||
	   (rect2_pos_x1 <= rect1_pos_x2 && rect1_pos_x2 <= rect2_pos_x2) ||
	   (rect2_pos_x1 > rect1_pos_x1 && rect1_pos_x2 > rect2_pos_x2) )
	{
		if((rect2_pos_y1 <= rect1_pos_y1 && rect1_pos_y1 <= rect2_pos_y2) ||
		   (rect2_pos_y1 <= rect1_pos_y2 && rect1_pos_y2 <= rect2_pos_y2) ||
		   (rect2_pos_y1 > rect1_pos_y1 && rect1_pos_y2 > rect2_pos_y2))
		{
			return true;
		}
	}
	return false;
}

/*
 * @name combinarRectangulos
 * @param
 * - rRect1 : Rect (Rectangulo de la libreria opencv)
 * - rRect2 : Rect (Rectangulo de la libreria opencv)
 * @return
 * - Rect (Un rectangulo formado de la combinacion de los dos rectangulos)
 * @Descrition
 * 		Este metodo se encagarga que a partir de 2 rectangulos formar un tercer rectangulo tomando como base
 * 		los vertices menores y mayores de los rectangulos, para de esta manera formar un rectangulo cuya area
 * 		sea la mayor y que abarque ambos rectangulos.
 */
Rect BlobDetector::combinarRectangulos(Rect rRect1, Rect rRect2)
{
	int pos_x_rect = rRect1.x;					//Asigna la posicion x a la posicion del Rect1
	int pos_y_rect = rRect1.y;					//Asigna la posicion y a la posicion del Rect1
	int pos_ancho = rRect1.x + rRect1.width;	//Asigna la posicion del ancho a la del Rect1
	int pos_alto = rRect1.y + rRect1.height;	//Asigna la posicion del ancho a la del Rect1

	if(pos_x_rect > rRect2.x)					//Verifica si la posicion x del Rect1 es menor a la del Rect2
	{
		pos_x_rect = rRect2.x;					//Cambia la posicion x a la del Rect2
	}

	if(pos_y_rect > rRect2.y)					//Verifica si la posicion y del Rect1 es mayor a la del Rect2
	{
		pos_y_rect = rRect2.y;					//Cambia la posicion y a la del Rect2
	}

	if(pos_ancho < (rRect2.x+rRect2.width))		//Verifica que la posicion del ancho del Rect1 sea mayor a la del Rect2
	{
		pos_ancho = rRect2.x+rRect2.width;		//Cambia la posicion del ancho a la del Rect2
	}

	if(pos_alto < (rRect2.y+rRect2.height))		//Verifica que la posicion del alto del Rect1 sea mayor a la del Rect2
	{
		pos_alto = rRect2.y+rRect2.height;		//Cambia la posicion del alto a la del Rect2
	}

	int alto = pos_alto-pos_y_rect;				//calcula el alto del nuevo rectangulo
	int ancho = pos_ancho-pos_x_rect;			//calcula el ancho del nuevo rectangulo

	Rect nuevo_rectangulo(pos_x_rect,pos_y_rect,ancho,alto);	//Crea el nuevo rectangulo con los valores calculados
	return nuevo_rectangulo;
}


/*
 * @name calcularDistanciaMinRectangulos
 * @param
 * - rRect1 : Rect (Rectangulo de la libreria opencv)
 * - rRect2 : Rect (Rectangulo de la libreria opencv)
 * @return
 * - float (Distancia minima entre ambos rectangulos)
 * @Descrition
 * 		Este metodo se encagarga que a partir de 2 rectangulos calcular la distancia minima entre ambos.
 * 		Cabe mencionar que este metodo funciona para rectangulos que no se encuentran traslapados.
 */
float BlobDetector::calcularDistanciaMinRectangulos(Rect rRect1, Rect rRect2)
{
	int distancia_x = 0;	//Distancia con respecto al eje x entre ambos rectangulos
	int distancia_y = 0;	//Distancia con respecto al eje y entre ambos rectangulos

	if((rRect1.x <= rRect2.x && rRect2.x <= rRect1.x + rRect1.width) ||
	   (rRect1.x <= rRect2.x+rRect2.width && rRect2.x+rRect2.width <= rRect1.x + rRect1.width))
	{
		if(rRect1.y < rRect2.y)
		{
			return rRect2.y - rRect1.y - rRect1.height;
		}
		else
		{
			return rRect1.y - rRect2.y - rRect2.height;
		}
	}

	if((rRect1.y <= rRect2.y && rRect2.y <= rRect1.y + rRect1.height) ||
	   (rRect1.y <= rRect2.y+rRect2.height && rRect2.y+rRect2.height <= rRect1.y + rRect1.height))
	{
		if(rRect1.x < rRect2.x)
		{
			return rRect2.x - rRect1.x - rRect1.width;
		}
		else
		{
			return rRect1.x - rRect2.x - rRect2.width;
		}
	}

	if(rRect1.x < rRect2.x)
	{
		distancia_x = rRect2.x - rRect1.x - rRect1.width;
	}
	else
	{
		distancia_x = rRect1.x - rRect2.x - rRect2.width;
	}

	if(rRect1.y < rRect2.y)
	{
		distancia_y = rRect2.y - rRect1.y - rRect1.height;
	}
	else
	{
		distancia_y = rRect1.y - rRect2.y - rRect2.height;
	}

	float distancia_total = sqrt((distancia_x*distancia_x)+(distancia_y*distancia_y));	//calcula la distancia a traves del teorema de pitagoras
	return distancia_total;
}

