/*
===============================================================================
Program Name    : Doubly Linear Linked List - InsertLast()
Program Number  : 006
File Name       : DoublyLL_06.java
Description     : This program demonstrates how to insert a new node at the
                  end of a Doubly Linear Linked List.

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
- Insert a node at the end of the linked list.
- Handle insertion into an empty linked list.
- Update last and previous references correctly.
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

class DoublyLL_06
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
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

Number of nodes are : 6

===============================================================================
Memory Representation:
===============================================================================

first
  │
  ▼

NULL <- |11| ⇄ |21| ⇄ |51| ⇄ |101| ⇄ |111| ⇄ |121| -> NULL
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
      Link the new node after the last node.
      Update the previous reference of the new node.
      Update last.
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
 first=last    Link After Last
    =newn            │
                     ▼
               Update last
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

Program 006 demonstrates the InsertLast() operation of a Doubly Linear
Linked List in Java. It inserts a new node at the end while correctly
updating the last reference and maintaining the previous and next links
between nodes.

===============================================================================
*/
