#include <iostream>

using namespace std;

const int rows = 3;
const int cols = 5;

void increaseAllElements(int arr[rows][cols], int incrValue) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] += incrValue;
        }
    }
}

void printArray(int arr[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[rows][cols];
    increaseAllElements(arr, 1);
    printArray(arr);
}