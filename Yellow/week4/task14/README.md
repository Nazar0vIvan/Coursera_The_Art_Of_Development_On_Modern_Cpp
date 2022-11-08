# Группировка строк по префиксу

### Часть 1. Группировка по символу

Напишите функцию `FindStartsWith`:

* принимающую отсортированный набор строк в виде итераторов `range_begin`, `range_end` и один символ `prefix`;
* возвращающую диапазон строк, начинающихся с символа `prefix`, в виде пары итераторов.

```c++
1   template <typename RandomIt>
2   pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix);
```

Если итоговый диапазон пуст, его границы должны указывать на то место в контейнере, куда можно без нарушения порядка сортировки вставить любую строку, начинающуюся с символа `prefix` (подобно алгоритму `equal_range`). Гарантируется, что строки состоят лишь из строчных латинских букв и символ `prefix` также является строчной латинской буквой.

Поиск должен осуществляться за логарифмическую сложность — например, с помощью двоичного поиска.

### Пример кода

```c++
1   int main() {
2     const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};
3     
4     const auto m_result =
5         FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
6     for (auto it = m_result.first; it != m_result.second; ++it) {
7       cout << *it << " ";
8     }
9     cout << endl;
10  
11    const auto p_result =
12        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
13    cout << (p_result.first - begin(sorted_strings)) << " " <<
14        (p_result.second - begin(sorted_strings)) << endl;
15  
16    const auto z_result =
17        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
18    cout << (z_result.first - begin(sorted_strings)) << " " <<
19        (z_result.second - begin(sorted_strings)) << endl;
20  
21    return 0;
22  }
```

### Вывод

```objectivec
1   moscow murmansk
2   2 2
3   3 3
```

### Часть 2. Группировка по префиксу

Напишите более универсальный вариант функции `FindStartsWith`, принимающий в качестве префикса произвольную строку, состоящую из строчных латинских букв.

```c++
1   template <typename RandomIt>
2   pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix);
```

### Пример кода

```c++
1   int main() {
2     const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
3  
4     const auto mo_result =
5         FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
6     for (auto it = mo_result.first; it != mo_result.second; ++it) {
7       cout << *it << " ";
8     }
9     cout << endl;
10  
11    const auto mt_result =
12        FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
13    cout << (mt_result.first - begin(sorted_strings)) << " " <<
14        (mt_result.second - begin(sorted_strings)) << endl;
15  
16    const auto na_result =
17        FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
18    cout << (na_result.first - begin(sorted_strings)) << " " <<
19        (na_result.second - begin(sorted_strings)) << endl;
20  
21    return 0;
22  }
```

### Вывод

```objectivec
1   moscow motovilikha
2   2 2
3   3 3
```


