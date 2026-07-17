/*
===============================================================================
Program Name    : Creation of Singly Circular Linked List using Head Pointer
Program Number  : 004
Description     : This program demonstrates the creation of a Singly Circular
                  Linked List using a head pointer in Java. Three nodes are
                  created dynamically and connected in a circular manner where
                  the last node points back to the head node. The program
                  displays the node data and the references stored in each
                  next pointer.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class and Object
2. Default Constructor
3. Self-Referential Class
4. Dynamic Memory Allocation using new
5. Head Pointer
6. Circular Linked List
7. Reference Variables

Key Learning Points:
- The head pointer stores the address of the first node.
- Every node contains data and a reference to the next node.
- The last node points back to the head node.
- A circular linked list has no NULL at the end.
- Printing references verifies the circular connections.

===============================================================================
*/
// Program 04 : Singly Circular Linked List using Head Pointer

class node
{
    public int data;
    public node next;

    public node()
    {
        data = 0;
        next = null;
    }
}

class SinglyCL4
{
    public static void main(String A[])
    {
        node head = null;
        node second = null;
        node third = null;

        // Allocate memory
        head = new node();
        second = new node();
        third = new node();

        // Store data
        head.data = 11;
        second.data = 21;
        third.data = 51;

        // Connect nodes
        head.next = second;
        second.next = third;
        third.next = head;

        // Display data
        System.out.println(head.data);
        System.out.println(second.data);
        System.out.println(third.data);

        // Display next references
        System.out.println(head.next);
        System.out.println(second.next);
        System.out.println(third.next);
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

11
21
51
node@xxxxxxxx
node@xxxxxxxx
node@xxxxxxxx

(Note: The hexadecimal values will differ for every execution because they
represent the object's hash code.)

===============================================================================
Memory Representation:
===============================================================================

                      head
                       │
                       ▼
              +----+------+     +----+------+     +----+------+
              | 11 |   •------->| 21 |   •------->| 51 |   •----+
              +----+------+     +----+------+     +----+------+   |
                   ^                                              |
                   |______________________________________________|

                11 → 21 → 51
                 ↑          │
                 └──────────┘

===============================================================================
Explanation:
===============================================================================

The program defines a self-referential class named node containing two data
members: data and next.

Three node objects are created dynamically using the default constructor.

The variable head acts as the head pointer and always stores the reference of
the first node in the linked list.

The nodes are connected as follows:

head → second → third → head

The last node points back to the head node, forming a circular linked list.
Unlike a linear linked list, there is no NULL reference at the end.

The program prints the data stored in each node and also displays the object
references stored in their next pointers to verify the circular links.

===============================================================================
Program Flow:
===============================================================================

Start Program
      │
      ▼
Create Head and Other Node References
      │
      ▼
Create Three Node Objects
      │
      ▼
Assign Data to Each Node
      │
      ▼
Connect Nodes Circularly
      │
      ▼
Display Node Data
      │
      ▼
Display Next References
      │
      ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Defined a self-referential node class.
2. Declared head, second and third reference variables.
3. Created three node objects dynamically.
4. Assigned data values to each node.
5. Connected the nodes to form a circular linked list.
6. Printed the data stored in each node.
7. Displayed the references stored in the next pointers.

===============================================================================
Time Complexity:
===============================================================================

Node Creation    : O(1)
Node Linking     : O(1)
Display Data     : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates the creation of a Singly Circular Linked List using
a head pointer. The head pointer always refers to the first node, while the
last node points back to the head, forming a closed circular structure. This
serves as the foundation for implementing traversal, insertion, and deletion
operations in a Singly Circular Linked List.

===============================================================================
*/
