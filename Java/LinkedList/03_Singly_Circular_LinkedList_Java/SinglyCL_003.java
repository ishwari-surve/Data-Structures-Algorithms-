/*
===============================================================================
Program Name    : Creation of a Singly Circular Linked List in Java
Program Number  : 003
Description     : This program demonstrates the creation of a Singly Circular
                  Linked List using three nodes in Java. The nodes are linked
                  in a circular manner where the last node points back to the
                  first node instead of NULL. The program also displays the
                  node data and the reference stored in each next pointer.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class and Object
2. Default Constructor
3. Self-Referential Class
4. Dynamic Memory Allocation using new
5. Circular Linked List
6. Reference Variables
7. Node Linking

Key Learning Points:
- A circular linked list has no NULL at the end.
- The last node points back to the first node.
- Every node stores data and a reference to the next node.
- References can be printed to verify node connections.
- Circular linking allows continuous traversal of the list.

===============================================================================
*/
// Program 03 : Creation of Singly Circular Linked List in Java

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

class SinglyCL3
{
    public static void main(String A[])
    {
        node first = null;
        node second = null;
        node third = null;

        // Allocate memory for nodes
        first = new node();
        second = new node();
        third = new node();

        // Store data
        first.data = 11;
        second.data = 21;
        third.data = 51;

        // Connect nodes (Circular)
        first.next = second;
        second.next = third;
        third.next = first;

        // Display data
        System.out.println(first.data);
        System.out.println(second.data);
        System.out.println(third.data);

        // Display next references
        System.out.println(first.next);
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

(Note: The hexadecimal values will differ each time the program executes
because they represent the object's hash code.)

===============================================================================
Memory Representation:
===============================================================================

               first
                 │
                 ▼
        +----+------+     +----+------+     +----+------+
        | 11 |   •-------> | 21 |   •-------> | 51 |   •----+
        +----+------+     +----+------+     +----+------+   |
             ^                                                |
             |________________________________________________|

        11 → 21 → 51
         ↑          │
         └──────────┘

===============================================================================
Explanation:
===============================================================================

The program defines a self-referential class named node consisting of two data
members: data and next.

Three node objects are created dynamically using the default constructor.

Initially, each node contains default values:
- data = 0
- next = null

The values 11, 21, and 51 are then assigned to the three nodes.

Unlike a linear linked list, the nodes are connected in a circular fashion:

first → second → third → first

This means the last node does not point to NULL. Instead, it points back to
the first node, creating a continuous circular chain.

The program displays the data stored in each node and also prints the object
references stored in each next pointer to verify the circular links.

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
Link Nodes Circularly
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
2. Declared three node reference variables.
3. Created three node objects dynamically.
4. Assigned data values to each node.
5. Linked the nodes to form a circular linked list.
6. Printed the data stored in each node.
7. Displayed the reference stored in each next pointer.

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

Program 003 demonstrates the basic implementation of a Singly Circular Linked
List in Java. Unlike a linear linked list, the last node points back to the
first node, forming a closed loop. This circular structure forms the
foundation for implementing insertion, deletion, and traversal operations in
Singly Circular Linked Lists.

===============================================================================
*/
