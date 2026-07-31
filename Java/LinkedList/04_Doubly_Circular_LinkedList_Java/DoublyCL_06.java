/*
===============================================================================
Program Name    : Doubly Circular Linked List - InsertLast()
Program Number  : 006
File Name       : DoublyCL_06.java
Description     : This program demonstrates how to insert a new node at the
                  end of a Doubly Circular Linked List while maintaining the
                  circular and doubly linked properties.

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
- Insert a node at the end of the linked list.
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

class DoublyCL_06
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
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>

Number of nodes are : 6

===============================================================================
Memory Representation:
===============================================================================

                +------------------------------------------------------+
                |                                                      |
                ▼                                                      |
first → |11| ⇄ |21| ⇄ |51| ⇄ |101| ⇄ |111| ⇄ |121| ← last
  ▲                                                            │
  └────────────────────────────────────────────────────────────┘

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. If the linked list is empty:
      Make first and last point to the new node.
3. Otherwise:
      Link the new node after the last node.
      Update last.
4. Connect last.next to first.
5. Connect first.prev to last.
6. Increment node count.
7. Stop.

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
 first=last    Insert After Last
    =newn            │
                     ▼
          Update Circular Links
                     │
                     ▼
            Increment Count
                     │
                     ▼
                    Stop

===============================================================================
Time Complexity:
===============================================================================

InsertLast() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates the InsertLast() operation of a Doubly Circular
Linked List in Java. It inserts a new node at the end while maintaining both
the doubly linked structure and the circular links between the first and last
nodes.

===============================================================================
*/
