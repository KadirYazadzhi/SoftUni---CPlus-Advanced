#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

int main() {
    queue<string> players;

    string buf;
    getline(cin, buf);
    istringstream istr(buf);

    while (istr >> buf) {
        players.push(buf);
    }

    int moves;
    cin >> moves;

    int remainingMoves = moves;
    while (players.size() > 1) {
        string currentPlayer = players.front();
        players.pop();
        remainingMoves--;

        if (remainingMoves == 0) {
            cout << "Removed " << currentPlayer << endl;
            remainingMoves = moves;
        }
        else {
            players.push(currentPlayer);
        }
    }

    cout << "Last is " << players.front() << endl;
}
