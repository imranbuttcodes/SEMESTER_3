#include <iostream>
using namespace std;
class Circle{
private:
    double radius;
    double pi = 3.14159;
public:
    Circle(){
        radius = 0.0;
    }    
    Circle(const double& radius){
        this->radius = radius;
    }
    void setRadius(const double& radius){
        this->radius = radius;
    }
    double getRadius(){
        return radius;
    }
    double Area(){
        return pi*(radius*radius);
    }
    double getDiameter(){
        return (radius + radius);
    }
    double getCircumference(){
        return (2*pi*radius);
    }
    void display(){
        cout<<"Radius: "<<radius<<endl;
        cout<<"Area: "<<Area()<<endl;
        cout<<"Diameter: "<<getDiameter()<<endl;
        cout<<"Circumference: "<<getCircumference()<<endl;
    }
};
int main() {
    Circle c1(3.34);
    c1.display();
    Circle c2;
    c2.display();

    return 0;
}