#include<iostream>
using namespace std;
class Student{
public:
string name;
double* cgpaPtr = new double;
//parameterized constructor
Student(string name, double cgpa){
    cout<<"HI im parameterized constructor...\n";
    this->name = name;
    *cgpaPtr = cgpa;
}
//deep copy-constructor
Student(Student& obj){
    
    cout<<"HI im deep copy constructor...\n";
    this->name = obj.name;
    cgpaPtr = new double;
    *(cgpaPtr) = *(obj.cgpaPtr);
}
//destrucor
~Student(){
    cout<<"Hi, im destructor and i'm deleting everything also i'm deleting dynamically allocated data members\nIf you have any problem then let me know?...\n";
    delete cgpaPtr;
}
void getInfo(){
    cout<<"Name: "<<name<<endl;
    cout<<"CGPA: "<<*cgpaPtr<<endl;
}
};
int main(){
    Student s1("Imran",3.56);
    s1.getInfo();
    Student s2(s1);
    *(s2.cgpaPtr) = 3.36;
    s1.getInfo();
    s2.getInfo();
    return 0;
}