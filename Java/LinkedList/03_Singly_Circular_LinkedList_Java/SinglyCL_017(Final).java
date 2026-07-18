/*
===============================================================================
Program Name    : Menu Driven Singly Circular Linked List
Program Number  : 017
Description     : This program demonstrates a complete Menu Driven
                  implementation of a Singly Circular Linked List in Java.
                  It allows the user to perform all insertion, deletion,
                  display, and counting operations interactively through
                  a menu-driven interface.
Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================
Concepts Used:
1. Object-Oriented Programming (OOP)
2. Classes and Objects
3. Constructors
4. Self-Referential Structure
5. Dynamic Memory Allocation
6. Singly Circular Linked List
7. Menu Driven Programming
8. Scanner Class
9. do-while Traversal
10. Position Based Operations
11. Switch Case
12. Node Counting

Key Learning Points:
- Complete implementation of Singly Circular Linked List.
- Circular connection maintained using last.next = first.
- Supports all insertion and deletion operations.
- Menu Driven approach provides interactive execution.
- Position validation prevents invalid operations.
- iCount maintains the total number of nodes.

===============================================================================
*/
// Program 17 : Menu Driven Singly Circular Linked List in Java

import java.util.*;

class node
{
    public int data;
    public node next;

    node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyCL
{
    public node first;
    public node last;
    public int iCount;

    public SinglyCL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    ///////////////////////////////////////////////////////////////

    public void Display()
    {
        node temp = first;

        if(first == null && last == null)
        {
            return;
        }

        do
        {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        }while(temp != last.next);

        System.out.println();
    }

    ///////////////////////////////////////////////////////////////

    public int Count()
    {
        return iCount;
    }

    ///////////////////////////////////////////////////////////////

    public void InsertFirst(int no)
    {
        node newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }

        last.next = first;

        iCount++;
    }

    ///////////////////////////////////////////////////////////////

    public void InsertLast(int no)
    {
        node newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            last = newn;
        }

        last.next = first;

        iCount++;
    }

    ///////////////////////////////////////////////////////////////

    public void InsertAtPos(int no, int iPos)
    {
        if((iPos < 1) || (iPos > iCount + 1))
        {
            System.out.println("Invalid Position");
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
            node newn = new node(no);
            node temp = first;

            for(int i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            iCount++;
        }
    }

    ///////////////////////////////////////////////////////////////

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
        }

        iCount--;
    }

    ///////////////////////////////////////////////////////////////

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
            node temp = first;

            while(temp.next != last)
            {
                temp = temp.next;
            }

            last = temp;
            last.next = first;
        }

        iCount--;
    }

    ///////////////////////////////////////////////////////////////

    public void DeleteAtPos(int iPos)
    {
        if((iPos < 1) || (iPos > iCount))
        {
            System.out.println("Invalid Position");
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
            node temp = first;

            for(int i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            node target = temp.next;
            temp.next = target.next;
            target = null;

            iCount--;
        }
    }
}

///////////////////////////////////////////////////////////////////////////

class SinglyCL17
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        SinglyCL lobj = new SinglyCL();

        int iChoice = 1;
        int iValue = 0;
        int iPos = 0;

        while(iChoice != 0)
        {
            System.out.println("\n------------------------------------");
            System.out.println("Singly Circular Linked List");
            System.out.println("------------------------------------");
            System.out.println("1 : Insert First");
            System.out.println("2 : Insert Last");
            System.out.println("3 : Insert At Position");
            System.out.println("4 : Delete First");
            System.out.println("5 : Delete Last");
            System.out.println("6 : Delete At Position");
            System.out.println("7 : Display");
            System.out.println("8 : Count");
            System.out.println("0 : Exit");
            System.out.print("Enter your choice : ");
            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                case 1:
                    System.out.print("Enter data : ");
                    iValue = sobj.nextInt();
                    lobj.InsertFirst(iValue);
                    break;

                case 2:
                    System.out.print("Enter data : ");
                    iValue = sobj.nextInt();
                    lobj.InsertLast(iValue);
                    break;

                case 3:
                    System.out.print("Enter data : ");
                    iValue = sobj.nextInt();

                    System.out.print("Enter position : ");
                    iPos = sobj.nextInt();

                    lobj.InsertAtPos(iValue, iPos);
                    break;

                case 4:
                    lobj.DeleteFirst();
                    break;

                case 5:
                    lobj.DeleteLast();
                    break;

                case 6:
                    System.out.print("Enter position : ");
                    iPos = sobj.nextInt();

                    lobj.DeleteAtPos(iPos);
                    break;

                case 7:
                    lobj.Display();
                    break;

                case 8:
                    System.out.println("Number of nodes are : " + lobj.Count());
                    break;

                case 0:
                    System.out.println("Thank you for using Singly Circular Linked List.");
                    break;

                default:
                    System.out.println("Invalid Choice");
                    break;
            }
        }

        sobj.close();
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

