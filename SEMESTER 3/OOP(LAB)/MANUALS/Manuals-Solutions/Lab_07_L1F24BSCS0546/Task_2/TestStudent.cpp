#include <iostream>
#include "Student.h"
using namespace std;

int main() {
    cout<<"Creating default obj s1....\n\n";
    Student s1;
    cout<<"Defualt obje...\n\n";
    s1.dispaly();
    cout<<"Total Students: "<<Student::studentCount<<endl;
    cout<<"Current Average: "<<Student::averageGrade<<endl;
    cout<<"Creating another obj s2....\n\n";
    Student s2(5546,78);
    cout<<"s2.....\n\n";
    s2.dispaly();
    cout<<"Current Average: "<<Student::averageGrade<<endl;
    cout<<"Creating another objs s3,s4,s5..........\n\n";
    Student s3(5555,80);
    cout<<"Current Average After s3: "<<Student::averageGrade<<endl;
    Student s4(5556,90);
    cout<<"Current Average After s4: "<<Student::averageGrade<<endl;
    Student s5(5557,67);
    cout<<"Current Average After s5: "<<Student::averageGrade<<endl;
    cout<<"Total Students: "<<Student::studentCount<<endl;
    cout<<"s3,s4,s5.....\n\n";
    s3.dispaly();
    cout<<endl;
    s4.dispaly();
    cout<<endl;
    s4.dispaly();
    cout<<endl;
    if(true){
        cout<<"Creating another obje in a block.......\n\n";
        Student temp(6767,98);
        cout<<"OBJ TEMP: \n\n";
        temp.dispaly();
        cout<<"Current Average: "<<Student::averageGrade<<endl;
    }
    cout<<"Current Average: "<<Student::averageGrade<<endl;
    cout<<"Total Students: "<<Student::studentCount<<endl;

    return 0;
}