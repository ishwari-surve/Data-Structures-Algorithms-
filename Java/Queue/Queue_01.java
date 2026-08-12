/*
===============================================================================
Program Name    : Queue - Basic Structure
Program Number  : 01
File Name       : Queue_01.java
Description     : This program demonstrates the basic structure of a Queue
                  using Java. It defines the node structure, Queue class,
                  constructor, and initializes an empty Queue.

Date            : August 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================
*/

class node
{
    public int data;
    public node next;
}

class Queue
{
    private node first;
    private int iCount;

    public Queue()
    {
        first = null;
        iCount = 0;
    }
}

class Queue_01
{
    public static void main(String A[])
    {
        Queue qobj = new Queue();

        System.out.println("Queue created successfully");
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

Queue created successfully

===============================================================================
Memory Representation:
===============================================================================

              Queue Object

        +----------------------+
        | first  ------> NULL  |
        | iCount = 0           |
        +----------------------+

Queue is Empty.

===============================================================================
Node Structure:
===============================================================================

class node
{
    public int data;
    public node next;
}

Each node contains:

data  : Stores the Queue element.
next  : Stores the reference to the next node.

===============================================================================
Queue Representation:
===============================================================================

        first
          |
          v
       +------+
       | NULL |
       +------+

Initially, the Queue is empty and first contains null.

===============================================================================
Algorithm:
===============================================================================

1. Define the node class.
2. Declare data and next members in the node.
3. Define the Queue class.
4. Declare first and iCount members.
5. Initialize first to null.
6. Initialize iCount to 0 using the constructor.
7. Create a Queue object.
8. Display the Queue creation message.
9. Stop.

===============================================================================
Program Flow:
===============================================================================

        Start
          |
          v
   Define Node Class
          |
          v
   Define Queue Class
          |
          v
    Call Constructor
          |
          v
  first = null
  iCount = 0
          |
          v
   Create Queue Object
          |
          v
 Display Success Message
          |
          v
         Stop

===============================================================================
Time Complexity:
===============================================================================

Constructor : O(1)

Queue Object Creation : O(1)

===============================================================================
Space Complexity:
===============================================================================

O(1)

No Queue nodes are created in this program.

===============================================================================
Key Learning Points:
===============================================================================

- Understand the basic structure of a Queue in Java.
- Learn how a node is represented using a class.
- Understand the data and next members of a node.
- Understand the use of object references in Java.
- Initialize an empty Queue using a constructor.
- Understand the role of first and iCount.
- Learn the basic foundation required for linked-list based Queue operations.

===============================================================================
Conclusion:
===============================================================================

Program 001 introduces the basic structure of a Queue using Java. It defines
the node class, Queue class, constructor, and Queue data members. The Queue
is initialized as empty with first set to null and iCount set to zero. This
program serves as the foundation for implementing Queue operations such as
Enqueue, Dequeue, Display, and Count.

===============================================================================
*/
