# Реализовать функции, объявленные в заголовочном файле

### Условие

Вам дан заголовочный файл `sum_reverse_sort.h`, содержащий объявления трёх функций

[sum_reverse_sort.h](source/sum_reverse_sort.h)

```c++
#pragma once
#include <string>
#include <vector>

using namespace std;

int Sum(int x, int y);
string Reverse(string s);
void Sort(vector<int>& nums);
```

Вам надо прислать cpp-файл, содержащий определения этих функций. 
Функции должны складывать два числа, обращать строку и сортировать вектор чисел по возрастанию соотвественно.