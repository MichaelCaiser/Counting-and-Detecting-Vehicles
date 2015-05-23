/*
 * ConfiguracionConexion.cpp
 *
 * Author: Alonso Loaiza Pereira
 * e-mail: hiyitsu@gmail.com
 * University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "ConfiguracionConexion.hpp"


/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */
ConfiguracionConexion::ConfiguracionConexion(int rPuerto, string rIP)
{
	mPuerto = rPuerto;
	mDireccionIP = new string(rIP);
}

ConfiguracionConexion::~ConfiguracionConexion()
{
	delete mDireccionIP;
}

/*
 *********************************************************************************
 *                                 Getters                                       *
 *********************************************************************************
 */
int ConfiguracionConexion::getPuerto()
{
	return mPuerto;
}

string ConfiguracionConexion::getDireccionIP()
{
	return *mDireccionIP;
}

/*
 *********************************************************************************
 *                                 Setters                                       *
 *********************************************************************************
 */
void ConfiguracionConexion::setPuerto(int rPuerto)
{
	mPuerto = rPuerto;
}

void ConfiguracionConexion::setDireccionIP(string rDireccionIP)
{
	mDireccionIP->clear();			//limpia el string
	*mDireccionIP += rDireccionIP;	//agrega el string
}

