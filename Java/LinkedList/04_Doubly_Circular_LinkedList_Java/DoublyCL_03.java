/*
===============================================================================
Program Name    : Doubly Circular Linked List - InsertFirst()
Program Number  : 003
File Name       : DoublyCL_03.java
Description     : This program demonstrates how to insert a new node at the
                  beginning of a Doubly Circular Linked List.

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
6. Circular Linking

Key Learning Points:
- Insert a node at the beginning of the linked list.
- Handle insertion into an empty linked list.
- Maintain next and previous references.
- Preserve the circular nature of the linked list.

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

class DoublyCL
{
    private Node first;
    private Node last;
    private int iCount;

    public DoublyCL()
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

        last.next = first;
        first.prev = last;

        iCount++;
    }

    public void Display()
    {
        if(first == null && last == null)
        {
            return;
        }

        Node temp = first;

        do
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.next;
        }while(temp != last.next);

        System.out.println();
    }
}

class DoublyCL_03
{
    public static void main(String A[])
    {
        DoublyCL obj = new DoublyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=>

===============================================================================
Memory Representation:
===============================================================================

             +------------------------------------+
             |                                    |
             ▼                                    |
first → |11| ⇄ |21| ⇄ |51| ← last
  ▲                                  │
  └──────────────────────────────────┘

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. If the list is empty:
      Make first and last point to the new node.
3. Otherwise:
      Insert the new node before the first node.
      Update first.
4. Connect last.next to first.
5. Connect first.prev to last.
6. Increment node count.
7. Stop.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 003 demonstrates the InsertFirst() operation of a Doubly Circular
Linked List in Java. It inserts a new node at the beginning while maintaining
both the doubly linked structure and the circular links between the first and
last nodes.

===============================================================================
*/
