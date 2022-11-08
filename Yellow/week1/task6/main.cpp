#include <iostream>
#include <utility>
#include <vector>
#include <map>

using namespace std;

// int, double
template <typename T>
T Sqr(const T& x);

// vector
template<typename T>
vector<T> Sqr(const vector<T>& v);

// map
template<typename Key, typename Value>
map<Key,Value> Sqr(const map<Key,Value>& m);

// pair
template<typename First, typename Second>
pair<First,Second> Sqr(const pair<First,Second>& p);

template <typename T>
T Sqr(const T& x) {
  return x*x;
}

template<typename T>
vector<T> Sqr(const vector<T>& v){
  vector<T> res;
  for(const T& x : v){
    res.push_back(Sqr(x));
  }
  return res;
}

template<typename Key, typename Value>
map<Key,Value> Sqr(const map<Key,Value>& m){
  map<Key,Value> res;
  for(const pair<Key,Value>& item : m){
    res[item.first] = Sqr(item.second);
  }
  return res;
}

template<typename First, typename Second>
pair<First,Second> Sqr(const pair<First,Second>& p){
  return make_pair(Sqr(p.first),Sqr(p.second));
}


int main()
{
  vector<int> v = { 1, 2, 3 };
  cout << "vector:";
  for (int x : Sqr(v)) {
    cout << ' ' << x;
  }
  cout << endl;

  map<int, pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
  };
  cout << "map of pairs:" << endl;
  for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
  }

  return 0;
}
