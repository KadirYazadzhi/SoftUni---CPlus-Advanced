#include <iostream>

using namespace std;

int main() {
    int a = 42;
    int b = 13;

    int* ptr = &a;
    cout << *ptr << endl;

    ptr = &b;
    *ptr = 7;
    cout << b << endl;

    string s = "world";
    string* sPtr = &s;

    sPtr -> insert(0, "hello");
    cout << *sPtr << endl;

    return 0;
}