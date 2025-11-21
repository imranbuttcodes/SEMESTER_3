#pragma once
#include<iostream>
class Rectangle{
private:
    double length;
    double width;
public:
    Rectangle();
    Rectangle(const double& length,const double& width);
    void set_width(double& width);
    void set_length(const double& length);
    double get_width() const;
    double get_length() const;
    void display() const;
};

std::ostream& operator<<(std::ostream& out,const Rectangle& right);
std::istream& operator>>(std::istream& out,Rectangle& right);
