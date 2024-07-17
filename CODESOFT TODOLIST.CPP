   CPP    CODESOFT   TO DO LIST 
 CODE:-  
 
#include <iostream>
#include <vector>
#include <string>

class ToDoListManager {
private:
    struct Task {
        std::string description;
        bool completed;

        Task(const std::string& desc) : description(desc), completed(false) {}
    };

    std::vector<Task> tasks;

public:
    void addTask(const std::string& task) {
        tasks.emplace_back(task);
        std::cout << "Task \"" << task << "\" added to the list." << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description << " - "
                      << (tasks[i].completed ? "Completed" : "Pending") << std::endl;
        }
    }

    void markTaskAsCompleted(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            std::cout << "Task \"" << tasks[taskNumber - 1].description << "\" marked as completed." << std::endl;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

    void removeTask(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            std::string removedTask = tasks[taskNumber - 1].description;
            tasks.erase(tasks.begin() + taskNumber - 1);
            std::cout << "Task \"" << removedTask << "\" removed from the list." << std::endl;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }
};

void displayMenu() {
    std::cout << "\nTo-Do List Manager" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. View Tasks" << std::endl;
    std::cout << "3. Mark Task as Completed" << std::endl;
    std::cout << "4. Remove Task" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

int main() {
    ToDoListManager manager;
    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cin.ignore(); // To clear the newline character from the input buffer
            std::cout << "Enter the task: ";
            std::string task;
            std::getline(std::cin, task);
            manager.addTask(task);
        } else if (choice == 2) {
            manager.viewTasks();
        } else if (choice == 3) {
            std::cout << "Enter task number to mark as completed: ";
            size_t taskNumber;
            std::cin >> taskNumber;
            manager.markTaskAsCompleted(taskNumber);
        } else if (choice == 4) {
            std::cout << "Enter task number to remove: ";
            size_t taskNumber;
            std::cin >> taskNumber;
            manager.removeTask(taskNumber);
        } else if (choice == 5) {
            std::cout << "Exiting To-Do List Manager." << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}




=	=	=	=	=	=	=	=	=	=	=	==		=	=	=	=	=	=	=	=	=	=	


Explanation:
Class Definition:

ToDoListManager class manages the tasks list.
It has a nested Task struct to store task details.
Methods:

addTask(const std::string& task): Adds a task to the list.
viewTasks() const: Displays all tasks with their status (completed or pending).
markTaskAsCompleted(size_t taskNumber): Marks a specific task as completed based on its number in the list.
removeTask(size_t taskNumber): Removes a specific task from the list based on its number.
Menu Display:

displayMenu(): Displays the menu options.
Main Loop:

The main() function runs the to-do list manager. It continuously prompts the user for their choice and performs the corresponding actions.
