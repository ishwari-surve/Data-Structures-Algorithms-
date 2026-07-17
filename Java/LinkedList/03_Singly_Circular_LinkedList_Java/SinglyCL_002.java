/*
===============================================================================
Program Name    : Creation and Linking of Three Nodes in Singly Circular Linked List
Program Number  : 002
Description     : This program demonstrates the creation of three nodes using
                  the default constructor in Java. The data members are
                  initialized separately, and the nodes are linked together
                  using reference variables to form a simple linked list.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class and Object
2. Default Constructor
3. Self-Referential Class
4. Dynamic Memory Allocation using new
5. Reference Variables
6. Node Linking

Key Learning Points:
- Objects can be created using a default constructor.
- Data members can be assigned values after object creation.
- Each node stores both data and the address of the next node.
- Nodes are connected through reference variables.
- The last node points to NULL, indicating the end of the list.

===============================================================================
*/
// Program 02 : Creation of Three Nodes

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

class SinglyCL2
{
    public static void main(String A[])
    {
        node first = null;
        node second = null;
        node third = null;

       
        first = new node();
        second = new node();
        third = new node();

       
        first.data = 11;
        second.data = 21;
        third.data = 51;

        
        first.next = second;
        second.next = third;
        third.next = null;

        
        System.out.println(first.data);
        System.out.println(second.data);
        System.out.println(third.data);
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

11
21
51

===============================================================================
Memory Representation:
===============================================================================

        first                  second                  third
          │                       │                       │
          ▼                       ▼                       ▼
     +-----------+          +-----------+          +-----------+
     | data = 11 |          | data = 21 |          | data = 51 |
     | next -----|--------> | next -----|--------> | next=NULL |
     +-----------+          +-----------+          +-----------+

===============================================================================
Explanation:
===============================================================================

The program defines a self-referential class named node containing two data
members: data and next.

Three node objects are created dynamically using the default constructor.

Initially, each node contains the default values:
- data = 0
- next = null

After object creation, values 11, 21, and 51 are assigned to the respective
nodes.

The nodes are then connected as follows:

first → second → third → NULL

Finally, the data stored in each node is displayed using the corresponding
reference variables.

===============================================================================
Program Flow:
===============================================================================

Start Program
      │
      ▼
Create Three Reference Variables
      │
      ▼
Create Three Node Objects
      │
      ▼
Assign Data to Each Node
      │
      ▼
Link Nodes Together
      │
      ▼
Set Last Node Next as NULL
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
2. Declared three node reference variables.
3. Created three node objects using the default constructor.
4. Assigned values to each node.
5. Linked all three nodes together.
6. Set the last node reference to NULL.
7. Displayed the data stored in each node.

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

Program 002 demonstrates the creation of multiple nodes using the default
constructor and shows how values can be assigned after object creation.
The program also illustrates how nodes are connected to form a linked
structure, providing the basic foundation for implementing Singly Circular
Linked Lists in Java.

===============================================================================
*/
