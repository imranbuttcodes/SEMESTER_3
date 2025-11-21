#include<iostream>
#include "Complex.h"
using namespace std;

Complex::Complex():real(0.0),imaginary(0.0){}

Complex::Complex(double real,double imaginary):real(real),imaginary(imaginary){}

void Complex::set_imaginary(double imaginary){
    this->imaginary = imaginary;
}

void Complex::set_real(double real){
    this->real = real;
}

double Complex::get_imaginary() const{
    return imaginary;
}

double Complex::get_real() const{
    return real;
}

void Complex::display() const{
    cout<<"Complex Number: "<<real<<" + "<<imaginary<<"i"<<endl;
}

std::ostream& operator<<(std::ostream& out,const Complex& right){
    right.display();
    return out;
}
std::istream& operator>>(std::istream& in,Complex& right){
    double real,imaginary;
    cout<<"Enter real Number: ";
    cin>>real;
    
    cout<<"Enter imaginry Number: ";
    cin>>imaginary;

    right.set_imaginary(imaginary);
    right.set_real(real);
    return in;
}

