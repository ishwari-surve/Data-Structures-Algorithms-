#  Stack in C 

## Overview

This comprehensive repository contains the **complete step-by-step implementation of Stack Data Structure** using **C Programming Language**. The programs are designed sequentially, progressing from basic structure setup to a fully functional **Menu-Driven Stack Application** with all core operations.

A **Stack** is a fundamental data structure that follows the **LIFO (Last-In-First-Out)** principle, where elements are added and removed from the **same end called the Top**. This repository demonstrates how stacks work internally using C pointers and dynamic memory allocation, providing practical implementations of stack operations.

---

##  What is a Stack?

### Definition

A **Stack** is a linear data structure where:

- **LIFO Principle:** Last element added is the first element to be removed
- **Single End Access:** All operations (Push/Pop) happen at the top
- **Dynamic Size:** Grows and shrinks based on insertions and deletions
- **Efficient Operations:** Push and Pop execute in **O(1)** time complexity
- **Real-World Analogy:** Like a stack of plates - add/remove from top only

---

### Visual Representation

                TOP
                 │
                 ▼
            +---------+
            |   50    |  ← Last Inserted
            +---------+
            |   40    |
            +---------+
            |   30    |
            +---------+
            |   20    |
            +---------+
            |   10    |  ← First Inserted
            +---------+

        Push()  ↑
        Pop()   ↓

        LIFO (Last-In-First-Out)

### Example 
Push(10)
Push(20)
Push(30)
Push(40)
Push(50)

Stack:
TOP
 │
 ▼
50
40
30
20
10

Pop()

TOP
 │
 ▼
40
30
20
10

---

---

## Stack Node Structure

### Node Structure Definition (C)

```c
struct node
{
    int data;              // Data value stored in node (4 bytes)
    struct node *next;     // Pointer to next node (8 bytes on 64-bit)
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
```

---

##  Technologies & Tools Used

### Programming & Development

- **Language:** C (C99 or C11 standard)
- **Paradigm:** Procedural Programming
- **Memory Management:** Dynamic Allocation (malloc/free)
- **Data Structure:** Linked List-based Stack
- **Features:** Pointers, Structures, Typedefs

### Development Environment

- **Compiler:** GCC (GNU C Compiler)
- **IDE:** Visual Studio Code
- **Platforms:** Windows, Linux, macOS
- **Compilation:** gcc -o program program.c

---

##  Key Features

###  Core Functionality

- **Dynamic Stack Creation** using dynamic memory allocation (`malloc`).
- **Push Operation** – Inserts an element at the top of the stack in **O(1)** time.
- **Pop Operation** – Removes the top element from the stack in **O(1)** time.
- **Peek (Top) Operation** – Retrieves the top element without removing it.
- **Display Operation** – Traverses and displays all elements of the stack.
- **Count Operation** – Returns the total number of elements present in the stack.
- **IsEmpty() Operation** – Checks whether the stack is empty.
- **Efficient Memory Management** – Allocates and deallocates memory using `malloc()` and `free()`.
- **Menu-Driven Implementation** – Provides an interactive interface for performing stack operations.
- **Step-by-Step Learning Approach** – Progresses from basic concepts to a complete Stack implementation.

---

## Learning Outcomes

After completing this repository, you will be able to:

- Understand the **Stack** data structure.
- Explain the **LIFO (Last-In-First-Out)** principle.
- Implement Stack using the **C programming language**.
- Perform **Push, Pop, Peek, Display, and Count** operations.
- Check **IsEmpty()** and **IsFull()** conditions.
- Analyze the time complexity of Stack operations.
- Solve basic problems using Stack.
- Develop a **Menu-Driven Stack Application**.
- Strengthen problem-solving and programming skills.
- Build a foundation for advanced data structures.

---

##  Author Information

### Ishwari Vijaykumar Surve


