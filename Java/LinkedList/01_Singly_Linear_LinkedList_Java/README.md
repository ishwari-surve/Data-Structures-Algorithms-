# Singly Linear Linked List in Java

## Overview

This folder contains a complete implementation of the **Singly Linear Linked List** using the **Java Programming Language**. The programs are developed from scratch to demonstrate the internal working of linked lists using **classes, objects, constructors, and object references**.

The implementation follows a structured approach, beginning with node creation and progressing to insertion, deletion, traversal, searching, and other utility operations. It is intended to strengthen the understanding of fundamental **Data Structures** while improving **Object-Oriented Programming (OOP)** skills in Java.

---

##  What is a Singly Linear Linked List?

A **Singly Linear Linked List** is a dynamic linear data structure composed of interconnected nodes. Each node contains:

- **Data** – Stores the integer value.
- **Next Reference** – Stores the reference of the next node.

The last node's **next** reference is **null**, indicating the end of the list.

### **Visualization**

```text
head
 |
 v
[11|•] ───► [21|•] ───► [51|null]
```

---

##  Node Structure

```java
class Node
{
    public int data;
    public Node next;

    public Node(int no)
    {
        this.data = no;
        this.next = null;
    }
}
```

### **Why Constructors?**

- Initializes every newly created node.
- Eliminates manual initialization.
- Promotes Object-Oriented Programming.
- Improves code readability and reusability.

---

##  Programs Included

The programs in this folder are arranged in a logical sequence to provide step-by-step learning of **Singly Linear Linked Lists**.

### **Program Progression**

### **Program Progression**

| Phase | Key Concepts |
|--------|--------------|
| **Foundation** | Classes, Objects, Node Structure, Object References |
| **Core Functions** | Constructors, Display(), Count(), Basic Traversal |
| **Insertion Operations** | InsertFirst(), InsertLast(), InsertAtPos() |
| **Deletion Operations** | DeleteFirst(), DeleteLast(), DeleteAtPos() |
| **Advanced Concepts** | Searching, Utility Functions, Problem Solving, Complexity Analysis |

> **Note:** Programs continue to be added as new topics are covered.

---

##  Topics Covered

### **Basic Concepts**

- Node Class
- Self-Referential Class
- Object References
- Constructors
- Object Creation using `new`
- Node Creation
- Node Initialization
- Node Linking
- Linked List Traversal
- `first` Reference
- Temporary Reference (`temp`)

### **Insertion Operations**

- Insert First — **O(1)**
- Insert Last — **O(n)**
- Insert At Position — **O(n)**

### **Deletion Operations**

- Delete First — **O(1)**
- Delete Last — **O(n)**
- Delete At Position — **O(n)**

### **Utility Operations**

- Display Linked List — **O(n)**
- Count Nodes — **O(n)**
- Search Element — **O(n)**

---

##  Concepts Covered

- Object-Oriented Programming (OOP)
- Classes and Objects
- Constructors
- Object References
- Self-Referential Classes
- Encapsulation
- Dynamic Object Creation
- Garbage Collection
- Linked Data Organization
- Modular Programming
- Time and Space Complexity Analysis

---

##  Applications

- Stack Implementation
- Queue Implementation
- Graph Representation
- Hash Tables
- Polynomial Manipulation
- Music Playlist Systems
- Browser Navigation
- Undo/Redo Functionality
- Dynamic Memory-Based Applications

---

##  Technologies Used

- **Language:** Java Programming Language
- **JDK:** Java 21
- **IDE:** Visual Studio Code
- **Version Control:** Git & GitHub

---

##  Learning Outcomes

After completing the programs in this folder, you will be able to:

- Understand the internal working of a Singly Linear Linked List.
- Implement insertion and deletion operations efficiently.
- Master object references and linked data structures.
- Perform traversal and searching operations.
- Analyze the time and space complexity of linked list operations.
- Apply Object-Oriented Programming concepts in Data Structures.
- Build a strong foundation for advanced Data Structures and Algorithms.

---

##  Key Features

- Clean and well-structured Java programs.
- Step-by-step implementation from basic concepts to advanced operations.
- Beginner-friendly and easy to understand.
- Well-commented source code.
- Follows Object-Oriented Programming principles.
- Suitable for academic learning, coding practice, and technical interview preparation.

---

##  Mastery Checklist

- [ ] Understand node class and object references.
- [ ] Understand self-referential classes.
- [ ] Know the purpose of constructors.
- [ ] Can draw accurate memory diagrams.
- [ ] Understand the `first` and `temp` references.
- [ ] Can write `InsertFirst()` from scratch.
- [ ] Can write `InsertLast()` from scratch.
- [ ] Can write `InsertAtPos()` from scratch.
- [ ] Can write `DeleteFirst()` from scratch.
- [ ] Can write `DeleteLast()` from scratch.
- [ ] Can write `DeleteAtPos()` from scratch.
- [ ] Know the time complexity of each operation.
- [ ] Ready for Doubly Linear Linked List.
- [ ] Can explain the implementation in technical interviews.
- [ ] Can solve related coding problems independently.

---

##  Author

**Ishwari Vijaykumar Surve**
