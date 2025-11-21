#pragma once
#include<iostream>
class Point{
private:
int x,y;
public:
Point();
Point(int x,int y);
void set_x(int x);
void set_y(int y);
int get_x() const;
int get_y() const;
void display() const;
};

std::ostream& operator<<(std::ostream& out,const Point& right);
std::istream& operator>>(std::istream& in,Point& right);