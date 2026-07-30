/*
===============================================================================
Program Name    : Doubly Circular Linked List - Skeleton Program
Program Number  : 002
File Name       : DoublyCL_02.java
Description     : This program demonstrates the basic skeleton of a Doubly
                  Circular Linked List using Java. It initializes the linked
                  list with first, last, and node count.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Constructor
5. Reference Variables

Key Learning Points:
- Create the basic structure of a Doubly Circular Linked List.
- Initialize first and last references.
- Initialize the node count.
- Create an object of the linked list class.

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

class DoublyCL
{
    private Node first;
    private Node last;
    private int iCount;

    public DoublyCL()
    {
        first = null;
        last = null;
        iCount = 0;
    }
}

class DoublyCL_02
{
    public static void main(String A[])
    {
        DoublyCL obj = new DoublyCL();

        System.out.println("Empty Doubly Circular Linked List Created Successfully...");
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

Empty Doubly Circular Linked List Created Successfully...

===============================================================================
Memory Representation:
===============================================================================

          DoublyCL Object

      first  ─────► null

      last   ─────► null

      iCount = 0

===============================================================================
Algorithm:
===============================================================================

1. Define the Node class.
2. Define the DoublyCL class.
3. Declare first, last, and iCount.
4. Initialize them inside the constructor.
5. Create an object of DoublyCL.
6. Display the success message.
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
    Define DoublyCL Class
             │
             ▼
   Initialize first, last,
         and iCount
             │
             ▼
   Create DoublyCL Object
             │
             ▼
     Display Message
             │
             ▼
            Stop

===============================================================================
Time Complexity:
===============================================================================

Object Creation : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 002 demonstrates the basic skeleton of a Doubly Circular Linked List
in Java. It initializes the linked list by setting the first and last
references to null and the node count to zero. This serves as the foundation
for implementing all linked list operations.

===============================================================================
*/
