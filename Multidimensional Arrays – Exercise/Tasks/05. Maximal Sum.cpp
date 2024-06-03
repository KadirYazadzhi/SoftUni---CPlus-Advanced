#include <iostream>
#include <sstream>
#include <vector>
#include <limits.h>

using namespace std;

void readMatrix(istream &in, vector<vector<int>> &mat) {
    int rows, cols;
    in >> rows >> cols;

    mat = vector<vector<int>>(rows, vector<int>(cols, 0));

    for (int curRow = 0; curRow < rows; curRow++) {
        for (int curCol = 0; curCol < cols; curCol++) {
            in >> mat[curRow][curCol];
        }
    }
}

pair<int, pair<int, int>> findMaxSumSquare(const vector<vector<int>> &mat) {
    int maxSum = INT_MIN;
    pair<int, int> topLeft;

    int rows = mat.size();
    int cols = mat[0].size();

    for (int i = 0; i <= rows - 3; i++) {
        for (int j = 0; j <= cols - 3; j++) {
            int sum = 0;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    sum += mat[x][y];
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
                topLeft = {i, j};
            }
        }
    }

    return {maxSum, topLeft};
}

int main() {
    vector<vector<int>> mat;

    readMatrix(cin, mat);

    auto result = findMaxSumSquare(mat);
    int maxSum = result.first;
    pair<int, int> topLeft = result.second;

    cout << "Sum = " << maxSum << endl;
    bool isFirst = true;
    for (int i = topLeft.first; i < topLeft.first + 3; i++) {
        for (int j = topLeft.second; j < topLeft.second + 3; j++) {
            if (isFirst) {
                cout << " ";
            }
            else {
                isFirst = false;
            }
            cout << mat[i][j];
        }
        cout << endl;
    }

    return 0;
}
