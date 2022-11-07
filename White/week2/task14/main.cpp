#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
  map<vector<string>, int> buses;

  int q;
  cin >> q;

  for(int i = 0; i < q; ++i){
    int n;
    cin >> n;
    vector<string> stops(n);
    for (string& stop : stops){
      cin >> stop;
    }
    if(buses.count(stops) == 0){
      const int new_number = buses.size() + 1;
      buses[stops] = new_number;
      cout << "New bus " << new_number << endl;

    }
    else{
      cout << "Already exists for " << buses[stops] << endl;
    }
  }

  return 0;
}
