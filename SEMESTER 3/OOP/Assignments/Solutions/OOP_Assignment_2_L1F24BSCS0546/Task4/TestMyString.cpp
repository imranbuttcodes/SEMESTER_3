#include <iostream>
#include "MyString.h"
using namespace std;

int main() {
    cout<<"Testing operator overloading for Class \"MyString\"....\n\n";
    cout<<"Creating an obj s1......\n\n";
    MyString s1;
    cout<<"Getting input in s1 using stream extration operato (>>)......\n\n";
    cin>>s1;
    cout<<"Printing obj using stream insertion operator (<<).....\n\n";
    cout<<s1;
    cout<<"Creating another object s2...........\n\n";
    MyString s2 = "Imran Butt";
    cout<<"s2.....\n\n";
    cout<<s2<<endl;
    cout<<"Testing (+) operator (s1 + s2)...........\n\n";
    MyString resultant_addition = s1 + s2;
    cout<<"Resultant object after adding s1 and s2.....\n\n";
    cout<<resultant_addition<<endl;
    cout<<"Testing (==) operator (s1 == n2)......\n\n";
    if(s1 == s2){
        cout<<"s1 and s2 are equal!\n\n";
    }else{
        cout<<"s1 and s2 aren't equal!\n\n";
    }
    cout<<"Testing (!=) operator (s1 != s2).....\n\n";
       if(s1 != s2){
        cout<<"s1 and s2 aren't equal!\n\n";
    }else{
        cout<<"s1 and s2 are equal!\n\n";
    }
    cout<<"Testing (<) operator s1 < s2......\n\n";
    if(s1 < s2){
        cout<<"s1 is less than s2\n\n";
    }else{
        cout<<"s1 is greater than or equal to s2\n\n";
    }

    cout<<"Testing (>) operator s1 > s2......\n\n";
    if(s1 > s2){
        cout<<"s1 is greater than s2\n\n";
    }else{
        cout<<"s1 is less than or equal to s2\n\n";
    }

    cout<<"Testing (<=) operator s1 <= s2......\n\n";
    if(s1 <= s2){
        cout<<"s1 is less than or equal to s2\n\n";
    }else{
        cout<<"s1 is greater than s2\n\n";
    }
     
    cout<<"Testing (>=) operator s1 >= s2......\n\n";
    if(s1 >= s2){
        cout<<"s1 is greater than or equal to s2\n\n";
    }else{
        cout<<"s1 is less than s2\n\n";
    }

    cout<<"Testing assignment operator (=) (s1 = s2).........\n\n";
    s1 = s2;
    cout<<"Objects after assignment...........\n\n";
    cout<<"s1........\n\n";
    cout<<s1<<endl;
    cout<<"s2........\n\n";
    cout<<s2<<endl;
    cout<<"Testing (++) pre-increament operator for s1";
    ++s1;
    cout<<"s1 after pre-increament.....\n\n";
    cout<<s1<<endl;

    cout<<"Testing (++) post-increament operator for s1\n\n";
    MyString temp = s1++;
    cout<<"Returned s1 after post-increament.....\n\n";
    cout<<temp<<endl;
    cout<<"s1 after post-increament......\n\n";
    cout<<s1<<endl;

    cout<<"-------------- The End --------------\n\n";

    
}