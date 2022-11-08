# База регионов

### Условие

Имеется база регионов, представленная вектором структур `Region`:  

```c++
1   struct Region {
2     string std_name;
3     string parent_std_name;
4     map<Lang, string> names;
5     int64_t population;
6   };
```

Здесь Lang — идентификатор языка:

```c++
1   enum class Lang {
2     DE, FR, IT
3   };
```

Напишите функцию `FindMaxRepetitionCount`, принимающую базу регионов и определяющую, какое максимальное количество повторов (число вхождений одного и того же элемента) она содержит. Две записи (объекты типа `Region`) считаются различными, если они отличаются хотя бы одним полем.

```c++
1   int FindMaxRepetitionCount(const vector<Region>& regions); 
```

Если все записи уникальны, считайте максимальное количество повторов равным 1. Если записи отсутствуют, верните 0. Гарантируется, что типа `int` достаточно для хранения ответа.

### Пример кода

```c++
1   int main() {
2     cout << FindMaxRepetitionCount({
3       {
4         "Moscow",
5         "Russia",
6         {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
7         89
8       }, {
9         "Russia",
10        "Eurasia",
11        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
12        89
13      }, {
14        "Moscow",
15        "Russia",
16        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
17        89
18      }, {
19        "Moscow",
20        "Russia",
21        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
22        89
23      }, {
24        "Russia",
25        "Eurasia",
26        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
27        89
28      },
29    }) << endl;
30    cout << FindMaxRepetitionCount({
31      {
32        "Moscow",
33        "Russia",
34        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
35        89
36      }, {
37        "Russia",
38        "Eurasia",
39        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
40        89
41      }, {
42        "Moscow",
43        "Russia",
44        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
45        89
46      }, {
47        "Moscow",
48        "Toulouse",
49        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
50        89
51      }, {
52        "Moscow",
53        "Russia",
54        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
55        31
56      },
57    }) << endl;
58  
59    return 0;
60  }
```

### Вывод

```objectivec
1   3
2   1
```