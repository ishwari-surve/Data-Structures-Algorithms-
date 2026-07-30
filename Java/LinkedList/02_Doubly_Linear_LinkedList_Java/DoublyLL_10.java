/*
===============================================================================
Program Name    : Doubly Linear Linked List - Complete Implementation
Program Number  : 010
File Name       : DoublyLL_10.java
Description     : This program demonstrates the complete implementation of a
                  Doubly Linear Linked List using Java. It includes insertion,
                  deletion, display, counting, and position-based operations.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Dynamic Memory Allocation
5. Reference Variables
6. Pointer Manipulation
7. Position Validation
8. Constructor

Key Learning Points:
- Insert nodes at the beginning, end, and any position.
- Delete nodes from the beginning, end, and any position.
- Display all nodes.
- Count total nodes.
- Maintain correct next and previous links.

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

class DoublyLL_10
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

        dobj.DeleteFirst();
        dobj.Display();
        System.out.println("Number of nodes are : " + dobj.Count());

        dobj.DeleteLast();
        dobj.Display();
        System.out.println("Number of nodes are : " + dobj.Count());

        dobj.InsertAtPos(75,4);
        dobj.Display();
        System.out.println("Number of nodes are : " + dobj.Count());

        dobj.DeleteAtPos(4);
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

| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL
Number of nodes are : 5

| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL
Number of nodes are : 4

| 21 | <=> | 51 | <=> | 101 | <=> | 75 | <=> | 111 | <=> NULL
Number of nodes are : 5

| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL
Number of nodes are : 4

===============================================================================
Memory Representation:
===============================================================================

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

1. Create a Doubly Linear Linked List object.
2. Insert nodes at the beginning.
3. Insert nodes at the end.
4. Display the linked list.
5. Count the total number of nodes.
6. Delete the first node.
7. Delete the last node.
8. Insert a node at the specified position.
9. Delete a node from the specified position.
10. Display the updated linked list after every operation.
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
           Count()
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
          Display()
               │
               ▼
              Stop

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()  : O(1)

InsertLast()   : O(1)

InsertAtPos()  : O(n)

DeleteFirst()  : O(1)

DeleteLast()   : O(1)

DeleteAtPos()  : O(n)

Display()      : O(n)

Count()        : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 010 demonstrates the complete implementation of a Doubly Linear
Linked List in Java. It supports insertion, deletion, display, counting,
and position-based operations while maintaining correct forward and backward
links between all nodes. This program serves as the foundation for the final
menu-driven implementation.

===============================================================================
*/
}
