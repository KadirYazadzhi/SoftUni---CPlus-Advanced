#include <iostream>
#include <vector>

using namespace std;

void printZeroIndices(const vector<int>* numbers) {
    for (int i = 0; i < numbers -> size(); i++) {
        if ((*numbers) [i] == 0) {
            cout << i << " ";
        }
    }
}

int main() {
    vector<int> numbers{1, 0, -2, 7, 0, 10, -100, 42};

    printZeroIndices(&numbers);

    return 0;
}
