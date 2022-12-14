#include <iostream>

using namespace std;

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
    if (m_denominator < 0) {
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

int main() {

// 1

  {
    const Rational r(3, 10);
    if (r.Numerator() != 3 || r.Denominator() != 10){
      cout << "Rational(3, 10) != 3/10" << endl;
      return 1;
    }
  }

  {
    const Rational r(8, 12);
    if (r.Numerator() != 2 || r.Denominator() != 3) {
      cout << "Rational(8, 12) != 2/3" << endl;
      return 2;
    }
  }

  {
    const Rational r(-4, 6);
    if (r.Numerator() != -2 || r.Denominator() != 3) {
      cout << "Rational(-4, 6) != -2/3" << endl;
      return 3;
    }
  }

  {
    const Rational r(4, -6);
    if (r.Numerator() != -2 || r.Denominator() != 3) {
      cout << "Rational(4, -6) != -2/3" << endl;
      return 4;
    }
  }

  {
    const Rational r(0, 15);
    if (r.Numerator() != 0 || r.Denominator() != 1) {
      cout << "Rational(0, 15) != 0/1" << endl;
      return 5;
    }
  }

  {
    const Rational defaultConstructed;
    if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
      cout << "Rational() != 0/1" << endl;
      return 6;
    }
  }

// 2

  {
    Rational r1(4, 6);
    Rational r2(2, 3);
    bool equal = r1 == r2;
    if (!equal) {
      cout << "4/6 != 2/3" << endl;
      return 7;
    }
  }

  {
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a + b;
    bool equal = c == Rational(2, 1);
    if (!equal) {
      cout << "2/3 + 4/3 != 2" << endl;
      return 8;
    }
  }

  {
    Rational a(5, 7);
    Rational b(2, 9);
    Rational c = a - b;
    bool equal = c == Rational(31, 63);
    if (!equal) {
      cout << "5/7 - 2/9 != 31/63" << endl;
      return 9;
    }
  }

// 3

  {
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a * b;
    bool equal = c == Rational(8, 9);
    if (!equal) {
      cout << "2/3 * 4/3 != 8/9" << endl;
      return 10;
    }
  }

  {
    Rational a(5, 4);
    Rational b(15, 8);
    Rational c = a / b;
    bool equal = c == Rational(2, 3);
    if (!equal) {
      cout << "5/4 / 15/8 != 2/3" << endl;
      return 11;
    }
  }

// 4

  {
    ostringstream output;
    output << Rational(-6, 8);
    if (output.str() != "-3/4") {
      cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
      return 12;
    }
  }

  {
    istringstream input("5/7");
    Rational r;
    input >> r;
    bool equal = r == Rational(5, 7);
    if (!equal) {
      cout << "5/7 is incorrectly read as " << r << endl;
      return 13;
    }
  }

  {
    istringstream input("");
    Rational r;
    bool correct = !(input >> r);
    if (!correct) {
      cout << "Read from empty stream works incorrectly" << endl;
      return 14;
    }
  }

  {
    istringstream input("5/7 10/8");
    Rational r1, r2;
    input >> r1 >> r2;
    bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct) {
      cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
      return 15;
    }

    input >> r1;
    input >> r2;
    correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct) {
      cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
      return 16;
    }
  }

  {
    istringstream input1("1*2"), input2("1/"), input3("/4");
    Rational r1, r2, r3;
    input1 >> r1;
    input2 >> r2;
    input3 >> r3;
    bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
    if (!correct) {
      cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
           << r1 << " " << r2 << " " << r3 << endl;
      return 17;
    }
  }

// 5

  {
    const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
    if (rs.size() != 3) {
      cout << "Wrong amount of items in the set" << endl;
      return 18;
    }

    vector<Rational> v;
    for (auto x : rs) {
      v.push_back(x);
    }
    if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
      cout << "Rationals comparison works incorrectly" << endl;
      return 19;
    }
  }

  {
    map<Rational, int> count;
    ++count[{1, 2}];
    ++count[{1, 2}];

    ++count[{2, 3}];

    if (count.size() != 2) {
      cout << "Wrong amount of items in the map" << endl;
      return 20;
    }
  }

  cout << "OK" << endl;
  return 0;
}
