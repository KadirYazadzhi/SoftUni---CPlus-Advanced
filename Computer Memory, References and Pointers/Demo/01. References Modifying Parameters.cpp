#include <iostream>
#include <string>
#include <list>

using namespace std;

void swap(int& a, int& b) {
    int oldA = a;
    a = b;
    b = oldA;
}

void removeNegative(list<int>& numbers) {
    auto i = numbers.begin();

    while (i != numbers.end()) {
        if (*i < 0) {
            i = numbers.erase(i);
        }
        else {
            i++;
        }
    }
}

int main() {
    int x = 13;
    int y = 42;

    swap(x, y);
    cout << x << " " << y << endl;

    list<int> numbers{1, 62, 98, -55, -5, 93, -1};
    removeNegative(numbers);

    for (int v : numbers) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
