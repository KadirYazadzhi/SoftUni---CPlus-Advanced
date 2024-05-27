#include <iostream>
#include <set>

using namespace std;

void readSet(int count, set<int> & set) {
    while(count--) {
        int n;
        cin >> n;
        set.insert(n);
    }
}

int main(void) {
    int n, m;
    set<int> N, M;

    cin >> n >> m;

    readSet(n, N);
    readSet(m, M);

    for (int firstSet : N) {
        if (M.find(firstSet) != M.end()) {
            cout << firstSet << " ";
        }
    }
    cout << endl;

    return 0;
}