#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> FindNamesHistory(const map<int,string>& names_by_year, int year){
  vector<string> names;
  for (const auto& item : names_by_year){
    if (item.first <= year && (names.empty() || names.back() != item.second)){
      names.push_back(item.second);
    }
  }
  return names;
}

string BuildJoinedName(vector<string> names){
  if (names.empty()){ return ""; }

  reverse(begin(names), end(names));
  string joined_name = names[0];

  for (size_t i = 1; i < names.size(); ++i){
    joined_name += i == 1 ? " (" : ", ";
    joined_name += names[i];
  }
  if (names.size() > 1){ joined_name += ")"; }

  return joined_name;
}

string BuildFullName(const string& first_name, const string& last_name){
  if (first_name.empty() && last_name.empty()){
    return "Incognito";
  }
  else if (first_name.empty()){
    return last_name + " with unknown first name";
  }
  else if (last_name.empty()){
    return first_name + " with unknown last name";
  }
  else{
    return first_name + " " + last_name;
  }
}

class Person{
public:
  void ChangeFirstName(int year, const string& first_name){
    first_names[year] = first_name;
  }

  void ChangeLastName(int year, const string& last_name){
    last_names[year] = last_name;
  }

  string GetFullName(int year){
    const vector<string> first_names_history = FindFirstNamesHistory(year);
    const vector<string> last_names_history = FindLastNamesHistory(year);

    string first_name;
    string last_name;
    if (!first_names_history.empty()){
      first_name = first_names_history.back();
    }
    if (!last_names_history.empty()){
      last_name = last_names_history.back();
    }
    return BuildFullName(first_name, last_name);
  }

  string GetFullNameWithHistory(int year){
    const string first_name = BuildJoinedName(FindFirstNamesHistory(year));
    const string last_name = BuildJoinedName(FindLastNamesHistory(year));
    return BuildFullName(first_name, last_name);
  }

private:
  vector<string> FindFirstNamesHistory(int year){
    return FindNamesHistory(first_names, year);
  }
  vector<string> FindLastNamesHistory(int year){
    return FindNamesHistory(last_names, year);
  }

  map<int, string> first_names;
  map<int, string> last_names;
};

/*
int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}
*/
