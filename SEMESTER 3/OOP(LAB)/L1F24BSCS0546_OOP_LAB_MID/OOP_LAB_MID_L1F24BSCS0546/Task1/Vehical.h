#pragma once
class Vehical
{
private:
	char* modelName;
	int manufacturingYear;
	char* Vehicletype;
	char* fuelType;
	double price;
	int currentYear;
	double Depreciation_;
public:
	Vehical();
	Vehical(char* modelName, int manufacturingYear, char* Vehicletype, char* fuelType, double price);
	Vehical( Vehical& other);
	void display() const;
	double calculteDepreciation();
	void set_modelName(char* modelName);
	void set_manufacturingYear(int manufacturingYear);
	void set_VehicleType(char* Vehicletype);
	void set_fuelType(char* fuelType);
	void set_price(double price);
	
	const char* get_modelName() const;
	int get_manufacturingYear() const;
	const char* get_VehicleType() const;
	const char* get_fuelType() const;
	double get_price() const;


};


void regrow(char*& arr, int& size, char input);

int getLen(char* arr);

char* copyArr(char* arr);