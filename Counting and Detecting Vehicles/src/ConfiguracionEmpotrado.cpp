/*
 * ConfiguracionEmpotrado.cpp
 *
 * Author: Alonso Loaiza Pereira
 * e-mail: hiyitsu@gmail.com
 * University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "ConfiguracionEmpotrado.hpp"

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */
ConfiguracionEmpotrado::ConfiguracionEmpotrado(int rEmpotradoID, int rEstructuraID)
{
	mEmpotradoID = rEmpotradoID;
	mEstructuraID = rEstructuraID;
}

ConfiguracionEmpotrado::~ConfiguracionEmpotrado()
{
	// TODO Auto-generated destructor stub
}

/*
 *********************************************************************************
 *                                 Getters                                       *
 *********************************************************************************
 */

int ConfiguracionEmpotrado::getEmpotradoID()
{
	return mEmpotradoID;
}

int ConfiguracionEmpotrado::getEstructuraID()
{
	return mEstructuraID;
}

/*
 *********************************************************************************
 *                                 Setters                                       *
 *********************************************************************************
 */

void ConfiguracionEmpotrado::setEmpotradoID(int rEmpotradoID)
{
	mEmpotradoID = rEmpotradoID;
}

void ConfiguracionEmpotrado::setEstructuraID(int rEstructuraID)
{
	mEstructuraID = rEstructuraID;
}


