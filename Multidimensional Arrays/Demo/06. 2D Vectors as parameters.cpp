#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> createVec2D(int rows, int cols) {
    vector<vector<int>> vec2D(rows, vector<int>(cols));
    return vec2D;
}

void increaseAllElementsByCopy(vector<vector<int>> vec2D,
                               int incrValue) {
    for (auto& row : vec2D) {
        for (auto& elem : row) {
            elem += incrValue;
        }
    }
}

void increaseAllElementsNoCopy(vector<vector<int>>& vec2D,
                               int incrValue) {
    for (auto& row : vec2D) {
        for (auto& elem : row) {
            elem += incrValue;
        }
    }
}

void print(const vector<vector<int>>& vec2D) {
    for (auto& row : vec2D) {
        for (auto& elem : row) {
            cout << elem << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    const int rows = 3;
    const int cols = 5;
    auto vec2D = createVec2D(rows, cols);

    increaseAllElementsByCopy(vec2D, 1);
    print(vec2D);

    increaseAllElementsNoCopy(vec2D, 1);
    print(vec2D);

    return 0;
}

