#include <iostream>
#include "MyString.h"
using namespace std;

int main() {
    cout << "Testing MyString Class.....\n\n";
    cout << "Testing default ctor.......\n\n";
    MyString s;
    cout << "Length: " << s.length() << endl;
    cout << endl;
    cout << "Testing Parameterized Ctor......\n";
    MyString s1("HelloWorld");
    cout << "Printing stirng usign .print() method...\n\n";
    cout << "Stirng: ";
    s1.print();
    cout << "Printing it's length using .length() method...\n\n";
    cout << "Length: " << s1.length() << endl;
    cout << "Creating another obj s2 using copy ctor....\n";
    MyString s2(s1);
    cout << "Stirng: ";
    s2.print();
    cout << "Creating another obj s3\n" << endl;
    MyString s3 = { "What's up. Hello World" };
    cout << "using .copy() method to copy s3's string into s2........\n\n";
    s2.copy(s3);
    cout << "s2 After copy from s3: \n";
    s2.print();
    cout << "Testing copy_n......\n\n";
    s2.copy_n(s3, 10);
    cout << "s2 after using copy_n...\n";
    s2.print();
    cout << "s1 before concat" << endl;
    s1.print();
    cout << endl << "Testing .concat() to concate two stings....\n\n";
    s2.concat(s1);
    cout << "s2 after concatinating with s1: ";
    s2.print();
    cout << "Testing .find_char(char ch) on s2 of character H...." << endl;
    cout << "Index where H exists: " << s2.find_char('H') << endl;
    cout << "Testing .find_substr(const MyString& substr) in s2 of s1" << endl;
    cout << "Index: " << s2.find_substr(s1) << endl;
    cout << endl;
    cout << "Testing MyString Complete!\n\n";
    cout << "--------------- The End -------------\n";
}