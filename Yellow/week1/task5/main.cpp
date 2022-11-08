#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <iterator>

using namespace std;

enum class TaskStatus {
  NEW,         // новая
  IN_PROGRESS, // в разработке
  TESTING,     // на тестировании
  DONE         // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

#include <algorithm>
#include <map>
#include <string>
#include <tuple>
#include <vector>

TaskStatus Next(TaskStatus taskStatus) {
  return static_cast<TaskStatus>(static_cast<int>(taskStatus) + 1);
}

class TeamTasks {
public:

  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const;

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person);

  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int taskCount);

private:
  map<string, TasksInfo> m_personTasks;
};

const TasksInfo& TeamTasks::GetPersonTasksInfo(const string& person) const {
    return m_personTasks.at(person);
}

void TeamTasks::AddNewTask(const string& person) {
  ++m_personTasks[person][TaskStatus::NEW];
}

void RemoveZeros(TasksInfo& tasksInfo) {
  vector<TaskStatus> statusesToRemove;
  for (const auto& task_item : tasksInfo) {
    if (task_item.second == 0) {
      statusesToRemove.push_back(task_item.first);
    }
  }
  for (const TaskStatus status : statusesToRemove) {
    tasksInfo.erase(status);
  }
}

tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const string& person, int taskCount) {
  TasksInfo updatedTasks, untouchedTasks;
  TasksInfo& tasks = m_personTasks[person];

  for(TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)) {
    updatedTasks[Next(status)] = min(taskCount, tasks[status]);
    taskCount -= updatedTasks[Next(status)];
  }

  for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)) {
    untouchedTasks[status] = tasks[status] - updatedTasks[Next(status)];
    tasks[status] += updatedTasks[status] - updatedTasks[Next(status)];
  }
  tasks[TaskStatus::DONE] += updatedTasks[TaskStatus::DONE];

  RemoveZeros(updatedTasks);
  RemoveZeros(untouchedTasks);
  RemoveZeros(m_personTasks.at(person));

  return { updatedTasks, untouchedTasks };
}

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}
