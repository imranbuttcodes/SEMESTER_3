#pragma once
#include<iostream>
class Complex{
private:
double real,imaginary;
public:
Complex();
Complex(double real,double imaginary);
void set_real(double real);
void set_imaginary(double imaginary);
double get_real() const;
double get_imaginary() const;
void display() const;
};

std::ostream& operator<<(std::ostream& out,const Complex& right);
std::istream& operator>>(std::istream& in,Complex& right);