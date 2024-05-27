#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    set<string> names;

    while (n--) {
        string name;
        cin >> name;

        names.insert(name);
    }

    for (string name : names) {
        cout << name << endl;
    }
}

