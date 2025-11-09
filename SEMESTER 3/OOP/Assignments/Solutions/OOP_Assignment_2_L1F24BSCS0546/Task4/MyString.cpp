#include "MyString.h"
#include<iostream>
using namespace std;

MyString::MyString() : MAX_LEN(100), len(0), data(new char[MAX_LEN]) {
    data[0] = '\0';
}
MyString::MyString(const char* str) :MyString() {

    int l = 0;
    for (int i = 0;str[i] != '\0';i++) {
        l++;
    }
    l = (l >= MAX_LEN) ? MAX_LEN - 1 : l;
    for (int i = 0; i < l; i++) {
        data[i] = str[i];
    }
    data[l] = '\0';
    len = l;
}
MyString::MyString(const MyString& other) : MyString() {
    len = other.len;
    for (int i = 0;i < len; i++) {
        data[i] = other.data[i];
    }
    data[len] = '\0';
}
int MyString::length() const {
    int leng = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        leng++;
    }
    return leng;
}

void MyString::copy(const MyString& source) {
    int l = (source.length() >= MAX_LEN) ? MAX_LEN - 1 : source.length();
    for (int i = 0;i < l; i++) {
        data[i] = source.data[i];
    }
    data[l] = '\0';
    len = l;
}
void MyString::copy_n(const MyString& source, int n) {
    if (n >= MAX_LEN) {
        n = MAX_LEN - 1;
    }
    if (n > source.length()) {
        n = source.length();
    }

    for (int i = 0; i < n; i++) {
        data[i] = source.data[i];
    }
    data[n] = '\0';
    len = n;
}

void MyString::concat(const MyString& other) {
    if (other.len + len >= MAX_LEN - 1) {
        cout << "Reached the maximum len limit.Can't be contaticate\n";
        return;
    }
    for (int i = 0, j = 0; i < other.len; i++) {
        data[len + i] = other.data[j++];
    }
    data[len + other.len] = '\0';
    len = len + other.len;
}

int MyString::compare(const MyString& other) {
    int i = 0;
    while (data[i] != '\0' && other.data[i] != '\0') {
        if (data[i] < other.data[i]) {
            return -1;
        }
        else if (data[i] > other.data[i]) {
            return 1;
        }
        i++;
    }
    if (data[i] == '\0' && other.data[i] == '\0') {
        return 0;
    }
    else if (data[i] == '\0' && other.data[i] != '\0') {
        return -1;
    }
    else {
        return 1;
    }
}
int MyString::find_char(char ch) {
    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] == ch)   return i;
    }
    return -1;
}
int MyString::find_substr(const MyString& substr) {
    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] == substr.data[0]) {
            int l = i;
            bool found = true;
            for (int k = 0; k < substr.len; k++) {
                if (data[l++] != substr.data[k]) {
                    found = false;
                    break;

                }
            }
            if (found) {
                return i;
            }
        }
    }
    return -1;
}

void MyString::print() {
    cout << data << endl;
}
