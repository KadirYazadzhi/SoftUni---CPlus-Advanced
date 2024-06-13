#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int &rows, int &cols, int matrix[MAX_SIZE][MAX_SIZE]) {
    cin >> rows;
    cin.ignore();
    for (int i = 0; i < rows; ++i) {
        int j = 0;
        while (cin.peek() != '\n' && cin.peek() != EOF) {
            cin >> matrix[i][j++];
        }
        cols = j;
        cin.ignore();
    }
}

bool compareMatrices(int rows1, int cols1, int matrix1[MAX_SIZE][MAX_SIZE], int rows2, int cols2, int matrix2[MAX_SIZE][MAX_SIZE]) {
    if (rows1 != rows2 || cols1 != cols2) {
        return false;
    }
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int rows1 = 0, cols1 = 0;
    int matrix1[MAX_SIZE][MAX_SIZE] = {0};
    readMatrix(rows1, cols1, matrix1);

    if (cin.peek() == EOF) {
        cout << "not equal" << endl;
        return 0;
    }

    int rows2 = 0, cols2 = 0;
    int matrix2[MAX_SIZE][MAX_SIZE] = {0};
    readMatrix(rows2, cols2, matrix2);

    if (compareMatrices(rows1, cols1, matrix1, rows2, cols2, matrix2)) {
        cout << "equal" << endl;
    } else {
        cout << "not equal" << endl;
    }

    return 0;
}

