#include <iostream>

using namespace std;

int main() {
    int number = 42;
    int* ptr = &number;

    *ptr++;
    cout << *ptr << endl;

    return 0;
}