------------------------------------
Singly Circular Linked List
------------------------------------
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

Enter your choice : 1
Enter data : 21

Enter your choice : 2
Enter data : 51

Enter your choice : 7

| 21 | -> | 11 | -> | 51 | ->

Enter your choice : 8

Number of nodes are : 3

Enter your choice : 3
Enter data : 31
Enter position : 2

| 21 | -> | 31 | -> | 11 | -> | 51 | ->

Number of nodes are : 4

Enter your choice : 6
Enter position : 2

| 21 | -> | 11 | -> | 51 | ->

Number of nodes are : 3

Enter your choice : 0

Thank you for using Singly Circular Linked List.

===============================================================================
Memory Representation:
===============================================================================

   first                                                     last
     │                                                        │
     ▼                                                        ▼

+-----------+     +-----------+     +-----------+     +-----------+
| Data : 11 | --> | Data : 21 | --> | Data : 51 | --> | Data :101 |
| Next :  • |     | Next :  • |     | Next :  • |     | Next :  • |
+-----------+     +-----------+     +-----------+     +-----------+
      ^                                                        |
      |                                                        |
      +--------------------------------------------------------+

                    last.next = first (Circular Link)

===============================================================================
Explanation:
===============================================================================

The program creates a complete Singly Circular Linked List using Java.

Initially, both first and last are initialized to NULL and the node count
(iCount) is set to zero.

The user interacts with the linked list through a menu-driven interface.
Depending upon the selected option, the corresponding linked list function
is executed.

Supported operations include:

• InsertFirst()
• InsertLast()
• InsertAtPos()
• DeleteFirst()
• DeleteLast()
• DeleteAtPos()
• Display()
• Count()

The Display() function traverses the circular linked list using a
do-while loop until it reaches the first node again.

The Count() function returns the total number of nodes maintained by
the iCount variable.

InsertAtPos() and DeleteAtPos() validate the position before performing
the requested operation.

The circular nature of the linked list is maintained after every insertion
or deletion by updating:

last.next = first

This ensures continuous traversal without reaching NULL.

===============================================================================
Program Flow:
===============================================================================

Create Scanner Object
          │
          ▼
Create SinglyCL Object
          │
          ▼
Constructor Invoked
          │
          ▼
first = NULL
last = NULL
iCount = 0
          │
          ▼
Display Menu
          │
          ▼
Accept User Choice
          │
          ▼
Perform Selected Operation
          │
          ▼
Update Linked List
          │
          ▼
Display Result / Count
          │
          ▼
Repeat Until Choice = 0
          │
          ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Created Singly Circular Linked List object.
2. Displayed menu repeatedly.
3. Inserted node at first position.
4. Inserted node at last position.
5. Inserted node at specified position.
6. Deleted first node.
7. Deleted last node.
8. Deleted node from specified position.
9. Displayed linked list.
10. Counted total number of nodes.
11. Validated user input positions.
12. Maintained circular link after every operation.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()      : O(1)
InsertLast()       : O(1)
InsertAtPos()      : O(n)
DeleteFirst()      : O(1)
DeleteLast()       : O(n)
DeleteAtPos()      : O(n)
Display()          : O(n)
Count()            : O(1)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 017 demonstrates a complete Menu Driven implementation of a
Singly Circular Linked List in Java. It integrates all fundamental
linked list operations into a single interactive application. The
program efficiently maintains the circular structure, validates user
input, updates the node count after every operation, and provides an
excellent example of applying Object-Oriented Programming concepts to
Data Structures.

===============================================================================
*/
