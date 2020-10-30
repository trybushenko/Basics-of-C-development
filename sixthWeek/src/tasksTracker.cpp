#include <iostream>
#include <tuple>
#include <map>
#include <tuple>
#include <set>
/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: 	Реализуйте класс TeamTasks,
		позволяющий хранить статистику по статусам задач команды разработчиков.

		Метод PerformPersonTasks должен реализовывать следующий алгоритм:

		Рассмотрим все невыполненные задачи разработчика person.
		Упорядочим их по статусам: сначала все задачи в статусе NEW,
		затем все задачи в статусе IN_PROGRESS и, наконец, задачи в статусе TESTING.
		Рассмотрим первые task_count задач и переведём каждую из них в следующий статус
		в соответствии с естественным порядком: NEW → IN_PROGRESS → TESTING → DONE.
		Вернём кортеж из двух элементов: информацию о статусах обновившихся задач
		(включая те, которые оказались в статусе DONE)
		и информацию о статусах остальных не выполненных задач.
		В случае отсутствия разработчика с именем person метод PerformPersonTasks
		должен вернуть кортеж из двух пустых TasksInfo

		Гарантируется, что task_count является положительным числом.
		Если task_count превышает текущее количество невыполненных задач разработчика,
		достаточно считать, что task_count равен количеству невыполненных задач:
		дважды обновлять статус какой-либо задачи в этом случае не нужно.

		Кроме того, гарантируется, что метод GetPersonTasksInfo не будет вызван для разработчика,
		не имеющего задач.
*/

// Перечислимый тип для статуса задачи


enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};


// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;


ostream& operator <<(ostream& out, const TaskStatus& status) {
    string statusName;
    switch (status) {
        case TaskStatus::NEW:
            statusName = "\"NEW\"";
            break;
        case TaskStatus::IN_PROGRESS:
            statusName = "\"IN_PROGRESS\"";
            break;
        case TaskStatus::TESTING:
            statusName = "\"TESTING\"";
            break;
        case TaskStatus::DONE:
            statusName = "\"DONE\"";
            break;
    }
    return out << statusName;
}

void deleteElemIfZero(TasksInfo& tasks) {
	TasksInfo copy = tasks;
	for (const auto& task : copy) {
		if (task.second == 0) {
			tasks.erase(task.first);
		}
	}
}

class TeamTasks {
	public:
  // Получить статистику по статусам задач конкретного разработчика
		const TasksInfo& GetPersonTasksInfo(const string& person) const {
			return surname_tasks.at(person);
		}

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
		void AddNewTask(const string& person) {
			if (surname_tasks.count(person) == 0) surname_tasks[person] = {{TaskStatus::NEW, 1}, {TaskStatus::IN_PROGRESS, 0},
			{TaskStatus::TESTING, 0}, {TaskStatus::DONE, 0}};
			else {
				surname_tasks[person][TaskStatus::NEW]++;
			}
		}

  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
		tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
			TasksInfo updated_tasks, untouched_tasks;
			if (!surname_tasks.count(person)) return make_tuple(updated_tasks, untouched_tasks);
			for (const auto& task : surname_tasks[person]) {
				if (task.second > task_count) {
					updated_tasks[(TaskStatus)(static_cast<int>(task.first) + 1)] = task_count;
					untouched_tasks[task.first] = task.second - task_count;
					task_count = 0;
				} else if (task.second < task_count) {
					updated_tasks[(TaskStatus)(static_cast<int>(task.first) + 1)] = task.second;
					task_count -= task.second;
				} else if (task.second == task_count) {
					untouched_tasks[(TaskStatus)(static_cast<int>(task.first) + 1)] = task_count;
					task_count = 0;
					}
				}
				for (auto& task : updated_tasks) {
					if (task.first != TaskStatus::NEW) {
						surname_tasks[person][(TaskStatus)(static_cast<int>(task.first) - 1)] -= updated_tasks[task.first];
					}
					surname_tasks[person][task.first] = updated_tasks[task.first] + untouched_tasks[task.first];
					if (surname_tasks[person][(TaskStatus)(static_cast<int>(task.first) - 1)] == 0) {
						surname_tasks[person].erase((TaskStatus)(static_cast<int>(task.first) - 1));
					}
				}
				deleteElemIfZero(updated_tasks);
				deleteElemIfZero(untouched_tasks);
				deleteElemIfZero(surname_tasks[person]);

			return make_tuple(updated_tasks, untouched_tasks);
		}
	private:
		map<string, TasksInfo> surname_tasks;
};



// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
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

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}


/*my out
Ilia's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
Ivan's tasks: 3 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
Untouched Ivan's tasks: 0 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done
 *
 *
 *orig
 * Ilia's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
	Ivan's tasks: 3 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
	Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
	Untouched Ivan's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
	Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
	Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done
 *
 * */
