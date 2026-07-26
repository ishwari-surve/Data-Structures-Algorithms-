/*
===============================================================================
Program Name    : Doubly Circular Linked List - Count()
Program Number  : 005
File Name       : DoublyCL_05.cpp
Description     : This program demonstrates how to count the total number of
                  nodes present in a Doubly Circular Linked List.

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
7. Counter Variable

Key Learning Points:
- Traverse a Doubly Circular Linked List.
- Count every node exactly once.
- Understand why do-while is used.
- Return the total number of nodes.

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
    int iCnt = 0;

    if(first == NULL && last == NULL)
    {
        return 0;
    }

    PNODE temp = first;

    do
    {
        iCnt++;
        temp = temp->next;

    }while(temp != first);

    return iCnt;
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
    cout<<"Number of nodes are : "<<dobj.Count()<<endl;

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

<=> | 11 | <=> | 21 | <=> | 51 | <=>

Number of nodes are : 3

===============================================================================
Memory Representation:
===============================================================================

    first 
     │
     ▼

<=> |11| ⇄ |21| ⇄ |51| <=>
 ^                     │
 |_____________________|

Traversal:

11 → 21 → 51 → Back to 11

Count = 3

===============================================================================
Algorithm:
===============================================================================

1. Check whether the linked list is empty.
2. If empty, return 0.
3. Create a temporary pointer and initialize it to first.
4. Initialize a counter variable to 0.
5. Traverse the linked list using a do-while loop.
6. Increment the counter for every visited node.
7. Stop when temp becomes first again.
8. Return the counter value.

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
    Return 0   temp = first
                    │
                    ▼
            Count = Count + 1
                    │
                    ▼
             temp = temp->next
                    │
                    ▼
            temp != first ?
              │         │
            Yes        No
              │         │
              └─────────┘
                    │
                    ▼
              Return Count

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)

Display() : O(n)

Count() : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 005 demonstrates the Count() operation of a Doubly Circular Linked
List. The program traverses the linked list exactly once using a do-while
loop, counts each node, and returns the total number of nodes present.

===============================================================================
*/
