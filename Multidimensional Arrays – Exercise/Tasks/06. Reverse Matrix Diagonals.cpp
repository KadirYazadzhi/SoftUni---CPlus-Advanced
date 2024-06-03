#include <iostream>
#include <vector>

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

void printReverseDiagonal(vector<vector<int>> & mat, int row, int col) {
    for (; row >= 0 && col < mat[0].size(); row--, col++) {
        cout << mat[row][col] << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> mat;
    readMatrix(cin, mat);

    for (int c = mat[0].size() - 1; c >= 0; c--) {
        printReverseDiagonal(mat, mat.size() - 1, c);
    }

    for (int r = mat.size() - 2; r >= 0; r--) {
        printReverseDiagonal(mat, r, 0);
    }
}