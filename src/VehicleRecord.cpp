/*
 * @file 		VehicleRecord.cpp
 * @version 	1.0
 * @Author  	Alonso Loaiza Pereira
 * @e-mail  	aloaizapereira@gmail.com
 * @university 	Tecnologico de Costa Rica (TEC)
 */

#include "VehicleRecord.hpp"

namespace Model {

/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */
VehicleRecord::VehicleRecord() {
	// TODO Auto-generated constructor stub
	mSpeed = 0;
	mDate = time(0);
}

VehicleRecord::VehicleRecord(string rLicense, string rType, float rSpeed, time_t rDate){
	mLicensePlate 	= rLicense;
	mVehicleType  	= rType;
	mSpeed 			= rSpeed;
	mDate 			= rDate;
}

VehicleRecord::~VehicleRecord() {
	// TODO Auto-generated destructor stub
}

/*
 *********************************************************************************
 *                           		GETTERS                                      *
 *********************************************************************************
 */
string VehicleRecord::getLicensePlate() const{
	return mLicensePlate;
}

string VehicleRecord::getVehicleType() const{
	return mVehicleType;
}

float VehicleRecord::getSpeed() const{
	return mSpeed;
}

time_t VehicleRecord::getDate() const{
	return mDate;
}


/*
 *********************************************************************************
 *                           		SETTERS                                      *
 *********************************************************************************
 */
void VehicleRecord::setLicensePlate(string rLicense){
	mLicensePlate = rLicense;
}

void VehicleRecord::setVehicleType(string rType){
	mVehicleType = rType;
}

void VehicleRecord::setSpeed(float rSpeed){
	mSpeed = rSpeed;
}

void VehicleRecord::setDate(time_t rDate){
	mDate = rDate;
}

} /* namespace Model */
