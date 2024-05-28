#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    istringstream istr(input);

    set<double> numbers;

    double num;
    while (istr >> num) {
        numbers.insert(num);
    }

    auto it = numbers.rbegin();
    int count = 0;
    while (it != numbers.rend() && count < 3) {
        cout << *it << " ";
        ++it;
        ++count;
    }

    return 0;
}
