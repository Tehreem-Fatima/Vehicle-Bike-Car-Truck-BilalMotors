# Vehicle-Bike-Car-Truck-BilalMotors
A C++ code having base class Vehicle and subclasses Bike, Car, Truck. The Vehicle class has aggregation with BilalMotors.

#include "Bike.h"
#include <iostream>
using namespace std;

//Bike::Bike() :Vehicle()
//{
//	height = 0.0;
//	SelfStart = false;
//	DiscBrake = false;
//	NumberOfBikes = 0;
//}
Bike::Bike(double h, bool s, bool d, char* n, char* c, int p) :Vehicle(n, c, p)
{
	this->height = h;
	this->SelfStart = s;
	this->DiscBrake = d;
	this->NumberOfBikes++;
}
Bike::Bike(Bike&obj):Vehicle(obj)
{
	this->height = obj.height;
	this->SelfStart = obj.SelfStart;
	this->DiscBrake = obj.DiscBrake;
	this->NumberOfBikes = obj.NumberOfBikes;
}
Bike::~Bike()
{
	this->height = 0;
	this->SelfStart = false;
	this->DiscBrake = false;
	this->NumberOfBikes = 0;
}
istream& Bike::input(istream& Cin)
{
	while (1) {
		char* name = new char[20];
		cout << "Enter Company Name: ";
		Cin >> name;
		cout << endl;
		Set_CompanyName(name);
		
		char* color = new char[20];
		cout << "Enter Color: ";
		Cin >> color;
		cout << endl;
		Set_Color(color);

		int wheels = 0;
		while (1) {
			cout << "Enter Wheels: ";
			Cin >> wheels;
			cout << endl;
			if (wheels == 2) {
				Set_NumberOfWheels(wheels);
				break;
			}
			else {
				cout << "Bike Has Only 2 Wheels ..." << endl;
				cout << endl;
			}
		}
		int power = 0;
		while (1) {
			cout << "Enter Power: ";
			Cin >> power;
			cout << endl;
			if (power <= 150) {
				Set_PowerCC(power);
				break;
			}
			else {
				cout << "Power is Less than 150 ..." << endl;
				cout << endl;
			}
		}

		while (1) {
			cout << "Enter Height: ";
			Cin >> this->height;
			cout << endl;
			if (this->height <= 80) {
				Set_Height(this->height);
				break;
			}
			else {
				cout << "Height is Not Greater Than 80 ..." << endl;
				cout << endl;
			}
		}

			cout << "... Is it Self Start or Not ? ..." << endl;
			cout << "1=(True) and 0=(False): ";
			Cin >> this->SelfStart;
			cout << endl;

			cout << "... Is it Disc Brake or Not ? ..." << endl;
			cout << "1=(True) and 0=(False): ";
			Cin >> this->DiscBrake;
			cout << endl;

			break;
	}
	return Cin;
}
ostream& Bike::output(ostream& Cout)
{
	Cout << "Company Name: " << Get_CompanyName() << endl;
	Cout << "Color: " << Get_Color() << endl;
	Cout << "Number Of Wheels: " << Get_NumberOfWheels() << endl;
	Cout << "Power: " << Get_PowerCC() << endl;
	Cout << "Height: " << this->height << endl;
	if (this->SelfStart) {
		Cout << "It is Self Start ..." << endl;
	}
	if (this->DiscBrake) {
		Cout << "It Has Disc Brake ..." << endl;
	}
	Cout << "Number of Bikes: " << this->NumberOfBikes << endl;
	Cout << endl;
	return Cout;
}
Bike& Bike::operator=(Bike& rhs)
{
	if (this != &rhs) {
		this->height = rhs.height;
		this->SelfStart = rhs.SelfStart;
		this->DiscBrake = rhs.DiscBrake;
		this->NumberOfBikes = rhs.NumberOfBikes;
	}
	return *this;
}
void Bike::Set_Height(double h)
{
	this->height = h;
}
void Bike::Set_SelfStart(bool s)
{
	this->SelfStart = s;
}
void Bike::Set_DiscBreak(bool d)
{
	this->DiscBrake = d;
}
//void Bike::SetNumberOfBikes(int b)
//{
//	this->NumberOfBikes = b;
//}
double Bike::Get_Height()
{
	return this->height;
}
bool Bike::Get_SelfStart()
{
	if (this->SelfStart) {
		return true;
	}
	else {
		return false;
	}
}
bool Bike::Get_DiscBrake()
{
	if (this->DiscBrake) {
		return true;
	}
	else {
		return false;
	}
}
int Bike::Get_NumberOfBikes()
{
	return this->NumberOfBikes;
}
void Bike::checkType()
{
	if (Get_NumberOfWheels() == 2) {
		char* type = new char[5]{ "Bike" };
		Set_TypeOfVehicle(type);
	}
	else {
		char* notype = new char[13]{ "No Such Type" };
		Set_TypeOfVehicle(notype);
	}
}
void Bike::Display()const
{
	Vehicle::Display();
	cout << "					Height :	" << this->height << endl;
	if (this->SelfStart) {
		cout << "					SelfStart :	Yes" << endl;
	}
	else {
		cout << "					SelfStart :	No" << endl;
	}
	if (this->DiscBrake) {
		cout << "					DiscBrake :	Yes" << endl;
	}
	else {
		cout << "					DiscBrake :	No" << endl;
	}
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
}
