/*
===============================================================================
Program Name    : Traversing a Singly Circular Linked List
Program Number  : 005
Description     : This program demonstrates the traversal of a Singly Circular
                  Linked List in Java. Three nodes are created dynamically and
                  connected in a circular manner. A temporary reference is used
                  to traverse the list by moving from one node to the next.
                  The traversal shows that after reaching the last node, the
                  control returns to the head node because of the circular link.

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
6. Head Pointer
7. Traversal using Temporary Reference

Key Learning Points:
- Traversal begins from the head node.
- A temporary reference is used for traversal.
- temp moves to the next node using temp.next.
- The last node points back to the head node.
- Circular linked lists do not contain a NULL link.

===============================================================================
*/
// Program 05 : Traversing Singly Circular Linked List

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

class SinglyCL5
{
    public static void main(String A[])
    {
        node head = null;
        node obj1 = null;
        node obj2 = null;

        // Allocate memory
        head = new node();
        obj1 = new node();
        obj2 = new node();

        // Store data
        head.data = 11;
        obj1.data = 21;
        obj2.data = 51;

        // Connect nodes
        head.next = obj1;
        obj1.next = obj2;
        obj2.next = head;

        // Traversal
        node temp = head;

        System.out.println(temp.data);

        temp = temp.next;
        System.out.println(temp.data);

        temp = temp.next;
        System.out.println(temp.data);

        temp = temp.next;
        System.out.println(temp.data);
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

11
21
51
11

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

Traversal:

temp
 │
 ▼
11 → 21 → 51 → 11 → ...

===============================================================================
Explanation:
===============================================================================

The program creates three node objects and connects them to form a Singly
Circular Linked List.

Initially, the temporary reference temp points to the head node.

The traversal is performed by repeatedly executing:

temp = temp.next;

The traversal sequence is:

Step 1 : temp points to node containing 11.
Step 2 : temp moves to node containing 21.
Step 3 : temp moves to node containing 51.
Step 4 : temp moves again and reaches the head node because the last node
         points back to head.

Unlike a Singly Linear Linked List, traversal in a circular linked list does
not terminate at NULL because there is no NULL reference.

===============================================================================
Program Flow:
===============================================================================

Start Program
      │
      ▼
Create Three Nodes
      │
      ▼
Assign Data
      │
      ▼
Connect Nodes Circularly
      │
      ▼
Initialize temp = head
      │
      ▼
Display 11
      │
      ▼
Move temp to Next Node
      │
      ▼
Display 21
      │
      ▼
Move temp to Next Node
      │
      ▼
Display 51
      │
      ▼
Move temp to Next Node
      │
      ▼
Display 11 Again
      │
      ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Defined a self-referential node class.
2. Created three node objects.
3. Assigned data to each node.
4. Connected the nodes in a circular manner.
5. Initialized a temporary reference for traversal.
6. Traversed the linked list using next references.
7. Verified that traversal returns to the head node.

===============================================================================
Time Complexity:
===============================================================================

Traversal Steps : O(1)

Space Complexity: O(1)

===============================================================================
Conclusion:
===============================================================================

Program 005 demonstrates the basic traversal of a Singly Circular Linked
List using a temporary reference variable. Since the last node points back
to the head node, traversal continues cyclically instead of terminating at
NULL. This concept forms the basis for implementing complete traversal and
other operations in a Singly Circular Linked List.

===============================================================================
*/
