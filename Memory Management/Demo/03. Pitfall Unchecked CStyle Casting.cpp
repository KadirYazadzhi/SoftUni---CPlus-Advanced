#include <iostream>

using namespace std;

int main() {
    char letter1 = 'a',
    letter2 = 'b',
    letter3 = 'c',
    letter4 = 'd';

    int* letter4Ptr = (int*) &letter1;

    *letter4Ptr = 842281524;

    cout << letter1 << letter2 << letter3 << letter4 << endl;

    return 0;
}