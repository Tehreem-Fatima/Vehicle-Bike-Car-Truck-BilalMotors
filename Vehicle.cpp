# Vehicle-Bike-Car-Truck-BilalMotors
A C++ code having base class Vehicle and subclasses Bike, Car, Truck. The Vehicle class has aggregation with BilalMotors.

#include "Vehicle.h"
#include <iostream>
using namespace std;

//Vehicle::Vehicle()
//{
//	this->CompanyName = nullptr;
//	this->color = nullptr;
//	this->NumberOfWheels = 0;
//	this->PowerCC = 0;
//	this->TypeOfVehicle = nullptr;
//}
Vehicle::Vehicle(char* n, char* c, int p)
{
	Strcopy(this->CompanyName, n);
	Strcopy(this->color, c);
	this->PowerCC = p;
}
Vehicle::Vehicle(const Vehicle& obj)
{
	Strcopy(this->CompanyName, obj.CompanyName);
	Strcopy(this->color, obj.color);
	this->NumberOfWheels = obj.NumberOfWheels;
	this->PowerCC = obj.PowerCC;
	Strcopy(this->TypeOfVehicle, obj.TypeOfVehicle);
}
Vehicle::~Vehicle()
{
	delete[] this->CompanyName;
	this->CompanyName = nullptr;
	delete[] this->color;
	this->color = nullptr;
	this->NumberOfWheels = 0;
	this->PowerCC = 0;
	delete[] this->TypeOfVehicle;
	this->TypeOfVehicle = nullptr;
}
Vehicle& Vehicle::operator=(Vehicle& rhs)
{
	if (this != &rhs) {
		Strcopy(this->CompanyName, rhs.CompanyName);
		Strcopy(this->color, rhs.color);
		this->NumberOfWheels = rhs.NumberOfWheels;
		this->PowerCC = rhs.PowerCC;
		Strcopy(this->TypeOfVehicle, rhs.TypeOfVehicle);
	}
	return *this;
}
void Vehicle::Set_CompanyName(char* n)
{
	if (this->CompanyName) {
		delete[] this->CompanyName;
		this->CompanyName = nullptr;
	}
	Strcopy(this->CompanyName, n);
}
void Vehicle::Set_Color(char* c)
{
	if (this->color) {
		delete[] this->color;
		this->color = nullptr;
	}
	Strcopy(this->color, c);
}
void Vehicle::Set_NumberOfWheels(int w)
{
	this->NumberOfWheels = w;
}
void Vehicle::Set_PowerCC(int p)
{
	this->PowerCC = p;
}
void Vehicle::Set_TypeOfVehicle(char* t)
{
	if (this->TypeOfVehicle) {
		delete[] this->TypeOfVehicle;
		this->TypeOfVehicle = nullptr;
	}
	Strcopy(this->TypeOfVehicle, t);
}
char* Vehicle::Get_CompanyName()
{
	char* temp = new char[Strlen(this->CompanyName) + 1];
	Strcopy(temp, this->CompanyName);
	return temp;
}
char* Vehicle::Get_Color()
{
	char* temp = new char[Strlen(this->color) + 1];
	Strcopy(temp, this->color);
	return temp;
}
int Vehicle::Get_NumberOfWheels()
{
	return this->NumberOfWheels;
}
int Vehicle::Get_PowerCC()
{
	return this->PowerCC;
}
char* Vehicle::Get_TypeOfVehicle()
{
	char* temp = new char[Strlen(this->TypeOfVehicle) + 1];
	Strcopy(temp, this->TypeOfVehicle);
	return temp;
}
void Vehicle::Display()const
{
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	cout << "					Company :	" << this->CompanyName << endl;
	cout << "					Color :		" << this->color << endl;
	cout << "					Power :		" << this->PowerCC << endl;
	cout << "					Type :		" << this->TypeOfVehicle << endl;
}
