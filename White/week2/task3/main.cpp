#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool IsPalindrom(string str){
	int n = str.size();
	
  for (int i = 0; i < n/2; ++i){
		if (str[i] != str[n-i-1]){
			return false;
    }
  }
	
	return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
  vector<string> filteredWords;
	
  for (const auto& word : words){
		if (IsPalindrom(word) && word.size() >= minLength){
      filteredWords.push_back(word);
    }
  }
  
	return filteredWords;
}

vector<string> stringToWords(string str){
	vector<string> words;
  string word;
		
  for(const auto& letter : str){
		if (letter != ' '){
			word+=letter;
    }
    else{
			words.push_back(word);
      word = "";
    }
  }
  words.push_back(word);
		
  return words;
}

int main() {
  string request;
  int minLength;
  getline(cin,request);
  cin >> minLength;
	
  vector<string> result = PalindromFilter(stringToWords(request),minLength);
	
  for (const auto& word : result){
    cout << word << ", ";
  }
	
  return 0;
}
