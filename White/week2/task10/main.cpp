#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main(){

  const vector<int> MONTH_LENGTHS = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  const int MONTH_COUNT = MONTH_LENGTHS.size();

  int q;
  cin >> q;

  int month = 0;
  vector<vector<string>> days_tasks(MONTH_LENGTHS[month]);

  for (int i = 0; i < q; ++i){
    string operation_code;
    cin >> operation_code;

    if (operation_code == "ADD"){
      int day; string task;
      cin >> day >> task;
      --day;
      days_tasks[day].push_back(task);
    }
    else if(operation_code == "NEXT"){
      const int oldMonthLength = MONTH_LENGTHS[month];
      month = (month + 1) % MONTH_COUNT;
      const int newMonthLength = MONTH_LENGTHS[month];
      if (newMonthLength < oldMonthLength) {
          vector<string>& lastDayTasks = days_tasks[newMonthLength - 1];
          for(int day = newMonthLength; day < oldMonthLength; ++day) {
            lastDayTasks.insert(end(lastDayTasks),begin(days_tasks[day]), end(days_tasks[day]));
          }
      }
      days_tasks.resize(newMonthLength);
    }
    else if(operation_code == "DUMP"){
      int day;
      cin >> day;
      --day;
      cout << days_tasks[day].size() << " ";
      for (const string& task : days_tasks[day]) {
        cout << task << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
