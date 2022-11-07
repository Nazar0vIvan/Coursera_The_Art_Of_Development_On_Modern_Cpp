# Структура LectureTitle

### Условие
 
Дана структура `LectureTitle`:

```c++
1   struct LectureTitle {
2     string specialization;
3     string course;
4     string week;
5   };
```

Допишите конструктор и структуры `Specialization`, `Course`, `Week` так, чтобы объект `LectureTitle` можно было создать с помощью кода 

```c++
1   LectureTitle title(
2       Specialization("C++"),
3       Course("White belt"),
4       Week("4th")
5   );
```

но нельзя было с помощью следующих фрагментов кода:

```c++
1   LectureTitle title("C++", "White belt", "4th");
2
3   LectureTitle title(string("C++"), string("White belt"), string("4th"));
4
5   LectureTitle title = {"C++", "White belt", "4th"};
6
7   LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
8
9   LectureTitle title(
10      Course("White belt"),
11      Specialization("C++"),
12      Week("4th")
13  );
14
15  LectureTitle title(
16      Specialization("C++"),
17      Week("4th"),
18      Course("White belt")
19  );
```
