#include <iostream>

using namespace std;

void print(int n) {
    cout << n << endl;
}

int main() {
    int number = 42;
    char cStr[] = "I'm a C-String";
    char* otherCStr = "I'm another C-String";

    int * numberPtr = &number;
    void* p;

    p = numberPtr;
    cout << p << endl;

    p = &number;
    cout << p << endl;

    p = cStr;
    cout << cStr << " " << p << endl;

    p = otherCStr;
    cout << otherCStr << " " << p << endl;

    p = print;
    cout << p << endl;

    return 0
}