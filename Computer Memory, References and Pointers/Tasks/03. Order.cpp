#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main() {
    string line;
    string name;
    int id;

    map<int, string> companies;

    while(true) {
        getline(cin, line);
        istringstream istr(line);

        istr >> name;
        if (name == "end") {
            break;
        }
        istr >> id;

        companies[id] = name;
    }

    for (const auto& company : companies) {
        cout << company.second << " " << company.first << endl;
    }
}
