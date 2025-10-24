#include<iostream>
using namespace std;

class Student{

};
class Rectangle {
private:
    int m_width;
    string m_height;

public:
    Rectangle(int width,string name){
        this->m_width = width;
        this->m_height = name;
    }
    // Rectangle(int width = 1, string height = "1") : m_width(width), m_height(height) {
    //     cout<<width<<endl;
    //     cout<<height<<endl;
    // }
        Rectangle() : m_width(12), m_height("height") {
    }
        Rectangle(int width) : m_width(width), m_height("height") {
    }
    Rectangle(string name) : m_width(12), m_height(name) {
    }
        
        
};

int main() {
    Rectangle r1(10, "5"); // A 10x5 rectangle
    Rectangle r2(7);
    Rectangle r3("fdsfdsfds");
}