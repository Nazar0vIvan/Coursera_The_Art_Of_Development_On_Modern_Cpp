# Строка

### Условие
 
Реализуйте класс `ReversibleString`, хранящий строку и поддерживающий методы `Reverse` для переворота строки и `ToString` для получения строки.  

### Пример

#### Код

```c++
1   int main() {
2     ReversibleString s("live");
3     s.Reverse();
4     cout << s.ToString() << endl;
5  
6     s.Reverse();
7     const ReversibleString& s_ref = s;
8     string tmp = s_ref.ToString();
9     cout << tmp << endl;
10  
11    ReversibleString empty;
12    cout << '"' << empty.ToString() << '"' << endl;
13  
14    return 0;
15  }
```

#### Вывод

```objectivec
1   evil
2   live
3   ""
```