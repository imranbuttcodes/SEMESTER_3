#include<iostream>
#include<string>
using namespace std;
//polymorphsism: the ability of a object to take on different forms depending on the context
//in C++, polymorphism is achieved through function overloading and constructoe overloading or through operator overloading
//there are two types of polymorphism in C++
//1. Compile-time polymorphism (also known as static polymorphism)
//2. Run-time polymorphism (also known as dynamic polymorphism)
//Compile-time polymorphism is achieved through function overloading and operator overloading
//Run-time polymorphism is achieved through virtual functions and inheritance
//this is an example of polymorphism

//through constructor overloading
class Student{
public:
string name;
//non-parameterized constructor
Student(){
    cout<<"This is non-parameterized constructor\n";
}
Student(string name){
    this->name = name;
    cout<<"This is parameterized constructor\n";
}
~Student(){
    cout<<"Destructor called...\n";
}
};
//now let's see an example of polymorphism through funciton overloading
class Print{
    public:
void show(int x){
    cout<<"Int: "<<x<<endl;
}
void show(char ch){
    cout<<"Character: "<<ch<<endl;
}
void show(double d){
    cout<<"Double: "<<d<<endl;
}
};
//Run-time polymorphism
//function overriding
class Parent{
public:
void getInfo(){
    cout<<"This is parent class...\n";
}
};
class child: public Parent{
public:
void getInfo(){
    cout<<"This is child class...\n";
}
};
//virtual function(Run-time polymorphism)
class Parent2{
public:
virtual void hello(){
    cout<<"Hello virtual parent!"<<endl;
}
};
class Child2: public Parent2{
public:
void hello(){
    cout<<"Hello virtual child!"<<endl;
}
};
int main(){
    cout<<".....Compile-Time polymorphism.....\n";
    cout<<"Constructor overloading...\n";
Student s1;
s1.name = "Imran";
cout<<s1.name<<endl;
Student s2("imran");
cout<<s2.name<<endl;
Print p1;
cout<<"Function overloading...\n";
p1.show(4);
p1.show(34.3);
p1.show('c');
cout<<"..... Run-Time polymorphism .....\n";
Parent p;
p.getInfo();
child c1;
c1.getInfo();
Parent2 p2;
p2.hello();
Child2 c2;
c2.hello();
    return 0;
}