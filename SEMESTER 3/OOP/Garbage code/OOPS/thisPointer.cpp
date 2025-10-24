#include<iostream>
#include<string>
using namespace std;
//what the hell is this->poointer and why it is required?
/*
this is a keyword in C++ that refers to the current object (the one calling the method).

Think of it like this:

Every object has its own copy of data. When a member function runs, this points to that specific object.

Where is this used?
When parameter names are same as member variables

To return the current object

To pass the current object to another function

With pointers to objects
*/
class Teacher{
public:
//parameterized-constructor
Teacher(string name,string dep, string subject, double salary){
    cout<<"Bro, I'm parameterized constructor...\n";
    this->name = name;// now 'this->name' refers to the member variable
    this->dep = dep;
    this->subject = subject;
    this->salary = salary;
}
    //copy constructor
      Teacher(Teacher &oriObj){// we are passing Teacher type of object by referenace
      cout<<"Bro, I'm your custom copy constructor...\n";
        this->name = oriObj.name;
      this->dep = oriObj.dep;
      this->subject = oriObj.subject;
      this->salary = oriObj.salary;
      }
string name;
string dep;
string subject;
double salary;
void show(){
    cout<<"Name: "<<name<<endl;
    cout<<"Department: "<<dep<<endl;
    cout<<"Subject: "<<subject<<endl;
    cout<<"Salary: "<<salary<<endl;
}

};
class Student{
public:
string name,dep,sub;
int rollNumber;
//parameterized-constructor
Student(string name,string dep, string sub, int rollNumber){
    cout<<"Now bro, we are in parameteriezed constructor of Student Class...\n";
    this->name = name;
    this->dep = dep;
    this->sub = sub;
    this->rollNumber = rollNumber;
}
//copy constructor
// Student(Student &oriObj){
//     cout<<"Now bro, we are in copy constructor of Student Class...\n";
//     this->name = oriObj.name;
//     this->dep = oriObj.dep;
//     this->sub = oriObj.sub;
//     this->rollNumber = oriObj.rollNumber;
// }
void show(){
    cout<<"RollNumber: "<<rollNumber<<endl;
    cout<<"Student Name: "<<name<<endl;
    cout<<"Department: "<<dep<<endl;
    cout<<"Subject: "<<sub<<endl;
}
};
int main(){
    Teacher t1("Imran","CS","C++",25000);//constructor call and initializing
    cout<<"Here's the properties of object 1...\n";
    t1.show();//output data
    //now let's create a copy constructor that used to copy properties of one object into another
    Teacher t2(t1);
    cout<<"Here's the properties of the object 2 copied from the object1 using a custom copy construtor...\n";
    t2.show();
    Student s1("Imran","CS","C++",546);
    cout<<"Here's the properties of the student object 1...\n";
    s1.show();
    Student s2(s1);//copy s1
    cout<<"Here's the properties of the Student object 2 copied from the object1 using a custom copy construtor...\n";
    s2.show();
    return 0;
}