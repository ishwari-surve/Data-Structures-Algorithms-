/*
===============================================================================
Program Name    : Doubly Linear Linked List - Display()
Program Number  : 004
File Name       : DoublyLL_04.java
Description     : This program demonstrates how to display all the nodes of a
                  Doubly Linear Linked List from first to last.

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
6. Traversing Linked List

Key Learning Points:
- Traverse a Doubly Linear Linked List.
- Display all nodes sequentially.
- Understand the use of a temporary reference variable.
- Display nodes from first to last.

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
}

class DoublyLL_04
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.Display();
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> NULL

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

Traversal:

11 → 21 → 51 → NULL

===============================================================================
Algorithm:
===============================================================================

1. Create a temporary reference variable temp.
2. Initialize temp with first.
3. Traverse the linked list until temp becomes null.
4. Display the data of each node.
5. Move temp to the next node.
6. Display NULL.
7. Stop.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
         temp = first
               │
               ▼
        temp != NULL ?
          │         │
        Yes         No
         │           │
         ▼           ▼
 Display temp->data  Print NULL
         │
         ▼
   temp = temp->next
         │
         └───────────────┐
                         │
                         ▼
                       Stop

  ===============================================================================
Time Complexity:
===============================================================================

Display() : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates the Display() operation of a Doubly Linear Linked
List in Java. It traverses the linked list from the first node to the last
node using a temporary reference variable and displays each node in sequence.

===============================================================================
*/
