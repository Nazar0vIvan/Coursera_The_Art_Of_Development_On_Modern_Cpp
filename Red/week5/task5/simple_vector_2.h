#pragma once

#include <cstdint>
#include <utility>
#include <iterator>

using namespace std;

// Реализуйте SimpleVector в этом файле
// и отправьте его на проверку

template <typename T>
class SimpleVector {
public:
  SimpleVector() = default;
  explicit SimpleVector(size_t size) : size(size), capacity(size * 2), data(new T[capacity]){}
  SimpleVector(const SimpleVector& rhs) = delete; // конструктор копирования
  SimpleVector(SimpleVector<T>&& rhs) : size(rhs.capacity), capacity(rhs.capacity), data(rhs.data){ // конструктор перемещения
    rhs.data = nullptr;
    rhs.size = rhs.capacity = 0;
  }
  ~SimpleVector(){ delete[] data; }

  T& operator[](size_t index){ return data[index]; }

  T* begin(){ return data; }
  T* end(){ return data + size; }

  size_t Size() const { return size; }
  size_t Capacity() const { return capacity; }
  void PushBack(T value){
    if (size >= capacity) {
      auto new_cap = capacity == 0 ? 1 : 2 * capacity;
      auto new_data = new T[new_cap];
      move(begin(), end(), new_data);
      delete[] data;
      data = new_data;
      capacity = new_cap;
    }
    data[size++] = move(value);
  }

private:
  size_t size = 0;
  size_t capacity = 0;
  T* data = nullptr;
};


