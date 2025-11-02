#include "Person.h"
#include<iostream>
using namespace std;

Person::Person():Name(nullptr),age(0),countryName(nullptr){}
Person::Person(char* Name, int age, char* countryName) {
	int nameLen = strLen(Name);
	this->Name = new char[nameLen + 1];
	for (int i = 0; Name[i] != '\0'; i++) {
		this->Name[i] = Name[i];
	}
	this->Name[nameLen] = '\0';
	this->age = age;
	int countryLen = strLen(countryName);
	this->countryName = new char[countryLen + 1];
	for (int i = 0; countryName[i] != '\0'; i++) {
		this->countryName[i] = countryName[i];
	}
	this->countryName[countryLen] = '\0';



}
Person::Person(const Person& other) {
	Name = new char[strLen(other.Name) + 1];
	for (int i = 0; other.Name[i] != '\0'; i++) {
		Name[i] = other.Name[i];
	}
	Name[strLen(other.Name)] = '\0';
	countryName = new char[strLen(other.countryName) + 1];
	for (int i = 0; other.countryName[i] != '\0'; i++) {
		countryName[i] = other.countryName[i];
	}
	countryName[strLen(other.countryName)] = '\0';
	age = other.age;
}
int Person::strLen(char* arr) {
	int len = 0;
	for (int i = 0; arr[i] != '\0'; i++) {
		len++;
	}
	return len;
}
void Person::setName(char* Name) {
	if (this->Name) {
		delete[] this->Name;
	}
	int NameLen = strLen(Name);
	this->Name = new char[NameLen + 1];
	for (int i = 0; Name[i] != '\0'; i++) {
		this->Name[i] = Name[i];
	}
	this->Name[NameLen] = '\0';
}
void Person::setCountry(char* countryName) {
	if (this->countryName) {
		delete[] this->countryName;
	}
	int countryLen = strLen(countryName);
	this->countryName = new char[countryLen + 1];
	for (int i = 0; countryName[i] != '\0'; i++) {
		this->countryName[i] = countryName[i];
	}
	this->countryName[countryLen] = '\0';
}

void Person::setAge(int age) {
	this->age = age;
}
int Person::getAge() const {
	return age;
}
char* Person::getName() const {
	return Name;
}
char* Person::getCountry() const {
	return countryName;
}
void Person::compareAge( Person& other) {
	if (age > other.age) {
		display();
	}
	else {
		other.display();
	}
}

void Person::display() {
	cout << "Name: " << Name << endl;
	cout << "Age: " << age<< endl;
	cout << "Country Name: " << countryName << endl;
}
Person::~Person() {
	delete[] Name;
	delete[] countryName;
}

