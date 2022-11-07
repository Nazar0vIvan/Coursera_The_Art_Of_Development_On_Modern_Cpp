# Отсортированные строки

### Условие
 
Реализуйте класс, поддерживающий набор строк в отсортированном порядке. Класс должен содержать два публичных метода:

```c++
1   class SortedStrings {
2   public:
3     void AddString(const string& s) {
4       // добавить строку s в набор
5     }
6     vector<string> GetSortedStrings() {
7       // получить набор из всех добавленных строк в отсортированном порядке
8     }
9   private:
10      // приватные поля
};
```

### Пример

#### Код

```c++
1   void PrintSortedStrings(SortedStrings& strings) {
2     for (const string& s : strings.GetSortedStrings()) {
3       cout << s << " ";
4     }
5     cout << endl;
6   }
7
8   int main() {
9     SortedStrings strings;
10  
11    strings.AddString("first");
12    strings.AddString("third");
13    strings.AddString("second");
14    PrintSortedStrings(strings);
15  
16    strings.AddString("second");
17    PrintSortedStrings(strings);
18  
19    return 0;
}
```

#### Вывод

```objectivec
1   first second third
2   first second second third
```
