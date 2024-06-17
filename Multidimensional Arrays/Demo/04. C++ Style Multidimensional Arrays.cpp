#include <iostream>
#include <array>

const int rows = 3;
const int cols = 5;

using namespace std;

void increaseAllElementByCopy(array<array<int, cols>, cols> arr, int incrValue) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = incrValue;
        }
    }
}

void increaseAllElementNoCopy(array<array<int, cols>, cols> arr, int incrValue) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = incrValue;
        }
    }
}

void printArray(array<array<int, cols>, cols> arr) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    array<array<int, cols>, cols> arr {};

    increaseAllElementByCopy(arr, 1);
    printArray(arr);

    increaseAllElementNoCopy(arr, 1);
    printArray(arr);

    return 0;
}