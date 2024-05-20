#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    istringstream istr(line);

    queue<int> numbers;
    int num;

    while (istr >> num) {
        numbers.push(num);
    }

    bool bFirst = true;
    while (!numbers.empty()) {
        int curNum = numbers.front();
        numbers.pop();

        if ((curNum % 2) == 0) {
            if (!bFirst) {
                cout << ", ";
            }
            else {
                bFirst = false;
            }

            cout << curNum;
        }
    }

    cout << endl;
}
