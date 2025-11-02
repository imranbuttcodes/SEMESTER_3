#include <iostream>
#include "Person.h"
using namespace std;

int main() {
    
    cout << "Testing Default Constructor...." << endl;
    Person p1;
    p1.setName((char*)"Imran");
    p1.setAge(25);
    p1.setCountry((char*)"Pakistan");
    p1.display();

    cout << endl;

    cout << "Testing Parameterized Constructor....." << endl;
    Person p2((char*)"Salman", 30, (char*)"Pakistan");
    p2.display();

    cout << endl;

    cout << "Testing Copy Constructor......" << endl;
    Person p3 = p2; 
    p3.display();

    cout << endl;

    cout << "Testing Deep Copy..." << endl;
    p3.setName((char*)"Rizwan");
    p3.setCountry((char*)"India");
    cout << "Modified Copy (p3):" << endl;
    p3.display();
    cout << "Original (p2) remains unchanged:" << endl;
    p2.display();

    cout << endl;

    // Test compareAge()
    cout << "Testing compareAge()....." << endl;
    cout << "Comparing Imran (25) and Salman (30):" << endl;
    p1.compareAge(p2);

    cout << endl;

  
    p1.setAge(35);
    cout << "Comparing Imran (35) and Salman (30):" << endl;
    p1.compareAge(p2);

    cout << endl;

    return 0;
}
