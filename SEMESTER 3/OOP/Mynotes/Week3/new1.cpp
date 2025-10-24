#include<iostream>
using namespace std;
int main(){
    const int age  = 18;
    const int* ptr = &age;
    int* new_ptr = const_cast<int*>(ptr);
    *new_ptr = 20;
    cout<<age<<endl;
    return 0;
}