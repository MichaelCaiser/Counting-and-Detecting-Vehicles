/*
 * @file 		Report.hpp
 * @version 	1.0
 * @author 		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university  Tecnológico de Costa Rica (TEC)
 *
 * @description
 *		This class is a report of vehicles which have been passed the road. This report contains
 *		the climate condition when the data was captured, the amount and the.
 */

#ifndef REPORT_HPP_
#define REPORT_HPP_

//Libraries
#include <string>	/* string object */
#include <ctime>	/* time_t */
#include <vector>	/* vector object*/
#include "WeatherCondition.hpp"	/* WeatherCondition object */
#include "VehicleRecord.hpp"	/* VehicleRecord Object */

//Classes specified by namespace
using std::string;
using std::time_t;
using std::vector;
using Model::WeatherCondition;
using Model::VehicleRecord;

namespace Model
{
	class Report{
	public:
		//Constructor and Destructor
		Report();
		virtual ~Report();

		//Getters
		string getDeviceCode() const;
		time_t getInitialDate() const;
		time_t getFinalDate() const;
		string getSecurityToken() const;
		WeatherCondition getWeatherCondition() const;
		vector<VehicleRecord*> getRecords();

		//Setters
		void setDeviceCode(string rCode);
		void setInitialDate(time_t rDate);
		void setFinalDate(time_t rDate);
		void setSecurityToken(string rToken);
		void setWeatherCondition(WeatherCondition rWeather);

		//Methods
		void addRecord(VehicleRecord* prRecord);

	private:
		//Attributes
		string mDeviceCode;		//Device code of the embedded platform that collect the information of the report
		time_t mInitialDate;	//Date in which the report started to collect information
		time_t mFinalDate;		//Date in which the report ended the collection of information
		string mSecurityToken;	//Security token which permits determinate the validation of the information
		WeatherCondition mWeather;			//Weather object which contains the climate conditions when the report was created.
		vector<VehicleRecord*> mRecords;	//All the records of the vehicles which were counted.
	};

} /* namespace Model */

#endif /* REPORT_HPP_ */
