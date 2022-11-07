#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double a, b, c;
	cin >> a >> b >> c;

	double D = b*b - 4*a*c;

	if (a == 0){
		if (b != 0){
			cout << -c/b << endl;
		}
	}
	else if (D == 0){
		cout << -b/(2*a) << endl;
	}
	else if (D > 0){
		double r1 = (-b + sqrt(D)) / (2*a);
		double r2 = (-b - sqrt(D)) / (2*a);
		cout << r1 << " " << r2 << endl;
	}
	
	return 0;
}
