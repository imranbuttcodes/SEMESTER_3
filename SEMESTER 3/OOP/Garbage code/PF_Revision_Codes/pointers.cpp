// Declare an int x = 5; and print its value and address using pointer.
// Create an array and print its elements using only pointers (no arr[i]).
#include<iostream>
using namespace std;
int main(){
    //Task 1:
    int x = 5;
    int *ptr = &x;
    cout<<"Value: "<<*ptr<<endl;//derefrencing
    cout<<"Address: "<<ptr<<endl;
    //Task 2:
    int arr[5] = {1,2,3,4,5};
    for(int i = 0; i < 5; i++){
        cout<<*(arr + i)<<" ";
    }
    return 0;
}