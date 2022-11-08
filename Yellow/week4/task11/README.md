# Поиск ближайшего элемента

### Условие
 
Напишите функцию `FindNearestElement`, для множества целых чисел `numbers` и данного числа `border` возвращающую итератор на элемент множества, ближайший к `border`. Если ближайших элементов несколько, верните итератор на наименьший из них.

```c++
1   set<int>::const_iterator FindNearestElement(
2       const set<int>& numbers,
3       int border);
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел
```

### Пример кода

```c++
1   int main() {
2     set<int> numbers = {1, 4, 6};
3     cout <<
4       *FindNearestElement(numbers, 0) << " " <<
5       *FindNearestElement(numbers, 3) << " " <<
6       *FindNearestElement(numbers, 5) << " " <<
7       *FindNearestElement(numbers, 6) << " " <<
8       *FindNearestElement(numbers, 100) << endl;
9      
10    set<int> empty_set;
11  
12    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
13    return 0;
14  }
```

### Вывод

```objectivec
1   1 4 4 6 6
2   1
```