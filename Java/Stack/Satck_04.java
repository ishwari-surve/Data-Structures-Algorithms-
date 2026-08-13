/*
===============================================================================
Program Name    : Stack - Count Operation
Program Number  : 04
File Name       : Stack_04.java

Description     : This program implements the Count operation of a Stack
                  using a singly linear linked list. The Count operation
                  returns the total number of elements currently present
                  in the Stack.

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
9. Count Operation
10. LIFO Principle

Key Learning Points:
- Understand how to count elements in a Stack.
- Learn how iCount keeps track of the number of elements.
- Understand the use of a counter variable in a data structure.
- Learn how Push() updates the element count.
- Understand how Count() returns the current number of elements.

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

class Stack_04
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

iCount = 4

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Stack object.
3. Insert elements using Push().
4. Increment iCount after every successful Push operation.
5. Display the Stack elements.
6. Call Count().
7. Return the value of iCount.
8. Display the number of elements.
9. Stop the program.

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
      iCount++
          |
          v
    Display Elements
          |
          v
       Count()
          |
          v
    Display iCount
          |
          v
         Stop

===============================================================================
Time Complexity:
===============================================================================

Push()  : O(1)
Display(): O(n)
Count() : O(1)

===============================================================================
Space Complexity:
===============================================================================

O(1) auxiliary space.

O(n) total space for n Stack nodes.

===============================================================================
Conclusion:
===============================================================================

Program 04 demonstrates the Count operation of a Stack using a singly
linear linked list in Java. The iCount variable keeps track of the total
number of elements, and the Count() function returns the current number
of elements in the Stack.

===============================================================================
*/
