/*
===============================================================================
Program Name    : Creation and Linking of Two Nodes in Singly Circular Linked List
Program Number  : 001
Description     : This program demonstrates the creation of two nodes in Java
                  using a self-referential class. It introduces the basic node
                  structure, dynamic object creation, and linking of nodes using
                  reference variables. This serves as the foundation for
                  implementing linked list data structures.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class and Object
2. Constructor
3. Self-Referential Class
4. Reference Variables
5. Dynamic Memory Allocation using new
6. Node Linking

Key Learning Points:
- Every node stores data and a reference to the next node.
- Objects are created dynamically using the new keyword.
- Nodes are connected through reference variables.
- The last node currently points to null.
- This program forms the basic foundation for linked list implementation.

===============================================================================
*/
// Program 01 : Creation of Two Nodes

class node
{
    public int data;
    public node next;

    public node(int no)
    {
        data = no;
        next = null;
    }
}
class SinglyCL1
{
    public static void main(String A[])
    {
        node first = null;
        node second = null;

        first = new node(11);
        second = new node(21);

        first.next = second;
        second.next = null;

        System.out.println(first.data);
        System.out.println(second.data);
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

11
21

===============================================================================
Memory Representation:
===============================================================================

        first                     second
          │                         │
          ▼                         ▼
     +-----------+             +-----------+
     | data = 11 |             | data = 21 |
     | next -----|-----------> | next=NULL |
     +-----------+             +-----------+

===============================================================================
Explanation:
===============================================================================

The program defines a self-referential class named node containing two data
members: an integer data and a reference variable next.

Two node objects are created dynamically using the constructor.

The first node stores the value 11, while the second node stores the value 21.

The statement

first.next = second;

connects the first node to the second node.

Since no additional nodes are present, the next reference of the second node
is assigned null.

Finally, the data stored in both nodes is displayed using the respective
reference variables.

===============================================================================
Program Flow:
===============================================================================

Start Program
      │
      ▼
Create first and second References
      │
      ▼
Create First Node (11)
      │
      ▼
Create Second Node (21)
      │
      ▼
Link First Node to Second Node
      │
      ▼
Set Second Node Next as NULL
      │
      ▼
Display Node Data
      │
      ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Defined a self-referential node class.
2. Declared two node reference variables.
3. Created two node objects dynamically.
4. Stored data in each node.
5. Linked the first node with the second node.
6. Set the second node reference to NULL.
7. Displayed the data of both nodes.

===============================================================================
Time Complexity:
===============================================================================

Node Creation     : O(1)
Node Linking      : O(1)
Display Data      : O(1)

Space Complexity  : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 demonstrates the basic creation and linking of nodes using a
self-referential class in Java. It introduces dynamic object creation,
reference linking, and node traversal concepts that are essential for
implementing Singly Circular Linked Lists and other linked data structures.

===============================================================================
*/
