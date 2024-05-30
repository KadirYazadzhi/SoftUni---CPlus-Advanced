#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main(void) {
    map<string, double> numbers;
    vector<string> order;

    string type;
    double number;

    cin >> type;
    while (type != "stop") {
        cin >> number;

        map<string, double>::iterator itI = numbers.find(type);
        if (itI != numbers.end()) {
            itI->second += number;
        }
        else {
            numbers[type] = number;
            order.push_back(type);
        }

        cin >> type;
    }

    for (string curr : order) {
        cout << curr << " -> " << numbers[curr] << endl;
    }

}