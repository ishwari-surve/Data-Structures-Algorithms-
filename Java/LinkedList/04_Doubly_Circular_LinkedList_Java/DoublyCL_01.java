/*
===============================================================================
Program Name    : Doubly Circular Linked List - Node Class & Object Creation
Program Number  : 001
File Name       : DoublyCL_01.java
Description     : This program demonstrates the creation of a node for a
                  Doubly Circular Linked List using Java.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Constructor
5. Objects

Key Learning Points:
- Create a node for a Doubly Circular Linked List.
- Understand self-referential classes.
- Initialize data, next, and previous references.
- Create an object of the Node class.

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

class DoublyCL_01
{
    public static void main(String A[])
    {
        Node obj = new Node(11);

        System.out.println("Data : " + obj.data);
        System.out.println("Next : " + obj.next);
        System.out.println("Previous : " + obj.prev);
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

        obj
         │
         ▼

+--------------------------------+
| Prev | Data | Next |
| null |  11  | null |
+--------------------------------+

===============================================================================
Algorithm:
===============================================================================

1. Define the Node class.
2. Declare data, next, and previous members.
3. Create a constructor to initialize the node.
4. Create an object of the Node class.
5. Display the data and reference values.
6. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
             │
             ▼
      Define Node Class
             │
             ▼
      Create Constructor
             │
             ▼
      Create Node Object
             │
             ▼
     Display Node Details
             │
             ▼
            Stop

===============================================================================
Time Complexity:
===============================================================================

Node Creation : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 demonstrates the basic structure of a node in a Doubly Circular
Linked List using Java. Each node stores data along with references to the
next and previous nodes. This forms the foundation for implementing all
subsequent Doubly Circular Linked List operations.

===============================================================================
*/
