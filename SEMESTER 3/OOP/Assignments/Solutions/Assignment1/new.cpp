#include <iostream>
using namespace std;
int decToBin(int dec){
    int binary = 0;
    int remainder = 0;
    int power = 1;
    while(dec != 0){
        remainder = dec % 2;
        binary = (remainder*power) + binary;
        dec /= 2;
        power *= 10;
    }
    return binary;
}

int main() {
    cout<<"Binary: "<<decToBin(8)<<endl;
    return 0;
}