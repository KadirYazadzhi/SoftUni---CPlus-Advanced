#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <cctype>
#include <algorithm>

using namespace std;

int main(void) {
    string buff;
    getline(cin, buff);

    for (char & c : buff) {
        if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z') && (c != ' ')) {
            c = ' ';
        }
    }

    istringstream istr(buff);
    set<string> words;

    string word;
    while (istr >> word) {
        words.insert(word);
    }

    while (true) {
        char c;
        cin >> c;

        if (c == '.') {
            break;
        }

        c = ::tolower(c);
        bool bFound = false;

        for (const string & curr : words) {
            string transformed = curr;
            if (c >= 'a' && c <= 'z') {
                transform(transformed.begin(),
                          transformed.end(),
                          transformed.begin(),
                          ::tolower);
            }

            if (transformed.find(c) != string::npos) {
                bFound = true;
                cout << curr << " ";
            }
        }

        if (!bFound) {
            cout << "---";
        }
        cout << endl;
    }
}
