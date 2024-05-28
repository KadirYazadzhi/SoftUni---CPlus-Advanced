#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string data;
    getline(cin, data);

    istringstream istr(data);

    vector<int> numbers;

    int num;
    while (istr >> num) {
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end(), greater<int>());

    for (auto n : numbers) {
        int sq = sqrt(n);
        if (sq * sq == n) {
            cout << n << " ";
        }
    }
}