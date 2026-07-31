/*
===============================================================================
Program Name    : Doubly Circular Linked List - InsertAtPos()
Program Number  : 009
File Name       : DoublyCL_09.java
Description     : This program demonstrates how to insert a new node at a
                  specified position in a Doubly Circular Linked List while
                  maintaining the circular and doubly linked properties.

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
6. Position Validation
7. Circular Linking

Key Learning Points:
- Insert a node at a specified position.
- Validate the position before insertion.
- Reuse InsertFirst() and InsertLast() whenever required.
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
        else if(iPos == iCount + 1)
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

    public int Count()
    {
        return iCount;
    }
}

class DoublyCL_09
{
    public static void main(String A[])
    {
        DoublyCL obj = new DoublyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.InsertLast(101);
        obj.InsertLast(111);

        obj.Display();

        System.out.println("Number of nodes are : " + obj.Count());

        obj.InsertAtPos(75,4);

        System.out.println("\nAfter InsertAtPos() :");

        obj.Display();

        System.out.println("Number of nodes are : " + obj.Count());
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>

Number of nodes are : 5

After InsertAtPos() :

| 11 | <=> | 21 | <=> | 51 | <=> | 75 | <=> | 101 | <=> | 111 | <=>

Number of nodes are : 6

===============================================================================
Memory Representation:
===============================================================================

Before Insertion

             +-------------------------------------------+
             |                                           |
             ▼                                           |
first → |11| ⇄ |21| ⇄ |51| ⇄ |101| ⇄ |111| ← last
  ▲                                                 │
  └─────────────────────────────────────────────────┘

↓

After InsertAtPos(75,4)

                 +------------------------------------------------+
                 |                                                |
                 ▼                                                |
first → |11| ⇄ |21| ⇄ |51| ⇄ |75| ⇄ |101| ⇄ |111| ← last
  ▲                                                      │
  └──────────────────────────────────────────────────────┘

===============================================================================
Algorithm:
===============================================================================

1. Validate the position.
2. If position is 1:
      Call InsertFirst().
3. If position is last position:
      Call InsertLast().
4. Otherwise:
      Traverse up to (position - 1).
      Create a new node.
      Insert the node between two existing nodes.
5. Increment node count.
6. Stop.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
      Validate Position
               │
               ▼
     Position == 1 ?
       │            │
      Yes          No
       │            │
InsertFirst()      ▼
          Position == Last ?
              │           │
             Yes         No
              │           │
      InsertLast()        ▼
                  Traverse List
                        │
                        ▼
               Insert New Node
                        │
                        ▼
               Increment Count
                        │
                        ▼
                       Stop

===============================================================================
Time Complexity:
===============================================================================

InsertAtPos() : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 009 demonstrates the InsertAtPos() operation of a Doubly Circular
Linked List in Java. It validates the given position, inserts the node at the
correct location, and maintains both the doubly linked and circular structure
of the linked list.

===============================================================================
*/
