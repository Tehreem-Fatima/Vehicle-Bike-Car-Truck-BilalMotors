# Vehicle-Bike-Car-Truck-BilalMotors
A C++ code having base class Vehicle and subclasses Bike, Car, Truck. The Vehicle class has aggregation with BilalMotors.

#pragma once
#include "Vehicle.h"
#include <iostream>
using namespace std;

class Truck:public Vehicle
{
private:
	double ContainerSize;
	char* category;
	bool FourWheelDrive;
	static int NumberOfTrucks;
	int Strlen(char* ptr) {
		int i = 0;
		while (ptr[i] != '\0') {
			i++;
		}
		return i;
	}
	void Strcopy(char*& ptr, char* arr) {
		ptr = new char[Strlen(arr) + 1];
		for (int i = 0; i < Strlen(arr); ++i) {
			ptr[i] = arr[i];
		}
		ptr[Strlen(arr)] = '\0';
	}
public:
	/*Truck();*/
	Truck(double=0,char* =nullptr,bool=false, char* = nullptr, char* = nullptr, int = 0);
	Truck(Truck&);
	~Truck();
	istream& input(istream&);
	ostream& output(ostream&);
	Truck& operator=(Truck&);
	void Set_ContainerSize(double);
	void Set_Category(char*);
	void Set_FourWheelDrive(bool);
	double Get_ContainerSize();
	char* Get_Category();
	bool Get_FourWheelDrive();
	int Get_NumberOfTrucks();
	void checkType();
	void Display()const;
};
