#include <iostream>

using namespace std;

int Factorial(int number){
	int f = 1;
	for (int i = 2; i <= number; ++i){
		f *= i;
	}
	return f;
}

int main(){
	int n;
	cin >> n;
    
	if(n < 0){
		cout << 1;
  else{
		cout << Factorial(n) << endl;
  }
	
	return 0;
}
