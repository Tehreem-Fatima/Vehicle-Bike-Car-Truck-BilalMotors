# Vehicle-Bike-Car-Truck-BilalMotors
A C++ code having base class Vehicle and subclasses Bike, Car, Truck. The Vehicle class has aggregation with BilalMotors.

#pragma once
#include "Vehicle.h"
#include <iostream>
using namespace std;

class Car :public Vehicle
{
private:
	int NumberOfDoors;
	char* transmission;
	int NumberOfSeats;
	static int NumberOfCars;
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
	/*Car();*/
	Car(int = 0, char* = nullptr, int = 0, char* = nullptr, char* = nullptr, int = 0);
	Car(Car&);
	~Car();
	istream& input(istream&);
	ostream& output(ostream&);
	Car& operator=(Car&);
	void Set_NumberOfDoors(int);
	void Set_Transmission(char*);
	void Set_NumberOfSeats(int);
	/*void Set_NumberOfCars(int);*/
	int Get_NumberOfDoors();
	char* Get_Transmission();
	int Get_NumberOfSeats();
	int Get_NumberOfCars();
	void checkType();
	void Display()const;
};

