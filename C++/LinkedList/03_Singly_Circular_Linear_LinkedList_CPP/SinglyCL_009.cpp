/*
===============================================================================
Program Name    : Singly Circular Linked List - InsertFirst()
Program Number  : 009
Description     : This program implements the InsertFirst() operation in a
                  Singly Circular Linked List. It inserts a new node at the
                  beginning of the list while maintaining the circular link.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Singly Circular Linked List
2. Dynamic Memory Allocation
3. InsertFirst Operation
4. Constructor
5. Circular Linking
6. Pointer Manipulation

Key Learning Points:
- Creating a new node dynamically.
- Inserting a node at the beginning.
- Handling empty and non-empty linked lists.
- Updating first and last pointers.
- Maintaining the circular nature of the list.

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

typedef struct node NODE;
typedef struct node *PNODE;

///////////////////////////////////////////////////////////////////////////////

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(int);

        void InsertLast(int);
        void InsertAtPos(int,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

///////////////////////////////////////////////////////////////////////////////

SinglyCL::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////

void SinglyCL::InsertFirst(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }

    last->next = first;

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////

void SinglyCL::Display()
{
}

int SinglyCL::Count()
{
    return iCount;
}

void SinglyCL::InsertLast(int iNo)
{
}

void SinglyCL::InsertAtPos(int iNo,int iPos)
{
}

void SinglyCL::DeleteFirst()
{
}

void SinglyCL::DeleteLast()
{
}

void SinglyCL::DeleteAtPos(int iPos)
{
}

///////////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyCL sobj;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    return 0;
}

/*
===============================================================================
Memory Representation:
===============================================================================

Initially

first = NULL
last  = NULL

InsertFirst(51)

first,last
    │
    ▼
+---------+
|   51    |
+---------+
     ▲
     └──────────────┐
                    │
                    └── next points to itself

InsertFirst(21)

first                  last
  │                     │
  ▼                     ▼
+------+      +------+
| 21   | ---> | 51   |
+------+      +------+
    ^______________|

InsertFirst(11)

first                           last
  │                              │
  ▼                              ▼
+------+ ---> +------+ ---> +------+
| 11   |      | 21   |      | 51   |
+------+      +------+      +------+
    ^_______________________________|

===============================================================================
Program Flow:
===============================================================================

Create New Node
        │
        ▼
Empty List ?
   │          │
 Yes         No
 │            │
 ▼            ▼
first=last    Insert Before first
 │            │
 └──────┬─────┘
        ▼
last->next = first
        │
        ▼
Increment iCount

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()      : O(1)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 009 demonstrates the InsertFirst() operation for a Singly Circular
Linked List. The new node is inserted at the beginning, the first pointer is
updated, and the last node is linked back to the new first node to preserve
the circular structure.

===============================================================================
*/
