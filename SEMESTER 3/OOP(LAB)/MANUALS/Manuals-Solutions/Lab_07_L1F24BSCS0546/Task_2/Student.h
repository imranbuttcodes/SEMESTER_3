#pragma once

class Student{
private:
int studentID;
int grade;
public:
static double averageGrade;
static int studentCount;
static int totalGrade;

Student();
Student(const int& studentID,const int& grade);
void set_grade(int grade);
int get_grade() const ;
int get_studentID() const;
~Student();
void dispaly() const;
void calculateAverageGrade();
};
