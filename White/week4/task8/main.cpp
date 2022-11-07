#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student{
  string first_name;
  string last_name;
  int day;
  int month;
  int year;
};

int main(){
  int n;
  cin >> n;

  vector<Student> students;

  for (int i = 0; i < n; ++i){
    Student student;
    cin >> student.first_name;
    cin >> student.last_name;
    cin >> student.day;
    cin >> student.month;
    cin >> student.year;
    students.push_back(student);
  }

  int m;
  cin >> m;
  string query;
  int student_number;

  for(int i = 0; i < m; ++i){
    cin >> query >> student_number;
    --student_number;

    if (query == "name" && student_number >= 0 && student_number < n) {
      cout << students[student_number].first_name << " "
           << students[student_number].last_name << endl;
    }
    else if(query == "date" && student_number >= 0 && student_number < n) {
      cout << students[student_number].day << "."
           << students[student_number].month << "."
           << students[student_number].year << endl;
    }
    else{
      cout << "bad request" << endl;
    }
  }

  return 0;
}
