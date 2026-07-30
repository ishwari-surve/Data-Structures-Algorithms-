# **Doubly Circular Linked List in Java**

## **📖 Overview**

This repository contains the implementation of a **Doubly Circular Linked List** using **Java**.

A **Doubly Circular Linked List (DCLL)** is a dynamic data structure in which each node contains:

- **Data**
- **Reference to the Next Node**
- **Reference to the Previous Node**

The **last node points to the first node**, and the **first node points back to the last node**, forming a circular structure. Since the list is circular, there are **no NULL links** between nodes.

---

# **✨ Features**

- **Node Creation**
- **InsertFirst()**
- **InsertLast()**
- **InsertAtPos()**
- **DeleteFirst()**
- **DeleteLast()**
- **DeleteAtPos()**
- **Display()**
- **Count()**
- **Menu Driven Implementation**

---

# **📂 Programs Included**

- **Program 001** – Node Class & Object Creation
- **Program 002** – Skeleton Program
- **Program 003** – InsertFirst()
- **Program 004** – Display()
- **Program 005** – Count()
- **Program 006** – InsertLast()
- **Program 007** – DeleteFirst()
- **Program 008** – DeleteLast()
- **Program 009** – InsertAtPos()
- **Program 010** – Complete Implementation
- **Program 011** – Menu Driven Doubly Circular Linked List

---

# **📚 What is a Doubly Circular Linked List?**

A **Doubly Circular Linked List (DCLL)** is a linked list in which:

- Every node has **three parts**:
  - **Previous**
  - **Data**
  - **Next**
- Each node stores the address of both its **previous** and **next** node.
- The **last node links back to the first node**.
- The **first node links back to the last node**.
- Traversal is possible in both **forward** and **backward** directions.
- There is **no NULL node** at either end of the list.

---

# **🧩 Node Structure**

```text
+-------------------------------+
| Previous | Data | Next |
+-------------------------------+
```

---

# **🔄 Representation**

```text
                 +--------------------------------+
                 |                                |
                 ▼                                |
      +------+------+      +------+------+      +------+
      | Prev | 11 | Next |<==>| Prev | 21 | Next |<==>| Prev | 51 | Next |
      +------+------+      +------+------+      +------+
            ▲                                |
            |________________________________|
```

---

# **⚙️ Operations Implemented**

- **Insert at Beginning**
- **Insert at End**
- **Insert at Specific Position**
- **Delete from Beginning**
- **Delete from End**
- **Delete from Specific Position**
- **Display the Linked List**
- **Count Total Nodes**

---

# **💻 Technologies Used**

- **Programming Language:** Java
- **Concepts:** Object-Oriented Programming (OOP)
- **Data Structure:** Doubly Circular Linked List
- **IDE:** Eclipse / IntelliJ IDEA / Visual Studio Code

---

# **🎯 Learning Outcomes**

After completing these programs, you will understand:

- **Classes and Objects**
- **Self-Referential Classes**
- **Dynamic Memory Management**
- **Circular Linked List Operations**
- **Forward & Backward Traversal**
- **Position-Based Insertion & Deletion**
- **Menu Driven Programming**
- **Implementation of Dynamic Data Structures in Java**

---

# **🖥️ Sample Output**

```text
| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>

Number of Nodes : 5
```

---

# **📊 Time Complexity**

| **Operation** | **Complexity** |
|---------------|----------------|
| **InsertFirst()** | **O(1)** |
| **InsertLast()** | **O(1)** |
| **InsertAtPos()** | **O(n)** |
| **DeleteFirst()** | **O(1)** |
| **DeleteLast()** | **O(1)** |
| **DeleteAtPos()** | **O(n)** |
| **Display()** | **O(n)** |
| **Count()** | **O(1)** |

---

# **👩‍💻 Author**

## **Ishwari Vijaykumar Surve**


