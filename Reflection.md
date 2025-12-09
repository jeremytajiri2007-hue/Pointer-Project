# Reflection — Task Manager Project

For this project, I got to work with three different types of pointers in C++: pointers to stack memory, pointers to heap memory, and smart pointers (`std::unique_ptr`). Each type works a little differently and has its own advantages and challenges.

---

## Differences Between Pointer Types

- **Pointer to stack memory**  
  This points to objects created on the stack. The object exists only as long as the scope it was created in. I didn’t have to worry about freeing memory manually, but stack memory is limited and not very flexible if I wanted to add more tasks dynamically.

- **Pointer to heap memory**  
  This points to objects created on the heap using `new`. It’s more flexible because I can create as many objects as I want (up to available memory), but I had to remember to use `delete` or `delete[]` to free the memory when I was done. Forgetting to do this would cause memory leaks.

- **Smart pointer (`std::unique_ptr`)**  
  Smart pointers also point to heap objects, but they manage memory automatically. Once the smart pointer goes out of scope, it deletes the object for me. This makes memory management much safer and simpler because I don’t have to track it manually.

---

## Where and Why `delete` Was Used

I used `delete[]` in Part B for the dynamically allocated array of tasks. This was necessary because the array was created on the heap, and without `delete[]` it would stay in memory, causing a leak. In Part A (stack pointers) and Part C (smart pointers), I didn’t need `delete` at all because stack memory is automatically cleaned up and `unique_ptr` takes care of heap memory.

---

## Ownership in Each Design

- **Stack pointer:** The object belongs to the scope where it was created. The pointer just references it.  
- **Heap raw pointer:** I, the programmer, am responsible for both creating and deleting the object.  
- **Smart pointer (`unique_ptr`):** The pointer owns the object exclusively. When it goes out of scope, it automatically deletes the object.

---

## Which Pointer Method is Safest and Why

Overall, **smart pointers (`unique_ptr`) are the safest**. They give me all the flexibility of heap memory without the risk of forgetting to delete objects. Stack pointers are also safe but limited, and raw heap pointers are flexible but easy to misuse. Using smart pointers makes the code cleaner, safer, and easier to maintain.


