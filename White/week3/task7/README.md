# Имена и фамилии — 3

### Условие
 
Дополните класс `Person` из задачи «Имена и фамилии — 2» конструктором, позволяющим задать имя и фамилию человека при рождении, а также сам год рождения. Класс не должен иметь конструктора по умолчанию.

При получении на вход года, который меньше года рождения:

* методы `GetFullName` и `GetFullNameWithHistory` должны отдавать **"No person"**;
* методы `ChangeFirstName` и `ChangeLastName` должны игнорировать запрос.

Кроме того, необходимо объявить константными все методы, которые по сути ими являются.

### Пример

#### Код

```c++
1   int main() {
2     Person person("Polina", "Sergeeva", 1960);
3     for (int year : {1959, 1960}) {
4       cout << person.GetFullNameWithHistory(year) << endl;
5     }
6  
7     person.ChangeFirstName(1965, "Appolinaria");
8     person.ChangeLastName(1967, "Ivanova");
9     for (int year : {1965, 1967}) {
10      cout << person.GetFullNameWithHistory(year) << endl;
11    }
12
13    return 0;
14  }
```

#### Вывод

```objectivec
1   No person
2   Polina Sergeeva
3   Appolinaria (Polina) Sergeeva
4   Appolinaria (Polina) Ivanova (Sergeeva)
```