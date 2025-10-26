#pragma once
class Date {
public:
 Date(); // Default constructor: initialize attributes with default values
 Date(int d, int m, int y); // Parameterized constructor: if invalid, set to default or system date
 Date(const Date& other); // Copy constructor
 bool inputDate(); // Input date from user; return true if valid, false otherwise
 bool inputCompleteDate(int d, int m, int y); // Assign and validate date directly
 bool copyDate(const Date& other); // Copy date from another Date object
 void retrieveDate(int& d, int& m, int& y); // Retrieve current date values via references
 void showDate(); // Display date in a readable format (e.g., DD/MM/YYYY)
 bool isEqual(const Date& other);// Compare two dates for equality
 bool isLeapYear(); // Return true if year is leap year
 // Additional Functions
 void setDay(int d); // Setter for day with validation
 void setMonth(int m); // Setter for month with validation
 void setYear(int y); // Setter for year with validation
 int getDay(); // Getter for day
 int getMonth(); // Getter for month
 int getYear(); // Getter for year
 void incrementDay(); // Add one day to the date
 void decrementDay(); // Subtract one day from the date
 private:
 bool validateDate(); // Validate current date values
 int day;
 int month;
 int year;
};