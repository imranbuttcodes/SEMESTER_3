#include<iostream>
#include<string>
using namespace std;
class Teacher{
    private:
    double salary;
public:
      string name;
      string dep;
      string subject;
      //Parameterized-constructor
      Teacher(string n,string d, string sub, double sal){
        cout<<"Constructor created succesfully! "<<endl;
      name = n;
      dep = d;
      subject = sub;
      salary = sal;
      }
  
      //member function
      void getInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Department; "<<dep<<endl;
        cout<<"Subject: "<<subject<<endl;
      }
};
int main(){
    Teacher t1("Imran","Computer Science","C++",25000);
    t1.getInfo();
    Teacher t2(t1);//default copy constructure
    /*
    As If we didn't define your own copy constructor, 
    the compiler automatically provides a default copy constructor that
    does a shallow copy of all fields (which is fine for basic types like string, double etc.).
    */
    t2.getInfo();
    //we can also create out own copy constructor for this visit thisPointer.cpp

    return 0;
}