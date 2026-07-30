/*
===============================================================================
Program Name    : Doubly Linear Linked List - DeleteFirst()
Program Number  : 007
File Name       : DoublyLL_07.java
Description     : This program demonstrates how to delete the first node from
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
- Delete the first node from the linked list.
- Handle deletion from an empty linked list.
- Handle deletion when only one node exists.
- Update first reference correctly.
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
            first.prev = null;
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

class DoublyLL_07
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(111);

        dobj.Display();

        System.out.println("Number of nodes are : " + dobj.Count());

        dobj.DeleteFirst();

        System.out.println("\nAfter DeleteFirst() :");

        dobj.Display();

        System.out.println("Number of nodes are : " + dobj.Count());
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL

Number of nodes are : 5

After DeleteFirst() :

| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL

Number of nodes are : 4

===============================================================================
Memory Representation:
===============================================================================

Before Deletion

first
  │
  ▼

NULL <- |11| ⇄ |21| ⇄ |51| ⇄ |101| ⇄ |111| -> NULL
                                                ▲
                                                │
                                               last

↓

After DeleteFirst()

first
  │
  ▼

NULL <- |21| ⇄ |51| ⇄ |101| ⇄ |111| -> NULL
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
      Move first to the next node.
      Set first.prev to null.
5. Decrement the node count.
6. Stop.

===============================================================================
Time Complexity:
===============================================================================

DeleteFirst() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 007 demonstrates the DeleteFirst() operation of a Doubly Linear
Linked List in Java. It removes the first node while correctly updating the
first reference and maintaining the integrity of the previous and next links.

===============================================================================
*/
