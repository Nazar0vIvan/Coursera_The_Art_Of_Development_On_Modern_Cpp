#include <iostream>
#include <exception>

using namespace std;

int gcd (int a, int b){ return !b ? a : gcd(b, a % b) ; }

class Rational{
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

  int Numerator() const{ return m_numerator; }
  int Denominator() const{ return m_denominator; }

private:
  int m_numerator;
  int m_denominator;
};

Rational operator * (const Rational& lhs, const Rational& rhs){
  return{ lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator() };
}

Rational operator / (const Rational& lhs, const Rational& rhs){
  if (rhs.Numerator() == 0){
    throw domain_error("");
  }
  return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

// Реализуйте для класса Rational операторы ==, + и -

int main(){
  try{
    Rational r(1, 0);
    cout << "Doesn't throw in case of zero denominator" << endl;
    return 1;
  }
  catch (invalid_argument& ex){
    cout << ex.what() << endl;
  }

  try{
    auto x = Rational(1, 2) / Rational(0, 1);
    cout << "Doesn't throw in case of division by zero" << endl;
    return 2;
  }
  catch (domain_error& ex){
    cout << ex.what() << endl;
  }

  cout << "OK" << endl;
  return 0;
}
