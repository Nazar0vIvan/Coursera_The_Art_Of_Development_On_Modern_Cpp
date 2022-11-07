#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main(){
  map<set<string>, int> buses;

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i){
    int n;
    cin >> n;
    set<string> stops;
    for (int j = 0; j < n; ++j){
      string stop;
      cin >> stop;
      stops.insert(stop);
    }
    if (buses.count(stops) == 0){
      const int newNumber = buses.size() + 1;
      buses[stops] = newNumber;
      cout << "New bus " << newNumber << endl;
    }
    else{
      cout << "Already exists for " << buses[stops] << endl;
    }
  }

  return 0;
}
