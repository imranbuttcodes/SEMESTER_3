#pragma once
class MyString {
private:
 const size_t MAX_LEN; // Maximum length size 
 char*  data; // Dynamically allocated character array
 size_t len; // Length of the string (excluding null terminator)
public:
 // ----- Constructors
 MyString(); // Default constructor
 MyString(const char* str); // Construct from C-string
 MyString(const MyString& other); // Copy constructor (deep copy)
 // ----- Member Functions -----
 int length() const; // 1. Returns length of string (like strlen)
 void copy(const MyString& source); // 2. Copy content (like strcpy)
 void copy_n(const MyString& source, int n); // 3. Copy first n chars (like strncpy)
 void concat(const MyString& other); // 4. Concatenate another string (like strcat)
 int compare(const MyString& other); // 5. Compare two strings (like strcmp)
 int find_char(char ch); // 6. Find first occurrence of char (like strchr)
 int find_substr(const MyString& substr); // 7. Find substring (like strstr)
 void print(); // Display string contents
 
};