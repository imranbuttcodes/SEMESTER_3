#include <iostream>
#include "Ticket.h"
using namespace std;

Ticket::Ticket():ticketID(1234),basePrice(10){
category = new char[strLen((char*)"Standard") + 1];
const char* temp = "Standard";
for(int i = 0; temp[i] != '\0'; i++){
    category[i] = temp[i];
}
category[strLen((char*)"Standard")] = '\0';

}
Ticket::Ticket(int id, const char* category, double price){
    ticketID = id;
    this->category = new char[strLen((char*)category) + 1];
    for(int i = 0; category[i] != '\0'; i++){
        this->category[i] = category[i];
    }
    this->category[strLen((char*)category)] = '\0';
}
Ticket::Ticket(const Ticket& other){
    int len = strLen(other.category);
    category = new char[len + 1];
    for(int i = 0; other.category[i] != '\0'; i++){
        category[i] = other.category[i];
    }
    category[len] = '\0';
    basePrice = other.basePrice;
    ticketID = other.ticketID;
}
double Ticket::calculateFinalPrice(double tax ){
    double finalPrice = 0;
    if(category[0] == 'P'){
        finalPrice = basePrice + basePrice*(30.0/100.0);
        finalPrice += finalPrice*(tax/100.0);
    }else if(category[0] == 'S'){
        finalPrice += finalPrice*(tax/100.0);    
    }else{
        finalPrice = basePrice + basePrice*(50.0/100.0);
        finalPrice += finalPrice*(tax/100.0);
    }
    return finalPrice;
}
double Ticket::getPrice()const {
    return basePrice;
}
int strLen(char* arr){
    int len = 0;
    for(int i = 0;arr[i] != '\0'; i++){
        len++;
    }
    return len;
}

Ticket compareTickets(Ticket t1, Ticket t2){
    if(t1.calculateFinalPrice() > t2.calculateFinalPrice()){
        Ticket temp = t1;
        return temp;
    }
    Ticket temp = t2;
    return temp;
    
}
