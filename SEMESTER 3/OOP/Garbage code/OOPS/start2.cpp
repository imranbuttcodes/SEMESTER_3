#include<iostream>
using namespace std;
class Teacher{
//Let's just keep private salary as it may a sensitive data member
private:
double salary;
//now public
public:
string name;
string department;
string subject;
/* now as salary is only accessible in inside the class then how can 
we access or set salary from main() for this we'll use the concept of 
seeter,getter where setter funciton are use to set the value of private data and getter funcitons 
are used to get the values of private data
so let's see 
*/ 
//setter
void setSalary(double sal){
    salary = sal;
}
//gettter 
double getSalary(){
    return salary;
}
// now we are indirectly set and get the salary
 
};
int main(){
Teacher t1;
t1.name = "Imran Butt";
t1.department = "CS";
t1.subject = "C++";
//now we are setting slary into a private member variable
t1.setSalary(75000);
//now we are getting the salary into a variable 
double t1Salary = t1.getSalary();
cout<<"Here's the info of teacher 1"<<endl;
cout<<"Name: "<<t1.name<<endl;
cout<<"Department: "<<t1.department<<endl;
cout<<"Subject: "<<t1.subject<<endl;
cout<<"Salary: "<<t1Salary<<endl;
    return 0;
}