#include <iostream>
#include <string>
using namespace std;

// Forward declaration: We need to tell the compiler that a class named "HomeWork" exists
// before we can refer to it in the Bank class.
class HomeWork;

class Bank {
private:
    string password;
    int age;

public:
    void setPassword(string pwd) {
        this->password = pwd;
    }

    void setAge(int a) {
        this->age = a;
    }

    // 1. DECLARE the function here, but do not define it.
    // This works because the compiler doesn't need to know the size of HomeWork, just that it's a type.
    void accessHomeworkInfo(HomeWork h);

    // Bank declares HomeWork as a friend.
    friend class HomeWork;
};

// 2. Now, fully define the HomeWork class.
class HomeWork {
private:
    int hom = 45;

public:
    // This function is fine to define here because the compiler has the full definition of Bank.
    void printInfo(Bank b) {
        cout << "--- Inside HomeWork::printInfo ---" << endl;
        cout << "Bank Age: " << b.age << endl; // Allowed
        cout << "Bank Password: " << b.password << endl; // Allowed
    }

    // HomeWork declares Bank as a friend.
    friend class Bank;
};

// 3. DEFINE the Bank member function here.
// At this point, the compiler has seen the full definitions for BOTH Bank and HomeWork.
void Bank::accessHomeworkInfo(HomeWork h) {
    cout << "\n--- Inside Bank::accessHomeworkInfo ---" << endl;
    // This is now allowed because HomeWork is a complete type.
    cout << "HomeWorkInfoo: " << h.hom << endl;
}


int main() {
    Bank b1;
    b1.setPassword("Imran@123");
    b1.setAge(19);

    HomeWork h;

    // HomeWork object accessing Bank's private data
    h.printInfo(b1);

    // Bank object accessing HomeWork's private data
    b1.accessHomeworkInfo(h);

    return 0;
}

