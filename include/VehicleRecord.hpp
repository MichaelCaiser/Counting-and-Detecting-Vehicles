/*
 * @file 		VehicleRecord.hpp
 * @version 	1.0
 * @Author  	Alonso Loaiza Pereira
 * @e-mail  	aloaizapereira@gmail.com
 * @university 	Tecnologico de Costa Rica (TEC)
 *
 * @description
 * 		This class represents the information when a vehicle is detected (simply container of information).
 * 		This class stores the information related with the detection as the speed, the date, the type of
 * 		vehicle (depends of your classification) and the license plate.
 */

#ifndef VEHICLERECORD_HPP_
#define VEHICLERECORD_HPP_

//Libraries
#include <string>	/* Object string defined in the STD */
#include <ctime>	/* time_t */

//Classes specified by namespace
using std::string;
using std::time_t;

namespace Model
{
	class VehicleRecord {
	public:
		//Constructor and Destructor
		VehicleRecord();
		VehicleRecord(string rLicense, string rType, float rSpeed, time_t rDate);
		virtual ~VehicleRecord();

		//Getters
		string getLicensePlate() const;
		string getVehicleType() const;
		float getSpeed() const;
		time_t getDate() const;

		//Setters
		void setLicensePlate(string rLicense);
		void setVehicleType(string rType);
		void setSpeed(float rSpeed);
		void setDate(time_t rDate);

	private:
		//Attributes
		string mLicensePlate;	//License plate of the vehicle
		string mVehicleType;	//Type of vehicle
		float mSpeed;			//Speed which the vehicle was detected
		time_t mDate;			//Date in which happened the action

	};

} /* namespace Model */

#endif /* VEHICLERECORD_HPP_ */
