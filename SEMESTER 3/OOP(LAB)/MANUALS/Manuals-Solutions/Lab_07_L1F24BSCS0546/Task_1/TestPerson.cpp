#include <iostream>
#include "Person.h"
using namespace std;

int main() {
    cout<<"Creating object p1...\n\n";
    Person p1("Imran Butt",19);
    cout<<"Creating another object p2....\n\n";
    Person p2("ALi",20);
    cout<<"Creating third object p3.......\n\n";
    Person p3("Muhammad Hassan",23);
    cout<<"P1 info.....\n\n";
    p1.dispaly();
    cout<<"\nP2 info.....\n\n";
    p2.dispaly();
    cout<<"\nP3 info.....\n\n";
    p3.dispaly();
    cout<<endl;
    cout<<"Total objects created (priting using static counter)......\n";
    cout<<"Objects Created: "<<Person::persontCount<<endl;
    cout<<"persontCount value using p1.....\n";
    cout<<"Count: "<<p1.persontCount<<endl;

    cout<<"persontCount value using p2.....\n";
    cout<<"Count: "<<p2.persontCount<<endl;
    
    cout<<"persontCount value using p3.....\n";
    cout<<"Count: "<<p3.persontCount<<endl;
    
    if(true){
        cout<<"Creating object in a block to check if the static member persontCount tied to the object's lifetime?....\n\n";
        Person temp("Temp",12);
        cout<<"Object...\n\n";
        cout<<"personentCount: "<<Person::persontCount<<endl;
    }
    cout<<"PersonentCount After destruction of fourth element....\n";
    cout<<"personentCount: "<<Person::persontCount<<endl;
    return 0;
}