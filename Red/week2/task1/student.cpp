#include <algorithm>

#include "student.h"

using namespace std;

// Оптимизируйте эту функцию
bool Compare(const Student& first, const Student& second) {
  return first.Less(second);
}
