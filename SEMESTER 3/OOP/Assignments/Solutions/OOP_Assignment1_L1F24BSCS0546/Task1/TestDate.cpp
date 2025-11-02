#include "Date.h"
#include<iostream>
using namespace std;
int main(){
    cout<<"Testing Date Class ......\n\n";
    cout<<"Testing Default Ctor ......\n\n";
    Date d1;
    cout<<"Default Date set..\n";
    d1.showDate();
    cout<<"Testing parameterized Ctor by using invlaid date....(0/12/20000)\n";
    Date d2(00,12,20000);
    cout<<"Due to invalid date the date set to defualt date.....\n";
    d2.showDate();
    cout<<"Setting date using setters.....\n";
    d2.setDay(29);
    d2.setMonth(11);
    d2.setYear(2005);
    cout<<"Accesing date using getters........\n";
    cout<<"Date: "<<d2.getDay()<<"/"<<d2.getMonth()<<"/"<<d2.getYear()<<endl;
    cout<<endl;
    cout<<"Using Copy cotr"<<endl;
    Date d3(d2);
    cout<<"Created object d3 using copy c-tor"<<endl;
    cout<<"Copied ctor's date\n\n";
    d3.showDate();
    cout<<endl;
    int d,m,y;
    cout<<"Reterieving date using .retrieveDate() mehtod.....\n";
    d3.retrieveDate(d,m,y);
    cout<<"Retrieved Date: "<<d<<"/"<<m<<"/"<<y<<endl;
    cout<<"Using .input Date and validating date using .validateDate() internally"<<endl;
    if(d3.inputDate()){
        cout<<"Valid date enterd!"<<endl;
    }else{
        cout<<"Invlaid date Entered"<<endl;
    }
    d3.showDate();
    cout<<endl;
    cout<<"Setting date(31/12/2005) using .inputCompleteDate()..."<<endl;
    d3.inputCompleteDate(31,12,2005);
    d3.showDate();
    cout<<"Increamenting day....\n";
    d3.incrementDay();
    cout<<"Date after increamenting day"<<endl;
    d3.showDate();
    cout<<endl;
    cout<<"Decreamenting Day....\n";
    d3.decrementDay();
    cout<<"Date after decreamentig day"<<endl;
    d3.showDate();
    cout<<endl;
    cout<<"Uisng .copyDate(other&) to copy date of d2 into d3...."<<endl;
    d3.copyDate(d2);
    cout<<"Date of object d3 After copying from d2"<<endl;
    cout<<"Equal d2 == d3?"<<(d2.isEqual(d3)?" Objects are Equal":"Objects are Not Equal")<<endl<<endl;
    cout<<"Cheking for d3 if the year is leap year using .isLeapYear()......."<<endl<<endl;;
    cout<<(d3.isLeapYear()?"Leap year":"Not a Leap year")<<endl;
    cout<<endl;
    cout<<"------------- Testing for Date Class Completed -------------\n\n";
    cout<<"------------- The End ---------------\n";
    return 0;
}