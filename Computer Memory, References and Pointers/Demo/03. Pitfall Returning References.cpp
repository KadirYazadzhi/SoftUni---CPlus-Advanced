#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int>& generateRoots(int toNumber) {
    vector<int> roots;

    for (int i = 0; i < toNumber; i++) {
        roots.push_back(sqrt(i));
    }

    return roots;
}

int main() {
    vector<int>& rootsRef = generateRoots(100);

    vector<int> otherVector{42, 13, 69};
    cout << rootsRef[4] << endl;

    cout << &rootsRef;

    return 0;
}
