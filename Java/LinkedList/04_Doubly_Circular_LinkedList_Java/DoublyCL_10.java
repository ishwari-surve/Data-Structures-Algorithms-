/*
===============================================================================
Program Name    : Doubly Circular Linked List - Complete Implementation
Program Number  : 010
File Name       : DoublyCL_10.java
Description     : This program demonstrates the complete implementation of a
                  Doubly Circular Linked List in Java. It supports insertion,
                  deletion, display, and count operations while maintaining
                  the circular and doubly linked properties.

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
7. Position Validation

Key Learning Points:
- Complete implementation of Doubly Circular Linked List.
- Perform insertion and deletion at different positions.
- Maintain next and previous references.
- Preserve the circular nature of the linked list.
- Count and display nodes efficiently.

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

    //=========================================================
    // InsertFirst()
    //=========================================================

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

    //=========================================================
    // InsertLast()
    //=========================================================

    public void InsertLast(int no)
    {
        Node newn = new Node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            newn.prev = last;
            last = newn;
        }

        last.next = first;
        first.prev = last;

        iCount++;
    }

    //=========================================================
    // DeleteFirst()
    //=========================================================

    public void DeleteFirst()
    {
        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            last.next = first;
            first.prev = last;
        }

        iCount--;
    }

    //=========================================================
    // DeleteLast()
    //=========================================================

    public void DeleteLast()
    {
        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            last = last.prev;
            last.next = first;
            first.prev = last;
        }

        iCount--;
    }

    //=========================================================
    // InsertAtPos()
    //=========================================================

    public void InsertAtPos(int no, int iPos)
    {
        if((iPos < 1) || (iPos > iCount + 1))
        {
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(no);
        }
        else if(iPos == (iCount + 1))
        {
            InsertLast(no);
        }
        else
        {
            Node newn = new Node(no);
            Node temp = first;

            for(int i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            newn.prev = temp;

            temp.next.prev = newn;
            temp.next = newn;

            iCount++;
        }
    }

      //=========================================================
    // DeleteAtPos()
    //=========================================================

    public void DeleteAtPos(int iPos)
    {
        if((iPos < 1) || (iPos > iCount))
        {
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount)
        {
            DeleteLast();
        }
        else
        {
            Node temp = first;

            for(int i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = temp;

            iCount--;
        }
    }

    //=========================================================
    // Display()
    //=========================================================

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

    //=========================================================
    // Count()
    //=========================================================

    public int Count()
    {
        return iCount;
    }
}

class DoublyCL_10
{
    public static void main(String A[])
    {
        DoublyCL obj = new DoublyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();

        System.out.println("Number of nodes are : " + obj.Count());

        obj.DeleteFirst();

        obj.Display();

        System.out.println("Number of nodes are : " + obj.Count());

        obj.DeleteLast();

        obj.Display();

        System.out.println("Number of nodes are : " + obj.Count());

        obj.InsertAtPos(75,4);

        obj.Display();

        System.out.println("Number of nodes are : " + obj.Count());

        obj.DeleteAtPos(4);

        obj.Display();

        System.out.println("Number of nodes are : " + obj.Count());
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>
Number of nodes are : 6

| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>
Number of nodes are : 5

| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>
Number of nodes are : 4

| 21 | <=> | 51 | <=> | 101 | <=> | 75 | <=> | 111 | <=>
Number of nodes are : 5

| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>
Number of nodes are : 4

===============================================================================
Memory Representation:
===============================================================================

                 +------------------------------------------------------+
                 |                                                      |
                 ▼                                                      |
first → |21| ⇄ |51| ⇄ |101| ⇄ |111| ← last
  ▲                                                    │
  └────────────────────────────────────────────────────┘

===============================================================================
Algorithm:
===============================================================================

1. Create an empty Doubly Circular Linked List.
2. Insert nodes at the beginning.
3. Insert nodes at the end.
4. Display the linked list.
5. Count the total number of nodes.
6. Delete the first node.
7. Delete the last node.
8. Insert a node at the specified position.
9. Delete a node from the specified position.
10. Display the updated linked list after each operation.
11. Stop.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
      Create Linked List
               │
               ▼
      InsertFirst()
               │
               ▼
      InsertLast()
               │
               ▼
        Display()
               │
               ▼
         DeleteFirst()
               │
               ▼
         DeleteLast()
               │
               ▼
        InsertAtPos()
               │
               ▼
        DeleteAtPos()
               │
               ▼
      Display & Count
               │
               ▼
              Stop

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()    : O(1)
InsertLast()     : O(1)
DeleteFirst()    : O(1)
DeleteLast()     : O(1)
InsertAtPos()    : O(n)
DeleteAtPos()    : O(n)
Display()        : O(n)
Count()          : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 010 demonstrates the complete implementation of a Doubly Circular
Linked List in Java. It supports insertion, deletion, display, and counting
operations while maintaining both the doubly linked and circular properties
of the linked list. This program serves as the complete non-menu-driven
implementation before developing the final menu-driven application.

===============================================================================
*/

