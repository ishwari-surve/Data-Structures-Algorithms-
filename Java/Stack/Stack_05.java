/*
===============================================================================
Program Name    : Stack - Pop Operation
Program Number  : 05
File Name       : Stack_05.java

Description     : This program implements the Pop operation of a Stack using
                  a singly linear linked list. The Pop operation removes the
                  top element from the Stack and returns its value.

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
9. Display Operation
10. Count Operation
11. LIFO Principle

Key Learning Points:
- Understand the Pop operation of a Stack.
- Learn how to delete the first node from the Stack.
- Understand how the first pointer is updated after deletion.
- Learn how iCount is decremented after Pop operation.
- Understand Stack Underflow when the Stack is empty.
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

class Stack_05
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

        iRet = sobj.Pop();
        System.out.println("\nRemoved Element : " + iRet);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("\nNumber of Elements : " + iRet);
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

Removed Element : 101

Elements of Stack are :
| 51 |
| 21 |
| 11 |

Number of Elements : 3

===============================================================================
Memory Representation:
===============================================================================

Before Pop():

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

After Pop():

first
  |
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

Removed Node = 101
iCount = 3

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Stack object.
3. Insert elements using Push().
4. Display the Stack elements.
5. Call Count() to display the number of elements.
6. Call Pop().
7. Check whether the Stack is empty.
8. If the Stack is empty, display "Stack is Empty".
9. Otherwise, store the data of the first node.
10. Move first to the next node.
11. Decrease iCount by 1.
12. Return the removed element.
13. Display the updated Stack.
14. Display the updated count.
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
      Push Elements
          |
          v
    Display Elements
          |
          v
        Pop()
          |
          v
    Is Stack Empty?
       /       \
     Yes        No
      |          |
      v          v
  Display     Store Data
   Empty          |
      |           v
      |       first = first.next
      |           |
      |           v
      |        iCount--
      |           |
      +-----+-----+
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

Program 05 demonstrates the Pop operation of a Stack using a singly linear
linked list in Java. The Pop operation removes the first node, which
represents the top element of the Stack. The program also updates the
element count and demonstrates the LIFO (Last In First Out) principle.

===============================================================================
*/
