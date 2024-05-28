#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main(void) {
    string data;
    getline(cin, data);

    istringstream istr(data);

    set<double> numbers;

    double num;
    while (istr >> num) {
        numbers.insert(num);
    }

    bool isValid = true;
    for (double n : numbers) {
        if (!isValid) {
            cout << " <= ";
        }
        else {
            isValid = false;
        }
        cout << n;
    }
}
