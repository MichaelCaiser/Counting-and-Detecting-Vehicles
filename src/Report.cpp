/*
 * @file 		Report.cpp
 * @version 	1.0
 * @author 		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university  Tecnológico de Costa Rica (TEC)
 */

#include "Report.hpp"

namespace Model {

/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */
Report::Report() {
	mInitialDate = time(0);
	mFinalDate = time(0);
}

Report::~Report() {
	//Free memory of the records vector
	for(unsigned int index_counter = 0; index_counter < mRecords.size(); index_counter++){
		VehicleRecord* p_vehicle_record = mRecords.at(index_counter);
		delete p_vehicle_record;
	}
}

/*
 *********************************************************************************
 *                           		GETTERS                                      *
 *********************************************************************************
 */
string Report::getDeviceCode() const{
	return mDeviceCode;
}

time_t Report::getInitialDate() const{
	return mInitialDate;
}

time_t Report::getFinalDate() const{
	return mFinalDate;
}

string Report::getSecurityToken() const{
	return mSecurityToken;
}

WeatherCondition Report::getWeatherCondition() const{
	return mWeather;
}

vector<VehicleRecord*> Report::getRecords() const{
	return mRecords;
}

/*
 *********************************************************************************
 *                           		SETTERS                                      *
 *********************************************************************************
 */
void Report::setDeviceCode(string rCode){
	mDeviceCode = rCode;
}

void Report::setInitialDate(time_t rDate){
	mInitialDate = rDate;
}

void Report::setFinalDate(time_t rDate){
	mFinalDate = rDate;
}

void Report::setSecurityToken(string rToken){
	mSecurityToken = rToken;
}

void Report::setWeatherCondition(WeatherCondition rWeather){
	mWeather = rWeather;
}


/*
 *********************************************************************************
 *                           		METHODS                                      *
 *********************************************************************************
 */

/**
 * This method add a vehicle record to the report. If the pointer to the object is null, it won't be
 * added to the report.
 *
 * @param prRecord A pointer to a vehicle record object that want to be added to the report
 */
void Report::addRecord(VehicleRecord* prRecord){
	//Check if the pointer is not null
	if(prRecord){
		mRecords.push_back(prRecord);
	}
}

} /* namespace Model */
