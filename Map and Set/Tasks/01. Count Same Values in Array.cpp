#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(void) {
   map<double, unsigned> occurrences;
   vector<double> order;

   string buff;
   getline(cin, buff);
   istringstream istr(buff);

   double curr;
   while (istr >> curr) {
       if (occurrences.find(curr) == occurrences.end()) {
           order.push_back(curr);
       }
       occurrences[curr]++;
   }

   for (double val : order) {
       cout << val << " - " << occurrences[val] << " times" << endl;
   }

    return 0;
}
