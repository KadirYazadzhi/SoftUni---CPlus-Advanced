#include <iostream>

using namespace std;

void readField(char * & field, size_t & rows, size_t & cols) {

    cin >> rows >> cols;

    field = new char[rows * cols];

    for (size_t curRow = 0; curRow < rows; curRow++) {
        for (size_t curCol = 0; curCol < cols; curCol++) {
            cin >> field[curRow * cols + curCol];
        }
    }

}

void deleteField (char * field) {

    delete [] field;

}

char getAt(size_t row, size_t col, char * field, size_t fieldRows, size_t fieldCols) {
    return field[row * fieldCols + col];
}

bool hasMine(size_t row, size_t col, char * field, size_t fieldRows, size_t fieldCols) {
    return getAt(row, col, field, fieldRows, fieldCols) == '!';
}

size_t numberOfMines(size_t row, size_t col, char * field, size_t fieldRows, size_t fieldCols) {
    size_t mines = 0;

    if (row > 0) {
        if (col > 0) {
            mines += hasMine(row - 1, col - 1, field, fieldRows, fieldCols);
        }
        mines += hasMine(row - 1, col, field, fieldRows, fieldCols);

        if (col < fieldCols - 1) {
            mines += hasMine(row - 1, col + 1, field, fieldRows, fieldCols);
        }
    }

    if (col > 0) {
        mines += hasMine(row, col - 1, field, fieldRows, fieldCols);
    }
    mines += hasMine(row, col, field, fieldRows, fieldCols);
    if (col < fieldCols - 1) {
        mines += hasMine(row, col + 1, field, fieldRows, fieldCols);
    }

    if (row < fieldRows - 1) {
        if (col > 0) {
            mines += hasMine(row + 1, col - 1, field, fieldRows, fieldCols);
        }
        mines += hasMine(row + 1, col, field, fieldRows, fieldCols);

        if (col < fieldCols - 1) {
            mines += hasMine(row + 1, col + 1, field, fieldRows, fieldCols);
        }
    }

    return mines;
}

int main() {
    size_t fieldRows, fieldCols;
    char * field;

    readField(field, fieldRows, fieldCols);

    for (size_t curRow = 0; curRow < fieldRows; curRow++) {
        for (size_t curCol = 0; curCol < fieldCols; curCol++) {
            cout << numberOfMines(curRow, curCol, field, fieldRows, fieldCols);
        }
        cout << endl;
    }

    deleteField(field);
}