#include "Date.h"
#include<iostream>
using namespace std;
int main(){
    cout<<"Testing Date Class Operator Overloading ......\n\n";
    cout<<"Creating obj using  Default Ctor ......\n\n";
    Date d1;
    cout<<"Getting date using stream extraction overloding (>>)....\n\n";
    cout<<"Enter Date in dd mm yyyy: ";
    cin>>d1;
    cout<<"Printing date using stream insertion operator overloadin......\n\n";
    cout<<d1;
    cout<<"\n\nCreating another object using default date to test other operator overlaodings....\n\n";
    Date d2;
    cout<<"Defaut date\n\n";
    cout<<d2<<endl;
    cout<<"Testing relational operators overlaoding....\n\n ";
    cout<<"Testing \"==\"....\n\n";
    if(d1 == d2){
        cout<<"Dates are equal.\n\n";
    }else{
        cout<<"Dates aren't equal!\n\n";
    }
    cout<<"Testing \"<\"....\n\n";
    if(d1 < d2){
        cout<<"First object d1 is less then the defualt date's object d2\n\n";
    }else{
        cout<<"First object d1 is greater then the defualt date's object d2\n\n";
    }
    cout<<"Testing \"<=\"....\n\n";
    if(d1 <= d2){
        cout<<"First object d1 is less then or equal to the defualt date's object d2\n\n";
    }else{
        cout<<"First object d1 is greater then the defualt date's object d2\n\n";
    }
    cout<<"Testing \">\"....\n\n";
    if(d1 > d2){
        cout<<"First object d1 is greater then the defualt date's object d2\n\n";
    }else{
        cout<<"First object d1 is less then the defualt date's object d2\n\n";
    }
    cout<<"Testing \">=\"....\n\n";
    if(d1 >= d2){
        cout<<"First object d1 is greater then or equal to the defualt date's object d2\n\n";
    }else{
        cout<<"First object d1 is less then the defualt date's object d2\n\n";
    }
    cout<<"Testing \"!=\"....\n\n";
    if(d1 != d2){
        cout<<"d1 is not equal to d2\n\n";
    }else{
        cout<<"d1 is equal to d2\n\n";
    }
    cout<<"Testing \"+\" (d1 + d2) \n\n";
    Date addition_result = d1 + d2;
    cout<<"Added Date after using + "<<endl;
    cout<<addition_result;
    cout<<"Creating another obj by setting a random date to check chaining...\n\n";
    Date d3(23,5,2006);
    cout<<"New object's date\n\n";
    cout<<d3<<endl;
    cout<<"Adding again using + (d1 + d2 + d3)\n\n";
    addition_result = d1 + d2 + d3;
    cout<<"Addition Result\n\n";
    cout<<addition_result<<endl;
    cout<<"Testing \"-\" (d1 - d2 - d3)"<<endl;
    Date subtraction_result = d1 - d2 - d3;
    cout<<"Resultant subtraction Date...\n\n";
    cout<<subtraction_result<<endl;
    cout<<"Testing \"=\" (d1 = d2 = d3)"<<endl;
    d1 = d2 = d3;
    cout<<"d1...\n";
    cout<<d1<<endl;
    cout<<"d2....\n";
    cout<<d2<<endl;
    cout<<"d3...\n";
    cout<<d3<<endl;
    cout<<"Chnging d3 date using setters for further operation.....\n";
    d3.setDay(31);
    d3.setMonth(12);
    d3.setYear(2024);
    cout<<"Changed Date...\n";
    cout<<d3<<endl;
    cout<<"Testing pre-increament...\n\n";
    ++d3;
    cout<<"After pre increament...\n\n";
    cout<<d3<<endl;
    cout<<"Testing post-increament...\n\n";
    Date temp1 = d3++;
    cout << "After post-increment (d3++) returned: " << temp1 << endl;
    cout << "Date after post-increment: " << d3 << endl;

    cout<<"Testing pre-deccreament...\n\n";
    --d3;
    cout<<"After pre decreament...\n\n";
    cout<<d3<<endl;
    cout<<"Testing post-decreament...\n\n";
    Date temp2 = d3--;
    cout << "After post-decrement (d3--) returned: " << temp2 << endl;
    cout << "Date after post-decrement: " << d3 << endl;
    

    return 0;
}