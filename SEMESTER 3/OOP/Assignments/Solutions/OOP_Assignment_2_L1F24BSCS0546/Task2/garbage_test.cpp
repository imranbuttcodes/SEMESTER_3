#include <iostream>
using namespace std;

int get2_2_determinant(int arr[2][2]){
    return (arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0]);
}

 int getSign(int row,int col){
    if((row + col) % 2 == 0)
        return 1;
    return -1;
}

void getMinor(int arr[][3],int temp[][2],int row_to_skip,int col_to_skip,int n){
    int temp_row  = 0;
    int temp_col  = 0;
    for(int i = 0; i < n; i++){
        if(i == row_to_skip)    continue;
        temp_col = 0;
        for(int j = 0; j < n; j++){
            if(j == col_to_skip)     continue;
            temp[temp_row][temp_col] = arr[i][j];
            temp_col++;
        }
        temp_row++;
    }
}

int main() {
    int arr[3][3] = {{1,-2,3},{2,0,3},{1,5,4}};
    int n = 3;
    int temp[2][2];
    int deter = 0;
    for(int i = 0; i < n; i++){
        getMinor(arr,temp,0,i,n);
        int sign = getSign(1,i+1);
        int co = arr[0][i];
            deter+= (sign*(co * get2_2_determinant(temp)));
    }
    cout<<"Determinant: "<<deter<<endl;
    
    return 0;
}