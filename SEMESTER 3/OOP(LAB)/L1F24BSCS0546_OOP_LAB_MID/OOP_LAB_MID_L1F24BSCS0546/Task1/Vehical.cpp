#include "Vehical.h"
#include<iostream>
using namespace std;

int getLen(char* arr) {
	int len = 0;
	for (int i = 0; arr[i] != '\0'; i++) {
		len++;
	}
	return len;
}

void regrow(char*& arr, int& size, char input) {
	char* temp = new char[size + 1];
	for (int i = 0; i< size; i++)
	{
		temp[i] = arr[i];
	}
temp[size] = input;
size++;
delete[] arr;
arr = temp;
}

char* copyArr(char* arr) {
	char* temp = new char[getLen(arr) + 1];
	for (int i = 0; arr[i] != '\0'; i++) {
		temp[i] = arr[i];
	}
	temp[getLen(arr)] = '\0';
	return temp;
}

Vehical::Vehical() {
	modelName = new char[1];
	modelName[0] = '\0';

	manufacturingYear = 0;

	Vehicletype = new char[1];
	Vehicletype[0] = '\0';

	fuelType = new char[1];
	fuelType[0] = '\0';
	price = 0.0;

	currentYear = 2025;

	Depreciation_ = 0.0;
}


Vehical::Vehical(char* modelName, int manufacturingYear, char* Vehicletype, char* fuelType, double price) {
	this->modelName = copyArr(modelName);
	this->manufacturingYear = manufacturingYear;
	this->Vehicletype = copyArr(Vehicletype);
	this->fuelType = copyArr(fuelType);
	this->price = price;

	Depreciation_ = calculteDepreciation();
}


Vehical::Vehical(Vehical& other) {
	this->modelName = copyArr(other.modelName);
	this->manufacturingYear = other.manufacturingYear;
	this->Vehicletype = copyArr(other.Vehicletype);
	this->fuelType = copyArr(other.fuelType);
	this->price = other.price;
	Depreciation_ = other.Depreciation_;
	this->currentYear = other.currentYear;
}

void Vehical::set_modelName(char* modelName) {
	if (this->modelName)		delete[] this->modelName;
	this->modelName = copyArr(modelName);
}

void Vehical::set_manufacturingYear(int manufacturingYear) {
	this->manufacturingYear = manufacturingYear;
}

void Vehical::set_VehicleType(char* Vehicletype) {
	this->Vehicletype = copyArr(Vehicletype);
}

void Vehical::set_fuelType(char* fuelType) {
	this->fuelType = copyArr(fuelType);
}


void Vehical::set_price(double price) {
	this->price = price;
}


const char* Vehical::get_modelName() const {
	return modelName;
}


int Vehical::get_manufacturingYear() const {
	return manufacturingYear;
}


const char* Vehical::get_VehicleType() const {
	return Vehicletype;
}

const char* Vehical::get_fuelType() const {
	return fuelType;
}

double  Vehical::get_price() const {
	return price;
}


double Vehical::calculteDepreciation() {
	double Depreciation_per_year = 0.0;
	int dep_year = (currentYear - manufacturingYear);
	if (dep_year <= 2) {
		 Depreciation_per_year = (price / 100.0) * 5;
		return Depreciation_per_year * dep_year;
	}
	else if (dep_year >= 3 && dep_year <= 5) {
		Depreciation_per_year = (price / 100.0) * 10;
		return Depreciation_per_year * dep_year;
	}
	else if (dep_year >= 6 && dep_year <= 10) {
		Depreciation_per_year = (price / 100.0) * 15;
		return Depreciation_per_year * dep_year;
	}
	Depreciation_per_year = (price / 100.0) * 20;
	return Depreciation_per_year * dep_year;

}


void Vehical::display() const {
	cout << "--- Displaying Details for Vehicle  ---\n\n";
	cout << "Model Name: " << modelName << endl;
	cout << "Manufacturing Year: " << manufacturingYear << endl;
	cout << "Fuel Type:          " << fuelType << endl;
	cout << "Original Price:     " << price << endl;
	cout << "---------------------------------------" << endl;
	cout << "Vehicle Age: " << currentYear - manufacturingYear << endl;
	cout << "Total Depreciation: " << Depreciation_ << endl;
	cout << "Current Estimated Value: " << price - Depreciation_ << endl;
}

