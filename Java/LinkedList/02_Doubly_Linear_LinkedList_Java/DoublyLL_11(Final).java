/*
===============================================================================
Program Name    : Doubly Linear Linked List - Menu Driven Program
Program Number  : 011
File Name       : DoublyLL_11.java
Description     : This program demonstrates a Menu Driven implementation of
                  a Doubly Linear Linked List in Java. It allows the user to
                  perform insertion, deletion, display, count, and
                  position-based operations interactively.

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
7. Menu Driven Programming
8. Position Validation

Key Learning Points:
- Implement all Doubly Linear Linked List operations.
- Perform operations using a menu.
- Maintain correct next and previous links.
- Understand real-time linked list manipulation.

===============================================================================
*/

import java.util.*;

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
}

class DoublyLL_11
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        DoublyLL dobj = new DoublyLL();

        int iChoice = 0;
        int iValue = 0;
        int iPos = 0;

        while(true)
        {
            System.out.println("\n-------------------------------------");
            System.out.println(" Doubly Linear Linked List ");
            System.out.println("-------------------------------------");

            System.out.println("1 : Insert First");
            System.out.println("2 : Insert Last");
            System.out.println("3 : Insert At Position");
            System.out.println("4 : Delete First");
            System.out.println("5 : Delete Last");
            System.out.println("6 : Delete At Position");
            System.out.println("7 : Display");
            System.out.println("8 : Count");
            System.out.println("0 : Exit");

            System.out.print("\nEnter your choice : ");
            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                case 1:
                    System.out.print("Enter data : ");
                    iValue = sobj.nextInt();
                    dobj.InsertFirst(iValue);
                    break;

                case 2:
                    System.out.print("Enter data : ");
                    iValue = sobj.nextInt();
                    dobj.InsertLast(iValue);
                    break;

                case 3:
                    System.out.print("Enter data : ");
                    iValue = sobj.nextInt();

                    System.out.print("Enter position : ");
                    iPos = sobj.nextInt();

                    dobj.InsertAtPos(iValue,iPos);
                    break;

                case 4:
                    dobj.DeleteFirst();
                    break;

                case 5:
                    dobj.DeleteLast();
                    break;

                case 6:
                    System.out.print("Enter position : ");
                    iPos = sobj.nextInt();

                    dobj.DeleteAtPos(iPos);
                    break;

                case 7:
                    dobj.Display();
                    break;

                case 8:
                    System.out.println("Number of nodes are : " + dobj.Count());
                    break;

                case 0:
                    System.out.println("Thank You...");
                    sobj.close();
                    System.exit(0);

                default:
                    System.out.println("Invalid Choice...");
            }
        }
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

-------------------------------------
 Doubly Linear Linked List
-------------------------------------

1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display
8 : Count
0 : Exit

Enter your choice : 1
Enter data : 11

Enter your choice : 2
Enter data : 21

Enter your choice : 7

| 11 | <=> | 21 | <=> NULL

Enter your choice : 8

Number of nodes are : 2

===============================================================================
Memory Representation:
===============================================================================

first
  │
  ▼

NULL <- |11| ⇄ |21| -> NULL
                     ▲
                     │
                    last

===============================================================================
Algorithm:
===============================================================================

1. Create a Doubly Linear Linked List object.
2. Display the menu repeatedly.
3. Accept the user's choice.
4. Perform the selected linked list operation.
5. Display or count nodes whenever requested.
6. Exit when the user selects 0.
7. Stop.

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

Program 011 demonstrates a complete Menu Driven implementation of a Doubly
Linear Linked List in Java. It allows the user to perform insertion,
deletion, display, count, and position-based operations interactively. This
program provides a practical understanding of dynamic linked list operations
using Object-Oriented Programming concepts in Java.

===============================================================================
*/
