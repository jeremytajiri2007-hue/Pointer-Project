```cpp

#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <memory>
#include <iostream>

class TaskManager {
private:
    std::unique_ptr<Task[]> tasks;
    int size;
    int capacity;

public:
    TaskManager(int initialCapacity);

    void addTask(const std::string& desc);
    void removeTask(int id);
    void listTasks() const;
};

#endif

