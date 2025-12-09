```cpp

#include "TaskManager.h"

// Constructor: allocate memory for tasks using unique_ptr
TaskManager::TaskManager(int initialCapacity) 
    : size(0), capacity(initialCapacity) 
{
    tasks = std::make_unique<Task[]>(capacity);
}

// Add a task
void TaskManager::addTask(const std::string& desc) {
    if (size >= capacity) {
        std::cout << "Task list is full! Cannot add more tasks.\n";
        return;
    }
    tasks[size++] = Task(size, desc); // Task IDs start at 1
}

// Remove a task by ID
void TaskManager::removeTask(int id) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (tasks[i].getId() == id) {
            // Shift remaining tasks left
            for (int j = i; j < size - 1; ++j) {
                tasks[j] = tasks[j + 1];
            }
            --size;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Task ID " << id << " not found.\n";
    }
}

// List all tasks
void TaskManager::listTasks() const {
    if (size == 0) {
        std::cout << "No tasks available.\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << tasks[i].getId() << ". " 
                  << tasks[i].getDescription()
                  << " [" << (tasks[i].isCompleted() ? "Completed" : "Incomplete") 
                  << "]\n";
    }
}

