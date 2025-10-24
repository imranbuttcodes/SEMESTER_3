#include<iostream>
#include<string>
using namespace std;
//in this code we will discuss hierarchical inheritance
//we will create a base class Person and two derived classes Student and GraduateStudent
//the GraduateStudent class will inherit from Student, which in turn inherits from Person
//this will demonstrate multiple levels of inheritance
//basically there are different types of inheritance in C++
//1. Single Inheritance
//2. Multiple Inheritance
//3. Multilevel Inheritance
//4. Hierarchical Inheritance
//5. Hybrid Inheritance
//6. Virtual Inheritance
//In this code we will discuss Multi-level inheritance
//Base class
class Person{
public:
string name,gender;
Person(string name,string gender){
    this->name = name;
    this->gender = gender;
}

};

//derived class
class Student: public Person{
public:
int rollno;
Student(string name,string gender,int rollno): Person(name,gender){
this->rollno = rollno;
}

};
//derived class
//GraduateStudent inherits from Student, which in turn inherits from Person
class GraduateStudent: public Student{
public:
bool status;
GraduateStudent(string name,string gender,int rollno,bool status): Student(name,gender,rollno){
    this->status = status;
}
void getInfo(){
    cout<<"Name: "<<name<<endl;
    cout<<"Gender: "<<gender<<endl;
    cout<<"Roll Number: "<<rollno<<endl;
    cout<<(status? "Pass" : "Fail")<<endl;
}
};
int main(){
GraduateStudent s1("Imran","Male",45,false),s2("Noman","Male",32,true);
s1.getInfo();
s2.getInfo();
    return 0;
}