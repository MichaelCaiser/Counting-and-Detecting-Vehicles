/*
 * @file 		FileReader.hpp
 * @version 	1.0
 * @author 		Alonso Loaiza Pereira
 * @e-mail	 	aloaizapereira@gmail.com
 * @university 	Tecnológico de Costa Rica (TEC)
 *
 * @description:
 * 		This class makes a parsing of a text file which contains the application configuration necessary
 * 		to do the image processing for vehicles detection as street's demarcation lines and Region of
 * 		Interest (ROI). Also this class makes objects which contains the application configuration
 * 		as line objects, regions objects and others.
 */

#ifndef FILEREADER_HPP_
#define FILEREADER_HPP_

//Libraries
#include <string>			/* Object string */
#include <vector>			/* Object vector */
#include <opencv2/imgproc/imgproc.hpp>	/* Object Rect of the lib opencv*/
#include "Line.hpp"						/* Line Object */
#include "ConnectionConfig.hpp"			/* Object Connection config */
#include "IDeviceInformationDAO.hpp"	/* Interface DeviceInformationDAO */
#include "IFilterConfigurationDAO.hpp"	/* Interface FilterConfigurationDAO */

//Specification of classes by namespace
using std::string;
using std::vector;
using cv::Rect;
using Model::Line;
using WebService::ConnectionConfig;
using DAO::IDeviceInformationDAO;
using DAO::IFilterConfigurationDAO;

namespace TextParser
{
	class FileReader : IDeviceInformationDAO, IFilterConfigurationDAO{
	public:
		//Constructor and Destructor
		FileReader();
		virtual ~FileReader();

		//Setters
		void setFilePath(string rPath);

		//Methods
		ConnectionConfig* getWebserviceConfig();

		//Methods of the interface IFilterConfigurationDAO
		Rect* getROI();
		Line* getRightLine();
		Line* getLeftLine();

		//Methods of the interface IDeviceInformationDAO
		string* getDeviceCode();

	private:
		//Attributes
		string mFilePath;		//Path of the file which will be open to find the information
		void*  pmDataCache; 	//Vector with pointers of the created objects  with the file text

		//Methods
		bool 	isNumber(string rString);
		string 	findValue(string rData, string rTag);
		void 	findDataByTag(string rTag, string &rData);
		void 	splitString(string rString, string rRegex, vector<string> &rStringList);

		Line* createLine(string rInformation);
		Rect* createRegion(string rInformation);
		ConnectionConfig* createConnectionConfig(string rInformation);

	};

} /* namespace TextParser */

#endif /* FILEREADER_HPP_ */
