#include <iostream>


using namespace std;

int main() {
    int n;
    cin >> n;

    double primarySum = 0;
    double nonPrimarySum = 0;

    double arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        primarySum += arr[i][i];
    }

    for (int i = 0; i < n; i++) {
        nonPrimarySum += arr[i][n - i - 1];
    }

    double answer = nonPrimarySum - primarySum;

    cout << answer << endl;
}
