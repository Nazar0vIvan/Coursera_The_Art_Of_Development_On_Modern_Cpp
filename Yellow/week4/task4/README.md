# Удаление повторов

### Условие
 
Напишите шаблонную функцию `RemoveDuplicates`, принимающую по ссылке вектор `elements` объектов типа `T` и удаляющую из него все дубликаты элементов. Порядок оставшихся элементов может быть любым.

Гарантируется, что объекты типа `T` можно сравнивать с помощью операторов `==`, `!=`, `<` и `>`.

```c++
1   template <typename T>
2   void RemoveDuplicates(vector<T>& elements);
```

### Пример кода

```c++
1   int main() {
2     vector<int> v1 = { 6, 4, 7, 6, 4, 4, 0, 1 };
3     RemoveDuplicates(v1);
4     for (int x : v1) {
5       cout << x << " ";
6     }
7     cout << endl;
8  
9     vector<string> v2 = { "C", "C++", "C++", "C", "C++" };
10    RemoveDuplicates(v2);
11    for (const string& s : v2) {
12      cout << s << " ";
13    }
14    cout << endl;

15    return 0;
16  }
```

### Вывод

```objectivec
1   6 4 7 0 1
2   C++ C
```

Порядок элементов может быть другим, например:

```objectivec
1   7 4 6 1 0
2   C C++
```