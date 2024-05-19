#include <iostream>
#include <queue>
#include <string>

using namespace std;

string readInput() {
    string input;
    getline(cin, input);
    return input;
}

queue<string> readEvents() {
    queue<string> events;
    string input;
    const string delimiter = "end";
    while(true) {
        input = readInput();
        if (input == delimiter) {
            break;
        }

        events.push(input);
    }

    return events;
}

void printContent(queue<string>& events) {
    while(!events.empty()) {
        cout << events.front() << ' ';
        events.pop();
    }
    cout << endl;
}

int main() {
    queue<string> events = readEvents();
    printContent(events);

    return 0;
}