#include<iostream>
#include "Matrix.h"
using namespace std;
int main() {
	srand(time(0));
	// cout << "-------- Testing Matrix Class -----------\n" << endl;
	// cout << "Testing default ctor..." << endl;
	// Matrix m1;
	// cout << "Default ctor created! (0x0)" << endl;
	// cout << "Testing Parameterized ctor" << endl;
	// Matrix A(2, 3);
	// cout << "Using .fillRandom() to fill matrix randomly..." << endl;
	// A.fillRandom();
	// cout << "Matrix A (2x3) created..." << endl;
	// A.displayMatrix();
	// cout << endl;
	// cout << "Testing Copy ctor...\n";
	// Matrix B(A);
	// cout << "Matrix B (copy of ctor A):\n";
	// B.displayMatrix();
	// cout << endl;
	// cout << "Testing setElement() and getElement()...\n";
	// A.setElement(1, 2, 99);
	// cout << "A(1,2) after setting: " << A.getElement(1, 2) << endl;
	// cout << "Updated Matrix A:\n";
	// A.displayMatrix();
	// cout << endl;
	// cout << "Testing addMatrix()...\n";
	// bool added = A.addMatrix(B);
	// if (added) {
	// 	cout << "A + B:\n";
	// 	A.displayMatrix();
	// }
	// else {
	// 	cout << "Couldn't added..." << endl;
	// }
	// cout << endl;
	// cout << "Testing subtractMatrix()...\n";
	// bool subtracted = A.subtractMatrix(B);
	// if (subtracted) {
	// 	cout << "A - B (result will be in Matrix A):\n";
	// 	A.displayMatrix();
	// }
	// cout << endl;
	// cout << "Testing isEqual()...\n";
	// cout << "A == B ? " << (A.isEqual(B) ? "Yes" : "No") << endl;
	// cout << endl;
	// cout << "Testing multiplyMatrix()...\n";
	// Matrix C(3, 2);
	// C.fillRandom();
	// cout << "Matrix C (3x2):\n";
	
	// C.displayMatrix();
	// cout << endl;
	// cout << "A (2x3) * C (3x2):\n";
	// Matrix ResultantMultiplication = A.multiplyMatrix(C);
	// cout << endl;
	// cout<<"Printing Resultant Multiplied Matrix.......\n\n";
	// ResultantMultiplication.displayMatrix();
	// cout<<endl<<endl;
	// cout << "Testing transpose()...\n";
	// cout << "Transpose of B:\n";
	// Matrix ResultantTranspose = B.transpose();
	// cout<<"Printing Resultant Transpose.......\n\n";
	// ResultantTranspose.displayMatrix();
	// cout << endl;
	// cout << "Testing clear()...\n";
	// A.clear();
	// B.clear();
	// C.clear();
	// cout << "All matrices cleared successfully.\n\n";
	// cout << "Testing Matrix Class Completed!" << endl << endl;
	// cout << "----------- The END -------------" << endl;
	cout<<"------------ Testing Matrix Class for overloaded Operators ----------\n\n";
	cout<<"Creating and filling two matrices with .fillRandom() method\n\n";
	Matrix A(2,3);
	A.fillRandom();
	Matrix B(3,3);
	B.fillRandom();
	cout<<"Testing stream insertion (<<) operator...\n\n";
	cout<<"Matrix A\n\n";
	cout<<A<<endl;
	cout<<"Matrix B\n\n";
	cout<<B<<endl;
    cout<<"Testing \"+\" Operator (A + B).....\n\n";
	Matrix Addition = A + B;
	cout<<"Resultant Addition matrix......\n\n";
	cout<<Addition<<endl;
    cout<<"Testing \"-\" Operator (A - B).....\n\n";
	Matrix subtraction = A - B;
	cout<<"Resultant subtraction matrix......\n\n";
	cout<<Addition<<endl;
	cout<<"Testing \"*\" Operator (A * B).....\n\n";
	Matrix multiplication = A * B;
	cout<<"Resultant Multiplied matrix......\n\n";
	cout<<multiplication<<endl;
	cout<<"Testing \"/\" operator (A / B)....\n\n";
	double** division_result = A / B;
	cout<<"Division of A and B is....\n\n";
	for(int i = 0; i < A.getRows(); i++){
		for(int j = 0; j < B.getCols();j++){
			cout<<division_result[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Let's also check chaning for a random operator we pick \"+\" operator....\n\n";
	cout<<"Creating another matrix C.....\n\n";
	Matrix C(4,4);
	Matrix chained_addition = A + B + C;
	cout<<"Resultant chanied addition matrix (A + B + C)......\n\n";
	cout<<chained_addition<<endl;
	cout<<"Testing \"=\" Operator (A = B = C).....\n\n";
	A = B = C;
	cout<<"Resultant matrices......\n\n";
	cout<<"Matrix A....\n\n";
	cout<<A<<endl;
	cout<<"Matrix B....\n\n";
	cout<<B<<endl;
	cout<<"Matrix C....\n\n";
	cout<<C<<endl;
	cout<<"Creating and filling another Matrix D...\n\n";
	Matrix D(3,4);
	cout<<"Matrix D....\n\n";
	cout<<D<<endl;
	cout<<"Testing \"==\" Operator (A == B ).....\n\n";
	if(A == B){
		cout<<"A and B are equal!\n\n";
	}else{
		cout<<"A and B aren't equal!\n\n";
	}
	cout<<"Testing \"<\" Operator (A < D ).....\n\n";
	if(A < D){
		cout<<"A is less than D!\n\n";
	}else{
		cout<<"A is greater than or equal to D!\n\n";
	}
	cout<<"Testing \"<=\" Operator (A <= D ).....\n\n";
	if(A <= D){
		cout<<"A is less than or equal to D!\n\n";
	}else{
		cout<<"A is greater than or equal to D!\n\n";
	}
	cout<<"Testing \">\" Operator (A > D ).....\n\n";
	if(A > D){
		cout<<"A is greater than D!\n\n";
	}else{
		cout<<"A is less than or equal to D!\n\n";
	}

	cout<<"Testing \">=\" Operator (A >= D ).....\n\n";
	if(A >= B){
		cout<<"A is greater than or equal D!\n\n";
	}else{
		cout<<"A is less than D!\n\n";
	}
	cout<<"Testing pre increament\"++\" (++A)....\n\n";
	++A;
	cout<<"Increamented matrix A.....\n\n";
	cout<<A<<endl;

	cout<<"Testing post increament\"++\" (A++)....\n\n";
	Matrix temp = A++;
	cout << "After post-increment (A++) returne:\n\n";
	cout<<temp<<endl;
    cout << "Matrix A after post-increment\n\n";
	cout<<A<<endl;

	cout<<"Testing pre decreament\"--\" (--A)....\n\n";
	--A;
	cout<<"decreamented matrix A.....\n\n";
	cout<<A<<endl;

	cout<<"Testing post decreament\"--\" (A--)....\n\n";
	Matrix temp1 = A--;
	cout << "After post-decrement (A--) returne:\n\n";
	cout<<temp1<<endl;
    cout << "Matrix A after post-decrement\n\n";
	cout<<A<<endl;

	cout<<"Testing stream extreaction operator(>>)....\n\n";
	cin>>A;
	cout<<"A after inputing data from user....\n\n";
	cout<<A<<endl;

	cout<<"---------------- THE END ----------------\n\n";
	

	




	return 0;
}