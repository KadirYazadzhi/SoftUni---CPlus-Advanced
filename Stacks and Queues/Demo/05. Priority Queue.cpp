#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pQueue;
    pQueue.push(13);
    pQueue.push(69);
    pQueue.push(42);

    while(!pQueue.empty()) {
        cout << pQueue.top() << endl;
        pQueue.pop();
    }

    cout << "==========================" << endl;

    priority_queue<int, deque<int>, greater<int>> reversedQueue;
    reversedQueue.push(13);
    reversedQueue.push(69);
    reversedQueue.push(42);

    while (!reversedQueue.empty()) {
        cout << reversedQueue.top() << endl;
        reversedQueue.pop();
    }

    return 0;
}
