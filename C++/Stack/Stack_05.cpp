/*
===============================================================================
Program Name    : Stack - Peep Operation
Program Number  : 05
File Name       : Stack_05.cpp
Description     : This program demonstrates the Peep() operation of a Stack
                  using C++. The Peep operation returns the topmost element
                  without removing it from the Stack.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Structure
4. Dynamic Memory Allocation
5. Stack Traversal

Key Learning Points:
- Retrieve the top element of the Stack.
- Do not modify the Stack during Peep().
- Check for Stack underflow.
- Understand the Top element in LIFO.

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
    return 0;
}

// Peep (Top Element)
int Stack::Peep()
{
    if(first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    return first->data;
}

// Display
void Stack::Display()
{
    struct node *temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |"<<endl;
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
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

    sobj.Display();

    iRet = sobj.Peep();

    cout<<"\nTop element is : "<<iRet<<"\n";

    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

| 101 |
| 51 |
| 21 |
| 11 |
NULL

Top element is : 101
Number of nodes are : 4

===============================================================================
Memory Representation:
===============================================================================

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

Peep() returns : 101

===============================================================================
Algorithm:
===============================================================================

1. Check whether the Stack is empty.
2. If empty, return an error value.
3. Otherwise, return the data of the first node.
4. Stop.

===============================================================================
Time Complexity:
===============================================================================

Push()    : O(1)

Peep()    : O(1)

Display() : O(n)

Count()   : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 005 demonstrates the Peep() operation of a Stack using C++. The
program retrieves the topmost element without removing it from the Stack,
thereby preserving the Stack structure while following the LIFO principle.

===============================================================================
*/
