#include <iostream>
using namespace std;
class Superint{
public:
int x = 12;
int y = 20;
    Superint(){
    cout<<(this)<<endl;
}
};
int main() {
    Superint s1;
    cout<<&s1<<endl;
    cout<<&(s1.x)<<endl;
    cout<<&(s1.y)<<endl;
    Superint s2;
    cout<<&s2<<endl;
    cout << "Hello World!" << std::endl;
    return 0;
}