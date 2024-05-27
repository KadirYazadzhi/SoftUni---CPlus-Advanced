#include <iostream>
#include <map>
#include <string>
#include <vector>


using namespace std;

int main(void) {
    cout.setf(ios::fixed);
    cout.precision(2);

    map<string, vector<double>> data;

    int records;
    cin >> records;

    while(records--) {
        string name;
        cin >> name;
        double grade;
        cin >> grade;

        data[name].push_back(grade);
    }

    for (map<string, vector<double>>::iterator itB = data.begin(); itB != data.end(); itB++) {
        cout << itB->first << " -> ";

        vector<double> & vec = itB->second;
        double average = 0;

        for (double d : vec) {
            average += d;
            cout << d << " ";
        }

        cout << "(avg: " << average / vec.size() << ")" << endl;
    }

    return 0;
}
