# Анаграммы

### Условие
 
Реализуйте справочник столиц стран.

На вход программе поступают следующие запросы:

* __CHANGE_CAPITAL__ ___country new_capital___ — изменение столицы страны ___country___ на ___new_capital___, либо добавление такой страны с такой столицей, если раньше её не было.
* __RENAME__ ___old_country_name new_country_name___ — переименование страны из ___old_country_name___ в ___new_country_name___.
* __ABOUT__ ___country___ — вывод столицы страны ___country___.
* __DUMP__ — вывод столиц всех стран.

### Формат ввода

В первой строке содержится количество запросов _Q_, в следующих _Q_ строках — описания запросов. Все названия стран и столиц состоят лишь из латинских букв, цифр и символов подчёркивания.

### Формат вывода

Выведите результат обработки каждого запроса:

В ответ на запрос __CHANGE_CAPITAL__ country ___new_capital___ выведите

* __Introduce new country ___country___ with capital ___new_capital_____, если страны ___country___ раньше не существовало;
* __Country ___country___ hasn't changed its capital__, если страна ___country___ до текущего момента имела столицу ___new_capital___;
* __Country ___country___ has changed its capital from ___old_capital___ to ___new_capital_____, если страна ___country___ до текущего момента имела столицу ___old_capital___, название которой не совпадает с названием ___new_capital___.

В ответ на запрос __RENAME__ ___old_country_name___ ___new_country_name___ выведите

* __Incorrect rename, skip__, если новое название страны совпадает со старым, страна ___old_country_name___ не существует или страна ___new_country_name___ уже существует;
* __Country ___old_country_name___ with capital ___capital___ has been renamed to ___new_country_name_____, если запрос корректен и страна имеет столицу ___capital___.

В ответ на запрос __ABOUT__ ___country___ выведите

* __Country ___country___ doesn't exist__, если страны с названием ___country___ не существует;
* __Country ___country___ has capital capital__, если страна ___country___ существует и имеет столицу ___capital___.

В ответ на запрос __DUMP__ выведите

* __There are no countries in the world__, если пока не было добавлено ни одной страны;
* последовательность пар вида ___country/capital___, описывающую столицы всех стран, если в мире уже есть хотя бы одна страна. При выводе последовательности пары указанного вида необходимо упорядочить по названию страны и разделять между собой пробелом.

### Пример 1

#### Ввод

```objectivec
1   6
2   CHANGE_CAPITAL RussianEmpire Petrograd
3   RENAME RussianEmpire RussianRepublic
4   ABOUT RussianRepublic
5   RENAME RussianRepublic USSR
6   CHANGE_CAPITAL USSR Moscow
7   DUMP
```

#### Вывод

```objectivec
1   Introduce new country RussianEmpire with capital Petrograd
2   Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
3   Country RussianRepublic has capital Petrograd
4   Country RussianRepublic with capital Petrograd has been renamed to USSR
5   Country USSR has changed its capital from Petrograd to Moscow
6   USSR/Moscow
```

### Пример 2

#### Ввод

```objectivec
1   24
2   RENAME FakeCountry FarFarAway
3   ABOUT FarFarAway
4   DUMP
5   CHANGE_CAPITAL TsardomOfRussia Moscow
6   CHANGE_CAPITAL TsardomOfRussia Moscow
7   CHANGE_CAPITAL ColonialBrazil Salvador
8   CHANGE_CAPITAL TsardomOfRussia SaintPetersburg
9   RENAME TsardomOfRussia RussianEmpire
10  CHANGE_CAPITAL RussianEmpire Moscow
11  CHANGE_CAPITAL RussianEmpire SaintPetersburg
12  CHANGE_CAPITAL ColonialBrazil RioDeJaneiro
13  DUMP
14  RENAME ColonialBrazil EmpireOfBrazil
15  ABOUT RussianEmpire
16  RENAME EmpireOfBrazil UnitedStatesOfBrazil
17  CHANGE_CAPITAL RussianEmpire Petrograd
18  RENAME RussianEmpire RussianRepublic
19  RENAME RussianRepublic USSR
20  CHANGE_CAPITAL USSR Moscow
21  CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
22  RENAME UnitedStatesOfBrazil FederativeRepublicOfBrazil
23  ABOUT RussianEmpire
24  DUMP
25  RENAME USSR USSR
```

#### Вывод

```objectivec
1   Incorrect rename, skip
2   Country FarFarAway doesn't exist
3   There are no countries in the world
4   Introduce new country TsardomOfRussia with capital Moscow
5   Country TsardomOfRussia hasn't changed its capital
6   Introduce new country ColonialBrazil with capital Salvador
7   Country TsardomOfRussia has changed its capital from Moscow to 8    SaintPetersburg
8   Country TsardomOfRussia with capital SaintPetersburg has been renamed to RussianEmpire
9   Country RussianEmpire has changed its capital from SaintPetersburg to Moscow
10  Country RussianEmpire has changed its capital from Moscow to SaintPetersburg
11  Country ColonialBrazil has changed its capital from Salvador to RioDeJaneiro
12  ColonialBrazil/RioDeJaneiro RussianEmpire/SaintPetersburg
13  Country ColonialBrazil with capital RioDeJaneiro has been renamed to EmpireOfBrazil
14  Country RussianEmpire has capital SaintPetersburg
15  Country EmpireOfBrazil with capital RioDeJaneiro has been renamed to UnitedStatesOfBrazil
16  Country RussianEmpire has changed its capital from SaintPetersburg to Petrograd
17  Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
18  Country RussianRepublic with capital Petrograd has been renamed to USSR
19  Country USSR has changed its capital from Petrograd to Moscow
20  Country UnitedStatesOfBrazil has changed its capital from RioDeJaneiro to Brasilia
21  Country UnitedStatesOfBrazil with capital Brasilia has been renamed to FederativeRepublicOfBrazil
22  Country RussianEmpire doesn't exist
23  FederativeRepublicOfBrazil/Brasilia USSR/Moscow
24  Incorrect rename, skip
```
### Пример 3

#### Ввод

```objectivec
1   10
2   CHANGE_CAPITAL RussianEmpire Petrograd
3   RENAME USSR RussianEmpire
4   DUMP
5   ABOUT USSR
6   DUMP
7   RENAME RussianEmpire RussianEmpire
8   DUMP
9   CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
10  RENAME RussianEmpire UnitedStatesOfBrazil
11  DUMP 
```

#### Вывод

```objectivec
1   Introduce new country RussianEmpire with capital Petrograd
2   Incorrect rename, skip
3   RussianEmpire/Petrograd
4   Country USSR doesn't exist
5   RussianEmpire/Petrograd
6   Incorrect rename, skip
7   RussianEmpire/Petrograd
8   Introduce new country UnitedStatesOfBrazil with capital Brasilia
9   Incorrect rename, skip
10  RussianEmpire/Petrograd UnitedStatesOfBrazil/Brasilia
```
