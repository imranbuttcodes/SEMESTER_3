#include<iostream>
using namespace std;
void displayInfo(string name, int age = 18, string city = "Unknown"){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"City: "<<city<<endl;
}
int main(){
    displayInfo("Imran",19,"Lahore");
    displayInfo("Imran",19);
    displayInfo("Imran");
    return 0;
}