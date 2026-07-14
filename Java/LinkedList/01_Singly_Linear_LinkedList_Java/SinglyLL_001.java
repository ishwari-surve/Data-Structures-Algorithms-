/*
===============================================================================

Program Name    : Singly Linear Linked List - Node Creation
Program Number  : 001
Description     : This program demonstrates the creation of a single node
                  for a Singly Linear Linked List in Java.
                  A node object is created dynamically using the
                  'new' keyword. The data member is initialized with
                  an integer value, while the next reference is set
                  to null, indicating that the node is currently
                  not connected to any other node.
Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve

===============================================================================

Concepts Used:

1. Classes and Objects
2. Self-Referential Class
3. Object References
4. Dynamic Object Creation using new
5. Instance Variables
6. Reference Initialization
7. Basic Memory Representation

Key Learning Points:

- Every node is an object in Java.
- Objects are created dynamically using the new keyword.
- The next reference stores the address of the next node object.
- A null reference indicates the end of the linked list.
- This program forms the basic building block of a Singly Linear Linked List.

===============================================================================
*/

class node
{
    public int data;
    public node next;
}

class SinglyLL001
{
    public static void main(String A[])
    {
        node newn = null;

        newn = new node();

        newn.data = 11;
        newn.next = null;

        System.out.println(newn.data);
        System.out.println(newn.next);
    }
}

/*
===============================================================================
Expected Output
===============================================================================

11
null

===============================================================================
Memory Diagram
===============================================================================

             newn
               |
               v
      +------------------+
      |    data = 11     |
      |------------------|
      |    next = null   |
      +------------------+

===============================================================================

Step-by-Step Execution

===============================================================================

Step 1:
A reference variable named newn is declared.

    node newn = null;

Currently it does not refer to any object.

Step 2:
Memory for a node object is allocated using the new keyword.

    newn = new node();

The reference variable now points to the newly created object.

Step 3:
The data member is initialized.

    newn.data = 11;

Step 4:
The next reference is initialized.

    newn.next = null;

Since there is no next node, the reference remains null.

Step 5:
The data member is displayed.

Output:

11

Step 6:
The next reference is displayed.

Output:

null

===============================================================================
Object Representation
===============================================================================

        newn
          |
          v

   +------------------+
   |   data : 11      |
   |------------------|
   |   next : null    |
   +------------------+

===============================================================================
Operations Performed
===============================================================================

1. Created a self-referential class.
2. Declared an object reference.
3. Allocated memory using the new keyword.
4. Stored an integer value in the node.
5. Initialized the next reference with null.
6. Displayed the node contents.

===============================================================================
Time Complexity
===============================================================================

Object Creation      : O(1)
Data Assignment      : O(1)
Display Values       : O(1)

Space Complexity     : O(1)


===============================================================================
Conclusion
===============================================================================

This program demonstrates the creation of a single node for a
Singly Linear Linked List using Java. It introduces the concepts
of classes, objects, object references, and dynamic object creation.
Understanding node creation is the first step toward implementing
complete linked list operations such as insertion, deletion,
traversal, and searching.

===============================================================================
*/
