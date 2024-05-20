#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <climits>

using namespace std;

int findSmallestElement(stack<int> numbers) {
    int min = INT_MAX;
    while (!numbers.empty()) {
        if (min > numbers.top()) {
            min = numbers.top();
        }
        numbers.pop();
    }
    return min;
}

int findBiggestElement(stack<int> numbers) {
    int max = INT_MIN;
    while (!numbers.empty()) {
        if (max < numbers.top()) {
            max = numbers.top();
        }
        numbers.pop();
    }
    return max;
}

void printElementFromStack(stack<int> numbers) {
    while (numbers.size() > 1) {
        cout << numbers.top() << ", ";
        numbers.pop();
    }
    if (!numbers.empty()) {
        cout << numbers.top();
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    stack<int> numbers;

    for (int i = 0; i < N; i++) {
        string input;
        getline(cin, input);
        istringstream istr(input);

        int operationNumber;
        istr >> operationNumber;

        switch (operationNumber) {
            case 1:
                int number;
                istr >> number;
                numbers.push(number);
                break;
            case 2:
                if (!numbers.empty()) {
                    numbers.pop();
                }
                break;
            case 3:
                if (!numbers.empty()) {
                    cout << findBiggestElement(numbers) << endl;
                }
                break;
            case 4:
                if (!numbers.empty()) {
                    cout << findSmallestElement(numbers) << endl;
                }
                break;
        }
    }
    printElementFromStack(numbers);

    return 0;
}
