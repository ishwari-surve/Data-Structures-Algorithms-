/*
===============================================================================
Program Name    : Doubly Circular Linked List - Menu Driven
Program Number  : 011
File Name       : DoublyCL_11.java
Description     : This program demonstrates a menu-driven implementation of a
                  Doubly Circular Linked List in Java. It supports insertion,
                  deletion, display, and count operations using user choices.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Constructor
5. Scanner Class
6. Menu Driven Programming
7. Circular Linking
8. Position Validation

Key Learning Points:
- Perform all linked list operations using a menu.
- Reuse existing methods for insertion and deletion.
- Maintain the circular doubly linked structure.
- Accept input dynamically from the user.

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

    //=========================================================
    // InsertFirst()
    //=========================================================

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

    //=========================================================
    // InsertLast()
    //=========================================================

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

        last.next = first;
        first.prev = last;

        iCount++;
    }

    //=========================================================
    // DeleteFirst()
    //=========================================================

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
            last.next = first;
            first.prev = last;
        }

        iCount--;
    }

    //=========================================================
    // DeleteLast()
    //=========================================================

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
            last.next = first;
            first.prev = last;
        }

        iCount--;
    }

    //=========================================================
    // InsertAtPos()
    //=========================================================

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
        else if(iPos == (iCount + 1))
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

      //=========================================================
    // DeleteAtPos()
    //=========================================================

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

    //=========================================================
    // Display()
    //=========================================================

    public void Display()
    {
        if(first == null && last == null)
        {
            System.out.println("Linked List is Empty");
            return;
        }

        Node temp = first;

        System.out.print("<=> ");

        do
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.next;
        }while(temp != last.next);

        System.out.println();
    }

    //=========================================================
    // Count()
    //=========================================================

    public int Count()
    {
        return iCount;
    }
}

class DoublyCL_11
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        DoublyCL obj = new DoublyCL();

        int iChoice = 0;
        int iNo = 0;
        int iPos = 0;

        while(true)
        {
            System.out.println("\n------------------------------------------------");
            System.out.println(" Doubly Circular Linked List ");
            System.out.println("------------------------------------------------");

            System.out.println("1 : Insert First");
            System.out.println("2 : Insert Last");
            System.out.println("3 : Insert At Position");
            System.out.println("4 : Delete First");
            System.out.println("5 : Delete Last");
            System.out.println("6 : Delete At Position");
            System.out.println("7 : Display");
            System.out.println("8 : Count");
            System.out.println("9 : Exit");

            System.out.print("\nEnter your choice : ");
            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                case 1:
                    System.out.print("Enter data : ");
                    iNo = sobj.nextInt();
                    obj.InsertFirst(iNo);
                    break;

                case 2:
                    System.out.print("Enter data : ");
                    iNo = sobj.nextInt();
                    obj.InsertLast(iNo);
                    break;

                case 3:
                    System.out.print("Enter data : ");
                    iNo = sobj.nextInt();

                    System.out.print("Enter position : ");
                    iPos = sobj.nextInt();

                    obj.InsertAtPos(iNo, iPos);
                    break;

                case 4:
                    obj.DeleteFirst();
                    break;

                case 5:
                    obj.DeleteLast();
                    break;

                case 6:
                    System.out.print("Enter position : ");
                    iPos = sobj.nextInt();

                    obj.DeleteAtPos(iPos);
                    break;

                case 7:
                    obj.Display();
                    break;

                case 8:
                    System.out.println("Number of nodes are : " + obj.Count());
                    break;

                case 9:
                    System.out.println("Thank you for using Doubly Circular Linked List...");
                    sobj.close();
                    System.exit(0);

                default:
                    System.out.println("Invalid Choice");
            }
        }
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

------------------------------------------------
 Doubly Circular Linked List
------------------------------------------------
1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display
8 : Count
9 : Exit

Enter your choice : 1
Enter data : 11

Enter your choice : 2
Enter data : 51

Enter your choice : 3
Enter data : 21
Enter position : 2

Enter your choice : 7
<=> | 11 | <=> | 21 | <=> | 51 | <=>

Enter your choice : 8
Number of nodes are : 3

Enter your choice : 9
Thank you for using Doubly Circular Linked List...

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

1. Create an empty Doubly Circular Linked List.
2. Display the menu repeatedly.
3. Accept the user's choice.
4. Perform the selected linked list operation.
5. Display or count nodes whenever requested.
6. Repeat until the user selects Exit.
7. Stop.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
      Create Linked List
               │
               ▼
         Display Menu
               │
               ▼
      Accept User Choice
               │
               ▼
      Perform Operation
               │
               ▼
     Display / Count List
               │
               ▼
      Exit Selected ?
        │             │
       No            Yes
        │             │
        └────────────►Stop

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()  : O(1)
InsertLast()   : O(1)
DeleteFirst()  : O(1)
DeleteLast()   : O(1)
InsertAtPos()  : O(n)
DeleteAtPos()  : O(n)
Display()      : O(n)
Count()        : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 011 demonstrates the complete menu-driven implementation of a Doubly
Circular Linked List in Java. It provides an interactive interface to perform
all insertion, deletion, display, and count operations while maintaining the
doubly linked and circular structure. This serves as the final implementation
of the Doubly Circular Linked List in Java.

===============================================================================
*/

