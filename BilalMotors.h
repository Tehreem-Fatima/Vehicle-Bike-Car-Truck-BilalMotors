# Vehicle-Bike-Car-Truck-BilalMotors
A C++ code having base class Vehicle and subclasses Bike, Car, Truck. The Vehicle class has aggregation with BilalMotors.

#pragma once
#include <iostream>
#include "Vehicle.h"
#include "Bike.h"
#include "Car.h"
#include "Truck.h"
using namespace std;

class BilalMotors
{
private:
	Vehicle** arr;
	int size;
public:
	BilalMotors();
	/*BilalMotors(int =20);*/
	BilalMotors(const BilalMotors&);
	~BilalMotors();
	const Vehicle* operator[](int)const;
	Vehicle* operator[](int);
	BilalMotors& operator=(const BilalMotors&);
	void Add_Vehicle();
	void Search_Vehicle(char*);
	bool Save_Data(const char*)const;
	const int Get_Size()const;
};

