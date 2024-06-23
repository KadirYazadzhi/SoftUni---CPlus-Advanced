#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    vector<pair<string, int>> stations;
    string line;

    while (getline(cin, line) && line != "end") {
        istringstream iss(line);
        string station;
        int demand;
        iss >> station >> demand;
        stations.push_back({station, demand});
    }

    vector<int> pallets;
    if (getline(cin, line)) {
        istringstream iss(line);
        int quantity;
        while (iss >> quantity) {
            pallets.push_back(quantity);
        }
    }

    int remainingPacks = 0;
    for (auto& pallet : pallets) {
        remainingPacks += pallet;
    }

    for (const auto& station : stations) {
        string stationName = station.first;
        int demand = station.second;

        cout << stationName;
        bool first = true;

        while (demand > 0 && !pallets.empty()) {
            int palletIndex = pallets.size() - 1;
            int& pallet = pallets.back();

            int toDeliver = min(demand, pallet);
            if (first) {
                cout << " ";
                first = false;
            } else {
                cout << " ";
            }
            cout << palletIndex << ":" << toDeliver;

            demand -= toDeliver;
            pallet -= toDeliver;
            remainingPacks -= toDeliver;

            if (pallet == 0) {
                pallets.pop_back();
            }

            if (demand > 0 && pallets.empty()) {
                cout << " Out of Stock!" << endl;
                cout << "Incomplete: " << demand << endl;
                return 0;
            }
        }
        cout << endl;
    }

    if (remainingPacks > 0) {
        cout << "Remaining packs: " << remainingPacks << endl;
    }

    return 0;
}