# Doubly Circular Linked List in C++

## Overview

This repository contains the implementation of a **Doubly Circular Linked List** using the **C++ programming language**.

A **Doubly Circular Linked List** is a dynamic linear data structure in which every node contains **data**, a pointer to the **next node**, and a pointer to the **previous node**. The last node points back to the first node, and the first node points back to the last node, forming a circular structure in both forward and backward directions.

This repository demonstrates the complete implementation of various Doubly Circular Linked List operations using Object-Oriented Programming (OOP) concepts in C++.

---

# What is a Doubly Circular Linked List?

A **Doubly Circular Linked List** is a linked list in which:

- Each node contains three fields:
  - Data
  - Pointer to the next node
  - Pointer to the previous node
- The **last node's next pointer** points to the **first node**.
- The **first node's previous pointer** points to the **last node**.
- Traversal is possible in both **forward** and **backward** directions.
- No node contains a `NULL` pointer for next or previous (except when the list is empty).

---

# Features

- Object-Oriented Implementation
- Class and Object Based Design
- Dynamic Memory Allocation
- Insert First
- Insert Last
- Insert At Position
- Delete First
- Delete Last
- Delete At Position
- Display Linked List
- Count Total Nodes
- Menu Driven Implementation
- Position Validation
- Forward Traversal
- Backward Linking
- Circular Linking

---

# Data Structure Used

```cpp
class node
{
public:
    int data;
    node *next;
    node *prev;
};
```

---

# Diagram

```text
                 first
                   │
                   ▼
      +----+ ⇄ +----+ ⇄ +----+ ⇄ +----+
      | 11 |   | 21 |   | 31 |   | 41 |
      +----+ ⇄ +----+ ⇄ +----+ ⇄ +----+
         ▲                             │
         │                             ▼
         └─────────────────────────────┘
                    last

last->next = first
first->prev = last
```
---

# Operations Implemented

## Insert Operations

- InsertFirst()
- InsertLast()
- InsertAtPos()

## Delete Operations

- DeleteFirst()
- DeleteLast()
- DeleteAtPos()

## Utility Operations

- Display()
- Count()

---

# Concepts Covered

- Object-Oriented Programming (OOP)
- Classes and Objects
- Self-Referential Class
- Dynamic Memory Allocation using `new`
- Memory Deallocation using `delete`
- Pointer Manipulation
- Forward Traversal
- Backward Traversal
- Circular Linked List
- Position Validation
- Menu Driven Programming
- Data Structure Fundamentals

---

# Sample Output

```text
--------------------------------------------------
      Doubly Circular Linked List
--------------------------------------------------

1. Insert First
2. Insert Last
3. Insert At Position
4. Delete First
5. Delete Last
6. Delete At Position
7. Display
8. Count
0. Exit

Enter your choice :
```

---

# Learning Objectives

After completing these programs, you will understand:

- How Doubly Circular Linked Lists work internally
- Dynamic memory allocation using `new`
- Memory deallocation using `delete`
- Forward and backward traversal
- Circular linking of nodes
- Insertion techniques
- Deletion techniques
- Position-based operations
- Pointer manipulation
- Menu Driven programming
- Object-Oriented implementation of linked lists

---

# Repository Structure

```text
Doubly-Circular-Linked-List-CPP/
│
├── DoublyCL_01.cpp
├── DoublyCL_02.cpp
├── DoublyCL_03.cpp
├── DoublyCL_04.cpp
├── DoublyCL_05.cpp
├── DoublyCL_06.cpp
├── DoublyCL_07.cpp
├── DoublyCL_08.cpp
├── DoublyCL_09.cpp
├── DoublyCL_10.cpp
├── DoublyCL_11.cpp
└── README.md
```

---

# Requirements

- C++ Compiler (G++)
- Visual Studio Code / CodeBlocks / Dev-C++
- Windows / Linux / macOS

---

# Compilation

```bash
g++ DoublyCL_01.cpp -o Program
```

---

# Execution

```bash
./Program
```

---

# Author

**Ishwari Vijaykumar Surve**


