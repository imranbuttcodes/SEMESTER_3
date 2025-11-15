#pragma once
#include<iostream>
using namespace std;
class MyString {
private:
	const size_t MAX_LEN; // Maximum length size 
	char* const data; // Dynamically allocated character array
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
	int find_substr( MyString& substr); // 7. Find substring (like strstr)
	void print() const; // Display string contents
	MyString operator+(const MyString& right);
	MyString operator=(const MyString& right);
	bool operator==(const MyString& right);
	bool operator!=(const MyString& right);
	bool operator<(const MyString& right);
	bool operator>(const MyString& right);
	bool operator<=(const MyString& right);
	bool operator>=(const MyString& right);
	MyString& operator++();
	MyString operator++(int);
	friend ostream& operator<<(ostream& out, const MyString& right);
	friend istream& operator>>(istream& in, MyString& right);

};

char* regrow(char* arr, int& size,char input);