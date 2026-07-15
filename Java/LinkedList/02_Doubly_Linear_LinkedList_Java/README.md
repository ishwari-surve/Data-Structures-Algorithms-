# Doubly Linear Linked List in Java

## Overview

This folder contains a complete implementation of the **Doubly Linear Linked List** using the **Java Programming Language**. The programs are developed from scratch to demonstrate the internal working of doubly linked lists using **classes, objects, constructors, object references, and Object-Oriented Programming (OOP)** concepts.

The implementation follows a structured learning approach, beginning with node creation and progressing through insertion, deletion, traversal, and utility operations. It is designed to strengthen the understanding of **Data Structures** while improving **Java programming and OOP skills**.

---

# What is a Doubly Linear Linked List?

A **Doubly Linear Linked List** is a dynamic linear data structure in which every node maintains **two references**.

- **Previous Reference (prev)** – Points to the previous node.
- **Data** – Stores the integer value.
- **Next Reference (next)** – Points to the next node.

The **first node's previous reference** is always `null`, and the **last node's next reference** is `null`.

---

# Visualization

```text
null <- [11] <-> [21] <-> [51] -> null
```

---

# Node Structure

```java
class Node
{
    public int data;
    public Node prev;
    public Node next;

    public Node(int no)
    {
        this.data = no;
        this.prev = null;
        this.next = null;
    }
}
```

---

# Why Constructors?

- Automatically initialize every newly created node.
- Eliminate manual initialization.
- Improve code readability.
- Promote Object-Oriented Programming.
- Reduce coding errors.
- Simplify insertion operations.

---

# Program Progression

| **Phase** | **Key Concepts** |
|-----------|------------------|
| **Foundation** | Node Class, References, Constructors |
| **Basic Operations** | Display, Count |
| **Insertion** | InsertFirst(), InsertLast(), InsertAtPos() |
| **Deletion** | DeleteFirst(), DeleteLast(), DeleteAtPos() |
| **Advanced** | Traversal, Utility Functions |

> **Note:** Programs will continue to be added as new concepts are covered.

---

# Topics Covered

## Basic Concepts

- Node Class
- Self-Referential Class
- Object References
- Constructors
- Object Creation using `new`
- Dynamic Memory Allocation
- Previous and Next References
- Doubly Linked List Traversal
- Forward Traversal
- Backward Traversal

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
- Count Nodes — **O(1)** *(using iCount)*
- Search Element — **O(n)**
- Forward Traversal
- Reverse Traversal

---

# Concepts Covered

- Object-Oriented Programming (OOP)
- Classes and Objects
- Constructors
- Object References
- Self-Referential Classes
- Encapsulation
- Dynamic Object Creation
- Linked Data Organization
- Modular Programming
- Memory Management
- Time and Space Complexity Analysis

---

# Applications

- Browser Back & Forward Navigation
- Undo / Redo Operations
- Music Playlist Systems
- Image Viewer Navigation
- Text Editors
- LRU Cache
- Deque Implementation
- Memory Management Systems
- Operating Systems
- Dynamic Data Applications

---

# Technologies Used

- **Language:** Java Programming Language
- **JDK:** Java 21
- **IDE:** Visual Studio Code
- **Version Control:** Git & GitHub

---

# Learning Outcomes

After completing the programs in this folder, you will be able to:

- Understand the internal working of a Doubly Linear Linked List.
- Implement insertion operations efficiently.
- Implement deletion operations efficiently.
- Perform forward and backward traversal.
- Understand previous and next references.
- Analyze time and space complexity.
- Apply Object-Oriented Programming concepts in Data Structures.
- Build a strong foundation for Circular Linked Lists and advanced Data Structures.

---

# Key Features

- Clean and well-structured Java programs.
- Step-by-step implementation from basic concepts to advanced operations.
- Beginner-friendly examples.
- Well-commented source code.
- Object-Oriented implementation.
- Easy to understand.
- Suitable for academic learning.
- Helpful for coding practice.
- Useful for technical interview preparation.

---

# Mastery Checklist

- [ ] Understand node structure.
- [ ] Understand previous and next references.
- [ ] Understand constructors.
- [ ] Draw memory diagrams.
- [ ] Understand `first` reference.
- [ ] Understand temporary reference (`temp`).
- [ ] Write `InsertFirst()` from scratch.
- [ ] Write `InsertLast()` from scratch.
- [ ] Write `InsertAtPos()` from scratch.
- [ ] Write `DeleteFirst()` from scratch.
- [ ] Write `DeleteLast()` from scratch.
- [ ] Write `DeleteAtPos()` from scratch.
- [ ] Perform forward traversal.
- [ ] Perform backward traversal.
- [ ] Know time complexity of every operation.
- [ ] Ready for Doubly Circular Linked List.
- [ ] Explain implementation confidently in technical interviews.
- [ ] Solve related coding problems independently.

---

# Author

**Ishwari Vijaykumar Surve**
