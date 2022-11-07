#include <iostream>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination){
	for (const auto& word : source){
		destination.push_back(word);
  }
  source.clear();
}

int main(){
  vector<string> source = {"a", "b", "c"};
  vector<string> destination = {"z"};
  MoveStrings(source, destination);
  
	for (const auto& word : destination){
      cout << word << ", ";
  }
	
  return 0;
}
