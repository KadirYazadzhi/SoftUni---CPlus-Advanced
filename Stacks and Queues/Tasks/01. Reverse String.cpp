#include <iostream>
#include <string>
#include <stack>

using namespace std;

string readInput() {
    string input;
    getline(cin, input);
    return input;
}

stack<char> reverseString(string &input){
    stack<char> words;
    for (int i = 0; i < input.length(); i++) {
        words.push(input[i]);
    }
    return words;
}

void reversedWord(stack<char> &words) {
    while (!words.empty()) {
        cout << words.top();
        words.pop();
    }
    cout << endl;
}

int main() {
    string input = readInput();
    stack<char> words = reverseString(input);
    reversedWord(words);

    return 0;
}
