#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> temperatures(n);
  int64_t sum = 0;
  
  for (int& temperature : temperatures) {
    cin >> temperature;
    sum += temperature;
  }

  int average = sum / n;

  vector<int> seek_indices;
  for (int i = 0; i < n; ++i) {
    if (temperatures[i] > average) {
      seek_indices.push_back(i);
    }
  }

  cout << seek_indices.size() << endl;
  for (int i : seek_indices) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
