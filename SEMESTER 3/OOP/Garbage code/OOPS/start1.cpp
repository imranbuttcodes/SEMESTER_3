#include<iostream>
using namespace std;
// let's create a simple class
/* Syntax:
calss ClassName{
//access specifier(by default its private)
access specifier:
      //writing properties/attributes/member variables
      int attribute1;
      float atttribute2;
      //now writing methods/member functions
      returnType memberFunctionName(parameters){
      //code for the method/function
      cout<<"This is the method"<<endl;
      }
      //you can write any number of methods/memberfuncitons/behaviors
};

*/ 
// now let's create a class of simple teacher to display teachers info and change department
class Teacher{
    //access modifier
    
public:
//properties/attributes
string name;
string department;
string subject;
double salary;
//methods/funcitons
void changeDepartment(string dep){
    department = dep;
}
void displayInfo(){
    cout<<"Name: "<<name<<endl;
    cout<<"Department: "<<department<<endl;
    cout<<"Subject: "<<subject<<endl;
    cout<<"Salary: "<<salary<<endl;
}
};
int main(){
//Creating objects
//Syntax className objectName;
Teacher t1;
//assinging data to assign and acces members of the class we use objecName.memberName 
t1.name = "Imran";
t1.department = "Computer Science";
t1.subject = "C++";
t1.salary = 75000;
//now acces memberFunctions
cout<<"--- Before changing departments ---"<<endl;
t1.displayInfo();
cout<<"--- After changing departments ---"<<endl;
t1.changeDepartment("Software Enginering");
t1.displayInfo();
// Now bro listen if we want to make any member private like salary then we can do
/*
class Teacher{
    //access modifier
    private:
    double salary;
public:
//properties/attributes
string name;
string department;
string subject;

//methods/funcitons
void changeDepartment(string dep){
    department = dep;
}
now salary will be accesible just inside the class   
for code visit start2.cpp  
*/
    return 0;
}