/*
===============================================================================
Program Name    : Traversing Singly Circular Linked List using do-while Loop
Program Number  : 006
Description     : This program demonstrates the traversal of a Singly Circular
                  Linked List using a do-while loop in Java. Three nodes are
                  created dynamically and connected in a circular manner. The
                  traversal starts from the head node and continues until the
                  traversal reaches the head node again.

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
6. do-while Loop
7. Head Pointer
8. Linked List Traversal

Key Learning Points:
- A do-while loop is ideal for traversing circular linked lists.
- The first node is always processed before checking the condition.
- Traversal continues until temp reaches the head node again.
- Every node is visited exactly once.
- No NULL pointer is encountered in a circular linked list.

===============================================================================
*/
// Program 06 : Traversing Singly Circular Linked List using do-while

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

class SinglyCL6
{
    public static void main(String A[])
    {
        node head = null;
        node obj1 = null;
        node obj2 = null;
        node temp = null;

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
        temp = head;

        do
        {
            System.out.println(temp.data);
            temp = temp.next;
        }
        while(temp != head);
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

                      head
                       │
                       ▼
              +----+------+     +----+------+     +----+------+
              | 11 |   •------->| 21 |   •------->| 51 |   •----+
              +----+------+     +----+------+     +----+------+   |
                   ^                                              |
                   |______________________________________________|

Traversal using do-while:

head → 11 → 21 → 51
 ↑                  │
 └──────────────────┘

===============================================================================
Explanation:
===============================================================================

The program creates three node objects and links them together to form a
Singly Circular Linked List.

A temporary reference variable temp is initialized with the head node.

The traversal is performed using a do-while loop:

do
{
    System.out.println(temp.data);
    temp = temp.next;
}
while(temp != head);

Since a do-while loop executes its body before checking the condition, the
head node is always visited first.

The loop continues moving from one node to the next until temp again becomes
equal to head, indicating that one complete traversal of the circular linked
list has been completed.

This approach is preferred over a while loop because it naturally supports
the circular structure without missing the first node.

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
Execute do Block
      │
      ▼
Display Current Node
      │
      ▼
Move temp to Next Node
      │
      ▼
Is temp == head ?
      │
  No ─────────────► Repeat Loop
      │
     Yes
      │
      ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Defined a self-referential node class.
2. Created three node objects dynamically.
3. Stored data in each node.
4. Connected the nodes to form a circular linked list.
5. Initialized the temporary reference variable.
6. Traversed the linked list using a do-while loop.
7. Displayed each node exactly once.

===============================================================================
Time Complexity:
===============================================================================

Traversal        : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates the traversal of a Singly Circular Linked List
using a do-while loop. Since the traversal starts from the head node and
continues until the head is encountered again, each node is visited exactly
once without requiring a NULL reference. This makes the do-while loop the
most suitable choice for traversing circular linked lists.

===============================================================================
*/
