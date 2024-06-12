#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    string lowerString;
    for (int i = 0; i < line.size(); i++) {
        lowerString += tolower(line[i]);
    }
    cout << lowerString << endl;

    string upperString;
    for (int i = 0; i < line.size(); i++) {
        upperString += toupper(line[i]);
    }
    cout << upperString << endl;
}
