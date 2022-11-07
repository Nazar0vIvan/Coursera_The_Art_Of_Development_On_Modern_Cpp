#include <iostream>
#include <string>

using namespace std;

int main(){
  string str;
  cin >> str;
  
  int result = -2;
  
  for (int i = 0; i < s.size(); ++i){
    if (s[i] == 'f'){
  	  if (result == -2){
  	    result = -1;
  	  } 
  	  else if (result == -1){
  	    result = i;
  	    break;
  	  }
    }
  }
  
  cout << result;
  
  return 0;
}
