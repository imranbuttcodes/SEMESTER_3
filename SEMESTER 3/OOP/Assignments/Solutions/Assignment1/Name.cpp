#include<iostream>
#include "Name.h"
using namespace std;

Name::Name(char* firstName,char* lastName){
    if(firstName){
        this->firstName = new char[Name::strLen(firstName)+1];
        for(int i = 0;firstName[i]!='\0';i++){
            this->firstName[i] = firstName[i];
        }
        this->firstName[strLen(firstName)] = '\0';
    }
    if(lastName){
        this->lastName = new char[strLen(lastName) + 1];
            for(int i = 0;lastName[i]!='\0';i++){
            this->lastName[i] = lastName[i];
        }
        this->lastName[strLen(lastName)] = '\0';        
    }

}
Name::Name(const Name& other){
    if(other.firstName){
    this->firstName = new char[strLen(other.firstName) + 1];
      for(int i = 0;other.firstName[i]!='\0';i++){
            this->firstName[i] = other.firstName[i];
        }
        this->firstName[strLen(other.firstName)] = '\0';        
}else{
    this->firstName = nullptr;
}
if(other.lastName){
    this->lastName = new char[strLen(other.lastName) + 1];
      for(int i = 0;other.lastName[i]!='\0';i++){
            this->lastName[i] = other.lastName[i];
        }
        this->lastName[strLen(other.lastName)] = '\0';
}else{
    this->lastName = nullptr;
}
}
void Name::copyName(const Name& other){
       if(other.firstName){
     this->firstName = new char[strLen(other.firstName) + 1];
      for(int i = 0;other.firstName[i]!='\0';i++){
            this->firstName[i] = other.firstName[i];
        }
        this->firstName[strLen(other.firstName)] = '\0';        
}else{
    this->firstName = nullptr;
}
if(other.lastName){
    this->lastName = new char[strLen(other.lastName) + 1];
      for(int i = 0;other.lastName[i]!='\0';i++){
            this->lastName[i] = other.lastName[i];
        }
        this->lastName[strLen(other.lastName)] = '\0';
}else{
    this->lastName = nullptr;
}
}
void Name::camelCase(){
    firstName[0] -= 32;
}