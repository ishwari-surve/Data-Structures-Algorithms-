# Queue in Java

This folder contains programs that demonstrate the fundamental concepts of **Queue in Java**, including queue operations, node structure, linked list implementation, and object-oriented programming concepts.

## Topics Covered

1. **Queue Concept**
   - FIFO (First In First Out)
   - Front
   - Rear
   - Enqueue operation
   - Dequeue operation

2. **Node Structure**
   - Data
   - Next Reference
   - Self-referential Node
   - Linking Nodes

3. **Queue Operations**
   - Enqueue
   - Dequeue
   - Display
   - Count
   - IsEmpty

4. **Queue Implementation**
   - Array
   - Linked List
   - Class and Object
   - Dynamic Object Creation

5. **Queue Analysis**
   - Best Case
   - Average Case
   - Worst Case
   - Time Complexity
   - Space Complexity

## Node Structure

- Data
- Next Reference
- Self-referential Node
- Dynamic Node Creation
- Linking Nodes using References
- Connecting One Node to the Next Node

          Queue Node
     +----------------+
     |      data      |
     +----------------+
     |      next      | -----> Reference to next Node
     +----------------+

  class Node
{
    int data;
    Node next;

}

## Queue Representation
FRONT                                      REAR
  |                                          |
  v                                          v
+------+-------+    +------+-------+    +------+-------+
|  11  |   o-------->|  21  |   o-------->|  51  | NULL |
+------+-------+    +------+-------+    +------+-------+

        Dequeue  <-------------------  Enqueue

## Structure

```text
Queue
│
├── Queue Concept
│   ├── FIFO
│   ├── Front
│   └── Rear
│
├── Node Structure
│   ├── Data
│   └── Next Reference
│
├── Queue Operations
│   ├── Enqueue
│   ├── Dequeue
│   ├── Display
│   ├── Count
│   └── IsEmpty
│
├── Queue Implementation
│   ├── Array
│   └── Linked List
│
└── Queue Analysis
    ├── Time Complexity
    └── Space Complexity

## Applications

- Process scheduling
- Printer job management
- CPU task scheduling
- Keyboard and I/O buffering
- Network packet handling
- Breadth First Search (BFS)
- Customer service systems
- Request processing
- Message processing
- Task management

## Key Learning Points

- Understand the basic concept of Queue.
- Understand the FIFO principle.
- Learn the role of Front and Rear.
- Understand the structure of a Queue node.
- Learn how Enqueue operation works.
- Learn how Dequeue operation works.
- Implement Queue using arrays and linked lists.
- Understand how nodes are connected using references.
- Handle empty Queue conditions.
- Analyze time and space complexity.

## Requirements

- Java Development Kit (JDK)
- Java Compiler (`javac`)
- VS Code / Eclipse / IntelliJ IDEA / Any Java IDE
- Command Prompt / Terminal

## Author

**Ishwari Vijaykumar Surve**

