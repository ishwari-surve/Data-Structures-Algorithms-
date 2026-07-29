/*
===============================================================================
Program Name    : Doubly Linear Linked List - Skeleton Program
Program Number  : 002
File Name       : DoublyLL_02.java
Description     : This program demonstrates the basic skeleton of a Doubly
                  Linear Linked List using Java. It defines the Node class,
                  Linked List class, constructor, and an empty Display()
                  function.

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
- Create a Node class.
- Create a Doubly Linear Linked List class.
- Initialize first, last, and node count.
- Create the basic structure before implementing operations.

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

class DoublyLL
{
    private Node first;
    private Node last;
    private int iCount;

    public DoublyLL()
    {
        first = null;
        last = null;
        iCount = 0;
    }

    public void Display()
    {

    }
}

class DoublyLL_02
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();

        dobj.Display();
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

The program only creates the linked list object and calls an empty Display()
method.

===============================================================================
Memory Representation:
===============================================================================

        DoublyLL Object

      +-------------------+
      | first  = null     |
      | last   = null     |
      | iCount = 0        |
      +-------------------+

No nodes are created.

===============================================================================
Algorithm:
===============================================================================

1. Define the Node class.
2. Define the DoublyLL class.
3. Declare first, last, and iCount.
4. Initialize them using the constructor.
5. Create an empty Display() method.
6. Create an object of DoublyLL.
7. Call Display().
8. Stop.

===============================================================================
Program Flow:
===============================================================================

        Start
           │
           ▼
    Define Node Class
           │
           ▼
  Define DoublyLL Class
           │
           ▼
 Create DoublyLL Object
           │
           ▼
     Call Display()
           │
           ▼
          Stop

===============================================================================
Time Complexity:
===============================================================================

Constructor : O(1)

Display() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 002 provides the basic skeleton of a Doubly Linear Linked List in
Java. It initializes the linked list object and prepares the framework for
implementing insertion, deletion, display, and other linked list operations
in subsequent programs.

===============================================================================
*/

