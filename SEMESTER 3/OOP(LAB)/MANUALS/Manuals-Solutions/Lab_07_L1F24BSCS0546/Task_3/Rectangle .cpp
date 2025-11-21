#include<iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle():length(0),width(0){}

Rectangle::Rectangle(const double& length,const double& width):length(length),width(width){}

void Rectangle::set_length(const double& length){
    this->length = length;
}

void Rectangle::set_width(double& width){
    this->width = width;
}


double Rectangle::get_length() const{
    return length;
}
double Rectangle::get_width() const{
    return width;
}

void Rectangle::display() const{
    cout<<"Length: "<<length<<endl;
    cout<<"width: "<<width<<endl;
}

ostream& operator<<(ostream& out,const Rectangle& right){
    right.display();
    return out;
}

istream& operator>>(istream& in,Rectangle& right){
    double temp_len,temp_wid;
    cout<<"Enter length: ";
    in>>temp_len;
    cout<<"Enter width: ";
    in>>temp_wid;
    right.set_length(temp_len);
    right.set_width(temp_wid);
    return in;
}

