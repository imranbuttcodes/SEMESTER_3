#include<iostream>
#include "Vehical.h"
using namespace std;

char* getInputChar() {
	char garbage;
	char* temp = nullptr;
	int size = 0;
	while (true) {
		cin.get(garbage);
		if (garbage == '\n') {
			break;
		}
		regrow(temp, size, garbage);
	}
	regrow(temp, size, '\0');
	return temp;
}


int main() {
	Vehical v1;
	int manufacturingYear;
	cout << "Vehicle Obj created...\n\n";
	cout << "Please enter vehicle model : ";
	char* modelName = getInputChar();
	cout << "Please enter manufacturing year : ";
	cin >> manufacturingYear;
	cin.ignore();
	cout << "Year: " << manufacturingYear << endl;
	cout << "Please enter vehicle type (Car/Truck/Bus): ";
	char* vehicleType = getInputChar();
	cout << "Please enter fuel type (Petrol/Diesel/Electric): ";
	char* fuel_type = getInputChar();
	cout << "Please enter price: ";
	double price;
	cin >> price;
	cin.ignore();
	v1.set_modelName(modelName);
	v1.set_fuelType(fuel_type);
	v1.set_manufacturingYear(manufacturingYear);
	v1.set_price(price);
	v1.set_VehicleType(vehicleType);
	v1.display();

	return 0;
}