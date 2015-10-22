/*
 * @file		FileReaderConstants.hpp
 * @version 	1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university 	Tecnológico de Costa Rica (TEC)
 *
 * @description
 * 		This file contains a simply declaration of constants which are required
 * 		by the FileReader class located in the TextParser namespace.
 */

#ifndef FILEREADERCONSTANTS_HPP_
#define FILEREADERCONSTANTS_HPP_

//Libraries
#include <string>	/* Object string */

/*
 *******************************************************************************
 *									File
 *******************************************************************************
 */

/* Configuration file name */
const std::string FILE_NAME = "data/config.txt";

/*
 *******************************************************************************
 *						Configuration file syntax
 *******************************************************************************
 */

/*
 * Character which indicates that the line is a comment if it is in the beginning.
 *
 * Example:
 * 		#This is a comment.
 * 		The previous line is a comment because has the comment tag (#) at the beginning.
 */
const char COMMENT_TAG = '#';

/*
 * This string is the separator between the tag and the information in a line.
 * All the comments have a structure as follows: TAG=INFORMATION, where the tag
 * is the type of information.
 *
 * Example:
 * 		PORT=1000.
 * 		In this case PORT is the tag which indicates that the information is a PORT, and 1000
 * 		is the value of the port.
 */
const std::string TAG_INFORMATION_SEPARATOR = "=";

/* position of the tag*/
const int POS_TAG = 1;
const int POS_INF = 2;

/*
 * This string is the separator to divide the data in the information contained in a line.
 *
 * Example:
 * 		ROI=100,100,100,100.
 * 		In the previous line the tag is ROI that indicates the information is a Region of Interest,
 * 		and the information is 100,100,100,100 if you look it the separator is ',' for this reason
 * 		the information can be divide in four parts.
 */
const std::string INFORMATION_SEPARATOR = ",";

/* This string indicates the ROI (Region of Interest) Tag. */
const std::string ROI_TAG = "ROI";

/* This string indicates the RL (Right Line) Tag. */
const std::string RIGH_LINE_TAG = "RL";

/* This string indicates the LL (Left Line) Tag. */
const std::string LEFT_LINE_TAG = "LL";

/* This string indicates the Embedded Code Tag */
const std::string EMBEDDED_CODE_TAG =  "CODE";

/* This string indicates  the web service connection config Tag */
const std::string WEB_CONNECTION_TAG = "WEB_CON";

/*
 *******************************************************************************
 *			 Region of interest(ROI) information structure
 *******************************************************************************
 */

/* The ROI information has a structure equal to as follows:
 * ROI=POSX,POSY,WIDTH,HEIGHT where:
 * 		1. POSX: is the position x of the ROI
 * 		2. POSY: is the position y of the ROI
 * 		3. WIDTH: is the width of the ROI
 * 		4. HEIGHT: is the height of the ROI
 */

/* Data quantity of the ROI information */
const int SIZE_ROI = 4;

/* Location of the POSX data in the ROI's information */
const int POS_X_ROI = 0;

/* Location of the POSY data in the ROI's information */
const int POS_Y_ROI = 1;

/* Location of the WIDTH data in the ROI's information */
const int POS_WIDTH_ROI = 2;

/* Location of the HEIGHT data in the ROI's information */
const int POS_HEIGHT_ROI = 3;

/*
 *******************************************************************************
 *						Line information structure
 *******************************************************************************
 */

/* The Line information has a structure equal to as follows:
 * RL=X1,Y1,X2,Y2 where:
 * 		1. X1: position x of the first point of the line
 * 		2. Y1: position y of the first point of the line
 * 		3. X2: position x of the second point of the line
 * 		4. Y2: position y of the second point of the line
 */

/* Data quantity of the line information */
const int SIZE_DATA_LINE = 4;

/* Location of the X1 data in the line information */
const int POS_X1_LINE = 0;

/* Location of the Y1 data in the line information */
const int POS_Y1_LINE = 1;

/* Location of the X2 data in the line information */
const int POS_X2_LINE = 2;

/* Location of the Y2 data in the line information */
const int POS_Y2_LINE = 3;

/*
 *******************************************************************************
 *				WebService Connection Config information structure
 *******************************************************************************
 */

/*
 * The connection config of a webservice has a structure to as follows:
 * WEB_CON=PORT,HOST,URL where:
 * 		1. PORT: Is the port to be used to connect to the webservice.
 * 		2. HOST: Is the host to connect.
 * 		3. URL : Is the host's url necessary to establish a connection.
 */

/* Data quantity of the connection config information */
const int SIZE_CONNEC_CONFIG = 3;

/* Location of the port in the connection configuration information*/
const int POS_PORT_WEBCON = 0;

/* Location of the host in the connection configuration information*/
const int POS_HOST_WEBCON = 1;

/* Location of the url in the connection configuration information*/
const int POS_URL_WEBCON = 2;


#endif /* FILEREADERCONSTANTS_HPP_ */
