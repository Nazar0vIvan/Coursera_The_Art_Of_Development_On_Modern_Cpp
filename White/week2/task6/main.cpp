#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Reverse(vector<int>& v){
  int n = v.size();
  int tmp;
  for(int i = 0; i < n/2; ++i){
    tmp = v[n-i-1];
    v[n-i-1] = v[i];
    v[i] = tmp;
  }
}

int main(){
  vector<int> numbers = { 1, 5, 4, 2 };
  Reverse(numbers);
  for (const auto& number : numbers){
    cout << number << ", ";
  }
  return 0;
}

