#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double * getPrecomputedSquareRoots(int toNumber) {
    double* roots = new double[toNumber + 1];
    for (size_t i = 0; i <= toNumber; i++) {
        roots[i] = sqrt(i);
    }

    return roots;
}

int main() {
    double* roots = getPrecomputedSquareRoots(10000);

    int numbers;
    cin >> numbers;

    for (int i = 0; i < numbers; i++) {
        int number;
        cin >> number;

        cout << "sqrt(" << number << ") = " << roots[number] << endl;
    }

    delete[] roots;

    return 0;
}