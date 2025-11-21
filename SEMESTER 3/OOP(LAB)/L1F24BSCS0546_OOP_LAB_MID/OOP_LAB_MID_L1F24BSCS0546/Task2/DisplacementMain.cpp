#include<iostream>
#include "Displacement.h"
using namespace std;
int main() {
	Displacement obj1(3.0,4.0);
	cout << "Displacement Obj1 created....\n\n";
	obj1.display();
	Displacement obj2(1.5, 2.5);
	cout << "Displacement Obj2 created....\n\n";
	obj2.display();
	cout << "Adding...\n\n";
	Displacement add = obj1 + obj2;
	cout << "Addition result\n\n";
	add.display();
	cout << "Subtracting...\n\n";
	Displacement sub = obj1 - obj2;
	cout << "subtraction result\n\n";
	sub.display();
	return 0;
}