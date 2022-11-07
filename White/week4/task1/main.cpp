#include <iostream>
#include <string>

using namespace std;

struct Specialization{
  explicit Specialization(const string& new_data) : data(new_data){}
  string data;
};

struct Course{
  explicit Course(const string& new_data) : data(new_data){}
  string data;
};

struct Week{
  explicit Week(const string& new_data) : data(new_data){}
  string data;
};

struct LectureTitle {
  LectureTitle(const Specialization& new_specialization, const Course& new_course, const Week& new_week)
    : specialization(new_specialization.data), course(new_course.data), week(new_week.data){}
  string specialization;
  string course;
  string week;
};

/*
int main()
{
    LectureTitle title1("C++", "White belt", "4th");

    LectureTitle title2(string("C++"), string("White belt"), string("4th"));

    LectureTitle title3 = {"C++", "White belt", "4th"};

    LectureTitle title4 = {{"C++"}, {"White belt"}, {"4th"}};

    LectureTitle title5(
        Course("White belt"),
        Specialization("C++"),
        Week("4th")
    );

    LectureTitle title6(
        Specialization("C++"),
        Week("4th"),
        Course("White belt")
    );

    return 0;
}
*/
