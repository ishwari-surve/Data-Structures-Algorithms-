/*
===============================================================================
Program Name    : Singly Linear Linked List - Accessing Node Data
Program Number  : 003
Description     : This program demonstrates how to access the data
                  stored in individual nodes of a Singly Linear
                  Linked List using the head reference and chained
                  next references.

                  Three node objects are dynamically created,
                  linked together, and their data members are
                  accessed sequentially without using loops.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve

===============================================================================
Concepts Used:

1. Classes and Objects
2. Self-Referential Class
3. Object References
4. Dynamic Object Creation using new
5. Head Reference
6. Manual Node Linking
7. Sequential Node Access

Key Learning Points:

- The head reference always points to the first node.
- Every node is accessed through its previous node.
- The next reference creates the connection between nodes.
- Chained references can be used to reach any node in the list.
- This program introduces the concept of linked list traversal without loops.

===============================================================================
*/

class node
{
    public int data;
    public node next;
}

class SinglyLL003
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

        System.out.println(head.data);
        System.out.println(head.next.data);
        System.out.println(head.next.next.data);
    }
}

/*
===============================================================================
Expected Output
===============================================================================

11
21
51

===============================================================================
Memory Diagram
===============================================================================

head
 |
 v
+-----------+     +-----------+     +-------------+
| data : 11 | --> | data : 21 | --> | data : 51   |
| next : ---|     | next : ---|     | next : null |
+-----------+     +-----------+     +-------------+

===============================================================================
Step-by-Step Execution
===============================================================================

Step 1:
Four reference variables are declared.

    node head = null;
    node obj1 = null;
    node obj2 = null;
    node obj3 = null;

-------------------------------------------------------------------------------

Step 2:
Memory is allocated for three node objects.

    obj1 = new node();
    obj2 = new node();
    obj3 = new node();

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

-------------------------------------------------------------------------------

Step 5:
The head reference stores the address of the first node.

    head = obj1;

-------------------------------------------------------------------------------

Step 6:
The node data is accessed through chained references.

First Node

    head.data

Output:

11

Second Node

    head.next.data

Output:

21

Third Node

    head.next.next.data

Output:

51

===============================================================================
Reference Flow
===============================================================================

head
 |
 v
obj1 ───► obj2 ───► obj3 ───► null

===============================================================================
Operations Performed
===============================================================================
1. Created a self-referential class.
2. Declared object references.
3. Allocated memory for three node objects.
4. Stored data in each node.
5. Linked all nodes using next references.
6. Assigned the first node to the head reference.
7. Accessed the first node using head.
8. Accessed the second node using head.next.
9. Accessed the third node using head.next.next.
10. Displayed the data stored in each node.

===============================================================================
Time Complexity
===============================================================================

Node Creation          : O(1)
Node Linking           : O(1)
Access First Node      : O(1)
Access Second Node     : O(1)
Access Third Node      : O(1)

Overall                : O(1)

Space Complexity       : O(1)

===============================================================================
Conclusion
===============================================================================

This program demonstrates how the head reference acts as the entry
point of a Singly Linear Linked List. By following the next references,
each node can be accessed sequentially. Understanding chained object
references is fundamental before implementing linked list traversal,
Display(), Count(), insertion, and deletion operations.

===============================================================================
*/
