#include <iostream>
using namespace std;


class Employee{
private:
    char* name;
    int employeeId;
    double salary;
public:
    Employee(){
        name = nullptr;
        employeeId = 0;
        salary = 0.0;
    }
    Employee(int employeeID){
        this->employeeId = employeeID;
    }
    void setName(char* name){
        this->name = name;
    }
    void setEmployeeID(int id){
        this->employeeId = id;
    }
    void setSalary(double salary){
        this->salary = salary;
    }
    char* getName(){
        return name;
    }
    int getID(){
        return employeeId;
    }
    int getSalary(){
        return salary;
    }

    double giveRaise(double percentage){
        salary = salary + (salary*percentage)/100;
        return percentage;
    }
    void display(){
        cout<<"Name: "<<getName()<<endl;
        cout<<"Employee ID: "<<getID()<<endl;
        cout<<"Salary: "<<getSalary()<<endl;
        cout<<"Giving a raise: "<<giveRaise(10.0)<<"%"<<endl;
        cout<<"New Salary: "<<getSalary()<<endl;
    }
};
int main() {
    Employee E1;
    E1.setName((char*)"Imran Butt");
    E1.setEmployeeID(546);
    E1.setSalary(50000);
    E1.display();
    return 0;
}
