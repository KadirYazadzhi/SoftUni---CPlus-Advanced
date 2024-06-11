#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string name;
    string id;

    unordered_map<string, string> companyMap;

    string line;
    getline(cin, line);
    while (line != "end") {
        istringstream istr(line);
        istr >> name >> id;

        companyMap[id] = name;

        getline(cin, line);
    }

    cin >> id;

    if (companyMap.find(id) != companyMap.end()) {
        cout << companyMap[id] << " " << id << endl;
    } else {
        cout << "[not found]" << endl;
    }

}