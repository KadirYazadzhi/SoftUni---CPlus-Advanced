#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <climits>

using namespace std;

void printOrders(int orderLeft, queue<int> orders) {
    if (orderLeft == -1) {
        cout << "Orders complete" << endl;
    } else {
        cout << "Orders left:";
        while (!orders.empty()) {
            cout << " " << orders.front();
            orders.pop();
        }
        cout << endl;
    }
}
int main() {
    int order;
    cin >> order;
    cin.ignore();

    queue<int> orders;

    string numberOrders;
    getline(cin, numberOrders);
    istringstream numbers(numberOrders);

    int ord;
    int maxOrder = INT_MIN;

    while (numbers >> ord) {
        orders.push(ord);
        if (ord > maxOrder) {
            maxOrder = ord;
        }
    }

    int orderLeft = -1;

    while (!orders.empty()) {
        int currentOrder = orders.front();

        if (order >= currentOrder) {
            order -= currentOrder;
            orders.pop();
        } else {
            orderLeft = currentOrder;
            break;
        }
    }

    cout << maxOrder << endl;

    printOrders(orderLeft, orders);
}

