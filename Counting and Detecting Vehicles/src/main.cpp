//============================================================================
// Name        : Counting.cpp
// Author      : Alonso Loaiza Pereira
// Version     :
// Copyright   : GNU GPL 3.0
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <Manager.hpp>
#include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	Manager* man = new Manager();
	int resultado = man->iniciarPrograma(0);
	cout << resultado << endl;
	return 0;
}
