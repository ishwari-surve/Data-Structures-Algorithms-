/*
===============================================================================
Program Name    : Doubly Linear Linked List - Count()
Program Number  : 005
File Name       : DoublyLL_05.java
Description     : This program demonstrates how to count the total number of
                  nodes present in a Doubly Linear Linked List.

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
6. Linked List Traversal

Key Learning Points:
- Traverse the linked list.
- Count the total number of nodes.
- Return the node count.
- Display the total number of nodes.

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

class DoublyLL_05
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.Display();

        System.out.println("Number of nodes are : " + dobj.Count());
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> NULL

Number of nodes are : 3

===============================================================================
Memory Representation:
===============================================================================

first
  │
  ▼

NULL <- |11| ⇄ |21| ⇄ |51| -> NULL
                           ▲
                           │
                          last

iCount = 3

===============================================================================
Algorithm:
===============================================================================

1. Create a Doubly Linear Linked List object.
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

Program 005 demonstrates the Count() operation of a Doubly Linear Linked
List in Java. The program returns the total number of nodes using the iCount
variable, making the counting operation efficient with constant time
complexity.

===============================================================================
*/
