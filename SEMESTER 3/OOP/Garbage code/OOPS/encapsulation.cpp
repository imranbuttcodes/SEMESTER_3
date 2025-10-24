#include<iostream>
#include<string>
using namespace std;
//encapsulation is wrapping up of data & member funcitons in a single unit called class
//the concept of encapsulation help us in hiding data(means to private member varialbes/ data that are sensitive)
//Note: The previous code start 2 was an example of encapsulation
//let's say
class Accounts{
private:
string password;

public:
string username;
string accountId;
double balance;
void displayInfo(){
    cout<<"User Name: "<<username<<endl;
    cout<<"AccountId: "<<accountId<<endl;
    cout<<"Balance: "<<balance;
}
bool enterPass(string pass){
    password = pass;
    if(password == "Password@123"){
              return true;
    }else{
        return false;
    }
}
};
// now it is wrapping up data and member funciton as well as hiding sensitive info so in a class so it is encapsulation
int main(){
    Accounts a1;
    a1.username = "imranbutt";
    a1.balance  = 25000;
    string pass;
    cout<<"Enter password to see info: ";
    getline(cin,pass);
    if(a1.enterPass(pass)){
        cout<<"Welcome here's your info\n";
        a1.displayInfo();
    }else{
        cout<<"Incorrect Password";
    }
}