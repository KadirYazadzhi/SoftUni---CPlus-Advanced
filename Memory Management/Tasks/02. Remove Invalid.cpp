#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

int main(){
    string line;
    getline(cin, line);
    int num;
    string word;

    list<int> numbers;
    list<string> words;

    bool isValid = true;
    while (line != "end") {
        istringstream istr(line);

        istr >> num;
        if (num < 0) {
            isValid = false;
        }

        istr >> word;

        if (isValid) {
            numbers.push_back(num);
            words.push_back(word);
        }

        isValid = true;
        getline(cin, line);
    }

    while (!numbers.empty() && !words.empty()) {
        cout << numbers.front() << " " << words.front() << endl;

        numbers.pop_front();
        words.pop_front();
    }

}