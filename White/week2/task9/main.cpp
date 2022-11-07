#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int q;
    cin >> q;
    vector<int> worried;
		
    for (int i = 0; i < q; ++i){
			string operation_code;
			cin >> operation_code;
			if (operation_code == "WORRY_COUNT"s){
				cout << count(begin(worried), end(worried), true) << endl;
			}
			else if (operation_code == "WORRY" || operation_code == "QUIET"){
				int index;
				cin >> index;
				worried[index] = (operation_code == "WORRY");
			}
			else if (operation_code == "COME"){
				int count;
				cin >> count;
				worried.resize(worried.size() + count, false);
			}
    }
}
