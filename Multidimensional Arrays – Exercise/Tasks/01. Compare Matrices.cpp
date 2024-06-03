#include <iostream>
#include <sstream>
#include <array>

using namespace std;

void readMatrix(istream &in, array<array<int, 10>, 10> &mat, int &rows, int &cols) {
    cin >> rows;
    cin.ignore();

    for (int curRow = 0; curRow < rows; curRow++) {
        string buff;
        getline(in, buff);

        istringstream istr(buff);
        cols = 0;
        int curValue;
        while (istr >> curValue) {
            mat[curRow][cols++] = curValue;
        }
    }
}

bool compareMatrices(array<array<int, 10>, 10> &mat1, int rows1, int cols1, array<array<int, 10>, 10> &mat2, int rows2, int cols2) {
    if (rows1 != rows2 || cols1 != cols2) {
        return false;
    }

    for (int curRow = 0; curRow < rows1; curRow++) {
        for (int curCol = 0; curCol < cols1; curCol++) {
            if (mat1[curRow][curCol] != mat2[curRow][curCol]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    array<array<int, 10>, 10> mat1, mat2;
    int m1r, m1c, m2r, m2c;

    readMatrix(cin, mat1, m1r, m1c);
    readMatrix(cin, mat2, m2r, m2c);

    cout << (compareMatrices(mat1, m1r, m1c, mat2, m2r, m2c) ? "equal" : "not equal") << endl;

    return 0;
}
