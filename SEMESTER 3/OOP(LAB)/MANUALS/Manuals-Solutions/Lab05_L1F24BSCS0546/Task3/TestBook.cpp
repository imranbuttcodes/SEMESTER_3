#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    cout<<"Testing prameterized ctor......\n\n";
    Book b1("C++ Programming", (char*)"Bjarne Stroustrup", 1299.99);
    Book b2("Clean Code", (char*)"Robert C. Martin", 899.50);
    Book b3("The Pragmatic Programmer", (char*)"Andrew Hunt", 1099.75);
    cout << "----- Book Details -----" << endl;
    b1.display();
    cout << endl;
    b2.display();
    cout << endl;
    b3.display();
    cout << endl;

    
    cout << "\nApplying 20% discount on '" << b1.getTitle() << "'...\n";
    b1.applyDiscount(20);
    cout << "After Discount:\n";
    b1.display();

    Book arr[] = { b1, b2, b3 };

    cout << "\nAverage Price of All Books: " << arr[0].average(arr, 3) << endl<<endl;
    cout << "Updating author and price for '" << b2.getTitle() << "'...\n";
    b2.setAuther((char*)"Uncle Bob");
    b2.setPrice(950.0);
    b2.display();

    return 0;
}
