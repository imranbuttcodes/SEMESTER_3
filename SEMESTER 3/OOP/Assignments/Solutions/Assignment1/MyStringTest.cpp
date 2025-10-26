#include <iostream>
#include "MyString.h"
using namespace std;

int main(){
MyString s1("HelloWorld");
MyString s2("orld");
cout << s1.find_substr(s2); // → 5

}