#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    string str;
    queue<string> names;

    while (true) {
        cin >> str;

        if (str == "End") {
            break;
        }
        else if (str == "Paid") {
            while (!names.empty()) {
                cout << names.front() << endl;
                names.pop();
            }
        }
        else {
            names.push(str);
        }
    }

    int counter = names.size();

    cout << counter << " people remaining." << endl;

    return 0;
}