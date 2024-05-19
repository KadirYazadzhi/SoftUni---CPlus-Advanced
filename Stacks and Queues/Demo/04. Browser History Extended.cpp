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

void executeBackUrl(stack<string> &urlBackHistory, stack<string> &urlForwardHistory) {
    if (urlBackHistory.empty()) {
        cout << "no previous URL" << endl;
        return;
    }

    urlForwardHistory.push(urlBackHistory.top());
    urlBackHistory.pop();
    if (urlBackHistory.empty()) {
        cout << "Empty browser" << endl;
    }
    else {
        cout << urlBackHistory.top() << endl;
    }
}

void executeForwardUrl(stack<string> &urlBackHistory, stack<string> &urlForwardHistory) {
    if (urlForwardHistory.empty()) {
        cout << "no next URL" << endl;
        return;
    }

    const string currUrl = urlForwardHistory.top();
    urlBackHistory.push(currUrl);
    urlForwardHistory.pop();
    cout << "Last URL: " << currUrl << endl;
}

int main() {
    stack<string> urlBackHistory;
    stack<string> urlForwardHistory;
    string currUrl;
    const string delimiter = "end";
    const string backInstruction = "/back";
    const string forwardInstruction = "/forward";
    while (true) {
        currUrl = readinput();
        if (currUrl == delimiter) {
            break;
        }

        if (currUrl == backInstruction) {
            executeBackUrl(urlBackHistory, urlForwardHistory);
        }
        else if (currUrl == forwardInstruction) {
            executeForwardUrl(urlBackHistory, urlForwardHistory);
        }
        else {
            executeAddUrl(currUrl, urlBackHistory, urlForwardHistory);
        }
    }

    return 0;
}
