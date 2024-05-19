#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> readInput() {
    vector<string> words;
    string input;
    getline(cin, input);
    istringstream istr(input);

    string word;
    while (istr >> word) {
        words.push_back(word);
    }

    return words;
}

void printWordReversed(const vector<string>& words) {
    stack<string> reversedWords;
    for (const string& word : words) {
        reversedWords.push(word);
    }

    while (!reversedWords.empty()) {
        cout << reversedWords.top() << ' ';
        reversedWords.pop();
    }

    cout << endl;
}

int main() {
    const vector<string> words = readInput();
    printWordReversed(words);

    return 0;
}