#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> Reversed(const vector<int>& input)
{
	vector<int> result;
	for (int i = input.size() - 1; i >= 0; --i) {
		result.push_back(input[i]);
	}
	return result;
}

int main() {
	vector<int> numbers = { 1, 5, 3, 4, 2 };
	vector<int> reversed_numbers = Reversed(numbers);
	for (const auto& number : reversed_numbers){
		cout << number << ", ";
	}
	return 0;
}
