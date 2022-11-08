# Имена и фамилии — 4

### Условие
 
Решите задачу «Имена и фамилии — 1» более эффективно, использовав двоичный поиск в методе `Person::GetFullName`. Напомним условие задачи.

Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.

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
11      // с помощью двоичного поиска
12    }
13  private:
14    // приватные поля
15  };
```

Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени. При этом с течением времени могут открываться всё новые факты из прошлого человека, поэтому года́ в последовательных вызовах методов `ChangeLastName` и `ChangeFirstName` не обязаны возрастать.

Гарантируется, что все имена и фамилии непусты.

Строка, возвращаемая методом `GetFullName`, должна содержать разделённые одним пробелом имя и фамилию человека по состоянию на конец данного года.

* Если к данному году не случилось ни одного изменения фамилии и имени, верните строку **"Incognito"**.
* Если к данному году случилось изменение фамилии, но не было ни одного изменения имени, верните "***last_name*** **with unknown first name**".
* Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, верните "***first_name*** **with unknown last name**".

### Пример

#### Код

```c++
1   int main() {
2     Person person;
3  
4     person.ChangeFirstName(1965, "Polina");
5     person.ChangeLastName(1967, "Sergeeva");
6     for (int year : {1900, 1965, 1990}) {
7       cout << person.GetFullName(year) << endl;
8     }
9  
10    person.ChangeFirstName(1970, "Appolinaria");
11    for (int year : {1969, 1970}) {
12      cout << person.GetFullName(year) << endl;
13    }
14  
15    person.ChangeLastName(1968, "Volkova");
16    for (int year : {1969, 1970}) {
17      cout << person.GetFullName(year) << endl;
18    }
19  
20    return 0;
21  }
```

#### Вывод

```objectivec
1   Incognito
2   Polina with unknown last name
3   Polina Sergeeva
4   Polina Sergeeva
5   Appolinaria Sergeeva
6   Polina Volkova
7   Appolinaria Volkova
```