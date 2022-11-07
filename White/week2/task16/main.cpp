#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> mapValues;
    for (const auto& item : m){
        mapValues.insert(item.second);
    }
    return mapValues;
}

/*
int main() {
    set<string> mapValues = BuildMapValuesSet({
        {1, "odd"},
        {2, "even"},
        {3, "odd"},
        {4, "even"},
        {5, "odd"}
    });
    for (const string& value : mapValues) {
      cout << value << endl;
    }
    return 0;
}
*/
