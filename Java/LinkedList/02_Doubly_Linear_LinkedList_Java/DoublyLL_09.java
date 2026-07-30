/*
===============================================================================
Program Name    : Doubly Linear Linked List - InsertAtPos()
Program Number  : 009
File Name       : DoublyLL_09.java
Description     : This program demonstrates how to insert a new node at a
                  specified position in a Doubly Linear Linked List.

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

Key Learning Points:
- Insert a node at any valid position.
- Validate the given position.
- Reuse InsertFirst() and InsertLast() methods.
- Maintain proper next and previous links.
- Increment node count after insertion.

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

class DoublyLL_09
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(111);

        System.out.println("Before Insertion :");
        dobj.Display();

        System.out.println("Number of nodes are : " + dobj.Count());

        dobj.InsertAtPos(75,4);

        System.out.println("\nAfter InsertAtPos() :");

        dobj.Display();

        System.out.println("Number of nodes are : " + dobj.Count());
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

Before Insertion :

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL

Number of nodes are : 5

After InsertAtPos() :

| 11 | <=> | 21 | <=> | 51 | <=> | 75 | <=> | 101 | <=> | 111 | <=> NULL

Number of nodes are : 6

===============================================================================
Memory Representation:
===============================================================================

Before Insertion

NULL <- |11| ⇄ |21| ⇄ |51| ⇄ |101| ⇄ |111| -> NULL

↓

After InsertAtPos(75,4)

NULL <- |11| ⇄ |21| ⇄ |51| ⇄ |75| ⇄ |101| ⇄ |111| -> NULL

===============================================================================
Algorithm:
===============================================================================

1. Validate the given position.
2. If position is 1:
      Call InsertFirst().
3. If position is Count()+1:
      Call InsertLast().
4. Otherwise:
      Traverse to the previous node.
      Create a new node.
      Update next and prev references.
      Increment node count.
5. Stop.

===============================================================================
Time Complexity:
===============================================================================

InsertAtPos() : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 009 demonstrates the InsertAtPos() operation of a Doubly Linear
Linked List in Java. It validates the given position and inserts a new node
at the specified location while maintaining the correct next and previous
links between adjacent nodes.

===============================================================================
*/
