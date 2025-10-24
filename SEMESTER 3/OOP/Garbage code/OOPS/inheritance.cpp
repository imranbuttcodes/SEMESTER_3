//this file contains inheritance concepts let's learn about inheritance in C++
//what is inheritance?
/*
inheritance is a way to form new classes using classes that have already been defined.
It is an important part of OOPs concept.
It allows us to create a new class that is based on an existing class, inheriting its properties and behaviors.
The new class is called the derived class, and the existing class is called the base class.
It allows us to reuse code and create a hierarchy of classes.
*/
//Basic syntax of inheritance in C++ is:
/*
class BaseClass{
    //base class members
};
class DerivedClass: public BaseClass{
    //derived class members
};
when we create an object of the derived class, it will have access to the members of the base class and the constructor of the base class will be called first and then the constructor of the derived class will be called.
//Let's see an example of inheritance in C++
*/
#include<iostream>
#include<string>
using namespace std;
class Person{
public:
string name;
string gender;
Person(){
    cout<<"Parent claas constructor called...\n";
}
~Person(){
    cout<<"Parent destructor destroyed everything after child destructor...\n";
}
};
class Student: public Person{
public:
int rollNumber;
void getInfo(){
    cout<<"Name: "<<name<<endl;
    cout<<"Gender: "<<gender<<endl;
    cout<<"roll Number: "<<rollNumber<<endl;
}
~Student(){
    cout<<"Child class destructor destroyed Before parent class destructor...\n";
}
Student(){
    cout<<"Child class constructor called...\n";
}
};
// now let's see for parameterized-constructor
class Person1{
public:
string name,gender;
Person1(string name,string gender){
    this->name = name;
    this->gender = gender;
        cout<<"1.Parent Constructor called...\n";
}
~Person1(){
    cout<<"1.Parent Destructor called...\n";
}
};
class Student1: public Person1{
public:
int rollNumber;
Student1(string name,string gender,int rollNumber) : Person1( name,gender){
    this->rollNumber = rollNumber;
cout<<"1.Child constructor called...\n";
}
~Student1(){
    cout<<"1.Child Destructor called...\n";
}
void getInfo(){
    cout<<"Name: "<<name<<endl;
    cout<<"gender: "<<gender<<endl;
    cout<<"rollnumber: "<<rollNumber<<endl;
}
};
int main(){
    cout<<"...Inheritance for non-parameterized constructors...\n";
    Student s;
    s.name = "Imran";
    s.gender = "Male";
    s.rollNumber = 546;
    s.getInfo();
     cout<<"...Inheritance for parameterized constructors...\n";
    Student1 s1("Noman","Male",456);
    s1.getInfo();
    return 0;
}