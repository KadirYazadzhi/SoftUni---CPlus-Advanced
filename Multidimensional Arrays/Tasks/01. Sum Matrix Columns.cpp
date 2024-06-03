#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int column = 0;
    int rows = 0;
    int sum = 0;

    string input;
    getline(cin, input);
    istringstream istr(input);

    istr >> column;
    istr >> rows;

    int arr[rows][column];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < column; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < column; i++) {
        sum = 0;
        for (int j = 0; j < rows; j++) {
            sum += arr[j][i];
        }
        cout << sum << endl;
    }

    return 0;
}
