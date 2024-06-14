#include <iostream>
#include <vector>
#include <iostream>

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

vector<Person*>* getPeople() {
    vector<Person*>* people = new vector<Person*>();

    people->push_back(new Person("Ben Doven", 42));
    people->push_back(new Person("Ary Usure", 25));

    return people;
}

int main() {
    auto people = getPeople();

    cout << people->at(0)->getName() << endl;

    delete people;

    return 0;
}