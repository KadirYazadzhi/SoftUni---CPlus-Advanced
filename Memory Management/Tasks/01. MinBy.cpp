#include <iostream>
#include <sstream>
#include <string>
#include <limits.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int smallestWord (string word, map<int, vector<string>>& data, int smallest) {
    int num = word.length();
    if (num < smallest) {
        smallest = num;
        data.clear();
        data[num].push_back(word);
    }

    return smallest;
}

int biggestWord (string word, map<int, vector<string>>& data, int biggest) {
    int num = word.length();
    if (num > biggest) {
        biggest = num;
        data.clear();
        data[num].push_back(word);
    }

    return biggest;
}

void printWord(map<int, vector<string>> data) {
    for (map<int, vector<string>>::iterator itB = data.begin(); itB != data.end(); itB++) {
        vector<string> & vec = itB->second;

        for (string d : vec) {
            cout << d << endl;
        }

    }
}

int main() {
    string line;
    getline(cin, line);
    istringstream istr(line);
    istringstream istrTwo(line);

    int operationNumber;
    cin >> operationNumber;

    string word;
    vector<string> words;

    map<int, vector<string>> data;
    int smallest = INT_MAX;
    int biggest = INT_MIN;

    while (istrTwo >> word) {
        words.push_back(word);
    }

    bool isValid = true;
    while (istr >> word) {
        if (operationNumber == 1) {
            auto earliest = min_element(words.begin(), words.end());
            cout << *earliest << endl;
            isValid = false;
            break;
        }
        else if (operationNumber == 2) {
            smallest = smallestWord(word, data, smallest);
        }
        else {
            biggest = biggestWord(word, data, biggest);
        }
    }

    if (isValid) {
        printWord(data);
    }
}
