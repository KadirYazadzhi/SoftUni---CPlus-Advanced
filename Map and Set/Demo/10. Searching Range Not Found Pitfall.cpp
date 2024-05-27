#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> nums {61, 41, 231, 764, 45};
    auto it = find(nums.begin(), nums.begin() + 3, 45);

    if (it != nums.end()) {
        cout << "found " << *it << " at " << it - nums.begin() << endl;
    }
    else {
        cout << "not found" << endl;
    }

    return 0;
}
