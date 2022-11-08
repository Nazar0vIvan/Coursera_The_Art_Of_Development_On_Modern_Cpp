# Трекер задач

### Условие

Реализуйте класс `TeamTasks`, позволяющий хранить статистику по статусам задач команды разработчиков:  

```c++
1   // Перечислимый тип для статуса задачи
2   enum class TaskStatus {
3     NEW,          // новая
4     IN_PROGRESS,  // в разработке
5     TESTING,      // на тестировании
6     DONE          // завершена
7   };
8
9   // Объявляем тип-синоним для map<TaskStatus, int>,
10  // позволяющего хранить количество задач каждого статуса
11  using TasksInfo = map<TaskStatus, int>;
12
13  class TeamTasks {
14  public:
15    // Получить статистику по статусам задач конкретного разработчика
16    const TasksInfo& GetPersonTasksInfo(const string& person) const;
17    
18    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
19    void AddNewTask(const string& person);
20    
21    // Обновить статусы по данному количеству задач конкретного разработчика,
22    // подробности см. ниже
23    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
24        const string& person, int task_count);
25  };
```

Метод `PerformPersonTasks` должен реализовывать следующий алгоритм:

1) Рассмотрим все невыполненные задачи разработчика `person`.
2) Упорядочим их по статусам: сначала все задачи в статусе `NEW`, затем все задачи в статусе `IN_PROGRESS` и, наконец, задачи в статусе `TESTING`.
3) Рассмотрим первые `task_count` задач и переведём каждую из них в следующий статус в соответствии с естественным порядком: `NEW → IN_PROGRESS → TESTING → DONE`.
4) Вернём кортеж из двух элементов: информацию о статусах обновившихся задач (включая те, которые оказались в статусе `DONE`) и информацию о статусах остальных не выполненных задач.

В случае отсутствия разработчика с именем person метод `PerformPersonTasks` должен вернуть кортеж из двух пустых `TasksInfo`.

Гарантируется, что `task_count` является положительным числом. Если `task_count` превышает текущее количество невыполненных задач разработчика, достаточно считать, что `task_count` равен количеству невыполненных задач: дважды обновлять статус какой-либо задачи в этом случае не нужно.

Кроме того, гарантируется, что метод `GetPersonTasksInfo` не будет вызван для разработчика, не имеющего задач.

### Пример работы метода PerformPersonTasks

Предположим, что у конкретного разработчика имеется 10 задач со следующими статусами:

* `NEW` — 3
* `IN_PROGRESS` — 2
* `TESTING` — 4
* `DONE` — 1

Поступает команда `PerformPersonTasks` с параметром `task_count = 4`, что означает обновление статуса для 3 задач c `NEW` до `IN_PROGRESS` и для 1 задачи с `IN_PROGRESS` до `TESTING`. 
Если выписать статусы всех задач по порядку, а обновляемые заключить в квадратные скобки, то изменение можно изобразить следующим образом:

  `[NEW, NEW, NEW, IN_PROGRESS,] IN_PROGRESS, TESTING, TESTING, TESTING, TESTING, DONE`

  ==>

  `[IN_PROGRESS, IN_PROGRESS, IN_PROGRESS, TESTING,] IN_PROGRESS, TESTING, TESTING, TESTING, TESTING, DONE`

Таким образом, новые статусы задач будут следующими:

* `IN_PROGRESS` — 3 обновлённых, 1 старая
* `TESTING` — 1 обновлённая, 4 старых
* `DONE` — 1 старая

В этом случае необходимо вернуть кортеж из 2 словарей:

* Обновлённые задачи: `IN_PROGRESS` — 3, `TESTING` — 1.
* Необновлённые задачи, исключая выполненные: `IN_PROGRESS` — 1, `TESTING` — 4.

Ни один из словарей не должен содержать лишних элементов, то есть статусов, которым соответствует ноль задач.

По условию, `DONE` задачи не нужно возвращать в необновлённых задачах (`untouched_tasks`).

### Примечание

Обновление словаря одновременно с итерированием по нему может привести к непредсказуемым последствиям. При возникновении такой необходимости рекомендуется сначала в отдельном временном словаре собрать информацию об обновлениях, а затем применить их к основному словарю.

### Пример кода

```c++
1   // Принимаем словарь по значению, чтобы иметь возможность
2   // обращаться к отсутствующим ключам с помощью [] и получать 0,
3   // не меняя при этом исходный словарь
4   void PrintTasksInfo(TasksInfo tasks_info) {
5     cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
6         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
7         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
8         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
9   }
10
11  int main() {
12    TeamTasks tasks;
13    tasks.AddNewTask("Ilia");
14    for (int i = 0; i < 3; ++i) {
15      tasks.AddNewTask("Ivan");
16    }
17    cout << "Ilia's tasks: ";
18    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
19    cout << "Ivan's tasks: ";
20    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
21    
22    TasksInfo updated_tasks, untouched_tasks;
23    
24    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
25    cout << "Updated Ivan's tasks: ";
26    PrintTasksInfo(updated_tasks);
27    cout << "Untouched Ivan's tasks: ";
28    PrintTasksInfo(untouched_tasks);
29  
30    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
31    cout << "Updated Ivan's tasks: ";
32    PrintTasksInfo(updated_tasks);
33    cout << "Untouched Ivan's tasks: ";
34    PrintTasksInfo(untouched_tasks);
35
36    return 0;
37  }
```

### Вывод

```objectivec
1   Ilia's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
2   Ivan's tasks: 3 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
3   Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
4   Untouched Ivan's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
5   Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
6   Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done
```

