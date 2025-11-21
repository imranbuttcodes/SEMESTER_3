#include "Displacement.h"
#include<iostream>
using namespace std;

Displacement::Displacement() {
	x = 0.0;
	y = 0.0;
}

Displacement::Displacement(double x, double y) {
	this->x = x;
	this->y = y;
}

Displacement Displacement::operator+(const Displacement& right) const {
	Displacement temp;
	temp.x = x + right.x;
	temp.y = y + right.y;
	return temp;

}


Displacement Displacement::operator-(const Displacement& right) const {
	Displacement temp;
	temp.x = x - right.x;
	temp.y = y - right.y;
	return temp;

}

void Displacement::display() const {
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
}