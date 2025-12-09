```cpp

#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    int id;
    std::string description;
    bool completed;

public:
    // Default constructor
    Task() : id(0), description(""), completed(false) {}

    // Parameterized constructor
    Task(int id, const std::string& desc) 
        : id(id), description(desc), completed(false) {}

    // Mark the task as completed
    void markCompleted() { completed = true; }

    // Check if task is completed
    bool isCompleted() const { return completed; }

    // Get task ID
    int getId() const { return id; }

    // Get task description
    std::string getDescription() const { return description; }
};

#endif

