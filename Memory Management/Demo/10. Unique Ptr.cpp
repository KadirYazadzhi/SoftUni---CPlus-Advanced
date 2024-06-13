#include <iostream>
#include <string>
#include <memory>
#include <vector>

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

unique_ptr<Person> getPerson() {
    Person* person = new Person("Ben Dover", 42);
    unique_ptr<Person> p;
    p.reset(person);

    return p;
}

int main() {
    unique_ptr<Person> personPtr(new Person("John", 20));

    cout << personPtr->getName() << endl;

    cout << getPerson()->getName() << endl;

    return 0;
}
