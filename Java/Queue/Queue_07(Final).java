/*
===============================================================================
Program Name    : Queue - Menu Driven Application
Program Number  : 07
File Name       : Queue_07.java

Description     : This program implements a menu driven Queue application
                  using a singly linear linked list. It provides operations
                  such as Enqueue, Dequeue, Display and Count.

Date            : August 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Constructor
5. Singly Linear Linked List
6. Queue
7. Enqueue Operation
8. Dequeue Operation
9. Display Operation
10. Count Operation
11. Menu Driven Programming
12. Scanner Class
13. FIFO Principle

Key Learning Points:
- Understand how to implement a Queue using a singly linear linked list.
- Learn how to perform Enqueue and Dequeue operations.
- Understand the FIFO (First In First Out) principle.
- Learn how to display Queue elements.
- Learn how to count the number of Queue elements.
- Understand menu driven programming using switch-case.
- Learn how to accept user input using Scanner.
- Handle the Queue Empty condition.

===============================================================================
*/

import java.util.*;

class node
{
    public int data;
    public node next;
}

class Queue
{
    private node first;
    private int iCount;

    public Queue()
    {
        first = null;
        iCount = 0;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Enqueue
    // Description   : Insert element at Last
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Enqueue(int iNo)
    {
        node newn = null;
        node temp = null;

        newn = new node();

        newn.data = iNo;
        newn.next = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }

        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Dequeue
    // Description   : Delete element from First
    //
    ///////////////////////////////////////////////////////////////////////////

    public int Dequeue()
    {
        int iValue = 0;
        node temp = null;

        if(first == null)
        {
            System.out.println("Queue is Empty");
            return -1;
        }

        iValue = first.data;

        temp = first;
        first = first.next;
        temp = null;

        iCount--;

        return iValue;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Display
    // Description   : Display Queue
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Display()
    {
        node temp = first;

        if(first == null)
        {
            System.out.println("Queue is Empty");
            return;
        }

        System.out.println("\nElements of Queue are : ");

        while(temp != null)
        {
            System.out.print("|"+temp.data+"| -> ");
            temp = temp.next;
        }

        System.out.println("NULL");
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Count
    // Description   : Count number of elements
    //
    ///////////////////////////////////////////////////////////////////////////

    public int Count()
    {
        return iCount;
    }
}

class Queue_07
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        Queue qobj = new Queue();

        int iChoice = 0;
        int iValue = 0;
        int iRet = 0;

        System.out.println("-------------------------------------------------");
        System.out.println("        Queue Menu Driven Application");
        System.out.println("-------------------------------------------------");

        while(true)
        {
            System.out.println("\n-------------------------------------------------");
            System.out.println("--------------------- QUEUE ---------------------");
            System.out.println("-------------------------------------------------");

            System.out.println("1. Enqueue");
            System.out.println("2. Dequeue");
            System.out.println("3. Display");
            System.out.println("4. Count");
            System.out.println("5. Exit");

            System.out.println("-------------------------------------------------");

            System.out.print("Enter your choice : ");
            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                case 1:

                    System.out.print("Enter the data : ");
                    iValue = sobj.nextInt();

                    qobj.Enqueue(iValue);

                    System.out.println("Element inserted successfully");
                    break;

                case 2:

                    iRet = qobj.Dequeue();

                    if(iRet != -1)
                    {
                        System.out.println("Removed Element : "+iRet);
                    }

                    break;

                case 3:

                    qobj.Display();
                    break;

                case 4:

                    iRet = qobj.Count();

                    System.out.println("Number of Elements : "+iRet);
                    break;

                case 5:

                    System.out.println("Thank you for using Queue Application");

                    sobj.close();

                    System.exit(0);

                default:

                    System.out.println("Invalid Choice");
                    break;
            }
        }
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

-------------------------------------------------
        Queue Menu Driven Application
-------------------------------------------------

-------------------------------------------------
--------------------- QUEUE ---------------------
-------------------------------------------------
1. Enqueue
2. Dequeue
3. Display
4. Count
5. Exit
-------------------------------------------------
Enter your choice : 1
Enter the data : 11
Element inserted successfully

Enter your choice : 1
Enter the data : 21
Element inserted successfully

Enter your choice : 1
Enter the data : 51
Element inserted successfully

Enter your choice : 3

Elements of Queue are :
|11| -> |21| -> |51| -> NULL

Enter your choice : 4
Number of Elements : 3

Enter your choice : 2
Removed Element : 11

Enter your choice : 3

Elements of Queue are :
|21| -> |51| -> NULL

Enter your choice : 5
Thank you for using Queue Application

===============================================================================
Memory Representation:
===============================================================================

After inserting 11, 21 and 51:

first
  |
  v
+------+-------+    +------+-------+    +------+-------+
|  11  |   o-------->|  21  |   o-------->|  51  | NULL|
+------+-------+    +------+-------+    +------+-------+

iCount = 3

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Scanner object for accepting user input.
3. Create a Queue object.
4. Initialize first to NULL and iCount to 0.
5. Display the Queue menu.
6. Accept the user's choice.
7. If the choice is 1:
   - Accept an element from the user.
   - Insert the element using Enqueue().
   - Display a success message.
8. If the choice is 2:
   - Call Dequeue().
   - Remove the first element of the Queue.
   - Display the removed element.
9. If the choice is 3:
   - Display all Queue elements.
10. If the choice is 4:
    - Call Count().
    - Display the number of Queue elements.
11. If the choice is 5:
    - Display the exit message.
    - Terminate the application.
12. If the choice is invalid:
    - Display "Invalid Choice".
13. Repeat the menu until the user selects Exit.
14. Stop the program.

===============================================================================
Program Flow:
===============================================================================

             Start
               |
               v
       Create Queue Object
               |
               v
         Display Menu
               |
               v
       Accept User Choice
               |
       +-------+-------+-------+-------+
       |       |       |       |       |
       v       v       v       v       v
    Enqueue Dequeue Display  Count    Exit
       |       |       |       |       |
       +-------+-------+-------+       |
               |                       |
               v                       v
          Display Menu              Stop

===============================================================================
Time Complexity:
===============================================================================

Enqueue() : O(n)
Dequeue() : O(1)
Display() : O(n)
Count()   : O(1)

===============================================================================
Space Complexity:
===============================================================================

O(n) total space for n Queue nodes.

===============================================================================
Conclusion:
===============================================================================

Program 07 demonstrates a complete menu driven Queue application using
a singly linear linked list in Java. The user can perform Enqueue,
Dequeue, Display and Count operations interactively. The program
demonstrates the FIFO principle and menu driven programming using
switch-case and Scanner.

===============================================================================
*/
