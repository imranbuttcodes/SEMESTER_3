#include<iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix():rows(0),cols(0) {
	allocateMatrix();
}

Matrix::Matrix(int rows, int cols):cols(cols < 0?0:cols),rows(rows<0?0:rows) {
    allocateMatrix();
}
Matrix::Matrix(const Matrix& other):rows(other.rows<0?0:other.rows),cols(other.cols<0?0:other.cols) {
    allocateMatrix();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] = other.data[i][j];
		}
	}


}
bool Matrix::inputMatrix() 
{
	cout << "Input " << rows * cols << "Elements: ";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> data[i][j];
		}
	}

	return true;

}
void Matrix::setElement(int r, int c, int value) {
	if (!isValidIndex(r, c)) {
		cout << "Invalid rows or columns enterd!";
		return;
	}
	data[r][c] = value;
}
int Matrix::getElement(int r, int c) {
	if (!isValidIndex(r,c)) {
		cout << "Invalid rows or columns enterd!";
		return 0;
	}
	return data[r][c];
}
void Matrix::displayMatrix() {
	cout << "Matrix:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}
bool Matrix::isValidIndex(int r, int c) {
	if (r < 0 || r >= rows || c < 0 || c >= cols) {
		return false;
	}
	return true;
}
bool Matrix::addMatrix(const Matrix& other) {
	if (!(other.rows == rows && other.cols == cols)) {
		cout << "Can't add the matrix due to mismatch size\n";
		return false;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] += other.data[i][j];

		}
	}
	return true;
}
bool Matrix::subtractMatrix(const Matrix& other) {
	if (!(other.rows == rows && other.cols == cols)) {
		cout << "Can't subtract the matrix due to mismatch size\n";
		return false;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] -= other.data[i][j];

		}
	}
	return true;
}
Matrix Matrix::multiplyMatrix(const Matrix& other){
    if(cols != other.rows){
        cout<<"Invlaid dimension can't be multiplied!"<<endl;
        return *this;
    }
    
    Matrix temp_obj(rows,other.cols);

    for(int i = 0;i < rows; i++){
        for(int j = 0; j < other.cols; j++){
            int sum = 0;
            for(int k = 0; k < cols; k++){
                sum += data[i][k]*other.data[k][j]; 
            }
            temp_obj.data[i][j] = sum;
        }
    }
    
    return temp_obj;
}

Matrix Matrix::transpose(){
    Matrix temp_obj(cols,rows);
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            temp_obj.data[i][j] = data[j][i];
        }
    }
    return temp_obj;
}
bool Matrix::isEqual(const Matrix& other){
    if(rows != other.rows || cols != other.cols)     return false;
    for(int i = 0; i < rows; i++){
        for(int j = 0 ; j < cols; j++){
            if(data[i][j] != other.data[i][j]){
                return false;
            }
        }
    }
    return true;
}
int Matrix::getRows(){
    return rows;
}
int Matrix::getCols(){
    return cols;
}
void Matrix::allocateMatrix(){
    data = new int*[rows];
    for(int i = 0;i < rows; i++){
        data[i] = new int[cols];
    }
}
void Matrix::clear(){
    for(int i = 0 ;i < rows; i++){
        delete[] data[i];
    }
    delete[] data;
}
void Matrix::fillRandom(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            data[i][j] = rand() % 100;
        }
    }
}

void Matrix::copyFrom(const Matrix& other){
    if(rows != other.rows || cols != other.cols){
        cout<<"Can't be copied due to dimensions mismatch!"<<endl;
        return;
    }
    for(int i = 0; i< rows; i++){
        for(int j = 0; j < cols; j++){
            data[i][j] = other.data[i][j];
        }
    }   
}