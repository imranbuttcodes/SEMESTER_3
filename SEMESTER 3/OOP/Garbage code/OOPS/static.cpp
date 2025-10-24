//what the hell is static keyword and how it can help in oop?
//In functions: variables declared as static in a function are created and initialisesdonce for the lifetime of the program
//In classes: static variables in classes are created and initialised once. THey are shared by all objects of the class.
//example
#include<iostream>
using namespace std;
//in funciton
void fun(){
    static int x =0;//now it initialised only once it doesn't care how many times you call the funciton it won't reset the value to 0
    cout<<"x: "<<x<<endl;
    x++;
}
//In classe
class A{
public:
static int x;
void incX(){
    x = x + 1;
}
};
int A::x = 0;// now see below
//defines and initializes the static variable x for class A.

//static int x; inside the class only declares the variable.
//int A::x = 0; outside the class allocates memory and sets its initial value to 0.
//All objects of class A share this single variable x.
//Without this line, you will get a linker error because the static variable is declared but not defined.
class ABC{
public:
ABC(){
    cout<<"Constructor called...\n";
}
~ABC(){
    cout<<"Destructor called...\n";
}

};
int main(){
    cout<<"--- In Function ----\n";
    fun(),fun(),fun();
    cout<<"--- In Class ----\n";
    A obj;
    obj.x = 0;
    cout<<obj.x<<endl;
    obj.incX();
    A obj1;
    cout<<obj1.x<<endl;
    obj1.incX();
    A obj2;
    cout<<obj.x<<endl;
    obj.incX();
    A obj3;
    cout<<obj3.x<<endl;
    if(true){
      static ABC obj;   // The static keyword ensures that this object is created only once,
    // even if the if-block is executed multiple times.
    // Its constructor is called the first time the block is entered,
    // and its destructor is called automatically when main() ends.
    }
    cout<<"end of main fun()...\n";
    return 0;
}