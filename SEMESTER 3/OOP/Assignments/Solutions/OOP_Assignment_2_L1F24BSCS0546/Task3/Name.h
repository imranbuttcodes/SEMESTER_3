#pragma once
class Name {
private:
 char* firstName; // dynamically allocated C-string for first name
 char* lastName; // dynamically allocated C-string for last name
public:
 // ----- Constructors
 Name(char* = nullptr, char* = nullptr); // Parameterized constructor with default values
 Name(const Name& other); // Copy constructor (must perform deep copy)
 // ----- Custom Copy -----
 void copyName(const Name& other); // Copy content of one Name to another
 // ----- String Manipulation Methods -----
 void camelCase(); // Capitalize first letter of each name
 void toLower(); // Convert both names to lowercase
 void toUpper(); // Convert both names to uppercase
 int nameLength(); // Return total length of first + last names (excluding space)
 void swapNames(); // Swap firstName and lastName values
 char* fullName(); // Return concatenated full name (with space in between)
 // ----- Validation and Display -----
 bool isValidName(); // Return true if both names contain only alphabets
 void display(); // Display full name neatly on console
 // ----- Setters and Getters -----
 void setFirstName(const char* fname); // Assign first name
 void setLastName(const char* lname); // Assign last name
 const char* getFirstName(); // Return pointer to first name
 const char* getLastName(); // Return pointer to last name
int strLen(char* arr);
~Name();
};