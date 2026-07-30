/*
===============================================================================
Program Name    : Doubly Circular Linked List - Display()
Program Number  : 004
File Name       : DoublyCL_04.java
Description     : This program demonstrates how to display all the nodes of a
                  Doubly Circular Linked List.

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
6. Circular Traversal

Key Learning Points:
- Traverse a Doubly Circular Linked List.
- Display all nodes using a do-while loop.
- Understand circular traversal.
- Stop traversal after reaching the starting node.

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

class DoublyCL_04
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

1. Check whether the linked list is empty.
2. If empty, return.
3. Create a temporary reference variable temp.
4. Initialize temp with first.
5. Display the data of the current node.
6. Move temp to the next node.
7. Repeat until temp becomes first again.
8. Stop.

===============================================================================
Time Complexity:
===============================================================================

Display() : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates the Display() operation of a Doubly Circular Linked
List in Java. It traverses the list using a do-while loop and displays each
node exactly once while preserving the circular nature of the linked list.

===============================================================================
*/
