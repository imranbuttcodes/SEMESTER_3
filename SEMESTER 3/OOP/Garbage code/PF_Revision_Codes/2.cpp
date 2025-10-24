// #include <iostream>
// using namespace std;

// int main() {
//     int arr[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };

//     int (*p)[4] = arr;       // pointer to row of 4 ints
//     int* q = &arr[0][0];     // pointer to first int

//     cout << "p points to row: " << p << endl;
//     cout << "p+1 jumps 16 bytes to next row: " << p+1 << endl;

//     cout << "q points to int: " << q << endl;
//     cout << "q+1 jumps 4 bytes to next int: " << q+1 << endl;
//     return 0;
// }
#include <iostream>
using namespace std;

int main() {
//     int rows = 3, cols = 4;
// int** dynArr = new int*[rows];  // array of int*
// for(int i=0; i<rows; i++){
//     dynArr[i] = new int[cols];  // each row is array of int
// }

// // Assigning values
// for (int i = 0; i < rows; i++) {
//     for (int j = 0; j < cols; j++) {
//         // Example assignment: (row * 10) + col
//         dynArr[i][j] = (i * cols) + j;
//     }
// }
// for (int i =0; i < rows; i++){
//     for(int j = 0;j < cols; j++){
//         cout<<dynArr[i][j]<<" ";
//     }
//     cout<<endl;
// }
// for (int i = 0;i < rows; i++){
//     for(int j = 0;j < cols; j++){
//         cout<<*(*(dynArr+i)+j)<<" ";
//     }cout<<endl;
// }
int* p = new int;
*p = 42;
cout<<p<<endl;
cout<<*p;
    return 0;
}
