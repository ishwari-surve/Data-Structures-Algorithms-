# Doubly Circular Linked List in C

## Overview

This repository contains the complete implementation of a **Doubly Circular Linked List** using the **C Programming Language**.

A **Doubly Circular Linked List (DCLL)** is a dynamic linear data structure in which each node contains **data**, a **pointer to the next node**, and a **pointer to the previous node**. The last node points back to the first node, and the first node points back to the last node, forming a circular structure in both forward and backward directions.

This repository demonstrates the complete implementation of Doubly Circular Linked List operations through well-structured, modular, and documented C programs. Each program is designed to explain a specific concept, making it suitable for beginners as well as students preparing for Data Structures practical examinations.

---

# What is a Doubly Circular Linked List?

A **Doubly Circular Linked List (DCLL)** is a dynamic linear data structure in which each node contains:

- Data
- Pointer to the next node (`next`)
- Pointer to the previous node (`prev`)

Unlike a Doubly Linear Linked List, the **last node is connected to the first node**, and the **first node is connected back to the last node**, creating a circular structure in both forward and backward directions.

This enables traversal of the list in both directions without reaching a `NULL` pointer.

---

# Features

- Node Creation
- Dynamic Memory Allocation using `malloc()`
- Circular Bidirectional Node Linking
- Forward Traversal
- Backward Traversal
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
- Memory Deallocation using `free()`

---

### Node Structure

```c
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
```

---

### Memory Representation

```
                   Forward Direction

        +-----+------+------+
        |Data | Next | Prev |
        +-----+------+------+
             │
             ▼

+----+      +----+      +----+      +----+
| 11 | <--> | 21 | <--> | 51 | <--> |101 |
+----+      +----+      +----+      +----+
   ▲                                         │
   │                                         ▼
   └─────────────────────────────────────────┘

                Circular Connection
```
---

### Advantages

- Efficient insertion at both ends.
- Efficient deletion at both ends.
- Traversal is possible in both forward and backward directions.
- No `NULL` pointer at the beginning or end of the list.
- Suitable for circular applications such as music playlists, browser history, task scheduling, and round-robin algorithms.

---

### Applications

- Music Playlist
- Browser Navigation
- Round Robin CPU Scheduling
- Circular Queue Implementation
- Undo / Redo Operations
- Image Carousel
- Multiplayer Turn-Based Games
- Operating System Process Scheduling

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

- Self-Referential Structures
- Doubly Linked List
- Circular Linked List
- Doubly Circular Linked List
- Dynamic Memory Allocation
- Memory Deallocation
- Pointer Manipulation
- Forward Traversal
- Backward Traversal
- Position-Based Insertion
- Position-Based Deletion
- Function-Based Programming
- Menu Driven Programming
- Data Structure Fundamentals

---

# Sample Output
<=> |11| <=> |21| <=> |51| <=> |101| <=> |111| <=>

Number of Nodes : 5

After InsertAtPos(105,4)

<=> |11| <=> |21| <=> |51| <=> |105| <=> |101| <=> |111| <=>

After DeleteAtPos(4)

<=> |11| <=> |21| <=> |51| <=> |101| <=> |111| <=>

```text
=================================================
     Doubly Circular Linked List
=================================================

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

- Fundamentals of Doubly Circular Linked Lists
- Node creation using dynamic memory allocation
- Circular bidirectional node linking
- Forward and backward traversal techniques
- Pointer manipulation using `next` and `prev`
- Position-based insertion operations
- Position-based deletion operations
- Memory management using `malloc()` and `free()`
- Building menu-driven applications in C
- Modular programming using functions

---

# Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **IDE:** Visual Studio Code / Code::Blocks / Dev-C++
- **Operating System:** Windows / Linux / macOS

---

# Requirements

- GCC Compiler
- Visual Studio Code / Code::Blocks / Dev-C++
- Basic Knowledge of C Programming
- Understanding of Pointers and Structures

---

# Compilation

```bash
gcc Program.c -o Program
```

---

# Execution

```bash
./Program
```

---

# Author

**Ishwari Vijaykumar Surve**

---

