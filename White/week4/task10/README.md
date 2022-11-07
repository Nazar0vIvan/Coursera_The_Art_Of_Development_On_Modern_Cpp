# Функция EnsureEqual

### Условие
 
Напишите функцию 

```c++
1   void EnsureEqual(const string& left, const string& right);
```

В случае, если строка **left** не равна строке **right**, функция должна выбрасывать исключение `runtime_error` с содержанием "<l> != <r>", где <l> и <r> - строки, которые хранятся в переменных **left** и **right** соответственно. Обратите внимание, что вокруг знака неравенства в строке, которая помещается в исключение, должно быть ровно по одному пробелу.

Если `left == right`, функция должна корректно завершаться.

Например, код

```c++
1   int main() {
2     try {
3       EnsureEqual("C++ White", "C++ White");
4       EnsureEqual("C++ White", "C++ Yellow");
5     } catch (runtime_error& e) {
6       cout << e.what() << endl;
7     }
8     return 0;
9   }
```

должен выводить

```objectivec
1   C++ White != C++ Yellow
```