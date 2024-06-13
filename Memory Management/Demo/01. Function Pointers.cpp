#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string s, char separator) {
    vector<string> strings;

    ostringstream current;
    for (char c : s) {
        if (c == separator) {
            strings.push_back(current.str());

            current.str("");
            current.clear();
        }
        else {
            current << c;
        }
    }

    return strings;
}

int main() {
    vector<string> (*p) (string, char) = split;

    vector<string> words = p("the quick brown fox jumps over the lazy dog", ' ');

    for (string w : words) {
        cout << w << endl;
    }

    return 0;
}
