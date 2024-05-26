#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> nums { 61, 41, 231, 764, 45 };
    nums.sort();

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    nums.sort(std::greater<int>());
    for (int num :nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
