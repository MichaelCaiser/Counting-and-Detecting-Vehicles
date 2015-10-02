//============================================================================
// Name        : main.cpp
// Author      : Alonso Loaiza Pereira
// Version     :
// Copyright   : MIT License
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "TokenBuilder.hpp"

using namespace std;
using Security::TokenBuilder;

int main() {

	/*
	 ************************************************************************************
	 *								TEST 1.0 = Token generation							*
	 ************************************************************************************
     */
	TokenBuilder* token_builder = new TokenBuilder();
	token_builder->setEncryptionKey("comidacomida");
	cout<< "Generated token: "<<token_builder->createToken()<<endl;

	//Free memory
	delete token_builder;

	return EXIT_SUCCESS;
}
