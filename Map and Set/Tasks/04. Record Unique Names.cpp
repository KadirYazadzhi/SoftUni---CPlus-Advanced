#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<string> names;
    unordered_set<string> names_set;

    while (n--) {
        string name;
        cin >> name;

        if (names_set.find(name) == names_set.end()) {
            names.push_back(name);
            names_set.insert(name);
        }
    }

    for (string name : names) {
        cout << name << endl;
    }
}


