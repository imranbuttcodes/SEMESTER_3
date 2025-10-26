#include "Name.h"
#include<iostream>
using namespace std;
 int main(){
    Name n1;
    cout<<"Test1. Default Ctor"<<endl;
    n1.display();
    cout<<"Length: "<<n1.nameLength()<<endl;

    Name n2((char*)"muhammad imran",(char*)"Butt");
    cout<<"Test2. Parameterized Ctor"<<endl;
    cout<<"First Name: "<<n2.getFirstName()<<endl;
    cout<<"Last Name: "<<n2.getLastName()<<endl;
    
    n2.display();

    cout<<"Length: "<<n2.nameLength()<<endl;
    cout<<"Applying camel casing... "<<endl;
    n2.camelCase();
    cout<<"After applying camel case\n";
    n2.display();
    cout<<"Applying upper case...."<<endl;
    n2.toUpper();
    cout<<"After Upper Case\n";
    n2.display();
    cout<<"Applying lower case...."<<endl;
    n2.toLower();
    cout<<"After lower Case\n";
    n2.display();
    Name n3(n2);
    cout<<"New object Created with copy ctor\n";
    n3.display();

    Name n4;
    cout<<"New Object Created using CopyName() Method\n";
    n4.copyName(n3);
    n4.display();
    n4.setFirstName("Rizwan");
    cout<<"First Name Updated using setter\n";
    n4.display();
    n4.setLastName("Jutt");
    cout<<"Last Name updated using setter\n";
    n4.display();
    cout<<"Swapping first and last name: "<<endl;
    n4.swapNames();
    cout<<"First Name: "<<n4.getFirstName()<<endl;
    cout<<"Last Name: "<<n4.getLastName()<<endl;
    n4.display();
    Name n5((char*)"  ", (char*)"123");
    cout << "Is n5(object's name) valid? "<< endl;
    if(n5.isValidName()){
        cout<<"Invalid Name!"<<endl;
    }else{
        cout<<"Valid name"<<endl;
    }

    return 0;
 }