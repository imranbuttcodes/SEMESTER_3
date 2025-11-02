#include "Vehicle.h"
#include<iostream>
using namespace std;

char* Vehicle::copyData(char* arr){
    char* temp_arr = new char[strLen(arr) + 1];
    for(int i = 0; arr[i] != '\0'; i++){
        temp_arr[i] = arr[i];
    }
    temp_arr[strLen(arr)] = '\0';
    return temp_arr;
}


Vehicle::Vehicle():name(nullptr),brand(nullptr),price(0.0){}
Vehicle::Vehicle(const char* name,char* brand,double price){
    this->name = copyData((char*)name);
    this->brand = copyData(brand);
    this->price = price;
}

Vehicle::Vehicle(const Vehicle& other){
 
    this->name = copyData((char*)other.name);
    this->brand = copyData((char*)other.brand);
    this->price = other.price;
}

void Vehicle::setName(const char* name){
    if(this->name)  delete[] this->name;
    this->name = copyData((char*)name);
}
void Vehicle::setBrand(char* brand){
    if(this->brand) delete[] this->brand;
    this->brand = copyData((char*) brand);
}
void Vehicle::setPrice(double price){
    this->price = price;
}
const char* Vehicle::getName() const{
    return name;
 }
 char* Vehicle::getBrand() const{
    return brand;
 }
double Vehicle::getPrice() const{
    return price;
}

void Vehicle::display(){
cout<<"Vehicle Name: "<<name<<endl;
cout<<"Vehicle Brand: "<<brand<<endl;
cout<<"Vehicle Price: "<<price<<endl;
}

void Vehicle::sortVehicles(Vehicle *arr,int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j].price > arr[j + 1].price){
                Vehicle temp(arr[j]);
                arr[j].setName(arr[j + 1].getName());
                arr[j].setBrand(arr[j + 1].getBrand());
                arr[j].setPrice(arr[j + 1].getPrice());

                arr[j + 1].setName(temp.getName());
                arr[j + 1].setBrand(temp.getBrand());
                arr[j + 1].setPrice(temp.getPrice());
            }
        }
    }
}

Vehicle::~Vehicle(){
    delete[] name;
    delete[] brand;
}
int Vehicle::strLen(char* arr){
    int len = 0;
    for(int i = 0;arr[i] != '\0'; i++){
        len++;
    }
    return len;
}