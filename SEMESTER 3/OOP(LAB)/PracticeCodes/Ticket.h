#pragma once
class Ticket{
private:
    int ticketID;
    double basePrice;
    char* category;
public:
    Ticket();
    Ticket(int id,const char* category,double price = 10);
    double calculateFinalPrice(double tax = 5.0);
    double getPrice()const;
    Ticket(const Ticket& other);

    
};
Ticket compareTickets(Ticket t1, Ticket t2);
int strLen(char* arr);