/*
================================================================================
Program Name    : Singly Linked List - Complete Menu Driven Implementation
Program Number  : 014 (Java Version)
Description     : This program demonstrates the complete implementation
                  of a Singly Linear Linked List using Java. It
                  integrates all insertion, deletion, display, and
                  count operations through a menu-driven interface.
                  The program allows users to perform linked list
                  operations interactively while maintaining the node
                  count automatically using iCount.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve

================================================================================
Concepts Used:
1. Object-Oriented Programming (OOP)
2. Class Encapsulation (private/public)
3. Constructor
4. Dynamic Node Creation
5. InsertFirst() Operation
6. InsertLast() Operation
7. InsertAtPos() Operation
8. DeleteFirst() Operation
9. DeleteLast() Operation
10. DeleteAtPos() Operation
11. Display() Operation
12. Count() Operation
13. Linked List Traversal
14. Temporary Reference (temp)
15. Position Validation
16. Automatic Node Counting (iCount)
17. Menu Driven Programming
18. Scanner Class

Key Learning Points:
- Combines all linked list operations into a single application.
- Supports insertion at the beginning, end, and any valid position.
- Supports deletion from the beginning, end, and any valid position.
- Display() traverses the linked list using a temporary reference.
- Count() returns the node count in O(1) time using iCount.
- Validates positions before insertion and deletion.
- Handles empty and single-node linked list cases.
- Demonstrates encapsulation and modular programming.
- Uses a menu-driven interface for interactive execution.
================================================================================
*/
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

class SinglyLL
{
    private  node first;
    private  int iCount;

    public SinglyLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void Display()
    {
        node temp = first;

        while(temp != null)
        {
            System.out.print("| "+temp.data+"| -> ");
            temp = temp.next;
        }
        System.out.print("NULL");
        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }

    public void InsertFirst(int iNo)
    {
        node newn = new node(iNo);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }
        iCount++;
    }

    public void InsertLast(int iNo)
    {
        node newn = new node(iNo);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            node temp = null;
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        iCount++;
    }

    public void InsertAtPos(int iNo,int iPos)
    {
        node temp = null;
        node newn = null;
        int i = 0;

        if(iPos < 1 || iPos > iCount + 1)
        {
           System.out.println("Invalid Position");
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(iNo);
        }
        else if(iPos == iCount + 1)
        {
            InsertLast(iNo);
        }
        else
        {
            newn = new node(iNo);
    
            temp = first;

            for( i = 1 ; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteFirst()
{
    if(first == null)
    {
        return;
    }
    else if(first.next == null)
    {
        first = null;
    }
    else
    {
        first = first.next;
    }

    iCount--;
}

   public void DeleteLast()
{
    if(first == null)
    {
        return;
    }
    else if(first.next == null)
    {
        first = null;
    }
    else
    {
        node temp = first;

        while(temp.next.next != null)
        {
            temp = temp.next;
        }

        temp.next = null;
    }

    iCount--;
}

    public void DeleteAtPos(int iPos)
    {
        node temp = null;
        int i = 0;

        if(iPos < 1 || iPos > iCount)
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
    
            temp = first;

            for( i = 1 ; i < iPos - 1; i++)
            {
                temp = temp.next;
            }       

            temp.next = temp.next.next;

            iCount--;
        }
    }

}

class class SinglyLL014
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();

        java.util.Scanner sobjX = new java.util.Scanner(System.in);

        int iChoice = 1;
        int iValue = 0;
        int iPos = 0;
        int iRet = 0;

        while(iChoice != 0)
        {
                System.out.println("\n--------------------------------------");
                System.out.println("      Singly Linked List Menu");
                System.out.println("--------------------------------------");

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
            iChoice = sobjX.nextInt();

            switch(iChoice)
            {
                case 1:
                    System.out.print("Enter data : ");
                    iValue = sobjX.nextInt();

                    sobj.InsertFirst(iValue);
                    break;

                case 2:
                    System.out.print("Enter data : ");
                    iValue = sobjX.nextInt();

                    sobj.InsertLast(iValue);
                    break;

                case 3:
                    System.out.print("Enter data : ");
                    iValue = sobjX.nextInt();

                    System.out.print("Enter position : ");
                    iPos = sobjX.nextInt();

                    sobj.InsertAtPos(iValue, iPos);
                    break;

                case 4:
                    sobj.DeleteFirst();
                    System.out.println("First node deleted");
                    break;

                case 5:
                    sobj.DeleteLast();
                    System.out.println("Last node deleted");
                    break;

                case 6:
                    System.out.print("Enter position : ");
                    iPos = sobjX.nextInt();

                    sobj.DeleteAtPos(iPos);
                    break;

                case 7:
                    sobj.Display();
                    break;

                case 8:
                    iRet = sobj.Count();
                    System.out.println("Number of Nodes : " + iRet);
                    break;

                case 0:
                    System.out.println("Thank you for using the application...");
                    break;

                default:
                    System.out.println("Invalid Choice");
                    break;
            }
        }

        sobjX.close();
    }
}
/*

Expected Output:
================================================================================

-------------------------------
      Singly Linked List Menu
-------------------------------

1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display
8 : Count
0 : Exit

(User performs different operations.)

Example:

|11| -> |21| -> |51| -> |101| -> |111| -> |121| -> NULL

Number of Nodes : 6

================================================================================
Memory Diagram:
================================================================================

                first
                  |
                  v

|11| → |21| → |51| → |101| → |111| → |121| → NULL

Display()

temp = first

temp
 |
 v
|11| → |21| → |51| → |101| → |111| → |121| → NULL

================================================================================
Pointer/Logic Explanation:
================================================================================

Insert Operations

• InsertFirst()
  Inserts a new node at the beginning of the linked list.

• InsertLast()
  Traverses to the last node and inserts a new node.

• InsertAtPos()
  Validates the position and inserts the node at the specified location.

------------------------------------------------------------

Delete Operations

• DeleteFirst()
  Removes the first node.

• DeleteLast()
  Traverses to the second last node and removes the last node.

• DeleteAtPos()
  Removes the node from the specified position after validation.

------------------------------------------------------------

Display()

Uses a temporary reference.

node temp = first;

Traverses until temp becomes null.

------------------------------------------------------------

Count()

Returns iCount.

No traversal is required.

================================================================================
Time Complexity:
================================================================================

InsertFirst()   : O(1)

InsertLast()    : O(n)

InsertAtPos()   : O(n)

DeleteFirst()   : O(1)

DeleteLast()    : O(n)

DeleteAtPos()   : O(n)

Display()       : O(n)

Count()         : O(1)

Space Complexity: O(1)

================================================================================
Operations Performed:
================================================================================

1. Created a Singly Linked List object.
2. Inserted nodes at the beginning.
3. Inserted nodes at the end.
4. Inserted nodes at a specified position.
5. Deleted the first node.
6. Deleted the last node.
7. Deleted a node from a specified position.
8. Displayed all nodes.
9. Counted total nodes.
10. Executed all operations through a menu-driven interface.

================================================================================
Conclusion:
================================================================================

Program 014 represents the complete implementation of a
Singly Linear Linked List in Java. It integrates all
fundamental linked list operations within a menu-driven
application while following Object-Oriented Programming
principles. The program demonstrates dynamic node
management, encapsulation, traversal techniques, position
validation, and efficient node counting using iCount.
This implementation serves as the foundation for advanced
linked list data structures and interview-oriented
problem solving.

================================================================================
*/
