#  Stack in Java 

## Overview

This repository contains the complete step-by-step implementation of the **Stack Data Structure using Java** and Object-Oriented Programming (OOP) principles. The programs are designed sequentially, starting from the basic structure of a Stack and progressing to a fully functional Menu-Driven Stack Application.

A Stack is a fundamental Linear Data Structure that follows the **LIFO (Last-In-First-Out)** principle, where the last element inserted is the first element removed. This repository demonstrates the internal working of a Stack and provides practical implementations of all major Stack operations.

---

##  What is a Stack?

### Definition

A **Stack** is a linear data structure in which all insertion and deletion operations are performed from one end, known as the Top. It follows the **Last-In-First-Out (LIFO)** principle, meaning the last element inserted into the stack is the first element to be removed.

---

##  Characteristics of Stack

### Key Characteristics
-Follows the Last-In-First-Out (LIFO) principle.
-Insertion (Push) and deletion (Pop) occur only at the Top.
-Simple and efficient linear data structure.
-Can be implemented using Arrays or Linked Lists.
-Widely used in software development, compilers, and algorithm design.

---

## Visual Representation
                TOP
                 │
                 ▼
            +---------+
            |   50    |  ← Last Pushed
            +---------+
            |   40    |
            +---------+
            |   30    |
            +---------+
            |   20    |
            +---------+
            |   10    |  ← First Pushed
            +---------+

        Push()  ↑
        Pop()   ↓

        LIFO (Last-In-First-Out)

---

## Example
Push(10)
Push(20)
Push(30)
Push(40)
Push(50)

Stack:

TOP
 │
 ▼
50
40
30
20
10

Pop()

TOP
 │
 ▼
40
30
20
10

---

### Node Class Definition

```java
class node
{
    public int data;           // Data value
    public node next;          // Reference to next node
    
    node(int no)
    {
        this.data = no;
        this.next = null;
    }
}
```

---

## Basic Stack Operations
-Push()
-Pop()
-Peek() / Top()
-Display()
-Count()
-IsEmpty()

---

## Key Features

- Step-by-step Stack implementation.
- Developed using **Java** and **OOP** concepts.
- Supports **Push()** operation.
- Supports **Pop()** operation.
- Supports **Peek()** operation.
- Supports **Display()** operation.
- Supports **Count()** operation.
- Checks **IsEmpty()** condition.
- Interactive **Menu-Driven Application**.
- Easy to understand and beginner-friendly.

---

##  Applications of Stack

- Function Call Management
- Recursion
- Expression Evaluation
- Expression Conversion
- Parentheses Matching
- Undo and Redo Operations
- Browser Navigation
- Depth First Search (DFS)
- Backtracking Algorithms
- Syntax Parsing
- String Reversal
- Memory Management

---

##  Learning Outcomes

After completing this repository, you will be able to:

- Understand the Stack data structure.
- Explain the LIFO principle.
- Implement Stack using Java.
- Perform basic Stack operations.
- Apply OOP concepts.
- Analyze Stack operations.
- Develop a Menu-Driven Stack application.
- Improve problem-solving skills.
- Build a foundation for advanced data structures.

---

## Author

**Ishwari Vijaykumar Surve**  



