/*
===============================================================================

Program Name    : Singly Linear Linked List - Manual Node Linking
Program Number  : 002
Description     : This program demonstrates the manual creation and
                  linking of multiple nodes in a Singly Linear Linked
                  List using Java.

                  Three node objects are dynamically created using
                  the 'new' keyword. Their data members are initialized
                  with integer values, and the nodes are connected
                  through their next references. A head reference is
                  used to store the address of the first node in the
                  linked list.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve

===============================================================================
Concepts Used:

1. Classes and Objects
2. Self-Referential Class
3. Object References
4. Dynamic Object Creation using new
5. Manual Node Linking
6. Head Reference
7. Singly Linear Linked List

Key Learning Points:

- Every node is an independent object.
- Nodes are connected using the next reference.
- The head reference always points to the first node.
- The last node's next reference is always null.
- Linked Lists are created dynamically during program execution.

===============================================================================
*/

class node
{
    public int data;
    public node next;
}

class SinglyLL002
{
    public static void main(String A[])
    {
        node head = null;
        node obj1 = null;
        node obj2 = null;
        node obj3 = null;

        obj1 = new node();
        obj2 = new node();
        obj3 = new node();

        obj1.data = 11;
        obj2.data = 21;
        obj3.data = 51;

        obj1.next = obj2;
        obj2.next = obj3;
        obj3.next = null;

        head = obj1;
    }
}

/*
===============================================================================
Expected Output
===============================================================================

No Output

The program demonstrates the internal creation and linking of nodes
in memory.

===============================================================================
Memory Diagram
===============================================================================

head
 |
 v
+-----------+     +-----------+     +-----------+
| data : 11 | --> | data : 21 | --> | data : 51 |
| next : ---|     | next : ---|     | next:null |
+-----------+     +-----------+     +-----------+

===============================================================================
Step-by-Step Execution
===============================================================================

Step 1:
Four reference variables are declared.

    node head = null;
    node obj1 = null;
    node obj2 = null;
    node obj3 = null;

Initially, all references contain null.

-------------------------------------------------------------------------------

Step 2:
Memory is allocated for three node objects.

    obj1 = new node();
    obj2 = new node();
    obj3 = new node();

Each reference now points to a separate node object.

-------------------------------------------------------------------------------

Step 3:
Data values are assigned.

    obj1.data = 11;
    obj2.data = 21;
    obj3.data = 51;

-------------------------------------------------------------------------------

Step 4:
The nodes are linked together.

    obj1.next = obj2;
    obj2.next = obj3;
    obj3.next = null;

The last node points to null, indicating the end of the list.

-------------------------------------------------------------------------------

Step 5:
The head reference stores the address of the first node.

    head = obj1;

The linked list is now ready.

===============================================================================
Final Linked List
===============================================================================

head
 |
 v
[11|•] ───► [21|•] ───► [51|null]

===============================================================================
Operations Performed
===============================================================================

1. Created a self-referential class.
2. Declared object references.
3. Allocated memory for three node objects.
4. Initialized data members.
5. Linked nodes using next references.
6. Assigned the first node to the head reference.
7. Constructed a complete Singly Linear Linked List.

===============================================================================
Time Complexity
===============================================================================

Node Creation      : O(1)
Node Linking       : O(1)
Head Assignment    : O(1)

Overall            : O(1)

Space Complexity   : O(1)

===============================================================================
Conclusion
===============================================================================

This program demonstrates how multiple node objects are manually
connected to form a Singly Linear Linked List. It introduces the
concept of linking nodes through object references and highlights
the importance of the head reference as the entry point of the
linked list. This forms the foundation for implementing traversal,
insertion, deletion, and searching operations in subsequent programs.

===============================================================================
*/
