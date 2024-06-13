#include <iostream>
#include <string>

using namespace std;

class Person {
    string name;
    int age;
public:
    Person(string name, int age) : name(name), age(age) {}

    string getName() {
        return this->name;
    }
};

int main() {
    int sizeVariable;
    cin >> sizeVariable;
    int* intArr = new int[sizeVariable] {42, 13, 255};

    for (int i = 0; i < 3; i++) {
        cout << intArr[i] << " ";
    }
    cout << endl;

    Person* personPtr = new Person("John", 20);

    cout << personPtr->getName() << endl;

    return 0;
}
