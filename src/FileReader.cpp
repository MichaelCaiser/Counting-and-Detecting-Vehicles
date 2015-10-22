/**
 * @file 		FileReader.cpp
 * @version 	1.0
 * @author 		Alonso Loaiza Pereira
 * @e-mail	 	aloaizapereira@gmail.com
 * @university 	Tecnológico de Costa Rica (TEC)
 */

#include "FileReader.hpp"

//Libraries
#include <fstream>		/* ifstream object to open and read text files*/
#include <iostream>		/* cout, cerr, endl */
#include <stdlib.h>     /* atoi function to convert strings to integers */
#include "FileReaderConstants.hpp"	/* Constants definition */

//Specification of classes by namespace
using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;

namespace TextParser {

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */

FileReader::FileReader(){
	mFilePath = FILE_NAME;
	/*
	 * This is and array of
	 */
	pmDataCache = new void*[5];
}

FileReader::~FileReader(){
	// TODO Auto-generated destructor stub
}

/*
 *********************************************************************************
 *                           		SETTERS                                      *
 *********************************************************************************
 */
void FileReader::setFilePath(string rPath){
	mFilePath = rPath;
}

/*
 *********************************************************************************
 *                           		METHODS                                      *
 *********************************************************************************
 */

/**
 * This method creates a ConnectionConfig object based on the information stored in a text file. First it searches for
 * a connection config tag to find the information, with this information then creates the object and return a pointer
 * to that object. In case of the information related with the connection config object cannot be found in the text
 * file this method returns a null pointer.
 *
 */
ConnectionConfig* FileReader::getWebserviceConfig(){
	string connec_config_information;
	findDataByTag(WEB_CONNECTION_TAG, connec_config_information);
	ConnectionConfig* p_connection_config = createConnectionConfig(connec_config_information);
	if(!p_connection_config){
		cerr << "Error: ConnectionConfig's information in the file is incorrect." << endl;
	}
	return p_connection_config;
}

/**
 * This method is a implementation of the method with the same name defined in the interface IDeviceInformationDAO.
 * In this case the string object which corresponds to device code of the platform is created with information stored
 * in a text file. This method reads the text file searching a device code tag to find the information then creates a
 * string object which contains the device code.In case of the information related with the device code object cannot
 * be found in the text file this method returns a null pointer.<p>
 */
string* FileReader::getDeviceCode(){
	string device_code;
	findDataByTag(EMBEDDED_CODE_TAG, device_code);
	//If the device code is equal to blank space that means that couldn't find the device code in the file text
	if(device_code == ""){
		return NULL;
	}
	string* p_device_code = new string(device_code);
	return 	p_device_code;
}

/**
 * This method is a implementation of the method with the same name defined in the interface IFilterConfigurationDAO.
 * In this case the rectangle object which corresponds to the region of interest (ROI) is created with information stored
 * in a text file, this method reads the text file searching a roi tag to find the information and creates a Rectangle object.
 * In case of the information related with the ROI object cannot be found in the text file this method returns a null pointer.<p>
 */
Rect* FileReader::getROI(){
	string roi_information;
	findDataByTag(ROI_TAG, roi_information);
	Rect* p_roi = createRegion(roi_information);
	if(!p_roi){
		cerr << "Error: ROI's information in the file is incorrect." << endl;
	}
	return p_roi;
}

/**
 * This method is a implementation of the method with the same name defined in the interface IFilterConfigurationDAO.
 * In this case the Line object which corresponds to the right line is created with information stored in a text file, this
 * method reads the text file searching a right line tag to find the information and creates a Line object. In case of the
 * information related with the right line object cannot be found in the text file this method returns a null pointer.<p>
 */
Line* FileReader::getRightLine(){
	string right_line_information;
	findDataByTag(RIGH_LINE_TAG, right_line_information);
	Line* p_right_line = createLine(right_line_information);
	if(!p_right_line){
		cerr << "Error: RightLine's information in the file is incorrect." << endl;
	}
	return p_right_line;
}


/**
 * This method is a implementation of the method with the same name defined in the interface IFilterConfigurationDAO.
 * In this case the Line object which corresponds to the left line is created with information stored in a text file, this
 * method reads the text file searching a left line tag to find the information and creates a Line object.In case of the
 * information related with the left line object cannot be found in the text file this method returns a null pointer.<p>
 */
Line* FileReader::getLeftLine(){
	string left_line_information;
	findDataByTag(LEFT_LINE_TAG, left_line_information);
	Line* p_left_line = createLine(left_line_information);
	if(!p_left_line){
		cerr << "Error: LeftLine's information in the file is incorrect." << endl;
	}
	return p_left_line;
}

/*
 * This method checks if a string is a number. <p>
 *
 * @param rString 	The string that we want to know if it is a number
 * @return bool		The result of check if the string is a number.
 */
bool FileReader::isNumber(string rString)
{
	try
	{
		//Try to convert the string to an integer
		atoi(rString.c_str());
		return true;
	}
	catch(int exception)
	{
		return false;
	}
}

/**
 * This method find the value (information) of a tag in a string. The string (rData) must have a format
 * as follows "TAG=Information". If the tag will not be find in the data the function return a empty string.
 * Example if rData is equal to "PORT=80" and rIdentifierTag is equal to "PORT", this method must return
 * "80" which corresponds to the value of the tag.<p>
 *
 * @param rIdentifierTag	This string corresponds to the kind of information that will be searched.
 * @return String			The value of the identifier tag.
 */
string FileReader::findValue(string rData, string rIdentifierTag)
{
	//The vector which will store the divided strings of the rData
	vector<string>	split_string_list;

	//Split the data based on the TAG_INFORMATION_SEPARATOR
	splitString(rData, TAG_INFORMATION_SEPARATOR, split_string_list);

	//The vector must have a size of 2 because it will store only two things the tag and the information (vector=[tag,value])
	if(split_string_list.size() == 2)
	{
		//The first element should be the tag
		string first_element = split_string_list.at(0);

		//Verify that the first element will be equal to the identifier tag
		if(first_element.compare(rIdentifierTag) == 0)
		{
			string second_element = split_string_list.at(1);
			return second_element;
		}
	}
	return "";
}

/**
 *	This method tries to find the data in a specific tag, the search is done a file (the path is the attribute mFilePath).
 *	The tag is a way to divide the information, all the information is stored in the file in a way as follows:
 *		Tag=Information.
 *	If this method finds the tag, store the information in the tag in the parameter (rData), otherwise store a empty string.<p>
 * @param rTag		The tag (a string) which is needed to find the information.
 * @param rData		The string in which will be stored tag's information.
 */
void FileReader::findDataByTag(string rTag, string &rData){
	rData = "";
	ifstream file(mFilePath.c_str());	//File descriptor
	string line;						//string to be used as a buffer of file's lines.

	if(!file.is_open()){
		cerr << "Error: File not found" << endl;
		return;
	}

	while (getline(file,line)){
		//check that the first character is not equal to a comment character
		if(!line.empty() && line[0] != COMMENT_TAG){

			//Vector with the parts of the line divided by the character '='
			vector<string> 		line_list;
			splitString(line, TAG_INFORMATION_SEPARATOR, line_list);

			//Check if the vector has two parts [TAG,INFORMATION]
			if(line_list.size() == 2){

				string tag = line_list.at(0);
				string information = line_list.at(1);
				//Check if the tag is equal to the searched tag
				if(tag == rTag){
					rData = information;
					break;
				}
			}
		}
	}

	if(rData == ""){
		cerr << "Error: The tag '" << rTag << "' could not found in the file." << endl;
	}

	file.close();
}

/*
 * This method divides a string (rString) every time that a regular expression (rRegex) appears in that string
 * and add to the strings vector (rStringList) the strings in which the original string was divided.<p>
 * Example:
 * 		1. rString = what,we,want
 * 		2. rRegex  = ,
 * 		3. rStringList = [what,we,want]
 * @param rString		String that we want to divide
 * @param rRegex    	Regular expression to divide the string
 * @param rStringList	Is a reference to the strings list in which will be stored the divided strings.
 */
void FileReader::splitString(string rString, string rRegex, vector<string> &rStringList)
{

	while(rString.size() != 0)
	{
		int pos_regex = rString.find(rRegex);

		//Case in which the string doesn't contain the regular expression
		if(pos_regex == -1)
		{
			rStringList.push_back(rString);
			break;
		}
		//The element which is previous to the regular expression in the original string
		string element = rString.substr(0,pos_regex);
		if(element.size() != 0)
		{
			rStringList.push_back(element);
		}
		rString = rString.substr(pos_regex+rRegex.size(), rString.size());
	}
}

/**
 * This method creates a line object based on the data in a string, the data in the string must contain two points
 * that describes the line. The format of the string (rInformation) must be equal to as follows:
 * "position_x_point_one,position_y_point_one,position_x_point_two,position_y_point_two". If the information is
 * incorrect this method return a null pointer. Example if rInformation is equal to "1,1,2,2", the first point is
 * (1,1) and the second one (2,2), that means the created line object must have a gradient equal to 1 and the Y
 * intercept will be 0.<p>
 *
 * @param rInformation		The information required to create the line (A string with the two points)
 * @return Line* 			A pointer to a Line which was created with the information on the string.
 */
Line* FileReader::createLine(string rInformation)
{
	//Vector that contains the data of the information
	vector<string>	string_list;

	//Split the information based on the character separator ","
	splitString(rInformation, INFORMATION_SEPARATOR, string_list);

	//Check if the information has been divided in four parts corresponding to the two points of the line
	if(string_list.size() == SIZE_DATA_LINE){
		//Check if the data are numbers
		for(unsigned int list_index = 0; list_index < string_list.size(); list_index++){
			//If some data aren't a number the line can not be created
			if(!isNumber(string_list.at(list_index))){
				return NULL;
			}
		}

		int pos_x_point_one = atoi(string_list.at(POS_X1_LINE).c_str());
		int pos_y_point_one = atoi(string_list.at(POS_Y1_LINE).c_str());
		int pos_x_point_two = atoi(string_list.at(POS_X2_LINE).c_str());
		int pos_y_point_two = atoi(string_list.at(POS_X2_LINE).c_str());

		Line* line = new Line(pos_x_point_one, pos_y_point_one, pos_x_point_two, pos_y_point_two);
		return line;
	}
	return NULL;
}

/**
 * This method creates a rectangle(ROI) object based on the data in a string, the data in the string must contain the
 * x and y positions and the width and height of the ROI. The format of the string (rInformation) must be equal to as
 * follows: "position_x,position_y,width,height". If the information is incorrect this method return a null pointer.
 * Example if rInformation is equal to "100,100,20,30" the function return a pointer to a rectangle which position is
 * (100,100), its width is 20 and its height is 30 .<p>
 *
 * @param rInformation		The information required to create the ROI (A string with the x and y position and the width and height)
 * @return Rect* 			A pointer to a Rectangle which was created with the information on the string.
 */
Rect* FileReader::createRegion(string rInformation)
{
	//Vector that contains the data of the information
	vector<string>	string_list;

	//Split the information based on the character separator ","
	splitString(rInformation, INFORMATION_SEPARATOR, string_list);

	//Check if the information has been divided in four parts
	if(string_list.size() == SIZE_ROI){
		//Check if the data are numbers
		for(unsigned int list_index = 0; list_index < string_list.size(); list_index++){
			//If some data aren't a number the ROI can not be created
			if(!isNumber(string_list.at(list_index))){
				return NULL;
			}
		}

		int pos_x_roi = atoi(string_list.at(POS_X_ROI).c_str());
		int pos_y_roi = atoi(string_list.at(POS_Y_ROI).c_str());
		int width_roi = atoi(string_list.at(POS_WIDTH_ROI).c_str());
		int height_roi = atoi(string_list.at(POS_HEIGHT_ROI).c_str());

		Rect* roi = new Rect(pos_x_roi, pos_y_roi, width_roi,height_roi);
		return roi;
	}
	return NULL;
}

/**
 * This method creates a ConnectionConfig object based on the data in a string, the data in the string must contain the
 * port, the host and the url of a web service. The format of the string (rInformation) must be equal to as follows:
 * "port,host,url". If the information is incorrect this method return a null pointer.
 * Example if rInformation is equal to "80,localhost,http//localhost:80/WebAppCar/service/rest/embedded/addReport"
 * the method return a pointer to a ConnectionConfig which the port is 80, the host is localhost and the url is
 * http//localhost:80/WebAppCar/service/rest/embedded/addReport. <p>
 *
 * @param  rInformation			The information required to create a ConnectionConfig (A string with the port, the host and the url)
 * @return ConnectionConfig* 	A pointer to a ConnectionConfig which was created with the information on the string.
 */
ConnectionConfig* FileReader::createConnectionConfig(string rInformation){
	//Vector that contains the data of the information
	vector<string>	string_list;

	//Split the information based on the character separator ","
	splitString(rInformation, INFORMATION_SEPARATOR, string_list);

	//Check if the information has been divided in three parts
	if(string_list.size() == SIZE_CONNEC_CONFIG){
		string string_port = string_list.at(POS_PORT_WEBCON);
		string host = string_list.at(POS_HOST_WEBCON);
		string url = string_list.at(POS_URL_WEBCON);
		//Check if the port is a number
		if(!isNumber(string_port)){
			return NULL;
		}
		int port = atoi(string_port.c_str());

		ConnectionConfig* p_connection_config = new ConnectionConfig(port,host,url);
		return p_connection_config;
	}

	return NULL;
}



} /* namespace TextParser */
