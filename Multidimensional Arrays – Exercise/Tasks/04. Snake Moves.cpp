#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string snake;
    size_t rows, cols;
    cin >> rows >> cols >> snake;

    char isle[12][12];

    string::iterator itS = snake.begin();
    for (size_t curRow = 0; curRow < rows; curRow++) {
        size_t firstCol, lastCol;
        int diff;
        if (curRow % 2) {
            firstCol = cols - 1;
            lastCol = 0;
            diff = -1;
        }
        else {
            firstCol = 0;
            lastCol = cols - 1;
            diff = 1;
        }
        for (size_t curCol = firstCol; ; curCol += diff) {
            if (itS == snake.end()) {
                itS = snake.begin();
            }
            isle[curRow][curCol]  = *itS;
            itS++;
            if (((diff == - 1 && (curCol == lastCol)) || (diff == 1 && (curCol == lastCol)))) {
                break;
            }
        }
    }

    for (size_t curRow = 0; curRow < rows; curRow++) {
        for (size_t curCol = 0; curCol < cols; curCol++) {
            cout << isle[curRow][curCol];
        }
        cout << endl;
    }
}
