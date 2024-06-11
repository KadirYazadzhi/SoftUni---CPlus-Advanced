#include <iostream>
#include <list>
#include <sstream>
#include <string>

using namespace std;

int main() {
    list<int> numbers;

    string line;
    getline(cin, line);
    istringstream istr(line);

    int num;
    while (istr >> num) {
        numbers.push_back(num);
    }

    int size = numbers.size();

    int sum = 0;
    while (!numbers.empty()) {
        int start = numbers.front();
        numbers.pop_front();

        if (!numbers.empty()) {
            int end = numbers.back();
            numbers.pop_back();

            sum = start + end;
        }
        else {
            sum = start;
        }
        cout << sum << " ";
    }
}