#include<iostream>
using namespace std;
//int this code we will see what the hell is abstraction
//abstraction is one of the four fundamental pillars OOP concepts
//abstraction is the concept of hiding the complex implementation details and showing only the essential features of the object
//one of the simplest way of abstraciton is through using access specifiers like private, public and protected
//another way of abstraction is through abstract classes and interfaces
//but what the hell is abstract class?
//hmm.. let's grab a cup of coffee and see it
//an abstract class is a class that cannot be instantiated and is meant to be inherited by other classes
//it can have pure virtual functions, which are functions that have no implementation in the base class and must be implemented in the derived class
//abstract classes can't create objects, but they can have constructors and destructors
//properties of abstract class:
//1. It can have data members and member functions
//2. It can have pure virtual functions
//3. It can have constructors and destructors
//4. It cannot be instantiated
//5. It can be inherited by other classes
//6. It can have both pure virtual and non-pure virtual functions
//7. It can have static members
//8. It is defined using the keyword 'abstract' or by declaring at least one pure virtual function
//let's see an example of abstraction in C++
//we will create an abstract class called Shape with a pure virtual function called draw
//then we will create two derived classes called Circle and Square that implement the draw function
class Shape{//now this is automatically an abstract class because it has a pure virtual function
    public:
virtual void draw() = 0; // pure virtual function
};
class Circle: public Shape{
    public:
    void draw(){
        cout << "Drawing Circle" << endl;
    }
};
class Square: public Shape{
    public:
    void draw(){
        cout << "Drawing Square" << endl;
    }
};
int main(){
    //now we cannot create an object of Shape class because it is an abstract class
     //Shape s; //this will give an error
    cout << "Creating Circle and Square objects..." << endl;
    Circle c;
    Square s;
    c.draw();
    s.draw();
    return 0;
}