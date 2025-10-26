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
    }else{
        this->firstName = new char[1];
        this->firstName[0] = '\0';
    }
    if(lastName){
        this->lastName = new char[strLen(lastName) + 1];
            for(int i = 0;lastName[i]!='\0';i++){
            this->lastName[i] = lastName[i];
        }
        this->lastName[strLen(lastName)] = '\0';        
    }else{
        this->lastName = new char[1];
        this->lastName[0] = '\0';
    }
    if(!isValidName()){
        if(this->firstName)   delete[] this->firstName;
        if(this->lastName)   delete[] this->lastName;
        cout<<"Invalid Name Entered! "<<endl;
        this->lastName = new char[1];
        this->lastName[0] = '\0';
        this->firstName = new char[1];
        this->firstName[0] = '\0';

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
    if(firstName)   delete[] firstName;
    if(lastName)    delete[] lastName;
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
void Name::toLower(){
    if(!isValidName())   return;
    for(int i = 0; firstName[i] != '\0'; i++){
        if(firstName[i] != ' ' && !(firstName[i] >= 97 && firstName[i] <= 122)){
        firstName[i] += 32;
        }
    }
    for(int i = 0; lastName[i] != '\0'; i++){
        if(lastName[i] != ' ' && !(lastName[i] >= 97 && lastName[i] <= 122)){
        lastName[i] += 32;
        }
    }
}
void Name::toUpper(){
    if(!isValidName())   return;
    for(int i = 0; firstName[i] != '\0'; i++){
        if(firstName[i] != ' ' && !(firstName[i] >= 65 && firstName[i] <= 90)){
        firstName[i] -= 32;
        }
    }
    for(int i = 0; lastName[i] != '\0'; i++){
        if(lastName[i] != ' ' && !(lastName[i] >= 65 && lastName[i] <= 90)){
        lastName[i] -= 32;
        }
    }
}
void Name::camelCase(){
    if(!isValidName())     return;
    if((firstName[0] >= 'a' && firstName[0] <= 'z')){
    firstName[0] -= 32;
    }
    for(int i = 0; firstName[i] != '\0'; i++){
        if(firstName[i] == ' ' && (firstName[i + 1] != '\0' && (firstName[i + 1] >= 'a' && firstName[i + 1] <= 'z' ))){
            firstName[i+1] -= 32;
        }
    }
    if(lastName[0] >= 'a' && lastName[0] <= 'z'){
    lastName[0] -= 32;
    }
    
    for(int i = 0; lastName[i] != '\0'; i++){
        if(lastName[i] == ' ' && (lastName[i + 1] != '\0' && (lastName[i + 1] >= 'a' && lastName[i + 1] <= 'z'))){
            lastName[i+1] -= 32;
        }
    }
}
bool Name::isValidName(){
    if(firstName[0] == ' ' || firstName[strLen(firstName) - 1] == ' ')    return false;

    if(lastName[0] == ' ' || lastName[strLen(lastName) - 1] == ' ')    return false;
    
    for(int i = 0; firstName[i] != '\0'; i++){
        if (firstName[i] == ' ') {
    if (firstName[i+1] == '\0' || !((firstName[i+1] >= 'A' && firstName[i+1] <= 'Z') || (firstName[i+1] >= 'a' && firstName[i+1] <= 'z'))) {
        return false;
    }
} 
else if (!((firstName[i] >= 'A' && firstName[i] <= 'Z') || (firstName[i] >= 'a' && firstName[i] <= 'z'))) {
    return false;
}

    }
    for(int i = 0; lastName[i] != '\0'; i++){
             if (lastName[i] == ' ') {
    if (lastName[i+1] == '\0' || !((lastName[i+1] >= 'A' && lastName[i+1] <= 'Z') || (lastName[i+1] >= 'a' && lastName[i+1] <= 'z'))) {
        return false;
    }
} 
else if (!((lastName[i] >= 'A' && lastName[i] <= 'Z') || (lastName[i] >= 'a' && lastName[i] <= 'z'))) {
    return false;
}
}
    return true;

}
int Name::nameLength(){
    int len = 0;
    for(int i = 0; firstName[i] != '\0'; i++){
        if(firstName[i] != ' '){
            len++;
        }
    }
    for(int i = 0; lastName[i] != '\0'; i++){
        if(lastName[i] != ' '){
            len++;
        }
    }
    return len;
    
}
void Name::swapNames(){
    char* temp = firstName;
    firstName = lastName;
    lastName = temp;
    temp = nullptr;
}
char* Name::fullName(){
    char* name = new char[strLen(firstName) + strLen(lastName) + 2];
    int j = 0;
    for(int i = 0; firstName[i] != '\0'; i++){
        name[j++] = firstName[i];
    }
    name[j] = ' ';
    j++;
    for(int i = 0; lastName[i] != '\0'; i++){
        name[j++] = lastName[i];
    }
    name[j] = '\0';
    return name;
}


void Name::display(){
    char* name = fullName();
    cout<<"Full Name: "<<name<<endl;
    delete[] name;
}
void Name::setFirstName(const char* fname){
   if(firstName){
    delete[] firstName;
   }
   int len = strLen((char*)fname);
   firstName = new char[len + 1];
    for(int i = 0; i < len; i++){
        firstName[i] = fname[i];
    }
    firstName[len] = '\0';
}
void Name::setLastName(const char* lname){
    if(lastName){
        delete[] lastName;
    }
    int len = strLen((char*)lname);
    lastName = new char[len + 1];
    for(int i = 0; i < len; i++){
        lastName[i] = lname[i];
    }
    lastName[len] = '\0';
}
const char* Name::getFirstName(){
    return firstName;
} 
const char* Name::getLastName(){
    return lastName;
}
Name::~Name(){
    delete[] firstName;
    delete[] lastName;
}
int Name::strLen(char* arr){
    int len =0;
    for(int i = 0; arr[i] != '\0'; i++){
        len++;
    }
    return len;
}