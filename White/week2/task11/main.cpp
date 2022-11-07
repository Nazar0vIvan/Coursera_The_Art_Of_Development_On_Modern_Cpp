#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& word){
  map<char, int> counter;
  for (char c : word){
    ++counter[c];
  }
  return counter;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i){
    string word1, word2;
    cin >> word1 >> word2;
    if(BuildCharCounters(word1) == BuildCharCounters(word2)){
      cout << "YES" << endl;
    } 
		else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
