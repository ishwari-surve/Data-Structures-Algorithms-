/*
===============================================================================
Program Name    : Stack - Peep Operation
Program Number  : 06
File Name       : Stack_06.java

Description     : This program implements the Peep operation of a Stack using
                  a singly linear linked list. The Peep operation returns the
                  topmost element of the Stack without removing it.

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
12. LIFO Principle

Key Learning Points:
- Understand the Peep operation of a Stack.
- Learn how to access the topmost element without deleting it.
- Understand how the first pointer represents the top of the Stack.
- Learn how to handle an empty Stack.
- Understand the difference between Peep and Pop operations.
- Understand the LIFO (Last In First Out) principle.

===============================================================================
*/

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

class Stack_06
{
    public static void main(String A[])
    {
        Stack sobj = new Stack();

        int iRet = 0;

        sobj.Push(11);
        sobj.Push(21);
        sobj.Push(51);
        sobj.Push(101);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("\nNumber of Elements : " + iRet);

        iRet = sobj.Peep();
        System.out.println("\nTopmost Element : " + iRet);

        iRet = sobj.Count();
        System.out.println("\nNumber of Elements : " + iRet);

        sobj.Display();
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Elements of Stack are :
| 101 |
| 51 |
| 21 |
| 11 |

Number of Elements : 4

Topmost Element : 101

Number of Elements : 4

Elements of Stack are :
| 101 |
| 51 |
| 21 |
| 11 |

===============================================================================
Memory Representation:
===============================================================================

first
  |
  v
+------+-------+
| 101  |   o---------+
+------+-------+     |
                      v
                +------+-------+
                |  51  |   o---------+
                +------+-------+     |
                                       v
                                 +------+-------+
                                 |  21  |   o---------+
                                 +------+-------+     |
                                                        v
                                                  +------+-------+
                                                  |  11  | NULL  |
                                                  +------+-------+

Topmost Element = 101
iCount = 4

Peep operation does not modify the Stack.

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Stack object.
3. Insert elements using Push().
4. Display the Stack elements.
5. Call Count() to display the number of elements.
6. Call Peep().
7. Check whether the Stack is empty.
8. If the Stack is empty, display "Stack is Empty".
9. Otherwise, return the data of the first node.
10. Display the topmost element.
11. Call Count() again.
12. Display the Stack to verify that no element was removed.
13. Stop the program.

===============================================================================
Program Flow:
===============================================================================

        Start
          |
          v
    Create Stack Object
          |
          v
      Push Elements
          |
          v
    Display Stack
          |
          v
        Peep()
          |
          v
    Is Stack Empty?
       /       \
     Yes        No
      |          |
      v          v
  Display     Return first.data
   Empty          |
      |           v
      +-------> Display Topmost
                    |
                    v
              Display Stack
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

O(1) auxiliary space.

O(n) total space for n Stack nodes.

===============================================================================
Conclusion:
===============================================================================

Program 06 demonstrates the Peep operation of a Stack using a singly linear
linked list in Java. The Peep operation accesses and returns the topmost
element without removing it from the Stack. The program also demonstrates
that the number of elements and the Stack structure remain unchanged after
the Peep operation.

===============================================================================
*/
