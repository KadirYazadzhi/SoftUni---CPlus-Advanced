#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int cols;
    int rows;

    string data;
    getline(cin, data);

    istringstream istr(data);
    istr >> rows;
    istr >> cols;


    int arr[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    int n;
    cin >> n;

    bool isValid = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == n) {
                cout <<  i << " " << j << endl;
                isValid = true;
            }
        }
    }

    if (!isValid) {
        cout << "not found" << endl;
    }
}