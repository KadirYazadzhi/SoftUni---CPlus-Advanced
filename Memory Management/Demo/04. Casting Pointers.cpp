#include <iostream>
#include <string>

using namespace std;

int main() {
    char letter = 'A';

    void* voidPtr = &letter;
    char* charPtr = &letter;

    char* cStyleCastPtr = (char*) voidPtr;
    int* badCast = (int*) charPtr;

    cout << *cStyleCastPtr << endl;
    cout << *badCast << endl;

    char* staticCastPtr = static_cast<char*> (voidPtr);

    return 0;
}