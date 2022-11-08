# Часть множества

### Условие
 
Напишите шаблонную функцию `FindGreaterElements`, принимающую множество `elements` объектов типа `T` и ещё один объект `border` типа `T` и возвращающую вектор из всех элементов множества, бо́льших `border`, в возрастающем порядке.

```c++
1   template <typename T>
2   vector<T> FindGreaterElements(const set<T>& elements, const T& border);
```

### Пример кода

```c++
1   int main() {
2     for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
3       cout << x << " ";
4     }
5     cout << endl;
6  
7     string to_find = "Python";
8     cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
9     return 0;
10  }
```

### Вывод

```objectivec
1   7 8
2   0
```