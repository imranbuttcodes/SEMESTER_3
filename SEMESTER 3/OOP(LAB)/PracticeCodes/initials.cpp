#include <iostream>
using namespace std;

//DisplaySum func

class Vector{
private:
    float x,y,z;
public:
    //defualt co-str
    Vector(){
        cout<<"Default Constructor\n";
        x = 0;
        y = 0;
        z = 0;
        cout<<"x y z Value Set to 0"<<endl;
    }
    //pra-co-str
    Vector(float x,float y,float z): x(x),y(y),z(z){
        cout<<"Parameterized Constructor\n";
        cout<<"X set to "<<x<<endl;
        cout<<"Y set to "<<y<<endl;
        cout<<"Z set to "<<z<<endl;
    }
    //copy co-str
    Vector(const Vector& obj){
        cout<<"Copy Constructor\n";
        this->x = obj.x;
        this->y = obj.y;
        this->z = obj.z;
        cout<<"X set to "<<obj.x<<endl;
        cout<<"Y set to "<<obj.y<<endl;
        cout<<"Z set to "<<obj.z<<endl;   
    }
    void xSetter(const float& x){
        this->x = x;
    }
    void ySetter(const float& y){
        this->y = y;
    }
    void zSetter(const float& z){
        this->z = z;
    }
    float xGetter() const{
        return x;
    } 
    float yGetter() const{
        return y;
    } 
    float zGetter() const{
        return z;
    } 
    void Display(){
        cout<<"Displaying Vector\n";
        cout<<"X = "<<x<<endl;
        cout<<"Y = "<<y<<endl;
        cout<<"Z = "<<z<<endl;
    }
};

void DisplaySum(const Vector& var1,const Vector& var2){
    cout<<"Sum of these two Vectors is\n";
    cout<<"X = "<<var1.xGetter() + var2.xGetter()<<endl;
    cout<<"Y = "<<var1.yGetter() + var2.yGetter()<<endl;
    cout<<"Z = "<<var1.zGetter() + var2.zGetter()<<endl;
}
int main() {
    Vector Var1;
    Vector Var2(2,2,2);
    Vector Var3 = Var2;
    DisplaySum(Var2,Var3);
    Var1.xSetter(15.2);
    Var2.zSetter(3.2);
    DisplaySum(Var1,Var2);
    cout<<"Ok Final Displays"<<endl;
    Var1.Display();
    Var2.Display();
    Var3.Display();
    return 0;
}