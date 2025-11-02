#pragma once
class Vehicle{
private:
    const char* name;
    char* brand;
    double price;
public:
    Vehicle();
    Vehicle(const char* name,char* brand,double price);
    Vehicle(const Vehicle& other);
    void setName(const char* name);
    void setBrand(char* brand);
    void setPrice(double price);
    const char* getName() const;
    char* getBrand() const;
    double getPrice() const;
    void display();
    void sortVehicles(Vehicle *arr,int size);
    int strLen(char* arr);
    char* copyData(char* arr);
    ~Vehicle(); 
};