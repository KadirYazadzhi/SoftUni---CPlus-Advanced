#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> names;
vector<pair<string, string>> coords;

void printByCoords(const pair<string, string> & coord) {
    vector<pair<string, string>>::iterator itFound = find(coords.begin(), coords.end(), coord);

    while (itFound != coords.end()) {
        int idx = itFound - coords.begin();
        cout << names[idx] << "," << coords[idx].first << "," <<coords[idx].second << endl;

        itFound = find(itFound+1, coords.end(), coord);
    }
}

void printByName(const string & name) {
    vector<string>::iterator itFound = find(names.begin(), names.end(), name);
    if (itFound != names.end()) {
        int idx = itFound - names.begin();

        cout << names[idx] << "," << coords[idx].first << "," <<coords[idx].second << endl;
    }
}

int main() {
    while (true) {
        string buffer;
        getline(cin, buffer);
        if (buffer == ".") {
            break;
        }

        istringstream istr(buffer);

        string name;
        pair<string, string> coord;

        getline(istr, name, ',');
        getline(istr, coord.first, ',');
        istr >> coord.second;

        names.push_back(name);
        coords.push_back(coord);
    }

    while (true) {
        string line;
        getline(cin, line);
        if (line == ".") {
            break;
        }

        istringstream istr(line);

        if (isdigit(line[0])) {
            pair<string, string> coord;
            istr >> coord.first >> coord.second;

            printByCoords(coord);
        }
        else {
            string name;
            istr >> name;

            printByName(name);
        }
    }
}
