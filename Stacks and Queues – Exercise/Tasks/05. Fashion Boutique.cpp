#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

int main() {
    stack<int> box;
    string buf;
    getline(cin, buf);
    istringstream istr(buf);


    int tmp;
    while (istr >> tmp) {
        box.push(tmp);
    }

    int rackCapacity;
    cin >> rackCapacity;

    int racks = 1;
    int currRackCapacity = rackCapacity;

    while (!box.empty()) {
        tmp = box.top();
        box.pop();

        if (tmp <= currRackCapacity) {
            currRackCapacity -= tmp;
        }
        else {
            racks++;
            currRackCapacity = rackCapacity;
            currRackCapacity -= tmp;
        }
    }

    cout << racks << endl;
}
