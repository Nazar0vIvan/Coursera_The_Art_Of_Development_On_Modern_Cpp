#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <exception>
#include <iomanip>
#include <algorithm>

using namespace std;

class Date{
public:
  Date(int y, int m, int d){
    year = y;
    if (m > 12 || m < 1){
      throw logic_error("Month value is invalid: " + to_string(m));
    }
    month = m;
    if (d > 31 || d < 1){
      throw logic_error("Day value is invalid: " + to_string(d));
    }
    day = d;
  }
  int GetYear()  const{ return year;  }
  int GetMonth() const{ return month; }
  int GetDay()   const{ return day;   }

private:
  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs){
  if(lhs.GetYear() != rhs.GetYear()){
      return lhs.GetYear() < rhs.GetYear();
  }
  else if (lhs.GetMonth() != rhs.GetMonth()){
      return lhs.GetMonth() < rhs.GetMonth();
  }
  else{
      return lhs.GetDay() < rhs.GetDay();
  }
}

ostream& operator << (ostream& stream, const Date& date)
{
  stream << setfill('0') << setw(4) << date.GetYear();
  stream << "-";
  stream << setfill('0') << setw(2) << date.GetMonth();
  stream << "-";
  stream << setfill('0') << setw(2) << date.GetDay();
  return stream;
}

class Database{
public:
  void AddEvent(const Date& date, const string& event){
    dateToEvents[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event){
    if(dateToEvents.count(date) && dateToEvents[date].count(event)){
      dateToEvents[date].erase(event);
      return true;
    }
    return false;
  }

  int DeleteDate(const Date& date){
    if(!dateToEvents.count(date)){
      return 0;
    }
    else{
      const int eventsCount = dateToEvents[date].size();
      dateToEvents.erase(date);
      return eventsCount;
    }
  }

  set<string> Find(const Date& date) const{
    if(dateToEvents.count(date)){
      return dateToEvents.at(date);
    }
    return{};
  }

  void Print() const{
    for (const auto& item : dateToEvents){
      for (const string& event : item.second){
        cout << item.first << " " << event << endl;
      }
    }
  }

private:
  map<Date,set<string>> dateToEvents;
};

Date ParseDate(const string& date){
  istringstream dateStream(date);
  bool ok = true;

  int year;
  ok = ok && (dateStream >> year);
  ok = ok && (dateStream.peek() == '-');
  dateStream.ignore(1);

  int month;
  ok = ok && (dateStream >> month);
  ok = ok && (dateStream.peek() == '-');
  dateStream.ignore(1);

  int day;
  ok = ok && (dateStream >> day);
  ok = ok && dateStream.eof();

  if (!ok){
    throw logic_error("Wrong date format: " + date);
  }
  return Date(year, month, day);
}

int main(){
  try{
    Database db;
    string command;

    while (getline(cin, command)){
      stringstream ss(command);
      string command; ss >> command;
      // ADD
      if (command == "Add"){
        string dateStr, event; ss >> dateStr >> event;
        const Date date = ParseDate(dateStr);
        db.AddEvent(date, event);
      }
      // DEL
      else if(command == "Del"){
        string dateStr; ss >> dateStr;
        string event;
        if (!ss.eof()){ ss >> event; }
        const Date date = ParseDate(dateStr);
        if (event.empty()){
          const int count = db.DeleteDate(date);
          cout << "Deleted " << count << " events" << endl;
        }
        else{
          if (db.DeleteEvent(date, event)){
            cout << "Deleted successfully" << endl;
          }
          else{
            cout << "Event not found" << endl;
          }
        }
      }
      // FIND
      else if (command == "Find"){
        string dateStr;
        ss >> dateStr;
        const Date date = ParseDate(dateStr);
        for (const string& event : db.Find(date)){
          cout << event << endl;
        }
      }
      // PRINT
      else if (command == "Print"){
        db.Print();
      }
      else if (!command.empty()){
        throw logic_error("Unknown command: " + command);
      }
    }
  }
  catch (const exception& e){
    cout << e.what() << endl;
  }

  return 0;
}

