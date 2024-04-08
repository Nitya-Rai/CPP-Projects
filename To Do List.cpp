#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the to-do list!" << endl;
            return;
        }
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed)
                cout << "[X] ";
            else
                cout << "[ ] ";
            cout << tasks[i].description << endl;
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }
};

int main() {
    ToDoList todo;
    char choice;

    do {
        int option;
        cout << "1. Add Task\n2. Display Tasks\n3. Mark Task as Completed\n4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        cin.ignore(); // Clear the input buffer

        switch (option) {
            case 1: {
                string taskDescription;
                cout << "Enter task: ";
                getline(cin, taskDescription);
                todo.addTask(taskDescription);
                break;
            }
            case 2:
                todo.displayTasks();
                break;
            case 3: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todo.markTaskAsCompleted(index);
                break;
            }
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        if (option != 4) {
            cout << "Do you want to perform another operation? (y/n): ";
            cin >> choice;
            cin.ignore(); // Clear the input buffer
        }
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
