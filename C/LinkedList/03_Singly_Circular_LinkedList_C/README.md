# Singly Circular Linked List in C

##  Overview

This repository contains a complete implementation of the **Singly Circular Linked List** using the **C Programming Language**.

A **Singly Circular Linked List (SCLL)** is a dynamic linear data structure in which each node contains two fields: **data** and a **pointer to the next node**. Unlike a Singly Linear Linked List, the **last node points back to the first node**, forming a circular loop instead of ending with `NULL`.

This repository demonstrates the complete implementation of Singly Circular Linked List operations through well-structured, step-by-step programs, starting from node creation and progressing to a fully functional **Menu Driven Application**.

---

#  Features

- ✔ Node Creation
- ✔ Dynamic Memory Allocation using `malloc()`
- ✔ Insert at Beginning
- ✔ Insert at End
- ✔ Insert at Specific Position
- ✔ Delete from Beginning
- ✔ Delete from End
- ✔ Delete from Specific Position
- ✔ Display the Circular Linked List
- ✔ Count Total Number of Nodes
- ✔ Position Validation
- ✔ Circular Node Linking
- ✔ Menu Driven Implementation
- ✔ Modular Function-Based Design

---

# 🏗 Data Structure Used

```c
struct node
{
    int data;
    struct node *next;
};
```

---

#  Operations Implemented

##  Insert Operations

- `InsertFirst()`
- `InsertLast()`
- `InsertAtPos()`

---

##  Delete Operations

- `DeleteFirst()`
- `DeleteLast()`
- `DeleteAtPos()`

---

##  Utility Operations

- `Display()`
- `Count()`

---

#  Concepts Covered

- Self-Referential Structures
- Dynamic Memory Allocation (`malloc()` and `free()`)
- Pointer Manipulation
- Singly Circular Linked List
- Circular Traversal using `do-while`
- Position Based Insertion
- Position Based Deletion
- Function-Based Programming
- Menu Driven Programming
- Data Structure Fundamentals

---

#  Learning Objectives

After completing these programs, you will understand:

- How Singly Circular Linked Lists work internally
- Difference between Linear and Circular Linked Lists
- Memory allocation using `malloc()`
- Creating and linking circular nodes
- Traversing a circular linked list safely
- Insertion and deletion at different positions
- Managing node connections efficiently
- Building modular and reusable C programs
- Developing Menu Driven Applications

---

#  Sample Output

```text
--------------------------------------
Singly Circular Linked List
--------------------------------------

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

#  Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Editor/IDE:** Visual Studio Code / CodeBlocks / Dev-C++
- **Operating System:** Windows / Linux / macOS

---

#  Compilation

```bash
gcc Program018.c -o Program018
```

---

#  Execution

### Windows

```bash
Program018.exe
```
---

#  Applications

- Learning Data Structures
- Academic Practical Programs
- Placement Preparation
- Interview Preparation
- Understanding Dynamic Memory Management
- Circular Queue Implementation
- Round Robin Scheduling Algorithms

---

#  Author

**Ishwari Vijaykumar Surve**

---

# ⭐ If you found this repository helpful, consider giving it a Star!
