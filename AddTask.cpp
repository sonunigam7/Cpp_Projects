#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

class TodoList {
public:
    // Add a new task to the list
    void addTask(const std::string& description) {
        Task task;
        task.description = description;
        task.completed = false;
        tasks.push_back(task);
    }

    // Mark a task as completed
    void completeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
        }
    }

    // Remove a task from the list
    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        }
    }

    // Display all tasks in the list
    void displayTasks() {
        std::cout << "To-Do List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << "[" << i + 1 << "] ";
            if (tasks[i].completed) {
                std::cout << "[X] ";
            } else {
                std::cout << "[ ] ";
            }
            std::cout << tasks[i].description << std::endl;
        }
    }

private:
    std::vector<Task> tasks;
};

int main() {
    TodoList todoList;
    int choice;

    do {
        std::cout << "Options:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Complete Task" << std::endl;
        std::cout << "3. Remove Task" << std::endl;
        std::cout << "4. Display Tasks" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();
                std::string description;
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                todoList.addTask(description);
                break;
            }
            case 2: {
                int index;
                std::cout << "Enter the task number to mark as complete: ";
                std::cin >> index;
                todoList.completeTask(index - 1);
                break;
            }
            case 3: {
                int index;
                std::cout << "Enter the task number to remove: ";
                std::cin >> index;
                todoList.removeTask(index - 1);
                break;
            }
            case 4: {
                todoList.displayTasks();
                break;
            }
            case 0: {
                std::cout << "Exiting the program." << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}
