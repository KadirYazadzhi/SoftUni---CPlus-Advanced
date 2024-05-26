#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main() {
    map<string, vector<int>> studentGrades;

    int numStudents;
    cout << "Enter students count: ";
    cin >> numStudents;
    cin.ignore();

    for (int i = 0; i < numStudents; i++) {
        string line;
        getline(cin, line);

        istringstream  lineIn(line);
        string name;
        lineIn >> name;

        vector<int> grades;
        int grade;
        while (lineIn >> grade) {
            grades.push_back(grade);
        }

        studentGrades[name] = grades;
    }

    string command;
    getline(cin, command);
    while (command != "end") {
        cout << endl;
        map<string, vector<int>>::iterator gradesIt =
                studentGrades.find(command);

        if (gradesIt != studentGrades.end()) {
            for (int grade : gradesIt->second) {
                cout << grade << " ";
            }
        }
        else {
            cout << "no info";
        }
        getline(cin, command);
    }
    cout << endl;

    return 0;
}
