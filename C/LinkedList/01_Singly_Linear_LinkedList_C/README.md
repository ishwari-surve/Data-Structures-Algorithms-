# Singly Linked List in C

## Overview

This folder contains a complete implementation of the **Singly Linked List** using the **C programming language**. The programs are developed from scratch to demonstrate the internal working of linked lists through dynamic memory allocation and pointer manipulation.

The implementation follows a structured approach, beginning with node creation and progressing to insertion, deletion, traversal, searching, and other utility operations. It is intended to strengthen the understanding of fundamental Data Structures and improve programming skills in C.

---

### What is a Singly Linked List?

A **Singly Linked List** is a dynamic linear data structure composed of nodes. Each node contains:

1. **Data** – Stores the integer value
2. **Next Pointer** – Stores the address of the next node

The last node's next pointer is `NULL`, indicating the end of the list.

---

Visualization:
head → [11|→] → [21|→] → [51|NULL]
        node1    node2     node3 

---

## Node Structure

```c
#pragma pack(1)
struct node
{
    int data;              // 4 bytes - stores value
    struct node *next;     // 8 bytes - points to next node
};                         // Total: 12 bytes per node

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
```

### Why #pragma pack(1)?

**Without pragma:** 16 bytes per node (4 bytes wasted padding)
**With pragma:** 12 bytes per node (0 bytes wasted)

---

## Programs Included

The programs in this folder are arranged in a logical sequence to provide step-by-step learning of Singly Linked Lists.

### Program Progression

| Program | Topic | Concepts Covered |
|---------|-------|-----------------|
| 001-011 | Foundation | Structure, pointers, linking basics |
| 012-016 | Functions | Display, Count, traversal patterns |
| 367 | Complete | All 8 operations together |

---

## Topics Covered

### Basic Concepts

- Node Structure
- Self-Referential Structure
- Memory Layout
- Structure Packing using `#pragma pack(1)`
- Dynamic Memory Allocation with `malloc()`
- Node Creation
- Node Initialization
- Node Linking
- Pointer Traversal
- Pointer Types (PNODE,PPNODE)

### Insertion Operations
- Insert First - O(1)
- Insert Last - O(n)
- Insert At Position - O(n)

### Deletion Operations
- Delete First – O(1)
- Delete Last – O(n)
- Delete At Position – O(n)

### Utility Operations
- Display Linked List – O(n)
- Count Nodes – O(n)
- Search Element – O(n)

---

## Concepts Covered

- Structures
- Self-Referential Structures
- Pointers
- Pointer Manipulation
- Dynamic Memory Allocation
- Memory Management
- Linked Data Organization
- Modular Programming
- Time and Space Complexity Analysis

---

## Applications

- Dynamic Memory Management
- Stack Implementation
- Queue Implementation
- Graph Representation
- Hash Tables
- Polynomial Manipulation
- Memory-efficient Data Storage
- Undo/Redo Functionality
- Browser History

---

## Technologies Used

- **Language:** C Programming Language
- **Compiler:** GCC Compiler
- **IDE:** Visual Studio Code
- **Version Control:** Git & GitHub

---

## Learning Outcomes

After completing the programs in this folder, you will be able to:

- Understand the internal working of a Singly Linked List.
- Implement insertion and deletion operations efficiently.
- Master pointer manipulation and dynamic memory allocation.
- Perform traversal and searching operations.
- Analyze the time and space complexity of linked list operations.
- Build a strong foundation for advanced Data Structures and Algorithms.

---

## Key Features

- Clean and well-structured C programs.
- Step-by-step implementation from basic concepts to advanced operations.
- Beginner-friendly and easy to understand.
- Well-commented source code.
- Suitable for academic learning, coding practice, and technical interview preparation.

---

## Mastery Checklist

- [ ] Understand node structure and memory layout
- [ ] Know why #pragma pack(1) is used
- [ ] Can draw accurate memory diagrams
- [ ] Understand pointer types (PNODE, PPNODE)
- [ ] Can write InsertAtPos() from scratch
- [ ] Can write DeleteAtPos() from scratch
- [ ] Know time complexity of each operation
- [ ] Ready for Doubly Linked List
- [ ] Can explain in technical interview
- [ ] Can solve related problems

---

## Author

**Ishwari Surve**


