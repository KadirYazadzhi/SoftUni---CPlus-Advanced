#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <climits>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    istringstream istr(input);

    int N, S, X;
    istr >> N >> S >> X;

    string number;
    getline(cin,number);
    istringstream nums(number);

    queue<int> numbers;
    int num;
    while (nums >> num) {
        numbers.push(num);
    }
    int size = numbers.size();

    for (int i = 0; i < S; i++) {
        if (!numbers.empty()) {
            numbers.pop();
        }
    }

    int smallest = INT_MAX;
    int curNum = 0;
    bool isValid = false;

    while (!numbers.empty()) {
        curNum = numbers.front();
        numbers.pop();
        if (curNum == X) {
            isValid = true;
            break;
        }
        if (curNum < smallest) {
            smallest = curNum;
        }
    }

    if (isValid) {
        cout << "true" << endl;
    }
    else if (size == S) {
        cout << 0 << endl;
    }
    else {
        cout << smallest << endl;
    }
}