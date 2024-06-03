#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int size;
    char algo;

    string buff;
    getline(cin, buff, ',');
    size = stoi(buff);

    cin >> algo;

    int counter = 1;
    int r = 0;
    int c = 0;
    int direction = 1;

    vector<vector<int>> mat(size, vector<int>(size, 0));

    for (; counter <= size * size; counter++) {
        mat[r][c] = counter;
        r += direction;

        if (algo == 'A') {
            if (r >= size) {
                r = 0;
                c++;
            }
        }
        else {
            if (r < 0 || r >= size) {
                c++;

                if (r >= size) {
                    r = size - 1;
                }
                else {
                    r = 0;
                }
                direction = -direction;
            }
        }
    }

    for (int curRow = 0; curRow < size; curRow++) {
        for (int curCol = 0; curCol < size; curCol++) {
            cout << mat[curRow][curCol] << ' ';
        }
        cout << endl;
    }
}