#include<iostream>
using namespace std;
int calculate(int a, int b){
    return a + b;
}
double calculate(double a, double b){
    return a * b;
}
int calculate(int a){
    int fact = 1;
    for(int i = 1; i <= a;i++){
        fact *= i;
    }
    return fact;
}
string calculate(string str, int n){
    string result = "";
    for(int i = 0;i < n; i++){
        result += str;
    }
    return result;
}
int main(){
    cout<<"Concetination"<<calculate("Hello",3)<<endl;
    cout<<"Factorial: "<<calculate(5)<<endl;
    cout<<"Sum: "<<calculate(5,3)<<endl;
    cout<<"Double multiplication: "<<calculate(5.0,3.0)<<endl;
}