#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int primarySum = 0;
    int nonPrimarySum = 0;

    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        primarySum += arr[i][i];
        nonPrimarySum += arr[i][n - i - 1];
    }

    double answer = abs(nonPrimarySum - primarySum);

    cout << answer << endl;
}
