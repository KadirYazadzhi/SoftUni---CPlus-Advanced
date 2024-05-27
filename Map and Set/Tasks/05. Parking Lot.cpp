#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
    set<string> parkingLot;

    while (1) {
        string row;
        getline(cin, row);
        if (row == "END") {
            break;
        }

        istringstream istr(row);

        string cmd;
        string number;

        istr >> cmd >> number;

        if (cmd == "IN,") {
            parkingLot.insert(number);
        }
        else {
            parkingLot.erase(number);
        }
    }

    if (parkingLot.empty()) {
        cout << "Parking Lot is Empty" << endl;
    }
    else {
        for (string reg : parkingLot) {
            cout << reg << endl;
        }
    }

    return 0;
}
