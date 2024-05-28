#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    string line;
    getline(cin, line);

    transform(line.begin(), line.end(), line.begin(), ::tolower);

    istringstream  iss(line);
    string word;
    map<string, int> word_count;
    vector<string> order_of_appearance;

    while (iss >> word) {
        if (word_count.find(word) == word_count.end()) {
            order_of_appearance.push_back(word);
        }
        word_count[word]++;
    }

    bool bFirst = true;
    for (const string& w : order_of_appearance) {
        if (word_count[w] % 2 != 0) {
            if (!bFirst) {
                cout << ", ";
            }
            else {
                bFirst = false;
            }
            cout << w;
        }
    }
}