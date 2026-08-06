# 📚 Queue

## **Overview**

This repository contains the **complete step-by-step implementation of the Queue Data Structure** using **C**. The programs are designed sequentially, progressing from the basic node structure to a fully functional **Menu Driven Queue Application**.

A **Queue** is a fundamental linear data structure that follows the **FIFO (First In First Out)** principle, where the **first element inserted into the queue is the first element removed**. This repository demonstrates the implementation of various queue operations in a simple and structured manner.

---

# 🎯 What is a Queue?

## **Definition**

A **Queue** is a linear data structure where:

- **FIFO (First In First Out)** principle is followed.
- Insertion is performed at the **Rear**.
- Deletion is performed from the **Front**.
- Elements are processed in the order they are inserted.
- Supports efficient insertion and deletion operations.

---

# 📌 Visual Representation

```text
Front                        Rear
  │                           │
  ▼                           ▼

|11| → |21| → |51| → |101| → NULL
```
---

# 🧩 Node Structure

```c
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;
```

### **Description**

- **data** – Stores the value of the queue element.
- **next** – Stores the address of the next node in the queue.
- **NODE** – Alias for `struct node`.
- **PNODE** – Pointer to a node.
- **PPNODE** – Pointer to a pointer of a node.

---

# ⚙️ Operations Implemented

- Enqueue
- Dequeue
- Display
- Count

---

# ✨ Key Features

- Dynamic Queue Implementation
- FIFO Implementation
- Enqueue Operation
- Dequeue Operation
- Queue Traversal
- Count Queue Elements
- Menu Driven Application
- Dynamic Memory Allocation

---

# 💡 Applications

- CPU Scheduling
- Printer Queue
- Keyboard Buffer
- Breadth First Search (BFS)
- Process Scheduling
- Ticket Booking Systems
- Call Center Management
- Network Packet Processing

---

# 🎓 Learning Outcomes

- Understand FIFO principle
- Learn Queue operations
- Implement Queue in C
- Traverse queue elements
- Count queue elements
- Develop menu driven applications

---

# 🛠️ Technologies Used

- C Programming Language
- GCC Compiler
- Visual Studio Code
- Git
- GitHub

---

# 👨‍💻 Author

**Ishwari Vijaykumar Surve**

