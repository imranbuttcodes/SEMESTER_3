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
int Date::getDay()
{
    return day;
}
int Date::getMonth()
{
    return month;
}
int Date::getYear()
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
