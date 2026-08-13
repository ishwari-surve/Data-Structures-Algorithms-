/*
===============================================================================
Program Name    : Stack - Basic Structure
Program Number  : 01
File Name       : Stack_01.java

Description     : This program demonstrates the basic structure of a Stack
                  using Java. It defines the node class, Stack class,
                  constructor, and initializes an empty Stack.

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
7. Dynamic Memory Allocation Preparation

Key Learning Points:
- Understand the basic structure of a Stack.
- Learn how a Stack can be represented using a linked list.
- Understand the node structure used in a Stack.
- Initialize an empty Stack using a constructor.
- Understand the first pointer and iCount variables.

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
}

class Stack_01
{
    public static void main(String A[])
    {
        Stack sobj = new Stack();

        System.out.println("Stack created successfully");
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Stack created successfully

===============================================================================
Memory Representation:
===============================================================================

             Stack Object

        +----------------------+
        | first  -------> NULL |
        | iCount = 0            |
        +----------------------+

Stack is Empty.

===============================================================================
Node Structure:
===============================================================================

        +-----------+-----------+
        |   data    |   next    |
        +-----------+-----------+
              |           |
              |           |
            Value       NULL

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Define the node class with data and next members.
3. Define the Stack class.
4. Declare first and iCount as private data members.
5. Initialize first to NULL using the constructor.
6. Initialize iCount to 0.
7. Create a Stack object.
8. Display the Stack creation message.
9. Stop the program.

===============================================================================
Program Flow:
===============================================================================

        Start
          |
          v
     Define Node Class
          |
          v
    Create Stack Class
          |
          v
    Call Constructor
          |
          v
 Initialize first = NULL
          |
          v
 Initialize iCount = 0
          |
          v
   Create Stack Object
          |
          v
    Display Message
          |
          v
         Stop

===============================================================================
Time Complexity:
===============================================================================

Constructor : O(1)

===============================================================================
Space Complexity:
===============================================================================

O(1)

===============================================================================
Conclusion:
===============================================================================

Program 01 introduces the basic structure of a Stack using Java. It defines
the node class and Stack class and initializes an empty Stack using a
constructor. This program serves as the foundation for implementing the
Stack operations in subsequent programs.

===============================================================================
*/
