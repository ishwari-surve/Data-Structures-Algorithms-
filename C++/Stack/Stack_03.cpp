/*
===============================================================================
Program Name    : Stack - Pop Operation
Program Number  : 03
File Name       : Stack_03.cpp
Description     : This program demonstrates the Pop() operation of a Stack
                  using C++. The Pop operation removes the topmost element
                  from the Stack following the LIFO principle.

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
- Remove an element from the top of the Stack.
- Return the deleted element.
- Release dynamically allocated memory.
- Decrease the Stack size after deletion.

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
    newn->next = first;
    first = newn;

    iCount++;
}

// Pop (Delete First)
int Stack::Pop()
{
    int iValue = 0;

    struct node *temp = NULL;

    if(first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    temp = first;

    iValue = first->data;
    first = first->next;

    delete temp;

    iCount--;

    return iValue;
}

// Peep (Top Element)
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
    int iRet = 0;

    sobj.Push(11);
    sobj.Push(21);
    sobj.Push(51);
    sobj.Push(101);

    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";

    iRet = sobj.Pop();

    cout<<"Removed element is : "<<iRet<<"\n";

    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Number of nodes are : 4
Removed element is : 101
Number of nodes are : 3

===============================================================================
Memory Representation:
===============================================================================

Before Pop()

                TOP
                 │
                 ▼
             +-------+
             | 101 | •──┐
             +-------+  │
                        ▼
             +-------+
             |  51 | •──┐
             +-------+  │
                        ▼
             +-------+
             |  21 | •──┐
             +-------+  │
                        ▼
             +-------+
             |  11 | •──► NULL
             +-------+

↓

After Pop()

                TOP
                 │
                 ▼
             +-------+
             |  51 | •──┐
             +-------+  │
                        ▼
             +-------+
             |  21 | •──┐
             +-------+  │
                        ▼
             +-------+
             |  11 | •──► NULL
             +-------+

Deleted Node : 101
iCount = 3

===============================================================================
Algorithm:
===============================================================================

1. Check whether the Stack is empty.
2. If empty, return an error value.
3. Store the data of the first node.
4. Move first to the next node.
5. Delete the old first node.
6. Decrement the node count.
7. Return the deleted element.

===============================================================================
Time Complexity:
===============================================================================

Push()  : O(1)

Pop()   : O(1)

Count() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 003 demonstrates the Pop() operation of a Stack using C++. The
program removes the topmost element, deallocates its memory, updates the
Stack pointer, and returns the deleted element while maintaining the
LIFO (Last-In-First-Out) principle.

===============================================================================
*/
