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

template <class K, class V> // // шаблонный оператор вывода для map
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

template<class T, class U> // проверка на равенство двух шаблонных аргументов, если не равны - вывод аргументов и hint в поток, бросание исключения runtime_error с содержимым потока
void AssertEqual(const T& t, const U& u, const string& hint)
{
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u << " hint: " << hint;
    throw runtime_error(os.str());
  }
}

inline void Assert(bool b, const string& hint) // запускает AssertEqual с произвольным первым аргументом, константой true в качестве второго аргумента и hint
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

bool IsPalindrom(string s) {
  for (size_t i = 0; i < s.size() / 2; ++i) {
    if (s[i] != s[s.size()-i-1]) {
        return false;
    }
  }
  return true;
}

void TestIsPalindrom(){
  string empty = "";
  Assert(IsPalindrom(empty), "// is a palindrom");

  string oneChar = "a";
  Assert(IsPalindrom(oneChar), "/a/ is a palindrom");

  string withSpaces = " aba aba ";
  Assert(IsPalindrom(withSpaces), "/ aba aba / is a palindrom");

  string manyPalindroms = "aba aba aba aba";
  Assert(IsPalindrom(manyPalindroms), "/aba aba aba aba/ is a palindrom");

  string digits = "777777";
  Assert(IsPalindrom(digits), "/777777/ is a palindrom");

  string str1 = "madams";
  AssertEqual(IsPalindrom(str1), false, "/madams/ - wrong");

  string str2 = "smadam";
  AssertEqual(IsPalindrom(str2), false, "/smadam/ - wrong");

  string str3 = "madam   ";
  AssertEqual(IsPalindrom(str3), false, "/madam   / - wrong");

  string str4 = "   madam";
  AssertEqual(IsPalindrom(str4), false, "/   madam/ - wrong");

  string str5 = "abaabA";
  AssertEqual(IsPalindrom(str5), false, "/abaabA/ -  wrong");

  string str6 = "Bba abb";
  AssertEqual(IsPalindrom(str6), false, "/Bba abb/ - wrong");

  string str7 = "s a d a m";
  AssertEqual(IsPalindrom(str7), false, "/s a d a m/ - wrong");

  string str8 = "a b  a";
  AssertEqual(IsPalindrom(str8), false, "/a b  a/ - wrong");

  string str9 = "ab";
  AssertEqual(IsPalindrom(str9), false, "/ab/ - wrong");

  string str10 = "Aa";
  AssertEqual(IsPalindrom(str10), false, "/Aa/ - wrong");

  string str11 = "aA";
  AssertEqual(IsPalindrom(str11), false, "/aA/ - wrong");

}

int main() {
  TestRunner runner;
  runner.RunTest(TestIsPalindrom,"TestIsPalindrom");

  return 0;
}
