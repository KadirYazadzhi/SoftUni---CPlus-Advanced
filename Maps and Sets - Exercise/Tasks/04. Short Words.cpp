#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

int main(void) {
    string line;
    getline(cin, line);

    transform(line.begin(), line.end(), line.begin(), ::tolower);

    istringstream istr(line);

    string word;
    set<string> words;

    bool bFirst = true;
    while (istr >> word) {
        words.insert(word);
    }

    for (string w : words) {
        if (w.length() < 5) {
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
