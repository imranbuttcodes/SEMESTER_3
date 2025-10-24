#include <iostream>
using namespace std;
class Thing{
public:
    int x = 0;
    Thing(int x): x(x){
        cout<<"para\n";
    };
    Thing(Thing& obj){
        cout<<"Copy\n";
        this->x = obj.x;
    }
    Thing& operator +(const Thing& obj){//here if won't do Thing& in the return type then it would call copy constructor 
        this->x += obj.x;
       // cout<<this<<endl;
       cout<<"Hello after one copy"<<endl;
        return *this;
    }
};
int main() {
    Thing one = 1;
    Thing two = 2;
    cout<<"Now\n";
    cout<<&one<<endl;
    Thing three = one + 10;
    cout<<"One: "<<one.x<<endl;
    cout<<"Three: "<<three.x<<endl;
    int a= 9;
    int b = a + 10;
    return 0;
}