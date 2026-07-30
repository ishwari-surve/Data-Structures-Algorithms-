/*
===============================================================================
Program Name    : Doubly Linear Linked List - DeleteLast()
Program Number  : 008
File Name       : DoublyLL_08.java
Description     : This program demonstrates how to delete the last node from
                  a Doubly Linear Linked List.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Garbage Collection
5. Reference Variables
6. Pointer Manipulation

Key Learning Points:
- Delete the last node from the linked list.
- Handle deletion from an empty linked list.
- Handle deletion when only one node exists.
- Update last reference correctly.
- Decrement the node count after deletion.

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
            last.next = null;
        }

        iCount--;
    }

    public void Display()
    {
        Node temp = first;

        while(temp != null)
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.next;
        }

        System.out.println("NULL");
    }

    public int Count()
    {
        return iCount;
    }
}

class DoublyLL_08
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(111);
        dobj.InsertLast(121);

        dobj.Display();

        System.out.println("Number of nodes are : " + dobj.Count());

        dobj.DeleteLast();

        System.out.println("\nAfter DeleteLast() :");

        dobj.Display();

        System.out.println("Number of nodes are : " + dobj.Count());
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

Number of nodes are : 6

After DeleteLast() :

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL

Number of nodes are : 5

===============================================================================
Memory Representation:
===============================================================================

Before Deletion

first
  │
  ▼

NULL <- |11| ⇄ |21| ⇄ |51| ⇄ |101| ⇄ |111| ⇄ |121| -> NULL
                                                         ▲
                                                         │
                                                        last

↓

After DeleteLast()

first
  │
  ▼

NULL <- |11| ⇄ |21| ⇄ |51| ⇄ |101| ⇄ |111| -> NULL
                                                  ▲
                                                  │
                                                 last

===============================================================================
Algorithm:
===============================================================================

1. Check whether the linked list is empty.
2. If empty, return.
3. If only one node exists:
      Make first and last null.
4. Otherwise:
      Move last to the previous node.
      Set last.next to null.
5. Decrement the node count.
6. Stop.

===============================================================================
Time Complexity:
===============================================================================

DeleteLast() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 008 demonstrates the DeleteLast() operation of a Doubly Linear
Linked List in Java. It removes the last node while correctly updating the
last reference and maintaining the integrity of the previous and next links
between the remaining nodes.

===============================================================================
*/
