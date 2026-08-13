/*
===============================================================================
Program Name    : Stack - Display Operation
Program Number  : 03
File Name       : Stack_03.java

Description     : This program implements the Display operation of a Stack
                  using a singly linear linked list. The Display operation
                  traverses the Stack from the first node and displays all
                  the elements.

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
8. Display Operation
9. Traversal
10. LIFO Principle

Key Learning Points:
- Understand how to display elements of a Stack.
- Learn how to traverse a Stack using a temporary pointer.
- Understand the relationship between first and the Stack nodes.
- Learn how Stack elements are displayed from top to bottom.
- Understand the LIFO (Last In First Out) structure.

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
    // Function Name : Display
    // Description   : Display Stack
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Display()
    {
        node temp = null;

        temp = first;

        System.out.println("\nElements of Stack are : ");

        while(temp != null)
        {
            System.out.println("| " + temp.data + " |");
            temp = temp.next;
        }
    }
}

class Stack_03
{
    public static void main(String A[])
    {
        Stack sobj = new Stack();

        sobj.Push(11);
        sobj.Push(21);
        sobj.Push(51);
        sobj.Push(101);

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

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Stack object.
3. Insert 11, 21, 51 and 101 using Push().
4. Set a temporary pointer temp to first.
5. Check whether temp is NULL.
6. If temp is not NULL:
   - Display the data of the current node.
   - Move temp to the next node.
7. Repeat the process until temp becomes NULL.
8. Stop the program.

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
      Set temp = first
          |
          v
     Is temp NULL?
       /       \
     No         Yes
     |           |
     v           v
 Display Data   Stop
     |
     v
 temp = temp.next
     |
     +---------> Is temp NULL?

===============================================================================
Time Complexity:
===============================================================================

Push()    : O(1)
Display() : O(n)

===============================================================================
Space Complexity:
===============================================================================

Display() : O(1) auxiliary space

O(n) total space for n Stack nodes.

===============================================================================
Conclusion:
===============================================================================

Program 03 demonstrates the Display operation of a Stack using a singly
linear linked list in Java. The Stack is traversed from the first node
using a temporary pointer, and all elements are displayed from the top
of the Stack to the bottom.

===============================================================================
*/
