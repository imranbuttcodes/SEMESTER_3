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
	cout << "Input " << rows * cols << " Elements: ";
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
void Matrix::displayMatrix()const {
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
int Matrix::getRows() const{
    return rows;
}
int Matrix::getCols() const{
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

 Matrix Matrix::operator+(const Matrix& right){
    Matrix addition(rows,cols);
    if (!(right.rows == rows && right.cols == cols)) {
		cout << "Can't add the matrix due to mismatch size\n";
        cout << "Skipping incompatible matrix during addition.\n\n";
		return *this;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			addition.data[i][j] = data[i][j] + right.data[i][j];

		}
	}
	return addition;
 }
Matrix Matrix::operator-(const Matrix& right){
    Matrix subtraction(rows,cols);
    if (!(right.rows == rows && right.cols == cols)) {
		cout << "Can't subtract the matrix due to mismatch size\n";
        cout << "Skipping incompatible matrix during subtraction.\n\n";
		return *this;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			subtraction.data[i][j] = data[i][j] - right.data[i][j];

		}
	}
    return subtraction;
}
 Matrix Matrix::operator*(const Matrix& right){
    if(cols != right.rows){
        cout<<"Invlaid dimension can't be multiplied!"<<endl;
        cout << "Skipping incompatible matrix during multiplication.\n\n";
        return *this;
    }
    
    Matrix temp_obj(rows,right.cols);

    for(int i = 0;i < rows; i++){
        for(int j = 0; j < right.cols; j++){
            int sum = 0;
            for(int k = 0; k < cols; k++){
                sum += data[i][k]*right.data[k][j]; 
            }
            temp_obj.data[i][j] = sum;
        }
    }
    
    return temp_obj;
 }
 double** Matrix::operator/(const Matrix& right){
    if(right.rows !=  right.cols){
        cout<<"Can't divide this matrix as the right matrix is not a square\n\n";
        return nullptr;
    }
    double** inverse_of_right = getInverse(right.data,right.rows);
    if(!inverse_of_right){
        cout<<"Division failed as right matrix is singular\n\n";
        return nullptr;
    }
    if(cols != right.rows){
        cout<<"Invlaid dimension can't be left's no. of cols must equal to right operand's no. of rows!"<<endl;
        return nullptr;
    }
    double** resultantDivision = new double*[rows];
    for(int i = 0; i < rows; i++){
        resultantDivision[i] = new double[right.cols];
    }
    for(int i = 0;i < rows; i++){
        for(int j = 0; j < right.cols; j++){
            double sum = 0;
            for(int k = 0; k < cols; k++){
                sum += data[i][k]*inverse_of_right[k][j]; 
            }
            resultantDivision[i][j] = sum;
        }
    }
    for(int i = 0; i< right.rows; i++){
        delete[] inverse_of_right[i];
    }
    delete[] inverse_of_right;
    return resultantDivision;

 }
int getSign(int rows,int cols){
    return ((rows + cols) %2 == 0)?1:-1; 
 }
int** createMatrix(int n){
    int** temp = new int*[n];
    for(int i = 0; i< n; i++){
        temp[i] = new int[n];
    }
    return temp;
}
 void getMinor(int** arr,int** temp,int row_to_skip,int col_to_skip,int n){
    int temp_rows = 0,temp_cols = 0;
    for(int i = 0; i < n; i++){
        if(i == row_to_skip){
            continue;
        }
        temp_cols = 0;
        for(int j = 0; j < n; j++){
            if(j == col_to_skip){
                continue;
            }
            temp[temp_rows][temp_cols] = arr[i][j];
            temp_cols++; 
        }
        temp_rows++;
    }

 }




 int get_determinant(int** arr,int n){
    if(n == 1){
        return arr[0][0];
    }
 if(n == 2){
    return (arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1]);
 }
 int det = 0;
 for(int i = 0; i < n; i++){
     int** temp = createMatrix(n - 1);
    getMinor(arr,temp,0,i,n);
    det +=  getSign(0,i) * (arr[0][i]*get_determinant(temp,n - 1));
    
    for(int j = 0; j < n - 1; j++){
        delete[] temp[j];
    }
    delete[] temp;

 }
 return det;
 
 }

 int** getAdjacent(int** matrix,int n){
    int** adjacent_matrix = createMatrix(n);
    
    int** temp = createMatrix(n-1); 
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            getMinor(matrix,temp,i,j,n);
            //doing [j][i] adjacent_matrix[j][i] instead of [i][j] for 
            //transpose 
            adjacent_matrix[j][i] = getSign(i,j) * get_determinant(temp,n-1);
        }
    }
    for(int i = 0; i < n - 1; i++){
        delete[] temp[i];
    }
    delete[] temp;
    return adjacent_matrix;
 }
 double** getInverse(int** arr,int n){
    double determinant = get_determinant(arr,n);
    if(determinant == 0){
        cout<<"Can't find inverse as determinant is 0\n\n";
        return nullptr;
    }
    int** adjacent = getAdjacent(arr,n);
    double** inverse = new double*[n];
    for(int i = 0; i < n; i++){
        inverse[i] = new double[n];
    }  
    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            inverse[i][j] = adjacent[i][j]/determinant;
        }
    }
    for(int i = 0; i< n; i++){
        delete[] adjacent[i];
    }
    delete[] adjacent;
    return inverse;
 }
ostream& operator<<(ostream& out,const Matrix& right){
    right.displayMatrix();
    return out;
}
 Matrix Matrix::operator=(const Matrix& right){
    if(rows != right.rows || cols != right.cols){
        cout<<"Can't assign due incompatible dimension.\n";
        cout<<"Skipping that matrix to assign.....\n\n";
        return *this;
    }
    for(int i = 0; i < right.rows; i++){
        for(int j = 0;j < right.cols; j++){
            data[i][j] = right.data[i][j];
        }
    }
    return *this;
 }
 bool Matrix::operator==(const Matrix& right) const{
    if(rows != right.rows || cols != right.cols)    return false;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(data[i][j] != right.data[i][j])      return false;
        }
    }
    return true;
 }

  bool Matrix::operator!=(const Matrix& right) const{
    return !(*this == right);
  }

  bool Matrix::operator<(const Matrix& right) const{
    if( rows != right.rows || cols != right.cols){
        cout<<"Matrix dimensions aren't matching!"<<endl;
        return false;
    }    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(data[i][j] >= right.data[i][j]){
                return false;
            }
        }
    }
    return true;
  }

   bool Matrix::operator>(const Matrix& right) const{
    return right < *this;
   }
  
bool Matrix::operator<=(const Matrix& right)const{
    return (*this < right) || (*this == right);

}

bool Matrix::operator>=(const Matrix& right)const{
return ((*this > right) || (*this == right));
}
 Matrix& Matrix::operator++()//pre-increament
 {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            ++data[i][j];
        }
    }
    return *this;
 }
 Matrix Matrix::operator++(int)//post-increament
 {
    Matrix temp = *this;
    ++(*this);
    return temp;
 }

 
 Matrix& Matrix::operator--()//pre-decreament
 {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            --data[i][j];
        }
    }
    return *this;
 }
 Matrix Matrix::operator--(int)//post-decreament
 {
    Matrix temp = *this;
    --(*this);
    return temp;
 }

 istream& operator>>(istream& in, Matrix& right){
 right.inputMatrix();
 return in;
 }
