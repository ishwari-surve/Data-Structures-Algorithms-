/*
===============================================================================
Program Name    : Stack - Push Operation
Program Number  : 02
File Name       : Stack_02.java

Description     : This program implements the Push operation of a Stack using
                  a singly linear linked list. The Push operation inserts a
                  new element at the first position of the Stack.

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
8. Dynamic Memory Allocation
9. LIFO Principle

Key Learning Points:
- Understand the Push operation of a Stack.
- Learn how a new node is inserted at the first position.
- Understand how the first pointer is updated.
- Learn how iCount is updated after insertion.
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
}

class Stack_02
{
    public static void main(String A[])
    {
        Stack sobj = new Stack();

        sobj.Push(11);
        sobj.Push(21);
        sobj.Push(51);
        sobj.Push(101);

        System.out.println("Elements inserted successfully");
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Elements inserted successfully

===============================================================================
Memory Representation:
===============================================================================

After Push(11):

first
  |
  v
+------+-------+
|  11  | NULL  |
+------+-------+


After Push(21):

first
  |
  v
+------+-------+    +------+-------+
|  21  |   o-------->|  11  | NULL|
+------+-------+    +------+-------+


After Push(51):

first
  |
  v
+------+-------+    +------+-------+    +------+-------+
|  51  |   o-------->|  21  |   o-------->|  11  | NULL|
+------+-------+    +------+-------+    +------+-------+


After Push(101):

first
  |
  v
+------+-------+    +------+-------+    +------+-------+    +------+-------+
| 101  |   o-------->|  51  |   o-------->|  21  |   o-------->|  11  | NULL|
+------+-------+    +------+-------+    +------+-------+    +------+-------+

iCount = 4

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a new node dynamically.
3. Store the given element in the data member of the new node.
4. Set the next pointer of the new node to NULL.
5. Connect the new node to the existing first node.
6. Update first to point to the new node.
7. Increment iCount by 1.
8. Repeat the Push operation for all given elements.
9. Display the success message.
10. Stop the program.

===============================================================================
Program Flow:
===============================================================================

        Start
          |
          v
    Create New Node
          |
          v
   Store Given Element
          |
          v
    newn.next = first
          |
          v
      first = newn
          |
          v
      iCount++
          |
          v
    Push Next Element
          |
          v
         Stop

===============================================================================
Time Complexity:
===============================================================================

Push() : O(1)

===============================================================================
Space Complexity:
===============================================================================

O(1) auxiliary space per new node.

O(n) total space for n Stack nodes.

===============================================================================
Conclusion:
===============================================================================

Program 02 demonstrates the Push operation of a Stack using a singly linear
linked list in Java. Each new element is inserted at the first position of
the Stack, and the first pointer is updated accordingly. The program
demonstrates the basic implementation of the LIFO (Last In First Out)
principle.

===============================================================================
*/
