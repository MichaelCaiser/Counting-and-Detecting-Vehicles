/*
 * Tracker.cpp
 *
 *  Created on: 24/4/2015
 *      Author: alonso
 */

#include "Tracker.hpp"

Tracker::Tracker()
{
	// TODO Auto-generated constructor stub
	mBloques = new vector<Rect>();
}

Tracker::~Tracker()
{
	// TODO Auto-generated destructor stub
	mBloques->clear();
	delete mBloques;
}

vector<Rect> Tracker::detectarBloques(vector< vector<Point> > rContornos)
{
	mBloques->clear();
	//cout<<"====================================================================="<<endl;
	cout<<"contornos totales: "<<rContornos.size()<<endl;
	while(rContornos.size() != 0)
	{
		vector<Point> contorno_base = rContornos.at(0);
		rContornos.erase(rContornos.begin());
		Rect rectangulo_contorno = boundingRect(contorno_base);
		//cout<<"RECTANGULO"<<endl;
		//cout<<"posx: "<<rectangulo_contorno.x<<" posy: "<<rectangulo_contorno.y<<" ancho: "<<rectangulo_contorno.width<<" alto: "<<rectangulo_contorno.height<<endl;
		bool contorno_traslapado = true;
		//cout<<"SE TRASLAPA"<<endl;
		while(contorno_traslapado)
		{
			int indice_fig_traslapada = buscarFiguraTraslapada(rectangulo_contorno, rContornos);
			if(indice_fig_traslapada != NOT_FOUND)
			{
				vector<Point> contorno_traslapado = rContornos.at(indice_fig_traslapada);
				Rect rectangulo_traslapado = boundingRect(contorno_traslapado);
				rectangulo_contorno = combinarRectangulos(rectangulo_contorno, rectangulo_traslapado);
				rContornos.erase(rContornos.begin()+indice_fig_traslapada);
				//cout<<"posx: "<<rectangulo_traslapado.x<<" posy: "<<rectangulo_traslapado.y<<" ancho: "<<rectangulo_traslapado.width<<" alto: "<<rectangulo_traslapado.height<<endl;
				//break;
			}
			else
			{
				contorno_traslapado = false;
			}
		}
		//cout<<"RECT RESULTANTE"<<endl;
		//cout<<"posx: "<<rectangulo_contorno.x<<" posy: "<<rectangulo_contorno.y<<" ancho: "<<rectangulo_contorno.width<<" alto: "<<rectangulo_contorno.height<<endl;
		mBloques->push_back(rectangulo_contorno);
	}
	cout<<"bloques totales: "<<mBloques->size()<<endl;
	//cout<<"=================================================================="<<endl;
	return *mBloques;
}

int Tracker::buscarFiguraTraslapada(Rect rRectangulo, vector< vector<Point> > rContornos)
{
	for(unsigned int i = 0; i < rContornos.size(); i++)
	{
		vector<Point> figura = rContornos.at(i);
		Rect rectangulo_figura = boundingRect(figura);

		if(estanTraslapados(rRectangulo, rectangulo_figura))
		{
			return i;
		}
	}
	return NOT_FOUND;
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
bool Tracker::estanTraslapados(Rect rRect1, Rect rRect2)
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
 * - Rect (Un rectangulo formado de la combinacion de los dos rectangulos de parametro)
 * @Descrition
 * 		Este metodo se encagarga que a partir de 2 rectangulos formar un tercer rectangulo tomando como base
 * 		los vertices menores y mayores de los rectangulos, para de esta manera formar un rectangulo cuya area
 * 		sea la mayor y que abarque ambos rectangulos.
 */
Rect Tracker::combinarRectangulos(Rect rRect1, Rect rRect2)
{
	int pos_x_rect = rRect1.x;					//Asigna la posicion x a la posicion del Rect1
	int pos_y_rect = rRect1.y;					//Asigna la posicion y a la posicion del Rect1
	int pos_ancho = rRect1.x + rRect1.width;	//Asigna la posicion del ancho al del Rect1
	int pos_alto = rRect1.y + rRect1.height;	//Asigna la posicion del ancho al del Rect1

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
 * @name combinarRectangulos
 * @param
 * - rRect1 : Rect (Rectangulo de la libreria opencv)
 * - rRect2 : Rect (Rectangulo de la libreria opencv)
 * @return
 * - Rect (Un rectangulo formado de la combinacion de los dos rectangulos de parametro)
 * @Descrition
 * 		Este metodo se encagarga que a partir de 2 rectangulos formar un tercer rectangulo tomando como base
 * 		los vertices menores y mayores de los rectangulos, para de esta manera formar un rectangulo cuya area
 * 		sea la mayor y que abarque ambos rectangulos.
 */
float Tracker::calcularDistanciaRectangulos(Rect rRect1, Rect rRect2)
{
	int distancia_x = 0;
	int distancia_y = 0;

	if((rRect1.x <= rRect2.x && rRect2.x <= rRect1.x + rRect1.width) ||
	   (rRect1.x <= rRect2.x+rRect2.width && rRect2.x+rRect2.width <= rRect1.x + rRect1.width))
	{
		if(rRect1.y < rRect2.y)
		{
			cout<<"Entro 1"<<endl;
			return rRect2.y - rRect1.y - rRect1.height;
		}
		else
		{
			cout<<"Entro 2"<<endl;
			return rRect1.y - rRect2.y - rRect2.height;
		}
	}

	if((rRect1.y <= rRect2.y && rRect2.y <= rRect1.y + rRect1.height) ||
	   (rRect1.y <= rRect2.y+rRect2.height && rRect2.y+rRect2.height <= rRect1.y + rRect1.height))
	{
		if(rRect1.x < rRect2.x)
		{
			cout<<"Entro 3"<<endl;
			return rRect2.x - rRect1.x - rRect1.width;
		}
		else
		{
			cout<<"Entro 4"<<endl;
			return rRect1.x - rRect2.x - rRect2.width;
		}
	}

	if(rRect1.x < rRect2.x)
	{
		cout<<"Entro 5"<<endl;
		distancia_x = rRect2.x-rRect1.x-rRect1.width;
		cout<<"Distancia x: "<<distancia_x<<endl;
	}
	else
	{
		cout<<"Entro 6"<<endl;
		distancia_x = rRect1.x-rRect2.x-rRect2.width;
		cout<<"Distancia x: "<<distancia_x<<endl;
	}

	if(rRect1.y < rRect2.y)
	{
		cout<<"Entro 7"<<endl;
		distancia_y = rRect2.y-rRect1.y-rRect1.height;
		cout<<"Distancia y: "<<distancia_y<<endl;
	}
	else
	{
		cout<<"Entro 8"<<endl;
		distancia_y = rRect1.y-rRect2.y-rRect2.height;
		cout<<"Distancia y: "<<distancia_y<<endl;
	}

	float distancia_total = sqrt((distancia_x*distancia_x)+(distancia_y*distancia_y));
	return distancia_total;
}

float Tracker::calcularDistancia(int rPosX1, int rPosY1, int rPosX2, int rPosY2)
{
	int distancia_x = abs(rPosX2-rPosX1);
	int distancia_y = abs(rPosY2-rPosY1);
	float distancia_total = sqrt(distancia_x^2+distancia_y^2);
	return distancia_total;
}

