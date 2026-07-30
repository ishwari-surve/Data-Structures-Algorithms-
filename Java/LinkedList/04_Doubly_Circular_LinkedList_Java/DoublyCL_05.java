/*
===============================================================================
Program Name    : Doubly Circular Linked List - Count()
Program Number  : 005
File Name       : DoublyCL_05.java
Description     : This program demonstrates how to count the total number of
                  nodes present in a Doubly Circular Linked List.

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
- Maintain the total number of nodes.
- Return the node count.
- Display the total number of nodes.
- Understand the use of iCount.

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

    public int Count()
    {
        return iCount;
    }
}

class DoublyCL_05
{
    public static void main(String A[])
    {
        DoublyCL obj = new DoublyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();

        System.out.println("Number of nodes are : " + obj.Count());
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=>

Number of nodes are : 3

===============================================================================
Memory Representation:
===============================================================================

             +------------------------------------+
             |                                    |
             ▼                                    |
first → |11| ⇄ |21| ⇄ |51| ← last
  ▲                                  │
  └──────────────────────────────────┘

iCount = 3

===============================================================================
Algorithm:
===============================================================================

1. Create a Doubly Circular Linked List object.
2. Insert nodes into the linked list.
3. Display the linked list.
4. Return the value of iCount.
5. Display the total number of nodes.
6. Stop.

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
         Display()
               │
               ▼
          Count()
               │
               ▼
    Display Total Nodes
               │
               ▼
              Stop

===============================================================================
Time Complexity:
===============================================================================

Count() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 005 demonstrates the Count() operation of a Doubly Circular Linked
List in Java. The program returns the total number of nodes using the iCount
variable, making the counting operation efficient with constant time
complexity.

==============================================================================
*/

