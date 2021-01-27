# Vehicle-Bike-Car-Truck-BilalMotors
A C++ code having base class Vehicle and subclasses Bike, Car, Truck. The Vehicle class has aggregation with BilalMotors.

#pragma once
#include "Vehicle.h"
#include <iostream>
using namespace std;

class Bike:public Vehicle
{
private:
	double height;
	bool SelfStart;
	bool DiscBrake;
	static int NumberOfBikes;
public:
	/*Bike();*/
	Bike(double = 0, bool = false, bool = false,char* = nullptr, char* = nullptr, int = 0);
	Bike(Bike&);
	~Bike();
	istream& input(istream&);
	ostream& output(ostream&);
	Bike& operator=(Bike&);
	void Set_Height(double);
	void Set_SelfStart(bool);
	void Set_DiscBreak(bool);
	/*void SetNumberOfBikes(int);*/
	double Get_Height();
	bool Get_SelfStart();
	bool Get_DiscBrake();
	int Get_NumberOfBikes();
	void checkType();
	void Display()const;
};

