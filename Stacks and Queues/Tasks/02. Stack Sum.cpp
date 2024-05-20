#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

int main() {
  stack<int> numbers;

  string line;
  getline(cin, line);

  istringstream istr(line);
  int curNum;
  while (istr >> curNum) {
      numbers.push(curNum);
  }

  while (true) {
      getline(cin,line);
      if (line == "end") {
          break;
      }

      istringstream istr(line);

      string command;
      istr >> command;

      if (command == "add") {
          int n1, n2;
          istr >> n1 >> n2;
          numbers.push(n1);
          numbers.push(n2);
      }
      else if (command == "remove") {
          int n;
          istr >> n;

          if (n <= numbers.size()) {
              while(n--) {
                  numbers.pop();
              }
          }
      }
  }

  int sum = 0;
  while (!numbers.empty()) {
      sum += numbers.top();
      numbers.pop();
  }

  cout << sum << endl;
}