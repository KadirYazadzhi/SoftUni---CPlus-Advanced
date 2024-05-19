#include <iostream>
#include <stack>
#include <string>

using namespace std;

string readInput() {
    string input;
    getline(cin, input);
    return input;
}

void executeAddUrl(const string &newUrl, stack<string> &urlHistory) {
    urlHistory.push(newUrl);
    cout << "Last URL: " << newUrl << endl;
}

void executeBackUrl(stack<string> &urlHistory) {
    if (urlHistory.empty()) {
        cout << "no previous URL" << endl;
        return;
    }

    urlHistory.pop();
    if (urlHistory.empty()) {
        cout << "Empty browser" << endl;
    }
    else {
        cout << urlHistory.top() << endl;
    }

}

int main() {
    stack<string> urlHistory;
    string currUrl;
    const string delimiter = "end";
    const string backInstruction = "/back";
    while (true) {
        currUrl = readInput();
        if (currUrl == delimiter) {
            break;
        }

        if (currUrl == backInstruction) {
            executeBackUrl(urlHistory);
        }
        else {
            executeAddUrl(currUrl, urlHistory);
        }
    }

    return 0;
}