#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>

/* Тестирующая система варьирует функцию или класс, для который надо написать юнит-тесты. В начале main вызываются ряд методов RunTest объекта класса TestRunner.
 * Каждый метод RunTest вызывает определенный юнит-тест (AsserEqual). Если при вызове юнит-теста НЕ сработало его исключение, то RunTest выводит "OK" в поток ошибок cerr.
 * Если при вызове юнит-теста сработало его исключение, то накапливается количество fail_count.
*/

using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
  string name;

  for (const auto& item : names) {
    if (item.first <= year) {
      name = item.second;
    }
    else {
      break;
    }
  }

  return name;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_names[year] = last_name;
  }
  string GetFullName(int year) {
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);

    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    }
    else if (first_name.empty()) {
      return last_name + " with unknown first name";
    }
    if (last_name.empty()) {
      return first_name + " with unknown last name";
    }
    else {
      return first_name + " " + last_name;
    }
  }

private:
  map<int, string> first_names;
  map<int, string> last_names;
};

template <class T> // шаблонный оператор вывода для set
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V> // шаблонный оператор вывода для map
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

// проверка на равенство двух шаблонных аргументов, если не равны - вывод аргументов и hint в поток, бросание исключения runtime_error с содержимым потока
template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint)
{
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u << " hint: " << hint;
    throw runtime_error(os.str());
  }
}

// запускает AssertEqual с произвольным первым аргументом, константой true в качестве второго аргумента и hint
inline void Assert(bool b, const string& hint)
{
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template<typename TestFunc>
  void RunTest(TestFunc func, const string& test_name){
    try{
      func();
      cerr << test_name << " OK" << endl;
    }
    catch (runtime_error& e){
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    }
  }

  ~TestRunner(){
    if (fail_count > 0){
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }
private:
    int fail_count = 0;
};

// TESTS -->

void TestIncognito(){
    Person person1;
    person1.ChangeFirstName(1,"Bob");
    AssertEqual(person1.GetFullName(0),"Incognito","must be Incognito: no last name, year < first first name change");

    Person person2;
    person2.ChangeLastName(1,"Smirnov");
    AssertEqual(person2.GetFullName(0),"Incognito","must be Incognito: no first name, year < first last name change");

    Person person3;
    person3.ChangeFirstName(1,"Bob");
    person3.ChangeLastName(1,"Smirnov");
    AssertEqual(person3.GetFullName(0),"Incognito","must be Incognito: year < first first and last names change");

    Person emptyPerson;
    AssertEqual(emptyPerson.GetFullName(50),"Incognito","must be Incognito for empty person");
}

void TestNoFirstName(){
    Person person1;
    person1.ChangeLastName(1,"Harvard");
    AssertEqual(person1.GetFullName(1),"Harvard with unknown first name","must be unknow first name");
    AssertEqual(person1.GetFullName(2),"Harvard with unknown first name","must be unknow first name");

    Person person2;
    person2.ChangeFirstName(3,"Bob");
    person2.ChangeLastName(1,"Harvard");
    AssertEqual(person1.GetFullName(1),"Harvard with unknown first name","must be unknow first name");
    AssertEqual(person1.GetFullName(2),"Harvard with unknown first name","must be unknow first name");
}

void TestNoLastName(){
    Person person1;
    person1.ChangeFirstName(1,"Bob");
    AssertEqual(person1.GetFullName(1),"Bob with unknown last name","must be unknow last name");
    AssertEqual(person1.GetFullName(2),"Bob with unknown last name","must be unknow last name");

    Person person2;
    person2.ChangeFirstName(1,"Bob");
    person2.ChangeLastName(3,"Harvard");
    AssertEqual(person1.GetFullName(1),"Bob with unknown last name","must be unknow last name");
    AssertEqual(person1.GetFullName(2),"Bob with unknown last name","must be unknow last name");
}

void TestTwoNames(){
    Person person;
    person.ChangeFirstName(1,"Bob");
    person.ChangeLastName(1,"Harvard");
    AssertEqual(person.GetFullName(1),"Bob Harvard","must be two names");
    AssertEqual(person.GetFullName(2),"Bob Harvard","must be two names");

    person.ChangeFirstName(5,"Harry");

    AssertEqual(person.GetFullName(5),"Harry Harvard","must be two names");
    AssertEqual(person.GetFullName(6),"Harry Harvard","must be two names");

    person.ChangeLastName(15,"Boomer");
    AssertEqual(person.GetFullName(15),"Harry Boomer","must be two names");
    AssertEqual(person.GetFullName(16),"Harry Boomer","must be two names");

    person.ChangeFirstName(0,"Larry");
    person.ChangeLastName(0,"King");
    AssertEqual(person.GetFullName(0),"Larry King","must be two names");
}

// <-- TESTS

int main()
{
    TestRunner runner;
    runner.RunTest(TestIncognito,"TestIncognito");
    runner.RunTest(TestNoFirstName,"TestNoFirstName");
    runner.RunTest(TestNoLastName,"TestNoLastName");
    runner.RunTest(TestTwoNames,"TestTwoNames");
    return 0;
}
