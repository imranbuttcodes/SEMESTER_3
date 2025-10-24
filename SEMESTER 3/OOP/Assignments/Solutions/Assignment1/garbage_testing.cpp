#include <iostream>
using namespace std;
char to_upper(char a){
    if(a >= 65 && a <= 90)   return a;
    a-= 32;
    return a;
}
char to_lower(char ch){
    if(ch >=97 && ch <= 122)   return ch;
    else if(ch >= 65 && ch <= 90)   return (ch+=32);
    cout<<"Invalid value entered!!!!"<<endl;
    return '\0';
}
class Name{
private:
char* firstname;
char* lastname;
public:
    Name(char* firstname = nullptr, char* lastname = nullptr) // Parameterized constructor with default values
    {
        if(firstname){
        
        this->firstname = new char[strLen(firstname) + 1];
        for(int i = 0;firstname[i]!='\0'; i++){
            this->firstname[i] = firstname[i];
        } 
        
    }
        if(lastname){
        for(int i = 0;lastname[i]!='\0'; i++){
           this->lastname[i] = lastname[i];
        } 
        }
    }
    int strLen(const char* arr){
        int len = 0;
        for(int i = 0;arr[i] != '\0';i++) {
            len++;
        }
        return len;
    }
    char* getFirstName() {
        return firstname;
    }
    char* getLastName() {
        return lastname;
    }
};
//  int strLen(const char* arr){
//         int len = 0;
//         for(int i = 0;arr[i] != '\0';i++) {
//             len++;
//         }
//         return len;
//     }
int main() {
//   const char* name = (const char*)"Imran Butt";
//   if(name){
//     cout<<"True"<<endl;
//   }else{
//     cout<<"False"<<endl;
//   }
    Name name((char*)"Imran",(char*)"Butt");
    cout<<name.getFirstName()<<endl;
    cout<<name.getLastName()<<endl;
    return 0;
}