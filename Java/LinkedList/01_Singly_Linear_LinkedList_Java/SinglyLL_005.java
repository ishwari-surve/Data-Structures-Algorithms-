/*
===============================================================================
Program Name    : Singly Linear Linked List - Traversal Using Temporary Reference
Program Number  : 005
File Name       : SinglyLL005.java

Description     : This program demonstrates how to traverse a Singly
                  Linear Linked List using a temporary reference
                  variable (temp). Instead of moving the original
                  head reference, a separate reference is used to
                  visit each node sequentially.

                  This approach preserves the head reference and is
                  the standard technique used in linked list
                  operations such as Display(), Count(), Search(),
                  Maximum(), Minimum(), and Frequency().

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================
Concepts Used:

1. Classes and Objects
2. Self-Referential Class
3. Object References
4. Dynamic Object Creation
5. Head Reference
6. Temporary Reference (temp)
7. Linked List Traversal

Key Learning Points:

- A temporary reference is used for traversal.
- The head reference remains unchanged.
- Each node is visited through its next reference.
- This is the standard traversal technique used in Linked Lists.
- The linked list can be traversed multiple times because head is preserved.

===============================================================================
*/

class node
{
    public int data;
    public node next;
}

class SinglyLL005
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

        node temp = head;

        System.out.println(temp.data);

        temp = temp.next;

        System.out.println(temp.data);

        temp = temp.next;

        System.out.println(temp.data);
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

head,temp
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

A temporary reference is created.

    node temp = head;

Both head and temp point to the first node.

-------------------------------------------------------------------------------

Step 7:

Display the first node.

    System.out.println(temp.data);

Output:

11

Move temp to the next node.

    temp = temp.next;

-------------------------------------------------------------------------------

Step 8:

Display the second node.

Output:

21

Move temp to the next node.

    temp = temp.next;

-------------------------------------------------------------------------------

Step 9:

Display the third node.

Output:

51

===============================================================================
Traversal Representation
===============================================================================

Initially

head,temp
    |
    v
[11] ───► [21] ───► [51] ───► null

-------------------------------------------------------------------------------

After First Move

head
 |
 v
[11] ───► [21] ───► [51] ───► null
             ^
             |
            temp

-------------------------------------------------------------------------------

After Second Move

head
 |
 v
[11] ───► [21] ───► [51] ───► null
                          ^
                          |
                         temp

===============================================================================
Important Observation
===============================================================================

The temporary reference (temp) is used for traversal while the
head reference remains unchanged.

This preserves the starting address of the linked list and allows
the list to be traversed multiple times.

Using a temporary reference is the standard approach for
implementing:

• Display()
• Count()
• Search()
• Maximum()
• Minimum()
• Frequency()

===============================================================================
Operations Performed
===============================================================================

1. Created a self-referential class.
2. Declared object references.
3. Allocated memory for three node objects.
4. Initialized data members.
5. Linked all nodes using next references.
6. Assigned the first node to the head reference.
7. Created a temporary reference.
8. Traversed the linked list using temp.
9. Displayed the data stored in each node.
10. Preserved the original head reference.

===============================================================================
Time Complexity
===============================================================================

Node Creation      : O(1)
Node Linking       : O(1)
Traversal          : O(n)

Overall            : O(n)

Space Complexity   : O(1)

===============================================================================
Conclusion
===============================================================================

This program demonstrates the correct technique for traversing a
Singly Linear Linked List using a temporary reference. Since the
head reference remains unchanged, the linked list structure is
preserved, making this the preferred approach for implementing
all traversal-based linked list operations.

===============================================================================
*/
