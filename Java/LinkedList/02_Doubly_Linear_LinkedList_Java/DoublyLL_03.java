/*
===============================================================================
Program Name    : Doubly Linear Linked List - InsertFirst()
Program Number  : 003
File Name       : DoublyLL_03.java
Description     : This program demonstrates how to insert a new node at the
                  beginning of a Doubly Linear Linked List.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Constructor
5. Reference Variables
6. Pointer Manipulation

Key Learning Points:
- Insert a node at the beginning of the linked list.
- Handle insertion into an empty linked list.
- Update first and previous references correctly.
- Increment the node count after insertion.

===============================================================================
*/

class Node
{
    public int data;
    public Node next;
    public Node prev;

    public Node(int no)
    {
        data = no;
        next = null;
        prev = null;
    }
}

class DoublyLL
{
    private Node first;
    private Node last;
    private int iCount;

    public DoublyLL()
    {
        first = null;
        last = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        Node newn = new Node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }

        iCount++;
    }
}

class DoublyLL_03
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

Three nodes are inserted successfully at the beginning of the linked list.

===============================================================================
Memory Representation:
===============================================================================

first
  │
  ▼

NULL <- |11| ⇄ |21| ⇄ |51| -> NULL
                           ▲
                           │
                          last

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Store the given data in the node.
3. If the linked list is empty:
      Make first and last point to the new node.
4. Otherwise:
      Link the new node before the first node.
      Update the previous reference of the old first node.
      Update first.
5. Increment the node count.
6. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
             │
             ▼
      Create New Node
             │
             ▼
      Is List Empty?
        │          │
      Yes         No
       │           │
       ▼           ▼
 first=last     Link Before First
    =newn             │
                      ▼
             Update first
                      │
                      ▼
            Increment Count
                      │
                      ▼
                     Stop

  ===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 003 demonstrates the InsertFirst() operation of a Doubly Linear
Linked List in Java. It inserts a new node at the beginning while correctly
updating the first reference and maintaining the previous and next links
between nodes.

===============================================================================
*/
  
