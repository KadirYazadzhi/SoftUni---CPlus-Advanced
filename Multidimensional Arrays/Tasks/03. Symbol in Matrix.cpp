#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int rows = 0;
    int cols = 0;
    cin >> n;
    cin.ignore();

    char arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    char symbol;
    cin >> symbol;

    bool isValid = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == symbol) {
                rows = i;
                cols = j;
                isValid = true;
                break;
            }
        }
        if (isValid) break;
    }

    if (isValid) {
        cout << "(" << rows << ", " << cols << ")" << endl;
    }
    else {
        cout << symbol << " does not occur in the matrix" << endl;
    }
}
