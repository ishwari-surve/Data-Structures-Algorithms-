/*
===============================================================================
Program Name    : Stack - Menu Driven Application
Program Number  : 08
File Name       : Stack_08.java

Description     : This program implements a complete Menu Driven Stack
                  Application using a singly linear linked list. The program
                  supports Push, Pop, Peep, Display and Count operations.

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
6. Stack
7. Push Operation
8. Pop Operation
9. Peep Operation
10. Display Operation
11. Count Operation
12. Menu Driven Application
13. Scanner Class
14. LIFO Principle

Key Learning Points:
- Understand the implementation of Stack using a singly linear linked list.
- Learn how to perform Push operation.
- Learn how to perform Pop operation.
- Understand the Peep operation.
- Learn how to display Stack elements.
- Learn how to count Stack elements.
- Understand menu driven programming.
- Understand the LIFO (Last In First Out) principle.

===============================================================================
*/

import java.util.*;

class node
{
    public int data;
    public node next;
}

class Stack
{
    private node first;
    private int iCount;

    public Stack()
    {
        first = null;
        iCount = 0;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Push
    // Description   : Insert element at First
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Push(int iNo)
    {
        node newn = null;

        newn = new node();

        newn.data = iNo;
        newn.next = null;

        newn.next = first;
        first = newn;

        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Pop
    // Description   : Delete element from First
    //
    ///////////////////////////////////////////////////////////////////////////

    public int Pop()
    {
        int iValue = 0;
        node temp = null;

        if(first == null)
        {
            System.out.println("Stack is Empty");
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
    // Function Name : Peep
    // Description   : Return topmost element
    //
    ///////////////////////////////////////////////////////////////////////////

    public int Peep()
    {
        if(first == null)
        {
            System.out.println("Stack is Empty");
            return -1;
        }

        return first.data;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Display
    // Description   : Display Stack
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Display()
    {
        node temp = first;

        System.out.println("\nElements of Stack are : ");

        while(temp != null)
        {
            System.out.println("| " + temp.data + " |");
            temp = temp.next;
        }
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

class Stack_08
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        Stack stobj = new Stack();

        int iChoice = 0;
        int iValue = 0;
        int iRet = 0;

        System.out.println("-------------------------------------------------");
        System.out.println("        Stack Menu Driven Application");
        System.out.println("-------------------------------------------------");

        while(true)
        {
            System.out.println("\n-------------------------------------------------");
            System.out.println("---------------------STACK-----------------------");
            System.out.println("-------------------------------------------------");

            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Peep");
            System.out.println("4. Display");
            System.out.println("5. Count");
            System.out.println("6. Exit");

            System.out.println("-------------------------------------------------");

            System.out.print("Enter your choice : ");
            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                case 1:

                    System.out.print("Enter the data : ");
                    iValue = sobj.nextInt();

                    stobj.Push(iValue);

                    System.out.println("Element inserted successfully");
                    break;

                case 2:

                    iRet = stobj.Pop();

                    if(iRet != -1)
                    {
                        System.out.println("Removed Element : " + iRet);
                    }
                    break;

                case 3:

                    iRet = stobj.Peep();

                    if(iRet != -1)
                    {
                        System.out.println("Topmost Element : " + iRet);
                    }
                    break;

                case 4:

                    stobj.Display();
                    break;

                case 5:

                    iRet = stobj.Count();

                    System.out.println("Number of Elements : " + iRet);
                    break;

                case 6:

                    System.out.println("Thank you for using Stack Application");
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
        Stack Menu Driven Application
-------------------------------------------------

-------------------------------------------------
---------------------STACK-----------------------
-------------------------------------------------
1. Push
2. Pop
3. Peep
4. Display
5. Count
6. Exit
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

Enter your choice : 1
Enter the data : 101
Element inserted successfully

Enter your choice : 4

Elements of Stack are :
| 101 |
| 51 |
| 21 |
| 11 |

Enter your choice : 5
Number of Elements : 4

Enter your choice : 3
Topmost Element : 101

Enter your choice : 2
Removed Element : 101

Enter your choice : 4

Elements of Stack are :
| 51 |
| 21 |
| 11 |

Enter your choice : 5
Number of Elements : 3

Enter your choice : 6
Thank you for using Stack Application

===============================================================================
Memory Representation:
===============================================================================

                    first
                      |
                      v
                +-----------+
                |   101     |
                |    next --------+
                +-----------+      |
                                   v
                             +-----------+
                             |    51     |
                             |    next --------+
                             +-----------+      |
                                                v
                                          +-----------+
                                          |    21     |
                                          |    next --------+
                                          +-----------+      |
                                                             v
                                                       +-----------+
                                                       |    11     |
                                                       | next=NULL |
                                                       +-----------+

iCount = 4

After Pop():

                    first
                      |
                      v
                +-----------+
                |    51     |
                |    next --------+
                +-----------+      |
                                   v
                             +-----------+
                             |    21     |
                             |    next --------+
                             +-----------+      |
                                                v
                                          +-----------+
                                          |    11     |
                                          | next=NULL |
                                          +-----------+

iCount = 3

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Import the Scanner class.
3. Create a Stack object.
4. Initialize first to NULL and iCount to 0.
5. Display the Stack menu.
6. Accept the user's choice.
7. If the choice is Push:
   - Accept an integer value.
   - Create a new node.
   - Insert the node at the beginning of the linked list.
   - Increment iCount.
8. If the choice is Pop:
   - Check whether the Stack is empty.
   - If empty, display "Stack is Empty".
   - Otherwise, remove the first node.
   - Decrement iCount.
9. If the choice is Peep:
   - Check whether the Stack is empty.
   - If not empty, display the data of the first node.
   - Do not modify the Stack.
10. If the choice is Display:
    - Traverse the linked list.
    - Display all Stack elements.
11. If the choice is Count:
    - Return and display iCount.
12. If the choice is Exit:
    - Display the exit message.
    - Terminate the program.
13. For an invalid choice, display "Invalid Choice".
14. Repeat the menu until the user selects Exit.
15. Stop the program.

===============================================================================
Program Flow:
===============================================================================

                         Start
                           |
                           v
                  Create Stack Object
                           |
                           v
                     Display Menu
                           |
                           v
                    Accept Choice
                           |
          +----------------+----------------+
          |        |       |       |        |
          v        v       v       v        v
        Push      Pop     Peep   Display   Count
          |        |       |       |        |
          |        |       |       |        |
          +--------+-------+-------+--------+
                           |
                           v
                    Continue Menu?
                       /       \
                     Yes        No
                      |          |
                      v          v
                 Display Menu   Exit
                                   |
                                   v
                                  Stop

===============================================================================
Time Complexity:
===============================================================================

Push()    : O(1)
Pop()     : O(1)
Peep()    : O(1)
Display() : O(n)
Count()   : O(1)

===============================================================================
Space Complexity:
===============================================================================

O(n) total space for n Stack nodes.

O(1) auxiliary space for Push, Pop, Peep and Count operations.

===============================================================================
Conclusion:
===============================================================================

Program 08 demonstrates a complete Menu Driven Stack Application using a
singly linear linked list in Java. It implements Push, Pop, Peep, Display
and Count operations and provides an interactive menu for the user. The
program helps understand dynamic memory representation, linked list based
Stack implementation and the LIFO (Last In First Out) principle.

===============================================================================
*/
