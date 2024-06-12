#include <iostream>

using namespace std;

int main() {
    int rows, column;
    cin >> rows >> column;

    int arr[rows][column];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < column; j++) {
            cin >> arr[i][j];
        }
    }

    int spRows, spColumn;
    cin >> spRows >> spColumn;

    for (int i = 0; i < spRows; i++) {
        for (int j = 0; j < spColumn; j++) {
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
