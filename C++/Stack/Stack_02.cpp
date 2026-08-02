/*
===============================================================================
Program Name    : Stack - Push Operation
Program Number  : 02
File Name       : Stack_02.cpp
Description     : This program demonstrates the Push() operation of a Stack
                  using C++. The Push operation inserts a new element at the
                  top of the Stack following the LIFO principle.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Structure
4. Dynamic Memory Allocation
5. Constructor

Key Learning Points:
- Insert an element at the top of the Stack.
- Understand dynamic memory allocation using new.
- Increase the Stack size after insertion.
- Follow the LIFO (Last-In-First-Out) principle.

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
    this->first = NULL;
    this->iCount = 0;
}

// Push (Insert First)
void Stack::Push(int iNo)
{
    struct node *newn = NULL;

    newn = new struct node;

    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }

    iCount++;
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

// Main
int main()
{
    Stack sobj;

    sobj.Push(11);
    sobj.Push(21);
    sobj.Push(51);
    sobj.Push(101);

    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";
/*
===============================================================================
Expected Output:
===============================================================================

Number of nodes are : 4

===============================================================================
Memory Representation:
===============================================================================

                TOP
                 │
                 ▼
             +-------+
             | 101 | •────┐
             +-------+    │
                          ▼
             +-------+
             |  51 | •────┐
             +-------+    │
                          ▼
             +-------+
             |  21 | •────┐
             +-------+    │
                          ▼
             +-------+
             |  11 | •───► NULL
             +-------+

iCount = 4

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Store the given data into the node.
3. If the Stack is empty:
      Make first point to the new node.
4. Otherwise:
      Insert the new node before the first node.
      Update first.
5. Increment the Stack count.
6. Stop.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
        Create New Node
               │
               ▼
      Is Stack Empty?
        │            │
      Yes           No
       │             │
       ▼             ▼
 first = newn   newn->next = first
                    │
                    ▼
               first = newn
                    │
                    ▼
             Increment Count
                    │
                    ▼
                   Stop

===============================================================================
Time Complexity:
===============================================================================

Push() : O(1)

Count() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 002 demonstrates the Push() operation of a Stack using C++. The
program inserts new elements at the top of the Stack using dynamic memory
allocation and follows the Last-In-First-Out (LIFO) principle.

===============================================================================
*/
    return 0;
}
