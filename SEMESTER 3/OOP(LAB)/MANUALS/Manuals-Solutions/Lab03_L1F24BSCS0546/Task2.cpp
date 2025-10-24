#include <iostream>
using namespace std;
class Time{
private:
    int hour,minute,seconds;
public:
void setHour(const int& hour){
    this->hour = hour;
}
void setMinute(const int& minute){
    this->minute = minute;
}
void setSeconds(const int& seconds){
    this->seconds = seconds;
}

int getHour() {
    return hour;
}
int getMinute() {
    return minute;
}
int getSeconds() {
    return seconds;
}
void display(){
    cout<<hour<<":"<<minute<<":"<<seconds<<endl;
}
void addTime(Time& t){
    int h,m,s;
    h = this->hour + t.hour;
    m = this->minute + t.minute;
    s = this->seconds + t.seconds;
     if(s>=60){
        s -= 60;
        m++;
    }
    if(m>=60){
        m -= 60;
        h++;
    }
    if(h>=24){
        h -= 24;
    }
     
  
    cout<<h<<":"<<m<<":"<<s<<endl;
}
};
int main() {
    Time t1,t2;
    t1.setHour(12);
    t1.setMinute(45);
    t1.setSeconds(30);
    t2.setHour(2);
    t2.setMinute(30);
    t2.setSeconds(45);
    cout<<"Time1: ";
    t1.display();
    cout<<"Time2: ";
    t2.display();
    cout<<"Total Time: ";
    t1.addTime(t2);
    return 0;
}