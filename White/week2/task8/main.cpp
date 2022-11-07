#include <iostream>
#include <vector>

using namespace std;

int main() {
	int daysCount;
	cin >> daysCount;
	vector<int> temperatures(daysCount);
	int sum = 0;
  for (int& temperature : temperatures) {
    cin >> temperature;
    sum += temperature;
  }
	
	int average = double(sum)/daysCount;
	vector<int> indices;
	for (int i = 0; i < daysCount; ++i){
		if (temperatures[i] > average){
			indices.push_back(i);
		}
	}
	
	cout << indices.size() << endl;
  for (int index : indices) {
    cout << index << " ";
  }
  cout << endl;
	
	return 0;
}
