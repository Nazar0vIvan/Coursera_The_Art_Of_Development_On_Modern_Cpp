#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
  set<string> unique_strings;

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i){
    string str;
    cin >> str;
    unique_strings.insert(str);
  }
  cout << unique_strings.size() << endl;

  return 0;
}
