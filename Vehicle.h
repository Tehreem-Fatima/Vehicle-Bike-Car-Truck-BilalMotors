# Vehicle-Bike-Car-Truck-BilalMotors
A C++ code having base class Vehicle and subclasses Bike, Car, Truck. The Vehicle class has aggregation with BilalMotors.

#pragma once
class Vehicle
{
private:
	char* CompanyName;
	char* color;
	int NumberOfWheels;
	int PowerCC;
	char* TypeOfVehicle;
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
	/*Vehicle();*/
	Vehicle(char* = nullptr, char* = nullptr, int = 0);
	Vehicle(const Vehicle&);
	~Vehicle();
	Vehicle& operator=(Vehicle&);
	void Set_CompanyName(char*);
	void Set_Color(char*);
	void Set_NumberOfWheels(int);
	void Set_PowerCC(int);
	void Set_TypeOfVehicle(char*);
	char* Get_CompanyName();
	char* Get_Color();
	int Get_NumberOfWheels();
	int Get_PowerCC();
	char* Get_TypeOfVehicle();
	virtual void checkType() = 0;
	virtual void Display()const;
};

