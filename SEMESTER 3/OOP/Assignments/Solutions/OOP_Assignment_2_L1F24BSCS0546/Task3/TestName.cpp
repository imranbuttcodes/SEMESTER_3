#include "Name.h"
#include<iostream>
using namespace std;
int main() {
    cout<<"Testing operator overloading for Class \"Name\"....\n\n";
    cout<<"Creating an object n1.....\n\n";
   Name n1((char*)"Muhammad", (char*)"Imran");
   cout<<"Testing stream insertion operator (<<).....\n\n";
   cout<<n1<<endl;
   cout<<"Creating another object to perform (+) object.......\n\n";
   Name n0((char*)"Butt",(char*)"Imran");
   cout<<"Object n0....\n\n";
   cout<<n0<<endl;
   cout<<"Adding n1 and n0 (n1 + n0).......\n\n";
   Name addition_result = n1 + n0;
   cout<<"resultant added obj....\n\n";
   cout<<addition_result<<endl;
   cout<<"Testing stream extraction operator (>>)........\n\n";
   cin>>n1;
   cout<<"n1 object after accepting user's input.........\n\n";
   cout<<n1<<endl;
   cout<<"Creating another object named n2......\n\n";
   Name n2((char*)"Usman",(char*)"Younus");
   cout<<"object n2......\n\n";
   cout<<n2<<endl;
   cout<<"Testing assignment operator (=) (n1 = n2)........\n\n";
   n1 = n2;
   cout<<"After assignment....\n\n";
   cout<<"n1.....\n\n";
   cout<<n1<<endl;
   cout<<"n2.....\n\n";
   cout<<n2<<endl;
   cout<<"Testing (==) operator (n1 == n2)......\n\n";
   if(n1 == n2){
    cout<<"Both objects are equal!\n\n";
   } else{
    cout<<"Objects n1 and n2 aresn't equal!\n\n";
   }

   cout<<"Testing (!=) operator (n1 != n0)......\n\n";
   if(n1 != n0){
    cout<<"Objects n1 and n0 aresn't equal!\n\n";
   } else{
    cout<<"Both objects are equal!\n\n";
   }
   cout<<"------------ The End ------------\n\n";
   return 0;
}