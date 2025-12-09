```cpp

#include <iostream>
#include "Task.h"
#include "TaskManager.h"

using namespace std;

// ----------------- Part A: Stack Raw Pointers -----------------
void completeTask(Task* t) {
    t->markCompleted();
    cout << "Task \"" << t->getDescription() << "\" marked completed.\n";
}

void partA() {
    cout << "--- Part A: Raw Pointers to Stack Objects ---\n";
    
    Task t1(1, "Finish project");
    Task t2(2, "Study for exam");

    Task* p1 = &t1;
    Task* p2 = &t2;

    completeTask(p1);
    completeTask(p2);

    cout << "Task 1: " << p1->getDescription() 
         << " [" << (p1->isCompleted() ? "Completed" : "Incomplete") << "]\n";
    cout << "Task 2: " << p2->getDescription() 
         << " [" << (p2->isCompleted() ? "Completed" : "Incomplete") << "]\n";
}

// ----------------- Part B: Dynamic Raw Pointers -----------------
void addTask(Task* tasks, int& size, int capacity, const string& desc) {
    if (size >= capacity) {
        cout << "Task array full! Cannot add task.\n";
        return;
    }
    tasks[size++] = Task(size, desc);
}

void removeTask(Task* tasks, int& size, int id) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (tasks[i].getId() == id) {
            for (int j = i; j < size - 1; ++j) {
                tasks[j] = tasks[j + 1];
            }
            --size;
            found = true;
            break;
        }
    }
    if (!found) cout << "Task ID " << id << " not found.\n";
}

void listTasks(Task* tasks, int size) {
    if (size == 0) {
        cout << "No tasks available.\n";
        return;
    }
    for (int i = 0; i < size; ++i) {
        cout << tasks[i].getId() << ". " 
             << tasks[i].getDescription() 
             << " [" << (tasks[i].isCompleted() ? "Completed" : "Incomplete") 
             << "]\n";
    }
}

void partB() {
    cout << "--- Part B: Dynamic Raw Pointers ---\n";

    int capacity = 5;
    int size = 0;
    Task* tasks = new Task[capacity];

    addTask(tasks, size, capacity, "Write report");
    addTask(tasks, size, capacity, "Prepare presentation");

    listTasks(tasks, size);

    removeTask(tasks, size, 1); // remove task with ID 1
    cout << "After removal:\n";
    listTasks(tasks, size);

    delete[] tasks; // Prevent memory leak
}

// ----------------- Part C: Smart Pointers -----------------
void partC() {
    cout << "--- Part C: Smart Pointer Version ---\n";

    TaskManager manager(5);

    manager.addTask("Go shopping");
    manager.addTask("Clean room");

    manager.listTasks();

    manager.removeTask(1);
    cout << "After removal:\n";
    manager.listTasks();
}

// ----------------- Main -----------------
int main() {
    partA();
    cout << "\n";
    partB();
    cout << "\n";
    partC();

    return 0;
}

