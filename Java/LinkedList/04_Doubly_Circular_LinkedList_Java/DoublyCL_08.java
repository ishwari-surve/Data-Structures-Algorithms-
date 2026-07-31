/*
===============================================================================
Program Name    : Doubly Circular Linked List - DeleteLast()
Program Number  : 008
File Name       : DoublyCL_08.java
Description     : This program demonstrates how to delete the last node from
                  a Doubly Circular Linked List while maintaining the circular
                  and doubly linked properties.

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
- Delete the last node from the linked list.
- Handle deletion from an empty linked list.
- Handle deletion when only one node exists.
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

class DoublyCL_08
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

        obj.DeleteLast();

        System.out.println("\nAfter DeleteLast() :");

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

After DeleteLast() :

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>

Number of nodes are : 5

===============================================================================
Memory Representation:
===============================================================================

Before Deletion

               +------------------------------------------------------+
               |                                                      |
               ▼                                                      |
first → |11| ⇄ |21| ⇄ |51| ⇄ |101| ⇄ |111| ⇄ |121| ← last
  ▲                                                            │
  └────────────────────────────────────────────────────────────┘

↓

After DeleteLast()

              +----------------------------------------------+
              |                                              |
              ▼                                              |
first → |11| ⇄ |21| ⇄ |51| ⇄ |101| ⇄ |111| ← last
  ▲                                                  │
  └──────────────────────────────────────────────────┘

===============================================================================
Algorithm:
===============================================================================

1. Check whether the linked list is empty.
2. If empty, return.
3. If only one node exists:
      Make first and last null.
4. Otherwise:
      Move last to the previous node.
      Connect last.next to first.
      Connect first.prev to last.
5. Decrement node count.
6. Stop.

===============================================================================
Time Complexity:
===============================================================================

DeleteLast() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 008 demonstrates the DeleteLast() operation of a Doubly Circular
Linked List in Java. It removes the last node while correctly updating the
last and first node links, ensuring that the circular doubly linked structure
remains intact.

===============================================================================
*/
