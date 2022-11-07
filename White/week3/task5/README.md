# Имена и фамилии — 2

### Условие
 
Дополните класс из предыдущей задачи «Имена и фамилии — 1» методом `GetFullNameWithHistory`:

```c++
1   class Person {
2   public:
3     void ChangeFirstName(int year, const string& first_name) {
4       // добавить факт изменения имени на first_name в год year
5     }
6     void ChangeLastName(int year, const string& last_name) {
7       // добавить факт изменения фамилии на last_name в год year
8     }
9     string GetFullName(int year) {
10      // получить имя и фамилию по состоянию на конец года year
11    }
12    string GetFullNameWithHistory(int year) {
13      // получить все имена и фамилии по состоянию на конец года year
14    }
15  private:
16    // приватные поля
17  };
```

В отличие от метода `GetFullName`, метод `GetFullNameWithHistory` должен вернуть не только последние имя и фамилию к концу данного года, но ещё и все предыдущие имена и фамилии в обратном хронологическом порядке. Если текущие факты говорят о том, что человек два раза подряд изменил фамилию или имя на одно и то же, второе изменение при формировании истории нужно игнорировать.

Для лучшего понимания формата см. примеры.

### Пример 1

#### Код

```c++
1   int main() {
2     Person person;
3
4     person.ChangeFirstName(1900, "Eugene");
5     person.ChangeLastName(1900, "Sokolov");
6     person.ChangeLastName(1910, "Sokolov");
7     person.ChangeFirstName(1920, "Evgeny");
8     person.ChangeLastName(1930, "Sokolov");
9     cout << person.GetFullNameWithHistory(1940) << endl;
10  
11    return 0;
12  }
```

#### Вывод

```objectivec
1   Evgeny (Eugene) Sokolov
```

### Пример 2

#### Код

```c++
1   int main() {
2     Person person;
3  
4     person.ChangeFirstName(1965, "Polina");
5     person.ChangeLastName(1967, "Sergeeva");
6     for (int year : {1900, 1965, 1990}) {
7       cout << person.GetFullNameWithHistory(year) << endl;
8     }
9  
10    person.ChangeFirstName(1970, "Appolinaria");
11    for (int year : {1969, 1970}) {
12      cout << person.GetFullNameWithHistory(year) << endl;
13    }
14  
15    person.ChangeLastName(1968, "Volkova");
16    for (int year : {1969, 1970}) {
17      cout << person.GetFullNameWithHistory(year) << endl;
18    }
19  
20    person.ChangeFirstName(1990, "Polina");
21    person.ChangeLastName(1990, "Volkova-Sergeeva");
22    cout << person.GetFullNameWithHistory(1990) << endl;
23  
24    person.ChangeFirstName(1966, "Pauline");
25    cout << person.GetFullNameWithHistory(1966) << endl;
26  
27    person.ChangeLastName(1960, "Sergeeva");
28    for (int year : {1960, 1967}) {
29      cout << person.GetFullNameWithHistory(year) << endl;
30    }
31  
32    person.ChangeLastName(1961, "Ivanova");
33    cout << person.GetFullNameWithHistory(1967) << endl;
34  
35    return 0;
36  }
```

#### Вывод

```objectivec
1   Incognito
2   Polina with unknown last name
3   Polina Sergeeva
4   Polina Sergeeva
5   Appolinaria (Polina) Sergeeva
6   Polina Volkova (Sergeeva)
7   Appolinaria (Polina) Volkova (Sergeeva)
8   Polina (Appolinaria, Polina) Volkova-Sergeeva (Volkova, Sergeeva)
9   Pauline (Polina) with unknown last name
10  Sergeeva with unknown first name
11  Pauline (Polina) Sergeeva
12  Pauline (Polina) Sergeeva (Ivanova, Sergeeva)
```

### Пример 3

#### Код

```c++
1   int main() {
2     Person person;
3
4     person.ChangeFirstName(1965, "Polina");
5     person.ChangeFirstName(1965, "Appolinaria");
6
7     person.ChangeLastName(1965, "Sergeeva");
8     person.ChangeLastName(1965, "Volkova");
9     person.ChangeLastName(1965, "Volkova-Sergeeva");
10
11    for (int year : {1964, 1965, 1966}) {
12      cout << person.GetFullNameWithHistory(year) << endl;
13    }
14
15    return 0;
16  }
```

#### Вывод

```objectivec
1   Incognito
2   Appolinaria Volkova-Sergeeva
3   Appolinaria Volkova-Sergeeva
```