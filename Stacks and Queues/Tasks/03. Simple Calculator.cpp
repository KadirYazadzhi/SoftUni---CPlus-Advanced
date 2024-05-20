#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    istringstream istr(str);

    stack<int> numbers;
    stack<char> operations;

    int operand;
    while (istr >> operand) {
        numbers.push(operand);

        char operation;
        if (istr >> operation) {
            operations.push(operation);
        }
        else {
            break;
        }
    }

    int sum = 0;
    while (!operations.empty()) {
        char c = operations.top();
        operations.pop();

        int number = numbers.top();
        numbers.pop();

        switch (c) {
            case '+': sum += number;
            break;
            case '-': sum -= number;
            break;
        }
    }

    if (!numbers.empty()) {
        sum += numbers.top();
    }

    cout << sum << endl;
}
