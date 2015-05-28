/*
 * SecurityToken.cpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "SecurityToken.hpp"

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */
SecurityToken::SecurityToken()
{
	// TODO Auto-generated constructor stub
}

SecurityToken::SecurityToken(string rUsername, string rPassword)
{
	mUsername = rUsername;
	mPassword = rPassword;
}

SecurityToken::~SecurityToken()
{
	// TODO Auto-generated destructor stub
}

/*
 *********************************************************************************
 *                                 Getters                                       *
 *********************************************************************************
 */

string SecurityToken::getUsername()
{
	return mUsername;
}

string SecurityToken::getPassword()
{
	return mPassword;
}

/*
 *********************************************************************************
 *                                 Setters                                       *
 *********************************************************************************
 */

void SecurityToken::setUsername(string rUser)
{
	mUsername = rUser;
}

void SecurityToken::setPassword(string rPassword)
{
	mPassword = rPassword;
}

