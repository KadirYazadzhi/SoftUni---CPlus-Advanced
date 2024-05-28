#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main(void) {
    string data;
    getline(cin, data);
    istringstream istr(data);

    set<string> numbers;
    map<string, int> count;

    string num;
    while (istr >> num) {
        numbers.insert(num);
        count[num]++;
    }

    for (const string& n : numbers) {
        cout << n << " -> " << count[n] << endl;
    }
}