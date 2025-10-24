#include <iostream>
using namespace std;

class ComplexNumber {
private:
	double realPart;
	double imaginaryPart;
public:
	void setValue(double realPart, double imaginaryPart) {
		this->realPart = realPart;
		this->imaginaryPart = imaginaryPart;
	}
	double getRealValue() {
		return realPart;
	}
	double getImaginaryPart() {
		return imaginaryPart;
	}
	void display() {

		cout << "Complex Number: " << realPart << " + " << imaginaryPart << "i" << endl;

	}
		
	
};
void sum(ComplexNumber& obj1, ComplexNumber& obj2) {
	cout << "Sum of ( " << obj1.getRealValue() << " + " << obj1.getImaginaryPart()<<"i" << " ) + ( " << obj2.getRealValue() << " + " << obj2.getImaginaryPart() << "i" << ")  = " << obj1.getRealValue() + obj2.getRealValue() << " + " << obj1.getImaginaryPart() + obj2.getImaginaryPart() << "i" << endl;

}
void difference(ComplexNumber& obj1, ComplexNumber& obj2) {
	cout << "Difference  of ( " << obj1.getRealValue() << " + " << obj1.getImaginaryPart()<<"i" << " ) - ( " << obj2.getRealValue() << " + " << obj2.getImaginaryPart()<<"i" << ") = " << obj1.getRealValue() - obj2.getRealValue() << " + " << (obj1.getImaginaryPart()) -  (obj2.getImaginaryPart()) << "i" << endl;

}
void getInputs(double& real, double& imag) {
	cout << "Enter Real part of Complex Number:  ";
	cin >> real;
	cout << "Enter Imaginary part of Complex Number: ";
	cin >> imag;
}


class Time{
private:
    int hour,minute,seconds;
public:
void setHour(const int& hour){
    this->hour = hour;
}
void setMinute(const int& minute){
    this->minute = minute;
}
void setSeconds(const int& seconds){
    this->seconds = seconds;
}

int getHour() {
    return hour;
}
int getMinute() {
    return minute;
}
int getSeconds() {
    return seconds;
}
void display(){
    cout<<hour<<":"<<minute<<":"<<seconds<<endl;
}
void addTime(Time& t){
    int h,m,s;
    h = this->hour + t.hour;
    m = this->minute + t.minute;
    s = this->seconds + t.seconds;
     if(s>=60){
        s -= 60;
        m++;
    }
    if(m>=60){
        m -= 60;
        h++;
    }
    if(h>=24){
        h -= 24;
    }
     
  
    cout<<h<<":"<<m<<":"<<s<<endl;
}
};

class Circle{
private:
    double radius;
    double pi = 3.14159;
public:
    Circle(){
        radius = 0.0;
    }    
    Circle(const double& radius){
        this->radius = radius;
    }
    void setRadius(const double& radius){
        this->radius = radius;
    }
    double getRadius(){
        return radius;
    }
    double Area(){
        return pi*(radius*radius);
    }
    double getDiameter(){
        return (radius + radius);
    }
    double getCircumference(){
        return (2*pi*radius);
    }
    void display(){
        cout<<"Radius: "<<radius<<endl;
        cout<<"Area: "<<Area()<<endl;
        cout<<"Diameter: "<<getDiameter()<<endl;
        cout<<"Circumference: "<<getCircumference()<<endl;
    }
};

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
void Task1(){
    ComplexNumber c1,c2;
	double real, imagin;
	cout << "1st Complex Number :\n";
	getInputs(real, imagin);
	c1.setValue(real, imagin);
	cout << "2nd Complex Number:\n";
	getInputs(real, imagin);
	c2.setValue(real,imagin);
	cout << "1st ";
	c1.display();
	cout << "2st ";
	c2.display();
	sum(c1, c2);
	difference(c1, c2);
}

void Task2(){
    Time t1,t2;
    t1.setHour(12);
    t1.setMinute(45);
    t1.setSeconds(30);
    t2.setHour(2);
    t2.setMinute(30);
    t2.setSeconds(45);
    cout<<"Time1: ";
    t1.display();
    cout<<"Time2: ";
    t2.display();
    cout<<"Total Time: ";
    t1.addTime(t2);
}
void Task3(){
     Circle c1(3.34);
    c1.display();
    Circle c2;
    c2.display();
}
void Task4(){
      Employee E1;
    E1.setName((char*)"Imran Butt");
    E1.setEmployeeID(546);
    E1.setSalary(50000);
    E1.display();
}
void menu(){
    int choice;        
    while(1){
        cout<<"--------- Welcome to tester ---------\n";
        cout<<"Press 1 for Testing \"ComplexNumber class\" "<<endl;
        cout<<"Press 2 for Testing \"Time class\" "<<endl;
        cout<<"Press 3 for Testing \"Circle class\" "<<endl;
        cout<<"Press 4 for Testing \"Employee class\" "<<endl;
        cout<<"Press 0 for exit "<<endl;
        cout<<"\nEnter your Chocice: ";
        cin>>choice;
        if(choice == 1){
            Task1();
        }else if(choice == 2){
            Task2();
        }else if(choice == 3){
            Task3();
        }else if(choice == 4){
            Task4();
        }else if(choice == 0){
            cout<<"Exiting......"<<endl;
            break;
        }else{
            cout<<"OOps :( Invalid input entered try again ;)"<<endl;
        }
        

    }
}
int main() {
    menu();
    return 0;
}