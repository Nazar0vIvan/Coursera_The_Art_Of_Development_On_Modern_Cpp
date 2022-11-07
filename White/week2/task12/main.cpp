#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void printDump(const vector<string>& m){
  for (const auto& str : m){
    cout << str << endl;
  }
}

string createMessage(map<string,string>& m, const string str1, const int commandCode = 0, string str2 = ""){
  switch (commandCode){
    case 0: { // CHANGE_CAPITAL: str1 - country, str2 - new_capital
      // if no such country str1 in the map
      if (!m.count(str1)){
        return "Introduce new country " + str1 + " with capital " + str2;}
      // if old_capital == new_capital
      else if (m.at(str1) == str2){
        return "Country " + str1 + " hasn't changed its capital";}
      // if old_capital != new_capital
      else{
        return "Country " + str1 + " has changed its capital from " + m.at(str1) + " to " + str2;}
    }
    case 1: { // RENAME: str1 - old_country_name, str2 - new_country_name
      if (str1 == str2 || !m.count(str1) || m.count(str2)){
        return "Incorrect rename, skip";}
      else {
        string str3 = m.at(str1);
        m[str2] = m[str1];
        m.erase(str1);
        return "Country " + str1 + " with capital " + str3 + " has been renamed to " + str2;
      }
    }
    case 2: { // ABOUT: str1 - country _name
      return !m.count(str1) ? "Country " + str1 + " doesn't exist" : "Country " + str1 + " has capital " + m.at(str1);
    }
    case 3: { // DUMP
      if (!m.size()){
        return "There are no countries in the world";
      }
      else{
        string list;
        for (const auto& item : m){
          list += item.first + "/" + item.second + " ";
        }
        return list;
      }
    }
    default: {
      return "";
    }
  }
}

int main() {

  int q;
  cin >> q;

  string commandCode;
  map<string,string> countryToCapital;
  vector<string> dump;
  string str1, str2;

  for (int i = 0; i < q; ++i) {
    cin >> commandCode;
    if (commandCode == "CHANGE_CAPITAL"){
      cin >> str1; // country
      cin >> str2; // new_capital
      dump.push_back(createMessage(countryToCapital, str1, 0, str2));
      countryToCapital[str1] = str2;
    }
    else if (commandCode == "RENAME"){
      cin >> str1; // old_country_name
      cin >> str2; // new_country_name
      dump.push_back(createMessage(countryToCapital, str1, 1, str2));
    }
    else if (commandCode == "ABOUT"){
      cin >> str1; // country
      dump.push_back(createMessage(countryToCapital, str1, 2, str2));
    }
    else{ // DUMP
      dump.push_back(createMessage(countryToCapital, str1, 3, str2));
    }
  }

  printDump(dump);

  return 0;
}
