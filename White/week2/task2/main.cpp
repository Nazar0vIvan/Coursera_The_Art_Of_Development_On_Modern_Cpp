#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool IsPalindrom(string str){
	int n = str.size();
	
  for (int i = 0; i < n/2; ++i) {
		if (str[i] != str[n-i-1]) {
			return false;
    }
  }
	return true;
}

int main() {
  string request;
  cin >> request;
  cout << IsPalindrom(request) << endl;
	
  return 0;
}
