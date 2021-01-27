# Vehicle-Bike-Car-Truck-BilalMotors
A C++ code having base class Vehicle and subclasses Bike, Car, Truck. The Vehicle class has aggregation with BilalMotors.

#include "Car.h"
#include <iostream>
using namespace std;

//Car::Car():Vehicle()
//{
//	this->NumberOfDoors = 0;
//	this->transmission = nullptr;
//	this->NumberOfSeats = 0;
//	this->NumberOfCars = 0;
//}
Car::Car(int d, char* t, int s, char* n, char* c, int p):Vehicle(n,c,p)
{
	this->NumberOfDoors = d;
	Strcopy(this->transmission, t);
	this->NumberOfSeats = s;
	this->NumberOfCars++;
}
Car::Car(Car& obj) :Vehicle(obj)
{
	this->NumberOfDoors = obj.NumberOfDoors;
	Strcopy(this->transmission, obj.transmission);
	this->NumberOfSeats = obj.NumberOfSeats;
	this->NumberOfCars = obj.NumberOfCars;
}
Car::~Car()
{
	this->NumberOfDoors = 0;
	delete[] this->transmission;
	this->transmission = nullptr;
	this->NumberOfSeats = 0;
	this->NumberOfCars = 0;
}
istream& Car::input(istream& Cin)
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
			if (wheels == 4) {
				Set_NumberOfWheels(wheels);
				break;
			}
			else {
				cout << "Car Has Only 4 Wheels ..." << endl;
				cout << endl;
			}
		}

		int power = 0;
		while (1) {
			cout << "Enter Power: ";
			Cin >> power;
			cout << endl;
			if (power <= 4500) {
				Set_PowerCC(power);
				break;
			}
			else {
				cout << "Power is Less than 4500 ..." << endl;
				cout << endl;
			}
		}

		while (1) {
			cout << "Input Number Of Doors: ";
			Cin >> this->NumberOfDoors;
			cout << endl;
			if (this->NumberOfDoors == 4 || this->NumberOfDoors==2) {
				Set_NumberOfDoors(this->NumberOfDoors);
				break;
			}
			else {
				cout << "Car Has 2 Doors or 4 Doors ..." << endl;
				cout << endl;
			}
		}

		cout << "Enter Transmission (Automatic/Manual): ";
		Cin >> this->transmission;
		cout << endl;

		while (1) {
			cout << "Enter Number Of Seats: ";
			Cin >> this->NumberOfSeats;
			cout << endl;
			if (this->NumberOfSeats == 2 && this->NumberOfDoors == 2) {
				Set_NumberOfSeats(this->NumberOfSeats);
				break;
			}
			else if (this->NumberOfDoors == 4 && this->NumberOfSeats==4) {
					Set_NumberOfSeats(this->NumberOfSeats);
					break;
				}
			else {
				cout << "Number Of Seats Should be 2 or 4 ..." << endl;
				cout << endl;
			}
		}

		break;
	}
	return Cin;
}
ostream& Car::output(ostream& Cout)
{
	Cout << "Company Name: " << Get_CompanyName() << endl;
	Cout << "Color: " << Get_Color() << endl;
	Cout << "Number Of Wheels: " << Get_NumberOfWheels() << endl;
	Cout << "Power: " << Get_PowerCC() << endl;
	Cout << "Number Of Doors: " << this->NumberOfDoors << endl;
	Cout << "Transmission: " << this->transmission << endl;
	Cout << "Number Of Seats: " << this->NumberOfSeats << endl;
	Cout << "Number Of Cars: " << this->NumberOfCars << endl;
	Cout << endl;
	return Cout;
}
Car& Car::operator=(Car& rhs)
{
	if (this != &rhs) {
		this->NumberOfDoors = rhs.NumberOfDoors;
		Strcopy(this->transmission, rhs.transmission);
		this->NumberOfSeats = rhs.NumberOfSeats;
		this->NumberOfCars = rhs.NumberOfCars;
	}
	return *this;
}
void Car::Set_NumberOfDoors(int d)
{
	NumberOfDoors = d;
}
void Car::Set_Transmission(char* t)
{
	if (this->transmission) {
		delete[] this->transmission;
		this->transmission = nullptr;
	}
	Strcopy(this->transmission, t);
}
void Car::Set_NumberOfSeats(int s)
{
	this->NumberOfSeats = s;
}
int Car::Get_NumberOfDoors()
{
	return this->NumberOfDoors;
}
char* Car::Get_Transmission()
{
	char* temp = new char[Strlen(this->transmission) + 1];
	Strcopy(temp, this->transmission);
	return temp;
}
int Car::Get_NumberOfSeats()
{
	return this->NumberOfSeats;
}
int Car::Get_NumberOfCars()
{
	return this->NumberOfCars;
}
void Car::checkType()
{
	if (Get_NumberOfWheels() == 4) {
		char* type = new char[4]{ "Car" };
		Set_TypeOfVehicle(type);
	}
	else{
		char* notype = new char[13]{ "No Such Type" };
		Set_TypeOfVehicle(notype);
	}
}
void Car::Display()const
{
	Vehicle::Display();
	cout << "					Number Of Doors :	" << this->NumberOfDoors << endl;
	cout << "					Transmission :	" << this->transmission << endl;
	cout << "					Number Of Seats :	" << this->NumberOfSeats << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
}
