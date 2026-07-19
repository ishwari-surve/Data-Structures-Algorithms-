#  Singly Circular Linked List in Java

##  Overview

This repository demonstrates the implementation of a **Singly Circular Linked List (SCLL)** using **Java** and **Object-Oriented Programming (OOP)** concepts. The programs are designed in a step-by-step manner, starting from basic node creation and progressing to a complete **Menu-Driven Singly Circular Linked List** implementation.

A Singly Circular Linked List is a dynamic data structure in which every node contains a **data field** and a **reference to the next node**. Unlike a Singly Linear Linked List, the **last node points back to the first node**, forming a continuous circular chain.

This collection helps learners understand how circular linked lists work internally and how various insertion, deletion, traversal, and position-based operations are implemented efficiently.

---

#  What is a Singly Circular Linked List?

A **Singly Circular Linked List** is a linked data structure where:

- Every node contains **Data** and a **Next** reference.
- The **last node does not point to NULL**.
- Instead, the **last node points back to the first node**.
- Traversal continues until the starting node is reached again.
- Memory is allocated dynamically during program execution.

---

#  Node Structure

```java
class node
{
    public int data;              // Data value stored in node
    public node next;             // Reference to next node
    
    // Constructor - Parameterized Initialization
    node(int no)
    {
        this.data = no;           // Initialize data field
        this.next = null;         // Initialize next to null
    }
}
+-------------+-------------+
|    Data     |    Next     |
+-------------+-------------+

```

---

#  Memory Visualization

```
        first
          │
          ▼
      +-----------+     +-----------+     +-----------+
      | Data : 11 | --> | Data : 21 | --> | Data : 51 |
      +-----------+     +-----------+     +-----------+
            ▲                                   │
            │                                   │
            └────────────── last.next ──────────┘
```

---

## Sample Output
Elements of Linked List:

|11| -> |21| -> |51| -> (Back to First)

Total Nodes : 3

---

##  Technologies & Tools Used

### Programming & Development
- **Language:** Java (JDK 8+)
- **Paradigm:** Object-Oriented Programming (OOP)
- **Memory Management:** Dynamic Allocation (new keyword)
- **Reference Variables:** Implicit Pointers

### Development Environment
- **IDE:** Visual Studio Code, IntelliJ IDEA, or Eclipse
- **Compiler:** Java Compiler (javac)
- **Runtime:** Java Virtual Machine (JVM)

### Version Control
- **Git** for version tracking
- **GitHub** for repository management

### Concepts Applied
- **OOP Principles:** Encapsulation, Abstraction, Inheritance
- **Data Structures:** Circular Linked List, Node Structure
- **Algorithms:** Insertion, Deletion, Traversal
- **Design Patterns:** Constructor Pattern, Encapsulation Pattern
  
---

#  Key Features

- Complete implementation using Java classes and objects
- Step-by-step learning approach from basic to advanced
- Dynamic node creation using constructors
- Circular node linking
- Forward traversal using `do-while` loop
- Efficient insertion at beginning, end, and any position
- Efficient deletion from beginning, end, and any position
- Position validation for safe operations
- Dynamic node counting
- Interactive menu-driven implementation
- Modular and reusable code
- Well-commented programs for better understanding

---

#  Operations Supported

###  Insertion Operations

- InsertFirst()
- InsertLast()
- InsertAtPos()

###  Deletion Operations

- DeleteFirst()
- DeleteLast()
- DeleteAtPos()

###  Utility Operations

- Display()
- Count()

---

#  Advantages

- Dynamic memory utilization
- No memory wastage due to fixed size
- Continuous circular traversal
- Efficient insertion and deletion operations
- Suitable for cyclic applications such as scheduling and buffering

---

#  Limitations

- Only forward traversal is possible
- More complex traversal compared to linear linked lists
- Careful termination condition is required to avoid infinite loops
- Random access is not supported

---

#  Learning Outcomes

After completing these programs, you will be able to:

- Understand the internal working of a Singly Circular Linked List.
- Visualize circular node connections in memory.
- Implement all basic linked list operations in Java.
- Apply Object-Oriented Programming concepts to data structures.
- Perform insertion and deletion at different positions.
- Traverse circular linked lists correctly using `do-while`.
- Develop a complete Menu-Driven Singly Circular Linked List application.
- Strengthen problem-solving and Data Structures & Algorithms (DSA) skills.

---

#  Author

**Ishwari Vijaykumar Surve**


