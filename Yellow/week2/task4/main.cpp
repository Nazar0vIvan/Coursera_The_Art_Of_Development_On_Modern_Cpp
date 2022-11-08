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

int gcd(int a, int b) { return !b ? a : gcd(b, a % b) ; }

class Rational {
public:
  Rational(){
      m_numerator = 0;
      m_denominator = 1;
  };

  Rational(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator){
    const int c = gcd(numerator, denominator);
    m_numerator = numerator / c;
    m_denominator = denominator / c;
    if(m_denominator < 0) {
      m_denominator = -m_denominator;
      m_numerator = -m_numerator;
    }
  }

  int Numerator() const { return m_numerator; }
  int Denominator() const { return m_denominator; }

  Rational operator+(const Rational& rhs){
    return Rational(m_numerator*rhs.Denominator()+m_denominator*rhs.Numerator(),m_denominator*rhs.Denominator());
  }

  Rational operator-(const Rational& rhs){
    return Rational(m_numerator*rhs.Denominator()-m_denominator*rhs.Numerator(),m_denominator*rhs.Denominator());
  }

  friend ostream& operator<<(ostream& out, const Rational& rhs){
    out << rhs.Numerator() << "/" << rhs.Denominator();
    return out;
  }

  friend istream& operator>>(istream& in, Rational& rhs){
    int n;
    in >> n;
    if (in){
      char c;
      in >> c;
      if (c == '/'){
        int d;
        in >> d;
        if (in){
          int c = gcd(abs(n),abs(d));
          rhs.m_numerator = n/c;
          rhs.m_denominator = d/c;
          return in;
        }
      }
    }
    return in;
  }

private:
  int m_numerator;
  int m_denominator;
};

bool operator==(const Rational& lhs, const Rational& rhs){
  return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) ? true : false;
}

Rational operator*(const Rational& lhs, const Rational& rhs){
  return Rational(lhs.Numerator()*rhs.Numerator(),lhs.Denominator()*rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs){
  return Rational(lhs.Numerator()*rhs.Denominator(),lhs.Denominator()*rhs.Numerator());
}

bool operator<(const Rational& lhs,const Rational& rhs){
  int a, b;
  a = lhs.Numerator()*rhs.Denominator();
  b = rhs.Numerator()*lhs.Denominator();
  return a < b ? true : false;
}

void TestDefaultConstructor(){
  Rational r1;
  AssertEqual(r1.Numerator(),0,"default constructor: zero numerator");
  AssertEqual(r1.Denominator(),1,"default constructor: denominator must be 1");
}

void TestReduceFraction(){
  Rational r1(3,9);
  AssertEqual(r1.Numerator(),1,"3/9: numerator must be 1");
  AssertEqual(r1.Denominator(),3,"3/9: denominator must be 3");
}

void TestNegativeFraction(){
  Rational r1(-3,9);
  AssertEqual(r1.Numerator(),-1, "-3/9: numerator must be -1");
  AssertEqual(r1.Denominator(),3, "-3/9: denominator must be 3");

  Rational r2(3,-9);
  AssertEqual(r2.Numerator(),-1, "3/-9: numerator must be -1");
  AssertEqual(r2.Denominator(),3, "3/-9: denominator must be 3");
}

void TestPositiveFraction(){
  Rational r1(8,13);
  AssertEqual(r1.Numerator(),8,"8/13: numerator must be 8");
  AssertEqual(r1.Denominator(),13,"8/13: denominator must be 13");

  Rational r2(-3,-9);
  AssertEqual(r2.Numerator(),1,"-3/-9: numerator must be 1");
  AssertEqual(r2.Denominator(),3,"-3/-9: denominator must be 3");
}

void TestZeroNumerator(){
  Rational r1(0,5);
  AssertEqual(r1.Numerator(),0,"0/5: numerator must be 0");
  AssertEqual(r1.Denominator(),1,"0/5: denominator must be 1");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestDefaultConstructor,"TestDefaultConstructor");
  runner.RunTest(TestReduceFraction,"TestReduceFraction");
  runner.RunTest(TestNegativeFraction,"TestNegativeFraction");
  runner.RunTest(TestPositiveFraction,"TestPositiveFraction");
  runner.RunTest(TestZeroNumerator,"TestZeroNumerator");

  return 0;
}
