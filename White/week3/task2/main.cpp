#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> words;
  for (string& s : words){
    cin >> s;
  }

  sort(begin(words),end(words), [](const string& a, const string& b){
    return lexicographical_compare(
             begin(a), end(a),
             begin(b), end(b),
             [](char ca, char cb){ return tolower(ca) < tolower(cb); }
           );
    }
  );

  for (const string& word : words){
      cout << word << " ";
  }

  return 0;
}
