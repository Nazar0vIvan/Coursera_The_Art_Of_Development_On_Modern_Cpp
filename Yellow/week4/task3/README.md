# Разбиение на слова

### Условие
 
Напишите функцию `SplitIntoWords`, разбивающую строку на слова по пробелам.

```c++
1   vector<string> SplitIntoWords(const string& s);
```

Гарантируется, что:

* строка непуста;
* строка состоит лишь из латинских букв и пробелов;
* первый и последний символы строки не являются пробелами;
* строка не содержит двух пробелов подряд.

### Пример кода

```c++
1   int main() {
2     string s = "C Cpp Java Python";
3
4     vector<string> words = SplitIntoWords(s);
5     cout << words.size() << " ";
6     for (auto it = begin(words); it != end(words); ++it) {
7       if (it != begin(words)) {
8         cout << "/";
9       }
10      cout << *it;
11    }
12    cout << endl;
13    
14    return 0;
15  }
```

### Вывод

```objectivec
1   4 С/Cpp/Java/Python
```