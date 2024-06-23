#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

bool isPunctuation(char c) {
    return c == ',' || c == '.' || c == '?' || c == '!';
}

int main() {
    string paragraph;
    getline(cin, paragraph);

    map<string, int> wordCount;
    map<char, int> punctuationCount;

    string word;
    for (char c : paragraph) {
        if (isPunctuation(c)) {
            punctuationCount[c]++;
            if (!word.empty()) {
                wordCount[word]++;
                word.clear();
            }
        } else if (isspace(c)) {
            if (!word.empty()) {
                wordCount[word]++;
                word.clear();
            }
        } else {
            word += c;
        }
    }

    if (!word.empty()) {
        wordCount[word]++;
    }

    set<string> sortedPunctuation;
    for (const auto &p : punctuationCount) {
        sortedPunctuation.insert(string(1, p.first));
    }

    set<string> sortedWordsUppercase;
    set<string> sortedWordsLowercase;
    for (const auto &w : wordCount) {
        if (isupper(w.first[0])) {
            sortedWordsUppercase.insert(w.first);
        } else {
            sortedWordsLowercase.insert(w.first);
        }
    }

    for (const auto &p : sortedPunctuation) {
        cout << p << " -> " << punctuationCount[p[0]] << endl;
    }

    for (const auto &w : sortedWordsUppercase) {
        cout << w << " -> " << wordCount[w] << endl;
    }

    for (const auto &w : sortedWordsLowercase) {
        cout << w << " -> " << wordCount[w] << endl;
    }

    return 0;
}
