#include <string>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class Person {
    string name;
    int age;
public:
    Person(string name, int age) : name(name), age(age) {}

    string getName() {
        return this->name;
    }

    int getAge() {
        return this->age;
    }
};

vector<Person*>* getPeople() {
    vector<Person*>* people = new vector<Person*>();

    people->push_back(new Person("Ben Doven", 42));
    people->push_back(new Person("Ary O'usure", 25));

    return people;
}

shared_ptr<Person> getOld(shared_ptr<Person> a, shared_ptr<Person> b) {
    if (a->getAge() > b->getAge()) {
        return a;
    }

    return b;
}

void printPerson(shared_ptr<Person> p) {
    cout << p->getName() << " " << p->getAge() << endl;
}

int main() {
    shared_ptr<Person> longerCopy;

    {
        shared_ptr<Person> person = make_shared<Person>("James", 23);
        shared_ptr<Person> copy = person;
        longerCopy = person;
    }

    cout << longerCopy->getName() << endl;

    vector<shared_ptr<Person>> people {
        shared_ptr<Person> (new Person("Youn Ger", 25)),
        make_shared<Person>("Ben Dover", 42)
    };

    printPerson(getOld(people[0], people[1]));

    return 0;
}
