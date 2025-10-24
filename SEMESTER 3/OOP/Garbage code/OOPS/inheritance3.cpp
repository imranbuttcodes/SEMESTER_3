//in this code we will discuss multiple inheritance,hierarchial inheritance
#include<iostream>
#include<string>
using namespace std;
//This is an example of multiple inheritance
//parent1
class Student{
public: 
string name;
int rollno;
};
//parent 2
class Teacher{
public:
string subject;
double salary;
};
//child
class TA: public Student,public Teacher{
public:
    void getInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Subject: "<<subject<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"Roll Number: "<<rollno<<endl;
    }
};
//this is an example of hierarchial inheritance
class Person{
public:
string name;
int age;
};
class Student1: public Person{
public:
string rollno;
void getInfo(){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Roll Number: "<<rollno<<endl;
}
};
class Teacher1: public Person{
public:
string department,subject;

void getInfo(){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Department: "<<department<<endl;
    cout<<"Subject: "<<subject<<endl;
}};
int main(){
    cout<<"This is an example of multiple inheritance...\n";
    TA t1;
    t1.name = "Imran";
    t1.rollno = 546;
    t1.subject = "C++";
    t1.salary = 25000;
    t1.getInfo();
    Student1 s1;
    cout<<"This is an example of heirarchial inheritance...\n";
    s1.name = "Heirarchial";
    s1.age = 23;
    s1.rollno = 54;
    Teacher1 t;
    t.name = "Hello World";
    t.age = 24;
    t.department = "Hello!";
    t.subject = "HEllo bro";
    cout<<"Student1 info...\n";
    s1.getInfo();
    cout<<"Teacher1 info...\n";
    t.getInfo();
    //there are also other types of inheritance in C++
    //like hybride inheritance
    //it means a combination of two or more types of inheritance
    //you can say it is a mix of multiple inheritance and hierarchical inheritance
    return 0;
}