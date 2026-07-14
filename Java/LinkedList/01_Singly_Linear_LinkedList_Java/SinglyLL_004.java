/*
===============================================================================

Program Name    : Singly Linear Linked List - Traversal Using Head Reference
Program Number  : 004
Description     : This program demonstrates how a Singly Linear
                  Linked List can be traversed by moving the head
                  reference from one node to the next.

                  Initially, the head reference points to the first
                  node. By assigning head = head.next, the head
                  reference advances to the next node, allowing
                  sequential access to every node in the linked list.

                  This program explains the internal traversal
                  mechanism and shows why modifying the original
                  head reference is generally avoided in practical
                  implementations.

Date            : July 2026
Language         : Java
Author           : Ishwari Vijaykumar Surve

===============================================================================
Concepts Used:

1. Classes and Objects
2. Self-Referential Class
3. Object References
4. Dynamic Object Creation
5. Head Reference
6. Node Traversal
7. Linked List Navigation

Key Learning Points:

- The head reference always points to the first node.
- Each node is accessed through its next reference.
- Traversal means visiting nodes one by one.
- Moving the head reference changes the starting point of the list.
- Practical traversal should use a temporary reference instead of modifying head.

===============================================================================
*/

class node
{
    public int data;
    public node next;
}

class SinglyLL004
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

        head = head.next;

        System.out.println(head.data);

        head = head.next;

        System.out.println(head.data);
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

Initially

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

The head reference points to the first node.

Output:

11

-------------------------------------------------------------------------------

Step 2:

The head reference is moved to the next node.

    head = head.next;

Now head points to the second node.

Output:

21

-------------------------------------------------------------------------------

Step 3:

The head reference is moved once again.

    head = head.next;

Now head points to the third node.

Output:

51

===============================================================================

Traversal Flow

===============================================================================

Initial Position

head
 |
 v
[11] ───► [21] ───► [51] ───► null

-------------------------------------------------------------------------------

After First Move

head
 |
 v
[21] ───► [51] ───► null

-------------------------------------------------------------------------------

After Second Move

head
 |
 v
[51] ───► null

===============================================================================

Important Observation

===============================================================================

This program modifies the original head reference.

After traversal completes:

head
 |
 v
[51] ───► null

The references to the previous nodes can no longer be accessed
through head.

Therefore, practical linked list traversal is performed using a
temporary reference.

Example:

node temp = head;

while(temp != null)
{
    System.out.println(temp.data);
    temp = temp.next;
}

The original head reference remains unchanged.

===============================================================================
Operations Performed
===============================================================================

1. Created three node objects.
2. Stored data inside each node.
3. Linked all nodes together.
4. Assigned the first node to the head reference.
5. Displayed the first node.
6. Moved the head reference to the second node.
7. Displayed the second node.
8. Moved the head reference to the third node.
9. Displayed the third node.
10. Demonstrated sequential linked list traversal.

===============================================================================
Time Complexity
===============================================================================

Node Creation          : O(1)
Node Linking           : O(1)
Traversal              : O(n)

Space Complexity       : O(1)

===============================================================================
Conclusion
===============================================================================

This program demonstrates the fundamental concept of traversing a
Singly Linear Linked List by following the next references from one
node to another. Although moving the head reference successfully
visits every node, it changes the starting point of the linked list.
For this reason, actual linked list implementations use a temporary
reference for traversal while preserving the original head reference.

===============================================================================
*/
