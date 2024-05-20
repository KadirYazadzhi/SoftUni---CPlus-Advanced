#include <iostream>
#include <queue>


using namespace std;

bool checkSuccessFullCircle(queue<int> fuelInCurrent, queue<int> distanceToNext) {
    int fuel = 0;

    while (fuelInCurrent.size()) {
        int curFuel = fuelInCurrent.front();
        fuel += curFuel;

        if (fuel >= distanceToNext.front()) {
            fuel -= distanceToNext.front();
        }
        else {
            break;
        }

        fuelInCurrent.pop();
        distanceToNext.pop();
    }
    return fuelInCurrent.empty();
}


int main() {
    queue<int> fuelInCurrent;
    queue<int> distanceToNext;

    int N;
    cin >> N;

    while (N--) {
     int tmp;
     cin >> tmp;
     fuelInCurrent.push(tmp);

     cin >> tmp;
     distanceToNext.push(tmp);
    }

    N = 0;
    while (N <= fuelInCurrent.size()) {
        if (checkSuccessFullCircle(fuelInCurrent, distanceToNext)) {
            break;
        }
        N++;
        fuelInCurrent.push(fuelInCurrent.front());
        fuelInCurrent.pop();

        distanceToNext.push(distanceToNext.front());
        distanceToNext.pop();
    }

    cout << N << endl;

    return 0;
}

