#include<iostream>
#include "Person.h"
#include<cstring>

using namespace std;

Person::Person(): age(0),Name(new char[1]){
    Name[0] = '\0';
    ++persontCount;
}

Person::Person(const char* Name,int age){
    this->Name = new char[strlen(Name) + 1];
    for (int i = 0; Name[i] != '\0'; i++)
    {
        this->Name[i] = Name[i];
    }
    this->Name[strlen(Name)] = '\0';
    this->age = age;
    persontCount++;
    
}

void Person::dispaly() const{
    cout<<"Name: "<<Name<<endl;
    cout<<"Age: "<<age<<endl;
}

Person::~Person(){
    cout<<"Destroying "<<Name<<"....."<<endl;
    --persontCount;
}

int Person::persontCount = 0;