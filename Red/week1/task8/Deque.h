#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Deque
{
public:
  Deque(){}

  bool Empty() const { return !(m_Front.size() || m_Back.size()); }
  size_t Size() const { return (m_Front.size() + m_Back.size()); }

  T& operator[](size_t index) {
    return (index >= m_Front.size()) ? m_Back[index - m_Front.size()] : m_Front[m_Front.size() - 1 - index];
  }
  const T& operator[](size_t index) const {
    return (index >= m_Front.size()) ? m_Back.at(index - m_Front.size()) : m_Front.at(m_Front.size() - 1 - index);
  }

  T& At(size_t index)
  {
    if(index >= Size())
      throw out_of_range("");
    return (*this)[index];
  }

  const T& At(size_t index) const
  {
    if(index >= Size())
      throw out_of_range("");
    return (*this)[index];
  }

  void PushFront(const T& value){ m_Front.push_back(value); }

  void PushBack(const T& value){ m_Back.push_back(value); }

  T& Front(){
    return m_Front.empty() ? m_Back.front() : m_Front.back();
  }

  const T& Front() const {
    return m_Front.empty() ? m_Back.at(0) : m_Front.at(m_Front.size()-1);
  }

  T& Back(){
    return m_Back.empty() ? m_Front.front() : m_Back.back();
  }
  const T& Back() const {
    return m_Back.empty() ? m_Front.at(0) : m_Back.at(m_Back.size()-1);
  }

private:
  vector<T> m_Front;
  vector<T> m_Back;
};
