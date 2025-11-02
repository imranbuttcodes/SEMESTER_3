#include <iostream>
#include "Vehicle.h"
using namespace std;

int main() {
    cout<<"Creating Vehicle Objects........\n";


    Vehicle v1("Civic", (char*)"Honda", 35000);
    Vehicle v2("Corolla", (char*)"Toyota", 32000);
    Vehicle v3("Swift", (char*)"Suzuki", 28000);
    Vehicle v4("City", (char*)"Honda", 30000);

    Vehicle arr[] = { v1, v2, v3, v4 };


    cout << "Before Sorting...\n";
    for (int i = 0; i < 4; i++) {
        cout << "\nVehicle #" << i + 1 << ":\n";
        arr[i].display();
    }
    cout<<endl;
    arr[0].sortVehicles(arr, 4);

    cout << "After Sorting by Price (Ascending).......\n";
    cout<<endl;
    for (int i = 0; i < 4; i++) {
        cout << "Vehicle #" << i + 1 << ":\n";
        arr[i].display();
    }

    return 0;
}
