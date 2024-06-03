#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void readMatrix(istream  & in, vector<vector<char>> & mat) {
    int rows, cols;
    in >> rows >> cols;

    mat.resize(rows, vector<char>(cols, 0));

    for (int curRow = 0; curRow < rows; curRow++) {
        for (int curCol = 0; curCol < cols; curCol++) {
            in >> mat[curRow][curCol];
        }
    }
}

bool detect2x2(vector<vector<char>> & mat, size_t row, size_t col) {
    char c = mat[row][col];

    return  c == mat[row][col + 1] &&
            c == mat[row + 1][col] &&
            c == mat[row + 1][col + 1];
}

int main() {
    vector<vector<char>> mat;

    readMatrix(cin, mat);

    size_t count = 0;
    for (size_t curRow = 0; curRow < mat.size() - 1; curRow++) {
        for (size_t curCol = 0; curCol < mat[0].size() - 2; curCol++) {
            if (detect2x2(mat, curRow, curCol)) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}