#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isValidNumber(string data) {
    bool isValid;
    int i = 0;
    isValid = false;
    for (char c : data) {
        if (c >= '0' && c <= '9') {
            i = i * 10 + (c - '0');
            isValid = true;
        }
    }

    return isValid;
}

int main() {
    string line;
    getline(cin, line);
    istringstream istr(line);

    string data1, data2;
    istr >> data1 >> data2;

    bool isValidOne = isValidNumber(data1);
    bool isValidTwo = isValidNumber(data2);

    if (isValidOne && isValidTwo) {
        cout << stoi(data1) + stoi(data2) << endl;
    }
    else if (!isValidOne && isValidTwo) {
        cout << "[error]" << " " << data1 << endl;
        cout << stoi(data2);
    }
    else {
        cout << "[error]" << " " << data2 << endl;
        cout << stoi(data1);
    }

    return 0;
}