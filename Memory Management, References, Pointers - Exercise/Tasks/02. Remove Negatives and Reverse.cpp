#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    istringstream istr(line);

    list<int> numbers;

    int num;
    while(istr >> num) {
        if (num >= 0) {
            numbers.push_back(num);
        }
    }

    int size = numbers.size();
    if (size > 0) {
        while (!numbers.empty()) {
            int i = numbers.back();
            cout << i << " ";
            numbers.pop_back();
        }
    }
    else {
        cout << "empty" << endl;
    }

}