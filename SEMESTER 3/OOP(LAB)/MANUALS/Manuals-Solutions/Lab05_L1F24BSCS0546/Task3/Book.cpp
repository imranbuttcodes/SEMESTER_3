#include "Book.h"
#include<iostream>
using namespace std;

 char* Book::copyData(char* arr){
    char* temp_arr = new char[strLen(arr) + 1];
    for(int i = 0; arr[i] != '\0'; i++){
        temp_arr[i] = arr[i];
    }
    temp_arr[strLen(arr)] = '\0';
    return temp_arr;
}

Book::Book():title(nullptr),auther(nullptr),price(0.0){}
Book::Book(const char* title, char* auther, float price){
   this->title = copyData((char*)title);
   this->auther = copyData(auther);
   this->price = price;
}
int Book::strLen(char* arr){
    int len = 0;
    for(int i = 0;arr[i] != '\0'; i++){
        len++;
    }
    return len;
}
Book::Book(Book& other,bool isDeep){
    if(isDeep){
    this->title = copyData((char*)other.title);
    this->auther = copyData((char*)other.auther);
    price = other.price;
    }else{
        this->title = other.title;//shallow
        this->auther = other.auther;//shallow
        this->price = other.price;
    }
}
void Book::setTitle(const char* title){
    if(this->title){
        delete[] this->title;
    }
    this->title = copyData((char*)title);
}
void Book::setAuther(char* auther){
    if(this->auther != nullptr){
        delete[] this->auther;
    }
    this->auther = copyData(auther);   
}
void Book::setPrice(float price){
    this->price = price;
}
const char* Book::getTitle() const{
    return title;
}
char* Book::getAuther() const{
    return auther;
}
float Book::getPrice() const{
    return price;
}
void Book::display() const{
    cout<<"Book Title: "<<title<<endl;
    cout<<"Auther: "<<auther<<endl;
    cout<<"Price: "<<price<<endl;
}
 void Book::applyDiscount(double percentage){
    price -= price*(percentage/100);
 }
 float Book::average(Book *arr,int size){
    int sum = 0;
    for(int i  = 0; i < size; i++){
        sum+= arr[i].price;
    }
    return (sum/size);
 }
 Book::~Book(){
    delete[] title;
    delete[] auther;
 }