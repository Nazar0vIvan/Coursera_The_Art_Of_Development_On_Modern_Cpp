# Демографические показатели

### Условие
 
В этой задаче вам необходимо вычислить различные демографические показатели для группы людей. Человек представляется структурой `Person`:

```c++
1   struct Person {
2     int age;  // возраст
3     Gender gender;  // пол
4     bool is_employed;  // имеет ли работу
5   };
```

Тип `Gender` определён следующим образом:  

```c++
1   enum class Gender {
2     FEMALE,
3     MALE
4   };
```

Вам необходимо написать функцию PrintStats, получающую вектор людей, вычисляющую и выводящую медианный возраст для каждой из следующих групп людей:  

* все люди;
* все женщины;
* все мужчины;
* все занятые женщины;
* все безработные женщины;
* все занятые мужчины;
* все безработные мужчины.

Все 7 чисел нужно вывести в строгом соответствии с форматом (см. пример).

```c++
1   void PrintStats(vector<Person> persons);
```

Принимая вектор по значению (а не по константной ссылке), вы получаете возможность модифицировать его копию произвольным образом и тем самым проще произвести вычисления.  

### Вычисление медианного возраста

Для вычисления медианного возраста группы людей вы должны использовать функцию `ComputeMedianAge`:  

```c++
1   template <typename InputIt>
2   int ComputeMedianAge(InputIt range_begin, InputIt range_end);
```

Эту функцию не нужно реализовывать самостоятельно: мы реализовали её за вас и автоматически добавим к каждому вашему решению.

Функцию `ComputeMedianAge` можно вызвать и для пустого набора людей: её результат в этом случае и нужно считать медианным возрастом пустого набора людей.

### Пример кода

```c++
1   template <typename InputIt>
2   int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
3     if (range_begin == range_end) {
4       return 0;
5     }
6     vector<typename InputIt::value_type> range_copy(range_begin, range_end);
7     auto middle = begin(range_copy) + range_copy.size() / 2;
8     nth_element(
9         begin(range_copy), middle, end(range_copy),
10        [](const Person& lhs, const Person& rhs) {
11          return lhs.age < rhs.age;
12        }
13    );
14    return middle->age;
15  }
16
17  void PrintStats(vector<Person> persons);
18
19  int main() {
20    vector<Person> persons = {
21        {31, Gender::MALE, false},
22        {40, Gender::FEMALE, true},
23        {24, Gender::MALE, true},
24        {20, Gender::FEMALE, true},
25        {80, Gender::FEMALE, false},
26        {78, Gender::MALE, false},
27        {10, Gender::FEMALE, false},
28        {55, Gender::MALE, true},
29    };
30    PrintStats(persons);
31    return 0;
32  }
```

### Вывод

```objectivec
1   Median age = 40
2   Median age for females = 40
3   Median age for males = 55
4   Median age for employed females = 40
5   Median age for unemployed females = 80
6   Median age for employed males = 55
7   Median age for unemployed males = 78
```
