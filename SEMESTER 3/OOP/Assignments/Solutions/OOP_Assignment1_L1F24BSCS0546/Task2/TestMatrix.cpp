#include<iostream>
#include "Matrix.h"
using namespace std;
int main() {
	srand(time(0));
	cout << "-------- Testing Matrix Class -----------\n" << endl;
	cout << "Testing default ctor..." << endl;
	Matrix m1;
	cout << "Default ctor created! (0x0)" << endl;
	cout << "Testing Parameterized ctor" << endl;
	Matrix A(2, 3);
	cout << "Using .fillRandom() to fill matrix randomly..." << endl;
	A.fillRandom();
	cout << "Matrix A (2x3) created..." << endl;
	A.displayMatrix();
	cout << endl;
	cout << "Testing Copy ctor...\n";
	Matrix B(A);
	cout << "Matrix B (copy of ctor A):\n";
	B.displayMatrix();
	cout << endl;
	cout << "Testing setElement() and getElement()...\n";
	A.setElement(1, 2, 99);
	cout << "A(1,2) after setting: " << A.getElement(1, 2) << endl;
	cout << "Updated Matrix A:\n";
	A.displayMatrix();
	cout << endl;
	cout << "Testing addMatrix()...\n";
	bool added = A.addMatrix(B);
	if (added) {
		cout << "A + B:\n";
		A.displayMatrix();
	}
	else {
		cout << "Couldn't added..." << endl;
	}
	cout << endl;
	cout << "Testing subtractMatrix()...\n";
	bool subtracted = A.subtractMatrix(B);
	if (subtracted) {
		cout << "A - B (result will be in Matrix A):\n";
		A.displayMatrix();
	}
	cout << endl;
	cout << "Testing isEqual()...\n";
	cout << "A == B ? " << (A.isEqual(B) ? "Yes" : "No") << endl;
	cout << endl;
	cout << "Testing multiplyMatrix()...\n";
	Matrix C(3, 2);
	C.fillRandom();
	cout << "Matrix C (3x2):\n";
	
	C.displayMatrix();
	cout << endl;
	cout << "A (2x3) * C (3x2):\n";
	Matrix ResultantMultiplication = A.multiplyMatrix(C);
	cout << endl;
	cout<<"Printing Resultant Multiplied Matrix.......\n\n";
	ResultantMultiplication.displayMatrix();
	cout<<endl<<endl;
	cout << "Testing transpose()...\n";
	cout << "Transpose of B:\n";
	Matrix ResultantTranspose = B.transpose();
	cout<<"Printing Resultant Transpose.......\n\n";
	ResultantTranspose.displayMatrix();
	cout << endl;
	cout << "Testing clear()...\n";
	A.clear();
	B.clear();
	C.clear();
	cout << "All matrices cleared successfully.\n\n";
	cout << "Testing Matrix Class Completed!" << endl << endl;
	cout << "----------- The END -------------" << endl;

	return 0;
}