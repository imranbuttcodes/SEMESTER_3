#pragma once
class Displacement
{
private:
	double x;
	double y;
public:	
	Displacement();
	Displacement(double x, double y);
	Displacement operator+(const Displacement& right) const;
	Displacement operator-(const Displacement& right) const;

	void display() const;
};

