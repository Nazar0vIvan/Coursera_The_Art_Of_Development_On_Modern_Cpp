# Множество значений словаря

### Условие
 
Напишите функцию `BuildMapValuesSet`, принимающую на вход словарь `map<int, string>` и возвращающую множество значений этого словаря:

```c++
1   set<string> BuildMapValuesSet(const map<int, string>& m) {
2     // ...
3   }
```

### Пример

#### Код

```c++
1   set<string> values = BuildMapValuesSet({
2       {1, "odd"},
3       {2, "even"},
4       {3, "odd"},
5       {4, "even"},
6       {5, "odd"}
7   });
8
9   for (const string& value : values) {
10    cout << value << endl;
11  }
```

#### Вывод

```objectivec
1   even
2   odd
```
