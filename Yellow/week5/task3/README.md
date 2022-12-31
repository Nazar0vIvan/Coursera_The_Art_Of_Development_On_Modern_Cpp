# Отправка уведомлений

### Условие

Вам дана функция `main`, которая считывает из стандартного ввода команды по работе с набором геометрических фигур:  

```c++ {.line-numbers}
void SendSms(const string& number, const string& message);
void SendEmail(const string& email, const string& message);
```
Разработайте: 

1. Абстрактный базовый класс `INotifier`, у которого будет один чисто виртуальный метод `void Notify(const string& message)`.
2. Класс `SmsNotifier`, который:
   * является потомком класса `INotifier`;
   * в конструкторе принимает один параметр типа `string` — номер телефона;
   * переопределяет метод `Notify` и вызывает из него функцию `SendSms`.
3. Класс `EmailNotifier`, который:
   * является потомком класса `INotifier`;
   * в конструкторе принимает один параметр типа `string` — адрес электронной почты;
   * переопределяет метод `Notify` и вызывает из него функцию `SendEmail`.

Пример кода для проверки

```c++ {.line-numbers}
int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
```
Как видно из кода, есть два вида команд: 

* **ADD** — добавить фигуру в набор;
* **PRINT** — для каждой фигуры в наборе распечатать название, периметр и площадь.

Программа поддерживает три вида фигур: прямоугольник, треугольник и круг. Их добавление описывается так:

* **ADD RECT** ***width height*** —  добавить прямоугольник с размерами ***width*** и ***height*** (например, **ADD RECT 2 3**).
* **ADD TRIANGLE** ***a b c*** —  добавить треугольник со сторонами ***a***, ***b*** и ***c***(например, **ADD TRIANGLE 3 4 5**).
* **ADD CIRCLE** ***r*** —  добавить круг радиуса ***r*** (например, **ADD CIRCLE 5**).

### Пример работы программы

#### Ввод

```objectivec {.line-numbers}
ADD RECT 2 3
ADD TRIANGLE 3 4 5
ADD RECT 10 20
ADD CIRCLE 5
PRINT
```
#### Вывод

```objectivec {.line-numbers}
RECT 10.000 6.000
TRIANGLE 12.000 6.000
RECT 60.000 200.000
CIRCLE 31.400 78.500
```
Не меняя функцию `main`, реализуйте недостающие функции и классы:

* базовый класс `Figure` с чисто виртуальными методами `Name`, `Perimeter` и `Area`;
* классы `Triangle`, `Rect` и `Circle`, которые являются наследниками класса `Figure` и переопределяют его виртуальные методы;
* функцию `CreateFigure`, которая в зависимости от содержимого входного потока создаёт `shared_ptr<Rect>`, `shared_ptr<Triangle>` или `shared_ptr<Circle>`.

Гарантируется, что размеры всех фигур — это натуральные числа не больше 1000. В качестве значения `PI` используйте 3,14.