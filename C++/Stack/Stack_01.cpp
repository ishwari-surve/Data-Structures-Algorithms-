/*
===============================================================================
Program Name    : Stack - Basic Structure
Program Number  : 01
File Name       : Stack_01.cpp
Description     : This program demonstrates the basic structure of a Stack
                  using C++. It defines the node structure, Stack class,
                  constructor, and function prototypes for Stack operations.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Structure
4. Constructor
5. Dynamic Memory Allocation (Preparation)

Key Learning Points:
- Understand the basic structure of a Stack.
- Learn how a Stack is represented using a linked list.
- Declare Stack operations using member functions.
- Initialize Stack using a constructor.

===============================================================================
*/

#include<iostream>
using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

class Stack
{
private:
    struct node *first;
    int iCount;

public:
    Stack();
    void Push(int iNo);
    int Pop();
    int Peep();
    void Display();
    int Count();
};

// Constructor
Stack::Stack()
{
    first = NULL;
    iCount = 0;
}

// Push
void Stack::Push(int iNo)
{

}

// Pop
int Stack::Pop()
{
    return 0;
}

// Peep
int Stack::Peep()
{
    return 0;
}

// Display
void Stack::Display()
{

}

// Count
int Stack::Count()
{
    return iCount;
}

int main()
{
    Stack sobj;

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

The program only creates a Stack object and initializes the stack.

===============================================================================
Memory Representation:
===============================================================================

          Stack Object

        +------------------+
        | first  -------> NULL
        | iCount = 0       |
        +------------------+

Stack is Empty

===============================================================================
Algorithm:
===============================================================================

1. Define the node structure.
2. Create the Stack class.
3. Declare data members.
4. Declare Stack operations.
5. Initialize the Stack using the constructor.
6. Create a Stack object.
7. Stop.

===============================================================================
Program Flow:
===============================================================================

        Start
          │
          ▼
   Define Node Structure
          │
          ▼
    Create Stack Class
          │
          ▼
 Declare Member Functions
          │
          ▼
 Call Constructor
          │
          ▼
 Create Stack Object
          │
          ▼
         Stop

===============================================================================
Time Complexity:
===============================================================================

Constructor : O(1)
Count()     : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 introduces the basic structure of a Stack using C++. It defines
the Stack class, declares all Stack operations, and initializes an empty
stack using a constructor. This program serves as the foundation for the
subsequent implementation of Stack operations.

===============================================================================
*/
