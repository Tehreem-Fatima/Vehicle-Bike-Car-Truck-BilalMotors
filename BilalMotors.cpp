# Vehicle-Bike-Car-Truck-BilalMotors
A C++ code having base class Vehicle and subclasses Bike, Car, Truck. The Vehicle class has aggregation with BilalMotors.

#include "BilalMotors.h"
#include <iostream>
#include <fstream>
using namespace std;

BilalMotors::BilalMotors()
{
	this->size = 0;
	this->arr = new Vehicle*[20];
}
//BilalMotors::BilalMotors(int s)
//{
//	this->size = s;
//	this->arr = new Vehicle * [this->size];
//}
BilalMotors::BilalMotors(const BilalMotors& obj)
{
	this->size = obj.size;
	this->arr = obj.arr;
}
BilalMotors::~BilalMotors()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
}
const Vehicle* BilalMotors::operator[](int index)const
{
	if (index >= 0 && index < 20) {
		return this->arr[index];
	}
	else {
		return this->arr[0];
	}
}
Vehicle* BilalMotors::operator[](int index)
{
	if (index >= 0 && index < 20) {
		return this->arr[index];
	}
	else {
		return this->arr[0];
	}
}
BilalMotors& BilalMotors::operator=(const BilalMotors& rhs)
{
	if (this != &rhs)
	{
		this->arr = rhs.arr;
		this->size = rhs.size;
	}
	return *this;
}
void BilalMotors::Add_Vehicle()
{
	char choice;
	Vehicle* temp = nullptr;
	while (1) {
		cout << "Press B for Bike" << endl;
		cout << "Press C for Car" << endl;
		cout << "Press T for Truck" << endl;
		cout << "Press 0 for Main Menu" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		cout << endl;
		if (choice == 'b' || choice == 'B') {
			char* name = new char[6]{ "Honda" };
			char* color = new char[6]{ "black" };
			
			Bike* obj = new Bike(10, true, true, name, color, 2);
			obj->input(cin);
			obj->checkType();
			
			this->arr[this->size++] = obj;
			cout << "Vehicle Added SuccessFully ..." << endl;
		}
		else if (choice == 'C' || choice == 'c') {
			char* name = new char[6]{ "Honda" };
			Car* obj = new Car(4, name, 4, name, name, 2);
			obj->input(cin);
			obj->checkType();

			this->arr[this->size++] = obj;
			cout << "Vehicle Added SuccessFully ..." << endl;
		}
		else if (choice == 't' || choice == 'T') {
			char* name = new char[6]{ "Honda" };
			Truck* obj = new Truck(4, name, 4, name, name, 2);
			obj->input(cin);
			obj->checkType();

			this->arr[this->size++] = obj;
			cout << "Vehicle Added SuccessFully ..." << endl;
		}
		else if (choice == '0') {
			break;
		}
		else {
			cout << "Enter Correct Choice ..." << endl;
		}
	}
}
void BilalMotors::Search_Vehicle(char* t)
{
	int flag = 0;
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(arr[i]->Get_TypeOfVehicle(), t)) {
			index = i;
			flag = 1;
			break;
		}
	}
	if (flag) {
		cout << "Vehicle's Are :--> " << endl;
		for (int i = index; i < size; i++) {
			cout << "					Vehicle # :		" << i + 1 << endl;
			cout << "--------------------------------------------------------------------------------------------------------" << endl;
			cout << "					Company :	" << arr[i]->Get_CompanyName() << endl;
			cout << "					Color :	" << arr[i]->Get_Color() << endl;
			cout << "					Type Of Vehicle :	" << arr[i]->Get_TypeOfVehicle() << endl;
			cout << "					Number Of Wheels :	" << arr[i]->Get_NumberOfWheels() << endl;
			cout << "					Power CC :	" << arr[i]->Get_PowerCC() << endl;
			cout << "--------------------------------------------------------------------------------------------------------" << endl;
		}
		cout << endl;
	}
	else {
		cout << "No Account Found !!" << endl;
	}
}
bool BilalMotors::Save_Data(const char* fname)const
{
	ofstream fout;
	char* name = new char[6]{ "Honda" };
	char* color = new char[6]{ "black" };
	fout.open(fname);
	if (fout.is_open()) {
		fout << "Vehicle Information" << endl;
		fout << "------------------------" << endl;
		fout << "Number Of Bikes: " << &Bike::Get_NumberOfBikes << endl;
		fout << "Number Of Cars: " << &Car::Get_NumberOfCars << endl;
		fout << "Number Of Trucks: " << &Truck::Get_NumberOfTrucks << endl;
		fout << endl;
		fout << "Company Name:		Type:		Color:		Power:" << endl;
		fout << "-----------------------------------------------------------------" << endl;
		for (int i = 0; i < size; i++) {
			fout << arr[i]->Get_CompanyName() << "			" << arr[i]->Get_TypeOfVehicle() << "		" << arr[i]->Get_Color() << "		" << arr[i]->Get_PowerCC() << endl;
		}
		return true;
	}
	else {
		return false;
	}
	fout.close();

}
const int BilalMotors::Get_Size()const
{
	return this->size;
}

//istream& operator>>(istream& Cin, Bike* obj)
//{
//	return obj->input(Cin);
//}
