#include<iostream>
#include "Point.h"
using namespace std;

Point::Point():x(0),y(0){}

Point::Point(int x,int y):x(x),y(y){}

void Point::set_x(int x){
    this->x = x;
}

void Point::set_y(int y){
    this->y = y;
}

int Point::get_y() const{
    return y;
}

int Point::get_x() const{
    return x;
}

void Point::display() const{
    cout<<"x: "<<x<<"\n"<<"y: "<<y<<endl;
}

std::ostream& operator<<(std::ostream& out,const Point& right){
    right.display();
    return out;
}
std::istream& operator>>(std::istream& in,Point& right){
    int x,y;
    cout<<"Enter x Point: ";
    cin>>x;
    
    cout<<"Enter y Point: ";
    cin>>y;

    right.set_x(x);
    right.set_y(y);
    return in;
}

