#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString
{
public:
  ReversibleString(){}
  ReversibleString(const string& s){
    m_string = s;
  }
  void Reverse(){
    reverse(m_string.begin(),m_string.end());
  }
  string ToString() const {
    return m_string;
  }

private:
  string m_string = "";
};

int main()
{
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}
