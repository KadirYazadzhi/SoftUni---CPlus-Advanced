#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkValidParentesis(stack<char> & pars, char expected) {
    if (pars.empty()) {
        return false;
    }
    if (pars.top() != expected) {
        return false;
    }
    else {
        pars.pop();
        return true;

    }
}

int main() {
    string eq;
    getline(cin, eq);

    stack<char> pars;

    bool bValid = true;

    string::iterator itS = eq.begin();
    for (; bValid && itS != eq.end(); itS++) {

        switch(*itS) {
            case '(':
            case '[':
            case '{':
                pars.push(*itS);
                break;
            case ')':
                if (!checkValidParentesis(pars, '(')) {
                    bValid = false;
                }
                    break;
            case ']':
                if (!checkValidParentesis(pars, '[')) {
                    bValid = false;
                }
                break;
            case '}':
                if (!checkValidParentesis(pars, '{')) {
                    bValid = false;
                }
                break;
        }
    }

    if (bValid && !pars.empty()) {
            bValid = false;
    }

    cout << (bValid ? "YES" : "NO") << endl;
}
