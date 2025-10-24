#include<iostream>
using namespace std;
class Bank{
private:
string password;
int age;
public:
void setPassword(string password){
    this->password = password;
}
void setAge(int age){
this->age = age;
}
friend void printInfo(Bank b);
//we can also make more friend functions
};
void printInfo(Bank b){
cout<<"Age: "<<b.age<<endl;
cout<<"Password: "<<b.password<<endl;
}

int main(){
    Bank b1;
    b1.setPassword("Imran@123");
    b1.setAge(19);
    printInfo(b1);

    return 0;
}