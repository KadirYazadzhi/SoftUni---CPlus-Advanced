#include <iostream>
#include <stack>
#include <string>

using namespace std;

string readinput() {
    string input;
    getline(cin, input);
    return input;
}

void executeAddUrl(const string &newUrl, stack<string> &urlBackHistory, stack<string> &urlForwardHistory) {
    urlBackHistory.push(newUrl);
    urlForwardHistory = stack<string>();
    cout << "Last URL: " << newUrl << endl;
}
