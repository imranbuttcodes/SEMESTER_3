#include<iostream>
using namespace std;

class ComplexNumber {
private:
	double realPart;
	double imaginaryPart;
public:
	void setValue(double realPart, double imaginaryPart) {
		this->realPart = realPart;
		this->imaginaryPart = imaginaryPart;
	}
	double getRealValue() {
		return realPart;
	}
	double getImaginaryPart() {
		return imaginaryPart;
	}
	void display() {

		cout << "Complex Number: " << realPart << " + " << imaginaryPart << "i" << endl;

	}
		
	
};
void sum(ComplexNumber& obj1, ComplexNumber& obj2) {
	cout << "Sum of ( " << obj1.getRealValue() << " + " << obj1.getImaginaryPart()<<"i" << " ) + ( " << obj2.getRealValue() << " + " << obj2.getImaginaryPart() << "i" << ")  = " << obj1.getRealValue() + obj2.getRealValue() << " + " << obj1.getImaginaryPart() + obj2.getImaginaryPart() << "i" << endl;

}
void difference(ComplexNumber& obj1, ComplexNumber& obj2) {
	cout << "Difference  of ( " << obj1.getRealValue() << " + " << obj1.getImaginaryPart()<<"i" << " ) - ( " << obj2.getRealValue() << " + " << obj2.getImaginaryPart()<<"i" << ") = " << obj1.getRealValue() - obj2.getRealValue() << " + " << (obj1.getImaginaryPart()) -  (obj2.getImaginaryPart()) << "i" << endl;

}
void getInputs(double& real, double& imag) {
	cout << "Enter Real part of Complex Number:  ";
	cin >> real;
	cout << "Enter Imaginary part of Complex Number: ";
	cin >> imag;
}
int main() {
	ComplexNumber c1,c2;
	double real, imagin;
	cout << "1st Complex Number :\n";
	getInputs(real, imagin);
	c1.setValue(real, imagin);
	cout << "2nd Complex Number:\n";
	getInputs(real, imagin);
	c2.setValue(real,imagin);
	cout << "1st ";
	c1.display();
	cout << "2st ";
	c2.display();
	sum(c1, c2);
	difference(c1, c2);
}