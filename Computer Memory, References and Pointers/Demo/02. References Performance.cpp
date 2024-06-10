#include <iostream>
#include <vector>

using namespace std;

void printZeroIndices(const vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<int> numbers{1, 0, -2, 7, 10, 0, 23, -67};
    printZeroIndices(numbers);

    return 0;
}
