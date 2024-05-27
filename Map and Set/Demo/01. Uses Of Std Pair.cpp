#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main() {
    pair<string, string> contact("Zhivko", "not-telling-you@gmail.com");
    cout << contact.first << ", email: " << contact.second << endl;

    contact.first = "Zhivko Petrov";
    contact.second = "still-not-telling-you@gmail.com";

    cout << contact.first << ", email: " << contact.second << endl;
    cout << endl;

    pair<string, pair<double, double> > location {
        "Great Pyramid of Gyza",
        pair<double, double>{29.9792345, 31.1342019}
    };

    cout << location.first
        << "GPS coords: "
        << location.second.first << ", " << location.second.second << endl;

    cout << endl;

    pair<int, string> integerName(42, "forty-two");
    integerName.second =  "Answer to the Ultimate Question of Life, the Universe, and Everything";

    cout << integerName.first << " is " << integerName.second << endl;

    return 0;
}
