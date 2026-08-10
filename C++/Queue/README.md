# Queue in C++

## **Description**

* This folder contains **Queue Data Structure programs implemented in C++**.
* Queue follows the **FIFO (First In First Out)** principle.
* The Queue is implemented using a **Singly Linear Linked List**.
* The programs demonstrate the basic operations of Queue:

  * **Enqueue**
  * **Dequeue**
  * **Display**
  * **Count**
* The programs also demonstrate important **C++ Object-Oriented Programming concepts**.

## **Concepts Covered**

* **Queue Data Structure**
* **FIFO Principle**
* **Singly Linear Linked List**
* **Structure and Class**
* **Classes and Objects**
* **Constructors**
* **Pointers**
* **Dynamic Memory Allocation**
* **Member Functions**
* **Object-Oriented Programming**
* **Menu-Driven Application**

## **Queue Operations**

### **1. Enqueue**

* Inserts a new element at the **rear/end** of the Queue.
* A new node is dynamically allocated using `new`.
* The new node is connected to the last node of the Queue.

### **2. Dequeue**

* Removes an element from the **front** of the Queue.
* The first node is removed from the linked list.
* The memory occupied by the removed node is released.

### **3. Display**

* Displays all elements of the Queue.
* Elements are displayed from **front to rear**.

### **4. Count**

* Returns the total number of elements currently present in the Queue.
* The `iCount` variable is maintained inside the Queue class.

## **Node Structure**

```cpp
struct node
{
    int data;
    struct node *next;
};
```

### **Node Components**

* `data`

  * Stores the element of the Queue.
* `next`

  * Stores the address of the next node.

## **Queue Structure**

```text
Queue
 |
 |-- first
 |
 |-- iCount
```

* `first`

  * Points to the first node of the Queue.
* `iCount`

  * Stores the total number of elements in the Queue.

## **Queue Representation**

```text
Front                                      Rear
  |                                          |
  ↓                                          ↓

+------+    +------+    +------+    +------+
|  11  | -> |  21  | -> |  51  | -> | 101  | -> NULL
+------+    +------+    +------+    +------+
```

## **Technologies Used**

* **Language:** C++
* **Data Structure:** Queue
* **Implementation:** Singly Linear Linked List
* **Programming Concept:** Object-Oriented Programming
* **Memory Management:** Dynamic Memory Allocation using `new`
* **Compiler:** GCC / G++
* **IDE / Editor:** VS Code / CodeBlocks / Dev-C++ / Any C++ IDE

## **Requirements**

* **C++ Compiler**

  * GCC / G++
  * Clang
  * MSVC

* **IDE / Code Editor**

  * VS Code
  * CodeBlocks
  * Dev-C++
  * Any C++ IDE

## **Program List**

* **Queue_01.cpp** – Basic Queue Class Structure
* **Queue_02.cpp** – Enqueue Operation
* **Queue_03.cpp** – Enqueue and Display Operations
* **Queue_04.cpp** – Enqueue, Display and Count Operations
* **Queue_05.cpp** – Dequeue Operation
* **Queue_06.cpp** – Complete Queue Application

## **Time Complexity**

| **Operation** | **Time Complexity** |
| ------------- | ------------------: |
| Enqueue       |            **O(n)** |
| Dequeue       |            **O(1)** |
| Display       |            **O(n)** |
| Count         |            **O(1)** |

> **Note:** The current `Enqueue()` implementation traverses the linked list to reach the last node, therefore its time complexity is **O(n)**.

## **Author**

**Ishwari Vijaykumar Surve**


