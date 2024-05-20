#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    stack<size_t> openBrackets;

    for (size_t idx = 0; idx < line.length(); idx++) {
        if (line[idx] == '(') {
            openBrackets.push(idx);
        }
        else if (line[idx] == ')') {
            size_t openBracket = openBrackets.top();
            openBrackets.pop();

            string strInner = line.substr(openBracket, idx - openBracket + 1);

            cout << strInner << endl;
        }
    }
}

