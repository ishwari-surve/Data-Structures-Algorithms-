# Singly Circular Linked List in C++

## Overview

This repository demonstrates the implementation of a **Singly Circular Linked List (SCLL)** using **C++** and **Object-Oriented Programming (OOP)** concepts. The programs are developed in a step-by-step manner, beginning with the basic node structure and progressing to a complete **Menu-Driven Singly Circular Linked List** application.

A **Singly Circular Linked List** is a dynamic linear data structure where each node contains **data** and a **pointer to the next node**. Unlike a Singly Linear Linked List, the last node does **not** point to `NULL`; instead, it points back to the **first node**, creating a continuous circular structure.

This repository helps learners understand the internal working of circular linked lists, dynamic memory allocation, pointer manipulation, and various linked list operations in C++.

---

#  What is a Singly Circular Linked List?

A **Singly Circular Linked List** is a linked data structure in which:

- Each node stores **Data** and a **Next Pointer**.
- The **last node points back to the first node**.
- There is **no NULL pointer** at the end of the list.
- Traversal continues until the starting node is encountered again.
- Memory is allocated dynamically during program execution.

---

#  Node Structure

```text
+-------------+-------------+
|    Data     |    Next     |
+-------------+-------------+
```

---

#  Memory Visualization

```text
                         first
                           │
                           ▼
      +-----------+     +-----------+     +-----------+
      | Data : 11 | --> | Data : 21 | --> | Data : 51 |
      +-----------+     +-----------+     +-----------+
            ▲                                   │
            │                                   │
            └────────────── last->next ─────────┘
```

---

# Sample Output
Insert First : 51
Insert First : 21
Insert First : 11

Elements of Linked List:
|11| -> |21| -> |51| -> (Back to First)

Total Nodes : 3

Summation : 83
Maximum : 51
Minimum : 11

---

#  Technologies Used

- C++
- Object-Oriented Programming (OOP)
- Dynamic Memory Allocation (`new` and `delete`)
- Pointers
- Classes and Objects
- Constructors
- Encapsulation
- Circular Linked List
- Console-Based Programming
- GNU G++ (MinGW / GCC)
- Visual Studio Code
- Git & GitHub

---

#  Key Features

- Object-Oriented implementation using C++ classes
- Step-by-step learning approach from basic to advanced
- Dynamic node creation using constructors
- Circular node linking
- Forward traversal using `do-while` loop
- Efficient insertion at the beginning, end, and any position
- Efficient deletion from the beginning, end, and any position
- Position validation for safe operations
- Dynamic node counting
- Interactive menu-driven implementation
- Modular, reusable, and well-structured code
- Beginner-friendly implementation with detailed comments

---

# Operations Implemented

- Create List
- Display()
- Count()
- InsertFirst()
- InsertLast()
- InsertAtPos()
- DeleteFirst()
- DeleteLast()
- DeleteAtPos()
- Menu-Driven Implementation

---

#  Advantages

- Dynamic memory utilization
- No fixed memory limitation
- Continuous circular traversal
- Efficient insertion and deletion operations
- Better memory utilization than arrays
- Suitable for cyclic applications such as Round Robin Scheduling and Circular Queues

---

#  Limitations

- Only forward traversal is possible
- Pointer manipulation is slightly complex
- Infinite loop may occur if traversal condition is incorrect
- Random access is not supported

---

#  Learning Outcomes

After completing this repository, you will be able to:

- Understand the internal structure of a Singly Circular Linked List.
- Visualize circular node connections in memory.
- Implement all basic linked list operations in C++.
- Apply Object-Oriented Programming concepts to data structures.
- Perform insertion and deletion at different positions.
- Traverse circular linked lists efficiently.
- Build a complete Menu-Driven Singly Circular Linked List application.
- Strengthen Data Structures & Algorithms (DSA) and problem-solving skills.

---

#  Author

**Ishwari Vijaykumar Surve**

