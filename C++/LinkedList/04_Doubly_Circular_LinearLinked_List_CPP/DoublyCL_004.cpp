/*
===============================================================================
Program Name    : Doubly Circular Linked List - Display()
Program Number  : 004
File Name       : DoublyCL_04.cpp
Description     : This program demonstrates how to display all the nodes of
                  a Doubly Circular Linked List using C++.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Pointer Traversal
5. Circular Linked List
6. do-while Loop
7. Constructor

Key Learning Points:
- Traverse a Doubly Circular Linked List.
- Display every node exactly once.
- Use do-while loop for circular traversal.
- Stop traversal after reaching the first node again.

===============================================================================
*/
#include<iostream>
using namespace std;

#pragma pack(1)

class node
{
public:
    int data;
    node *next;
    node *prev;
};

typedef class node NODE;
typedef class node *PNODE;

class DoublyCL
{
private:
    PNODE first;
    PNODE last;
    int iCount;

public:
    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

DoublyCL::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

void DoublyCL::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    PNODE temp = first;

    cout<<"<=> ";

    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }while(temp != first);

    cout<<endl;
}

int DoublyCL::Count()
{
    return 0;
}

void DoublyCL::InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;

    iCount++;
}

void DoublyCL::InsertLast(int no)
{
}

void DoublyCL::InsertAtPos(int no,int iPos)
{
}

void DoublyCL::DeleteFirst()
{
}

void DoublyCL::DeleteLast()
{
}

void DoublyCL::DeleteAtPos(int iPos)
{
}

int main()
{
    DoublyCL dobj;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.Display();

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

<=> | 11 | <=> | 21 | <=> | 51 | <=>

===============================================================================
Memory Representation:
===============================================================================

             first
               │
               ▼

<=> [11] ⇄ [21] ⇄ [51] <=>
 ^                      │
 |______________________|

Traversal:

11 → 21 → 51 → back to 11 (Stop)

===============================================================================
Algorithm:
===============================================================================

1. Check whether the linked list is empty.
2. If empty, return.
3. Create a temporary pointer and initialize it to first.
4. Traverse the linked list using a do-while loop.
5. Display the data of each node.
6. Stop when temp becomes first again.
7. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
             │
             ▼
      Is List Empty?
        │          │
      Yes         No
       │           │
       ▼           ▼
     Return    temp = first
                   │
                   ▼
             Display Node
                   │
                   ▼
           temp = temp->next
                   │
                   ▼
          temp != first ?
             │        │
            Yes      No
             │        │
             └────────┘
                  │
                  ▼
                 Stop

===============================================================================
Time Complexity:
===============================================================================

Display() : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates the Display() operation of a Doubly Circular
Linked List. The program traverses the list using a do-while loop and
prints each node exactly once while maintaining the circular traversal.

===============================================================================
*/
