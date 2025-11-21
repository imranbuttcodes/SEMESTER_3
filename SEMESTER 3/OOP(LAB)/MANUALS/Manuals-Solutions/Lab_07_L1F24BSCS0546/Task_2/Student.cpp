#include<iostream>
#include "Student.h"
using namespace std;

Student::Student():studentID(1234),grade(0){
    totalGrade += grade;
    ++studentCount;
    calculateAverageGrade();
}

double Student::averageGrade = 0;

int Student::totalGrade = 0;

int Student::studentCount = 0;
Student::Student(const int& studentID,const int& grade):studentID(studentID),grade(grade){
    ++studentCount;
    totalGrade += grade;
    calculateAverageGrade();
}

void Student::calculateAverageGrade(){
    averageGrade = totalGrade / studentCount;
}

void Student::dispaly() const{
    cout<<"Student ID: "<<studentID<<endl;
    cout<<"Grade: "<<grade<<endl;

}


void Student::set_grade(int grade){
    this->grade = grade;
}

int Student::get_grade() const {
    return grade;
}

int Student::get_studentID() const{
    return studentID;
    
}



Student::~Student(){
    cout<<"Destroying student id....\n\n"<<studentID<<endl;
    --studentCount;
    totalGrade -= grade;
    if(studentCount != 0)
        calculateAverageGrade();
}




