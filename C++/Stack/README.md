# 📚 Stack in C++

## Overview

This comprehensive repository contains the **complete step-by-step implementation of Stack Data Structure** using **C++** and **Object-Oriented Programming (OOP)** principles. The programs are designed sequentially, progressing from basic structure setup to a fully functional **Menu-Driven Stack Application** with all core operations.

A **Stack** is a fundamental data structure that follows the **LIFO (Last-In-First-Out)** principle, where elements are added and removed from the **same end called the Top**. This repository demonstrates how stacks work internally and provides practical implementations of stack operations.

---

##  What is a Stack?

### Definition

A **Stack** is a linear data structure where:

- **LIFO Principle:** Last element added is the first element to be removed
- **Single End Access:** All operations (Push/Pop) happen at the top
- **Dynamic Size:** Grows and shrinks based on insertions and deletions
- **Efficient Operations:** Push and Pop execute in **O(1)** time complexity
- **Real-World Analogy:** Like a stack of plates - add/remove from top only

### Visual Representation
┌─────────┐
    │   Top → │ (Most Recent)
    ├─────────┤
    │  Data   │
    ├─────────┤
    │  Data   │
    ├─────────┤
    │  Data   │
    └─────────┘
    (Oldest)

##  Stack Node Structure

### Node Class Definition (C++)

```cpp
struct node
{
    int data;              // Data value stored in node
    struct node *next;     // Pointer to next node
};

typedef struct node NODE;
typedef struct node *PNODE;
```
---

## Stack Operations
-Push
-Pop
-Peek (Top Element)
-Display Stack
-Count Elements

---

##  Technologies & Tools Used

### Programming & Development
- **Language:** C++ (Standard C++11 or later)
- **Paradigm:** Object-Oriented Programming (OOP)
- **Memory Management:** Dynamic Allocation (new/delete)
- **Data Structure:** Linked List-based Stack

### Development Environment
- **Compiler:** G++ / MSVC
- **IDE:** Visual Studio Code, Code::Blocks
- **Operating System:** Windows / Linux / macOS

### Version Control
- **Git** for version tracking
- **GitHub** for repository management

---

##  Applications of Stack

Stacks are widely used in computer science and software development. Some common applications include:

- **Function Call Management** – Stores function calls during program execution (Call Stack).
- **Recursion** – Keeps track of recursive function calls.
- **Expression Evaluation** – Evaluates postfix and prefix expressions.
- **Expression Conversion** – Converts infix expressions to postfix or prefix notation.
- **Parentheses Matching** – Checks balanced parentheses, brackets, and braces in expressions.
- **Undo and Redo Operations** – Used in text editors, IDEs, and graphic design software.
- **Browser Navigation** – Maintains Back and Forward history in web browsers.
- **Depth First Search (DFS)** – Used in graph and tree traversal algorithms.
- **Backtracking Algorithms** – Solves problems such as Maze Solving, N-Queens, Sudoku, and Knight's Tour.
- **Syntax Parsing** – Used by compilers and interpreters for syntax analysis.
- **Memory Management** – Helps manage local variables and function execution using the call stack.
- **String Reversal** – Reverses strings by utilizing the LIFO property of a stack.

---

##  Learning Outcomes

After completing this repository, you will be able to:

- Understand the **Stack** data structure and the **LIFO (Last-In-First-Out)** principle.
- Differentiate between **Array-based** and **Linked List-based** Stack implementations.
- Perform all fundamental Stack operations, including:
  - Push
  - Pop
  - Peek (Top)
  - Display
  - Count
  - IsEmpty
  - IsFull (Array Stack)
- Understand memory management during Stack operations.
- Analyze the **time and space complexity** of Stack operations.
- Solve problems using the Stack data structure.
- Develop a **Menu-Driven Stack Application** using Object-Oriented Programming (OOP) concepts.
- Strengthen problem-solving skills through step-by-step implementation.
- Build a strong foundation for advanced data structures such as **Queues, Trees, Graphs, Expression Evaluation, and Recursion**.

---

##  How to Use

### Compilation

```bash
# Compile C++ program
g++ -o stack_program program_name.cpp

# Or using MSVC
cl program_name.cpp
```

### Running Programs

```bash
# Run individual program
./stack_program

# Or
java ProgramName
```
---

## 👨‍💻 Author Information

### Ishwari Vijaykumar Surve
















