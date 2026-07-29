/*
===============================================================================
Program Name    : Doubly Linear Linked List - Node Class & Object Creation
Program Number  : 001
File Name       : DoublyLL_01.java
Description     : This program demonstrates the basic structure of a Doubly
                  Linear Linked List by creating a Node class and an object of
                  that class.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object Creation
3. Reference Variable
4. Self-Referential Class
5. Constructors

Key Learning Points:
- Understand the structure of a node.
- Create an object of the Node class.
- Initialize node data members.
- Learn how previous and next references work.

===============================================================================
*/

class Node
{
    public int data;
    public Node next;
    public Node prev;

    public Node(int no)
    {
        data = no;
        next = null;
        prev = null;
    }
}

class DoublyLL_01
{
    public static void main(String A[])
    {
        Node first = new Node(11);

        System.out.println("Data : " + first.data);
        System.out.println("Next : " + first.next);
        System.out.println("Previous : " + first.prev);
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

Data : 11
Next : null
Previous : null

===============================================================================
Memory Representation:
===============================================================================

        first
          │
          ▼

     +-----------+
     | data = 11 |
     | next=null |
     | prev=null |
     +-----------+

===============================================================================
Algorithm:
===============================================================================

1. Define a Node class.
2. Declare data, next, and prev members.
3. Create a parameterized constructor.
4. Create an object of Node in main().
5. Initialize the node with a value.
6. Display the data, next, and previous references.
7. Stop.

===============================================================================
Program Flow:
===============================================================================

        Start
           │
           ▼
    Define Node Class
           │
           ▼
     Create Node Object
           │
           ▼
    Initialize Members
           │
           ▼
     Display Node Data
           │
           ▼
          Stop

===============================================================================
Time Complexity:
===============================================================================

Object Creation : O(1)

Display : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 introduces the basic building block of a Doubly Linear Linked
List. It demonstrates how a node stores data along with references to the
next and previous nodes, forming the foundation for implementing linked list
operations in Java.

===============================================================================
*/
