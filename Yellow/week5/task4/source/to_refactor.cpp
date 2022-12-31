#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
public:
  Student(string m_name, string favouriteSong){
    m_name = m_name;
    FavouriteSong = favouriteSong;
  }

  void Learn(){
    cout << "Student: " << m_name << " learns" << endl;
  }

  void Walk(string destination){
    cout << "Student: " << m_name << " walks to: " << destination << endl;
    cout << "Student: " << m_name << " sings a song: " << FavouriteSong << endl;
  }

  void SingSong(){
    cout << "Student: " << m_name << " sings a song: " << FavouriteSong << endl;
  }

public:
  string m_name;
  string FavouriteSong;
};


class Teacher
{
public:
  Teacher(string m_name, string subject){
    m_name = m_name;
    Subject = subject;
  }

  void Teach(){
    cout << "Teacher: " << m_name << " teaches: " << Subject << endl;
  }

  void Walk(string destination){
    cout << "Teacher: " << m_name << " walks to: " << destination << endl;
  }

public:
  string m_name;
  string Subject;
};


class Policeman
{
public:
  Policeman(string m_name){
      m_name = m_name;
  }

  void Check(Teacher t){
      cout << "Policeman: " << m_name << " checks Teacher. Teacher's m_name is: " << t.m_name << endl;
  }

  void Check(Student s){
      cout << "Policeman: " << m_name << " checks Student. Student's m_name is: " << s.m_name << endl;
  }

  void Check(Policeman p){
      cout << "Policeman: " << m_name << " checks Policeman. Policeman's m_name is: " << p.m_name << endl;
  }

  void Walk(string destination){
      cout << "Policeman: " << m_name << " walks to: " << destination << endl;
  }

public:
    string m_name;
};


void VisitPlaces(Teacher t, vector<string> places){
  for (auto p : places){
    t.Walk(p);
  }
}

void VisitPlaces(Student s, vector<string> places){
  for (auto p : places){
    s.Walk(p);
  }
}

void VisitPlaces(Policeman pol, vector<string> places){
  for (auto p : places){
    pol.Walk(p);
  }
}
