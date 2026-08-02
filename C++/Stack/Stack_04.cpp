/*
===============================================================================
Program Name    : Stack - Display Operation
Program Number  : 004
File Name       : Stack_04.cpp
Description     : This program demonstrates the Display() operation of a Stack
                  using C++. The Display operation traverses the Stack from
                  top to bottom and displays all elements.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Structure
4. Dynamic Memory Allocation
5. Traversing a Linked List

Key Learning Points:
- Traverse the Stack from Top to Bottom.
- Display all elements of the Stack.
- Understand Stack representation using linked lists.
- Observe the LIFO ordering of elements.

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
    return 0;
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

    iRet = sobj.Count();

    cout<<"Number of nodes are : "<<iRet<<"\n";


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

===============================================================================
Algorithm:
===============================================================================

1. Create a temporary pointer and initialize it to first.
2. Traverse the Stack until temp becomes NULL.
3. Display the data of each node.
4. Move temp to the next node.
5. Display NULL.
6. Stop.

===============================================================================
Time Complexity:
===============================================================================

Push()    : O(1)

Display() : O(n)

Count()   : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates the Display() operation of a Stack using C++.
The program traverses the Stack from Top to Bottom and displays all
elements in LIFO order, helping visualize the current state of the Stack.

===============================================================================
*/
