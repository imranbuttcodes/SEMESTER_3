
#include <iostream>
using namespace std;

class Ram{
public:
    Ram(){
        cout<<"I'm ram"<<endl;
    }
};
class Hard{
public:
    Hard(){
        cout<<"I'm Hard!"<<endl;
    }
};
class MotherBord{
public:
    
    MotherBord(){
        cout<<"I'm mother baord"<<endl;
    }
    Ram ram;
    Hard hard;
};

int main() {
   MotherBord motherboard;
    return 0;
}

