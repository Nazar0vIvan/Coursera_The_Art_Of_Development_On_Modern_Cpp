#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
  Person(const string& name, const string& occupation) : m_name(name), m_occupation(occupation){}

  string Name() const { return m_name; }
  string Occupation() const { return m_occupation; }
  virtual void Walk(const string& destination) const = 0;

private:
  string m_name;
  string m_occupation;
};


class Student : public Person
{
public:
  Student(const string& name, const string& favouriteSong) : Person(name, "Student"), m_favouriteSong(favouriteSong){}

  void Learn() const {
    cout << "Student: " << Name() << " learns" << endl;
  }
  void Walk(const string& destination) const override {
    cout << "Student: " << Name() << " walks to: " << destination << endl;
    SingSong();
  }
  void SingSong() const {
    cout << "Student: " << Name() << " sings a song: " << m_favouriteSong << endl;
  }

public:
  string m_favouriteSong;
};

class Teacher : public Person
{
public:
  Teacher(string name, string subject) : Person(name, "Teacher"), m_subject(subject){}

  void Teach() const {
    cout << "Teacher: " << Name() << " teaches: " << m_subject << endl;
  }
  void Walk(const string& destination) const override {
    cout << "Teacher: " << Name() << " walks to: " << destination << endl;
  }

public:
  string m_subject;
};

class Policeman : public Person
{
public:
  Policeman(const string& name) : Person(name, "Policeman"){}

  void Check(const Person& p) const {
    cout << "Policeman: " << Name() << " checks " << p.Occupation() << ". "
      << p.Occupation() << "'s name is: " << p.Name() << endl;
  }
  void Walk(const string& destination) const override {
    cout << "Policeman: " << Name() << " walks to: " << destination << endl;
  }
};

void VisitPlaces(const Person& pers, const vector<string>& places)
{
  for (const auto& p : places){
    pers.Walk(p);
  }
}

int main()
{
  Teacher t("Jim", "Math");
  Student s("Ann", "We will rock you");
  Policeman p("Bob");

  VisitPlaces(t, { "Moscow", "London" });
  p.Check(s);
  VisitPlaces(s, { "Moscow", "London" });

  return 0;
}
