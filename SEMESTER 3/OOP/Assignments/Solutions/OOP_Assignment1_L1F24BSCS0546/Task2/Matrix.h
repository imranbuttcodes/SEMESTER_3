#pragma once
class Matrix {
public:
 Matrix(); // Default constructor: initialize an empty (0x0) matrix
 Matrix(int rows, int cols); // Parameterized constructor: dynamically allocate memory
 Matrix(const Matrix& other); // Copy constructor: deep copy of matrix
 bool inputMatrix(); // Input all matrix elements from user (cin)
 void setElement(int r, int c, int value);// Set value at specific row and column (with bounds check)
 int getElement(int r, int c); // Return value at specific row and column
 void displayMatrix(); // Display all elements in matrix form
 // ----- Matrix Operations -----
 bool addMatrix(const Matrix& other); // Add another matrix (same size), store result in current 

 bool subtractMatrix(const Matrix& other);// Subtract another matrix (same size)
 Matrix multiplyMatrix(const Matrix& other);// Multiply with another matrix (matrix multiplication 

 Matrix transpose(); // Transpose current matrix
 bool isEqual(const Matrix& other); // Compare if two matrices are identical
 // ----- Utility and Accessors -----
 int getRows(); // Return total number of rows
 int getCols(); // Return total number of columns
 void fillRandom(); // Fill matrix with random integer values (e.g., 1–9)
 void clear(); // Release memory and reset to empty matrix
private:
 const int rows; // Number of rows
 const int cols; // Number of columns
 int** data; // Pointer to a dynamically allocated 2D array
 bool isValidIndex(int r, int c); // Helper to check valid row/column index
 void allocateMatrix(); // Allocate memory dynamically for given rows and cols
 void copyFrom(const Matrix& other); // Copy data from another matrix
};