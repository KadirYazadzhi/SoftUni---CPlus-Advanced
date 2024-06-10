#include <iostream>

using namespace std;

void f() {

}

int main() {
    int x = 42;
    auto addressX = &x;
    cout << x << " at " << addressX << endl;

    cout << "f()" << " code at " << &f << endl;

    double (&absAddress) (double) = abs;
    cout << "abs(double)" << " code at " << absAddress << endl;

    return 0;
}
