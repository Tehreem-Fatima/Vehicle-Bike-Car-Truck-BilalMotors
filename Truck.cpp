# Vehicle-Bike-Car-Truck-BilalMotors
A C++ code having base class Vehicle and subclasses Bike, Car, Truck. The Vehicle class has aggregation with BilalMotors.

#include "Truck.h"
#include <iostream>
using namespace std;

//Truck::Truck():Vehicle()
//{
//	ContainerSize = 0.0;
//	category = nullptr;
//	FourWheelDrive = false;
//	NumberOfTrucks = 0;
//}
Truck::Truck(double s, char* t, bool f, char* n, char* c, int p) :Vehicle(n, c, p)
{
	this->ContainerSize = s;
	Strcopy(this->category, t);
	this->FourWheelDrive = f;
	this->NumberOfTrucks++;
}
Truck::Truck(Truck& obj) :Vehicle(obj)
{
	this->ContainerSize = obj.ContainerSize;
	Strcopy(this->category, obj.category);
	this->FourWheelDrive = obj.FourWheelDrive;
	this->NumberOfTrucks = obj.NumberOfTrucks;
}
Truck::~Truck()
{
	this->ContainerSize = 0.0;
	delete[] category;
	category = nullptr;
	this->FourWheelDrive = false;
	this->NumberOfTrucks = 0;
}
istream& Truck::input(istream& Cin)
{
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
		if (wheels == 6 || wheels == 4) {
			Set_NumberOfWheels(wheels);
			break;
		}
		else {
			cout << "Truck Has 4 or 6 Wheels ..." << endl;
			cout << endl;
		}
	}

	int power = 0;
	while (1) {
		cout << "Enter Power: ";
		Cin >> power;
		cout << endl;
		if (power <= 3000) {
			Set_PowerCC(power);
			break;
		}
		else {
			cout << "Power is Less than 4500 ..." << endl;
			cout << endl;
		}
	}

	while (1) {
		cout << "Enter Container Size: ";
		Cin >> this->ContainerSize;
		cout << endl;
		if (this->ContainerSize <= 90) {
			Set_ContainerSize(this->ContainerSize);
			break;
		}
		else {
			cout << "Container Size is Less then 90 ..." << endl;
			cout << endl;
		}
	}

	cout << "Enter Category Of Container (Double-cabin/Single-cabin): ";
	Cin >> this->category;
	cout << endl;

	cout << "... Is it Four Wheel Drive ? ..." << endl;
	cout << "1=(True) and 0=(False): ";
	Cin >> this->FourWheelDrive;
	cout << endl;

	if (this->FourWheelDrive == true) {
		Set_NumberOfWheels(4);
	}

	return Cin;
}
ostream& Truck::output(ostream& Cout)
{
	Cout << "Company Name: " << Get_CompanyName() << endl;
	Cout << "Color: " << Get_Color() << endl;
	Cout << "Number Of Wheels: " << Get_NumberOfWheels() << endl;
	Cout << "Power: " << Get_PowerCC() << endl;
	Cout << "Container Size: " << this->ContainerSize << endl;
	Cout << "Category: " << this->category << endl;
	if (this->FourWheelDrive == true) {
		Cout << "It is A Four Wheel Drive ..." << endl;
	}
	Cout << "Number of Trucks: " << this->NumberOfTrucks << endl;
	Cout << endl;
	return Cout;
}
Truck& Truck::operator=(Truck& rhs)
{
	if (this != &rhs) {
		this->ContainerSize = rhs.ContainerSize;
		Strcopy(this->category, rhs.category);
		this->FourWheelDrive = rhs.FourWheelDrive;
		this->NumberOfTrucks = rhs.NumberOfTrucks;
	}
	return *this;
}
void Truck::Set_ContainerSize(double s)
{
	this->ContainerSize = s;
}
void Truck::Set_Category(char* c)
{
	if (this->category) {
		delete[] this->category;
		this->category = nullptr;
	}
	Strcopy(this->category, c);
}
void Truck::Set_FourWheelDrive(bool f)
{
	this->FourWheelDrive = f;
}
double Truck::Get_ContainerSize()
{
	return this->ContainerSize;
}
char* Truck::Get_Category()
{
	char* temp = new char[Strlen(this->category) + 1];
	Strcopy(temp, this->category);
	return temp;
}
bool Truck::Get_FourWheelDrive()
{
	if (this->FourWheelDrive)
	{
		return true;
	}
	else {
		return false;
	}
}
int Truck::Get_NumberOfTrucks()
{
	return this->NumberOfTrucks;
}
void Truck::checkType()
{
	if (this->FourWheelDrive==true && Get_NumberOfWheels() == 4) {
		char* type = new char[6]{ "Truck" };
		Set_TypeOfVehicle(type);
	}
	else if (Get_NumberOfWheels() == 6) {
		char* type = new char[6]{ "Truck" };
		Set_TypeOfVehicle(type);
	}
	else {
		char* notype = new char[13]{ "No Such Type" };
		Set_TypeOfVehicle(notype);
	}
}
void Truck::Display()const
{
	Vehicle::Display();
	cout << "					Container Size :	" << this->ContainerSize << endl;
	cout << "					Category :	" << this->category << endl;
	if (this->FourWheelDrive) {
		cout << "					FourWheelDrive :	Yes" << endl;
	}
	else {
		cout << "					FourWheelDrive :	No" << endl;
	}
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
}
