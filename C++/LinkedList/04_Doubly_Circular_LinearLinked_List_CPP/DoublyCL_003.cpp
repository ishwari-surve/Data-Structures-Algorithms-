/*
===============================================================================
Program Name    : Doubly Circular Linked List - InsertFirst()
Program Number  : 003
File Name       : DoublyCL_03.cpp
Description     : This program demonstrates how to insert a new node at the
                  beginning of a Doubly Circular Linked List using C++.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Dynamic Memory Allocation using new
5. Pointer Manipulation
6. Circular Linking
7. Constructor

Key Learning Points:
- Insert a node at the beginning of the linked list.
- Handle insertion into an empty linked list.
- Maintain both next and previous pointers.
- Preserve the circular nature of the linked list.

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

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

Nodes inserted successfully using InsertFirst().

===============================================================================
Memory Representation:
===============================================================================

After InsertFirst(51)

       +------+
       |  51  |
       +------+
        ↑    ↓
        └────┘

---------------------------------------

After InsertFirst(21)

+------+ ⇄ +------+
|  21  |   |  51  |
+------+ ⇄ +------+
   ▲              │
   └──────────────┘

---------------------------------------

After InsertFirst(11)

+------+ ⇄ +------+ ⇄ +------+
|  11  |   |  21  |   |  51  |
+------+ ⇄ +------+ ⇄ +------+
   ▲                         │
   └─────────────────────────┘

last->next = first
first->prev = last

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Store the given data.
3. If the linked list is empty:
      Make first and last point to the new node.
4. Otherwise:
      Insert the new node before first.
      Update next and previous pointers.
5. Make last->next point to first.
6. Make first->prev point to last.
7. Increment the node count.
8. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
             │
             ▼
      Create New Node
             │
             ▼
      Is List Empty?
        │          │
      Yes         No
       │           │
       ▼           ▼
 first=last     Insert Before First
    =newn             │
                      ▼
        Update Circular Links
                      │
                      ▼
             Increment Count
                      │
                      ▼
                     Stop

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 003 demonstrates the InsertFirst() operation of a Doubly Circular
Linked List. It inserts a new node at the beginning while correctly
maintaining both the forward and backward circular links between nodes.

===============================================================================
*/
