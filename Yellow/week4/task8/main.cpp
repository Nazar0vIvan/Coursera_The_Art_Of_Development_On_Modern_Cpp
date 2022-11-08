#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
  int size = distance(range_begin,range_end);
  if(size < 2){
    return;
  }
  else{
    auto range_one_thirds = next(range_begin,size/3);
    auto range_two_thirds = next(range_one_thirds,size/3);
    vector<typename RandomIt::value_type> v1(range_begin,range_one_thirds);
    vector<typename RandomIt::value_type> v2(range_one_thirds,range_two_thirds);
    vector<typename RandomIt::value_type> v3(range_two_thirds,range_end);
    MergeSort(v1.begin(),v1.end());
    MergeSort(v2.begin(),v2.end());
    MergeSort(v3.begin(),v3.end());
    vector<typename RandomIt::value_type> tmp;
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(tmp));
    merge(tmp.begin(),tmp.end(),v3.begin(),v3.end(),range_begin);
  }
}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
