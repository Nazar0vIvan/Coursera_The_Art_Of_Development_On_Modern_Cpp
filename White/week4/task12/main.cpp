#include <iostream>
#include <exception>

using namespace std;

int gcd (int a, int b) { return !b ? a : gcd(b, a % b) ; }

class Rational {
public:
  Rational(){
    m_numerator = 0;
    m_denominator = 1;
  };
  Rational(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator){
    if (denominator == 0){
      throw invalid_argument("");
    }
    const int c = gcd(numerator, denominator);
    m_numerator = numerator / c;
    m_denominator = denominator / c;
    if (m_denominator < 0){
      m_denominator = -denominator;
      m_numerator = -numerator;
    }
  }

  int Numerator() const {return m_numerator;}
  int Denominator() const {return m_denominator;}

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
  if (rhs.Numerator() == 0){
    throw domain_error("Division by zero");
  }
  else{
    return Rational(lhs.Numerator()*rhs.Denominator(),lhs.Denominator()*rhs.Numerator());
  }
}

bool operator<(const Rational& lhs,const Rational& rhs){
  int a,b;
  a = lhs.Numerator()*rhs.Denominator();
  b = rhs.Numerator()*lhs.Denominator();
  return a < b ? true : false;
}

int main() {

  Rational r1, r2;

  char operation;
  try{
    cin >> r1;
  }
  catch (invalid_argument& ex) {
    cout << "Invalid argument" << endl;
    return 0;
  }

  cin >> operation;
  try{
    cin >> r2;
  }
  catch (invalid_argument& ex) {
    cout << "Invalid argument" << endl;
    return 0;
  }

  switch(operation){
    case '+':
      cout << r1+r2;
      break;
    case '-':
      cout << r1-r2;
      break;
    case '*':
      cout << r1*r2;
      break;
    case '/':
      Rational div;
      try{
        div = r1/r2;
      }
      catch (domain_error& ex){
        cout << ex.what() << endl;
        return 0;
      }
      cout << div << endl;
      break;
  }
  return 0;
}
