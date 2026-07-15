# Singly Linked List in C++

## Overview

This folder contains a complete implementation of the **Singly Linear Linked List** using the **C++ programming language**. The programs are developed from scratch to demonstrate the internal working of linked lists using **classes, objects, dynamic memory allocation, and pointer manipulation**.

The implementation follows a structured approach, beginning with node creation and progressing to insertion, deletion, traversal, searching, and menu-driven applications. It is designed to strengthen the understanding of fundamental Data Structures while introducing Object-Oriented Programming concepts in C++.

---

# What is a Singly Linked List?

A **Singly Linked List** is a dynamic linear data structure composed of nodes. Each node contains:

- **Data** – Stores the value.
- **Next Pointer** – Stores the address of the next node.

The last node points to **NULL**, indicating the end of the list.

### Visualization

```
Head
 │
 ▼
[11|•] → [21|•] → [51|•] → [101|NULL]
```

---

# Node Structure

```cpp
class node
{
public:
    int data;
    node *next;

    node(int no)
    {
        data = no;
        next = NULL;
    }
};
```

Each node contains:

- Integer Data
- Pointer to the Next Node

Memory for every node is allocated dynamically using the **new** operator.

---

# Why use Classes?

Unlike C, C++ allows us to combine both **data** and **operations** inside a single class.

Advantages include:

- Better code organization
- Encapsulation
- Reusability
- Easier maintenance
- Cleaner implementation

The linked list is represented using a separate **SinglyLL** class.

---

# Programs Included

The programs in this folder are arranged in a logical sequence to provide step-by-step learning of Singly Linked Lists.

## Program Progression

## Program Progression

| Phase | Key Concepts |
|--------|--------------|
| Foundation | Classes, Objects, Constructors, Node Creation, Dynamic Memory Allocation |
| Basic Operations | InsertFirst, InsertLast, Display, Count |
| Advanced Operations | Delete Operations, Position-wise Operations, Complete Menu-Driven Implementation |

> **Note:** Programs will continue to be added as more DSA concepts are covered.

---

# Topics Covered

## Basic Concepts

- Classes and Objects
- Constructors
- Dynamic Memory Allocation using `new`
- Node Creation
- Object References
- Pointer Manipulation
- Linked List Traversal
- Memory Layout

---

## Insertion Operations

- Insert First — **O(1)**
- Insert Last — **O(n)**
- Insert At Position — **O(n)**

---

## Deletion Operations

- Delete First — **O(1)**
- Delete Last — **O(n)**
- Delete At Position — **O(n)**

---

## Utility Operations

- Display Linked List — **O(n)**
- Count Nodes — **O(1)** *(using maintained counter)*
- Search Element — **O(n)**

---

# Concepts Covered

- Object-Oriented Programming (OOP)
- Classes
- Objects
- Constructors
- Encapsulation
- Dynamic Memory Allocation
- Pointer Manipulation
- Linked Data Structures
- Traversal Techniques
- Modular Programming
- Time Complexity Analysis
- Space Complexity Analysis

---

# Applications

- Dynamic Memory Management
- Stack Implementation
- Queue Implementation
- Graph Representation
- Hash Tables
- Polynomial Representation
- Browser History
- Undo / Redo Operations
- Music Playlist Management

---

# Technologies Used

- **Language:** C++
- **Compiler:** G++
- **IDE:** Visual Studio Code
- **Version Control:** Git & GitHub

---

# Learning Outcomes

After completing the programs in this folder, you will be able to:

- Understand the internal working of a Singly Linked List.
- Implement insertion and deletion operations efficiently.
- Master dynamic memory allocation using `new`.
- Understand pointer manipulation in C++.
- Perform traversal and searching operations.
- Implement complete Linked List operations using OOP.
- Analyze time and space complexity.
- Build a strong foundation for advanced Data Structures.

---

# Key Features

- Object-Oriented Implementation
- Clean and Modular C++ Programs
- Step-by-Step Learning Approach
- Well-Commented Source Code
- Beginner Friendly
- Interview-Oriented Programs
- Easy to Understand

---

# Mastery Checklist

- [ ] Understand node structure
- [ ] Understand classes and objects
- [ ] Know constructor execution
- [ ] Understand dynamic memory allocation using `new`
- [ ] Understand pointer manipulation
- [ ] Can write InsertFirst() from scratch
- [ ] Can write InsertLast() from scratch
- [ ] Can write InsertAtPos() from scratch
- [ ] Can write DeleteFirst() from scratch
- [ ] Can write DeleteLast() from scratch
- [ ] Can write DeleteAtPos() from scratch
- [ ] Know time complexity of every operation
- [ ] Ready for Doubly Linked List
- [ ] Can explain implementation in technical interviews

---

# Author

**Ishwari Vijaykumar Surve**
