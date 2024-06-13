#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void waitForEnter(string message) {
    cout << message << endl;

    string s;
    getline(cin, s);
}

void allocateLargeAutoMemory() {
    int autoArr[1000];
    for (size_t i = 0; i < 1000; i++) {
        autoArr[i] = i;
    }
}

void allocateLargeAutoVector() {
    vector<int> autoVector;
    for (size_t i = 0; i < 1000000; i++) {
        autoVector.push_back(i);
    }

    waitForEnter("in allocateLargeAutoVector(), after filling vector - check memory, should be sizeof(int) MB more");
}

int main() {
    int autoVar = 42;

    for (int i = 0; i < 1000000; i++) {
        int autoVarLoop = i * i;
        autoVar += autoVarLoop;
    }

    allocateLargeAutoMemory();

    waitForEnter("before allocateLargeAutoVector() - check memory usage");
    allocateLargeAutoVector();
    waitForEnter("after allocateLargeAutoVector() - memory usage now should match usage before");

    return 0;
}
