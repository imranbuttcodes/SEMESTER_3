#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() : day(29), month(10), year(2025) {};

bool Date::isLeapYear()
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    return false;
}
bool Date::validateDate()
{
    int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (!(this->month >= 1 && this->month <= 12))
        return false;
    if (isLeapYear())
    {
        daysInMonths[2] = 29;
    }
    if (this->day < 1 || this->day > daysInMonths[this->month])
        return false;
    if(this->year < 1900 || this->year > 2025)  return false;
    return true;
}
Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{
    if (!validateDate())
    {
        this->day = 29;
        this->month = 10;
        this->year = 2025;
    }
}
Date::Date(const Date &other)
{
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}
bool Date::inputDate()
{
    cout << "Enter day: ";
    cin >> this->day;
    cout << "Enter month: ";
    cin >> this->month;
    cout << "Enter year: ";
    cin >> this->year;
    return validateDate();
}
bool Date::inputCompleteDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
    return validateDate();
}
void Date::setDay(int day)
{
    this->day = day;
}
void Date::setMonth(int month)
{
    this->month = month;
}
void Date::setYear(int year)
{
    this->year = year;
}
int Date::getDay () const
{
    return day;
}
int Date::getMonth () const
{
    return month;
}
int Date::getYear() const
{
    return year;
}
bool Date::copyDate(const Date &other)
{
    day = other.day;
    month = other.month;
    year = other.year;
    return validateDate();
}

void Date::retrieveDate(int &day, int &month, int &year)
{
    day = this->day;
    month = this->month;
    year = this->year;
}

void Date::showDate()
{
    cout << "Date: ";
    if (day < 10)
    {
        cout << "0" << day << "/";
    }
    else
    {
        cout << day << "/";
    }
    if (month < 10)
    {
        cout << "0" << month << "/";
    }
    else
    {
        cout << month << "/";
    }
    cout << year << endl;
}

bool Date::isEqual(const Date &other)
{
    return (day == other.day && month == other.month && year == other.year);
}
void Date::incrementDay()
{
    int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear())
    {
        daysInMonths[2] = 29;
    }
    day++;
    if (day > daysInMonths[month])
    {
        month++;
        day = 1;
        if (month > 12)
        {
            year++;
            month = 1;
        }
    }
}
void Date::decrementDay(){
    int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    day--;
    if(day<1){
        month--;
        if(month < 1){
            year--;
            month = 12;
        }
        if(month == 2 && isLeapYear()){
            day = 29;
        }else{
            day = daysInMonths[month];
        }
    }
}

Date Date::operator +(const Date& right) const {
    Date addition;
    addition.day = day + right.day;
    addition.month = month + right.month;
    //addition.year =  year + (((year - right.year) < 0)?(year - right.year)*-1:(year - right.year))  + (year % 1000);
    addition.year = (year + right.year);
    int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((addition.year % 4 == 0 && addition.year % 100 != 0) || (addition.year % 400 == 0))
    {
     daysInMonths[2] = 29;   
    }
    addition.year += (addition.month - 1)/12;
    addition.month = (addition.month-1) % 12 + 1;
    while (addition.day > daysInMonths[addition.month]){ 
        if ((addition.year % 4 == 0 && addition.year % 100 != 0) || (addition.year % 400 == 0)) {
                daysInMonths[2] = 29;   
            }else{
                daysInMonths[2] = 28;
            }       
        addition.day = addition.day - daysInMonths[addition.month];
        addition.month++;
        if(addition.month > 12){
            addition.month = 1;
            addition.year++;
        }
    }
    return addition;
}

Date Date::operator -(const Date& right) const{
    int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Date subtraction;
    subtraction.day = day - right.day;
    subtraction.month = month - right.month;
    if(!(right.year>year)){
        subtraction.year = year - right.year;
    }else{
        subtraction.year = right.year - year;
    }
    if(subtraction.day <= 0){
        subtraction.month--;
        if(subtraction.month <= 0) {
            subtraction.year--;
            subtraction.month += 12;
        }
            if ((subtraction.year % 4 == 0 && subtraction.year % 100 != 0) || (subtraction.year % 400 == 0)) {
                daysInMonths[2] = 29;   
            }else{
                daysInMonths[2] = 28;
            }
        
    
       subtraction.day +=  daysInMonths[subtraction.month] ;
    }

    return subtraction;
}

Date& Date::operator =(const Date& right) {
   if(this != &right){
    day = right.day;
    month = right.month;
    year = right.year;
   } 
   return *this;
 }
 bool Date::operator ==(const Date& right) const{
    return (day == right.day && month == right.month && year == right.year);
 }
 bool Date::operator!=(const Date& right) const{
    if(day != right.day || month != right.month || year != right.year)
        return true;
    return false;
 }

 bool Date::operator<(const Date& right) const{
    if (year != right.year){
        return year < right.year;
    }
    if(month != right.month){
        return month < right.month;
    }
    return day < right.day;
 }
 
 bool Date::operator >(const Date& right) const{
    if (year != right.year){
        return year > right.year;
    }
    if(month != right.month){
        return month > right.month;
    }
    return day > right.day;
 }

 bool Date::operator >= (const Date& right) const{
    if (year != right.year){
        return year >= right.year;
    }
    if(month != right.month){
        return month >= right.month;
    }
    return day >= right.day;
 }


 bool Date::operator <= (const Date& right) const{
    if (year != right.year){
        return year <= right.year;
    }
    if(month != right.month){
        return month <= right.month;
    }
    return day <= right.day;
 }

 ostream& operator <<(ostream& out,const Date& other){
    out << "Date: ";
    if (other.getDay() < 10)
    {
        out << "0" << other.getDay() << "/";
    }
    else
    {
        out << other.getDay() << "/";
    }
    if (other.getMonth() < 10)
    {
        out << "0" << other.getMonth() << "/";
    }
    else
    {
        out << other.getMonth() << "/";
    }
    out << other.getYear() << endl;
    return out;
 }
 istream& operator >>(istream& in,Date& other){
    int day,month,year;
    in >> day>>month>>year;
    other.setDay(day);
    other.setMonth(month);
    other.setYear(year);
    return in;
 }
Date& Date::operator++()//pre increament
{
    incrementDay();
    return *this;
}
Date Date::operator++(int)//post increament
{
    Date temp = *this;
    ++(*this);
    return temp;
}

Date& Date::operator--()//pre decreament
{
    decrementDay();
   return *this;
}
Date Date::operator--(int)//post decreament
{
    Date temp = *this;
    --(*this);
    return temp;
    
}
