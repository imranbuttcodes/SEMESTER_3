    #include<iostream>
    using namespace std;
//shallow vs deep copy
//Shallow copy: When a copy constructor copies the values of the member variables from one object
//to another object, and both objects point to the same memory location for dynamic data members.
//Deep copy: When a copy constructor creates a new memory location for the dynamic data members of
//the copied object, ensuring that changes to one object do not affect the other.
//Example: class Student{
//    public:
//    string name;
//    double* cgpaPtr = new double;
//    Student(string name, double cgpa){
    //        this->name = name;
    //        *cgpaPtr = cgpa;
    //    }
//    //copy-constructor
//    Student(Student& obj){
//        this->name = obj.name;
//        this->cgpaPtr = new double; // allocate new memory for cgpaPtr
//        *(this->cgpaPtr) = *(obj.cgpaPtr); // copy the value
//    }
    class Student{
    public:
    string name;
    double* cgpaPtr = new double;
    //parameterized-constructor
    // this constructor initializes the name and cgpaPtr
    // cgpaPtr points to a dynamically allocated memory for storing CGPA
    Student(string name, double cgpa){
        this->name = name;
        *cgpaPtr = cgpa;
    }
    //copy-constructor
    // this constructor creates a deep copy of the original object
    Student(Student& obj){
        this->name = obj.name;
        //this->cgpaPtr = obj.cgpaPtr;// this will cause shallow copy and both objects will point to the same memory location which is not desired as it will change the value of original object as well as the copied object
        cgpaPtr = new double; // allocate new memory for cgpaPtr to avoid shallow copy which may also change the value of original object
        *(cgpaPtr) = *(obj.cgpaPtr);
    }
void getInfo(){
    cout<<"Name: "<<name<<endl;
    cout<<"CGPA: "<<*cgpaPtr<<endl;
}
// ~Student(){
// delete cgpaPtr;
// }
    };

    int main(){
        Student s1("Imran",3.56);
        cout<<"Student 1...\n";
        s1.getInfo();
        Student s2(s1);
        s2.name = "Butt";
        *(s2.cgpaPtr) = 3.36;//it would change also change the value of original object if we didn't use deep copy
        // if we did s2.cgpaPtr = s1.cgpaPtr; then it would cause shallow copy and both objects would point to the same memory location
        // so we used deep copy to avoid this issue
        //we did cgpaPtr = new double; *(cgpaPtr) = *(obj.cgpaPtr); to allocate new memory for cgpaPtr and copy the value from original object
        cout<<"Now bro, we are in copy constructor of Student Class...\n";
        cout<<"After copying...\n";

        cout<<"Student 2...\n";
        s2.getInfo();
        cout<<"Student 1...\n";
        s1.getInfo();
    }