/*
===============================================================================
Program Name    : Singly Circular Linked List - InsertLast()
Program Number  : 010
Description     : This program implements the InsertLast() operation in a
                  Singly Circular Linked List. A new node is inserted at the
                  end of the list while maintaining the circular link between
                  the last node and the first node.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Singly Circular Linked List
2. Dynamic Memory Allocation
3. InsertLast Operation
4. Pointer Manipulation
5. Circular Linking
6. Constructor

Key Learning Points:
- Creating a new node dynamically.
- Inserting a node at the end of the list.
- Handling empty and non-empty linked lists.
- Updating the last pointer.
- Preserving the circular structure.

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

SinglyCL::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

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

void SinglyCL::InsertLast(int iNo)
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
        last->next = newn;
        last = newn;
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

int main()
{
    SinglyCL sobj;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    return 0;
}

/*
===============================================================================
Memory Representation:
===============================================================================

Initially

first = NULL
last  = NULL

InsertLast(51)

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

InsertLast(101)

first                    last
  │                        │
  ▼                        ▼
+------+ -------> +------+
| 51   |          |101   |
+------+ <------- +------+

InsertLast(111)

first                                   last
  │                                      │
  ▼                                      ▼
+------+ ---> +------+ ---> +------+
| 51   |      |101   |      |111   |
+------+      +------+      +------+
    ^___________________________________|

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
first=last   last->next = new Node
 │            │
 │            ▼
 │         last = new Node
 └────────────┬────────────
              ▼
       last->next = first
              │
              ▼
        Increment iCount

===============================================================================
Time Complexity:
===============================================================================

InsertLast()       : O(1)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 010 implements the InsertLast() operation for a Singly Circular Linked
List. The new node is inserted at the end of the list, the last pointer is
updated, and the circular connection between the last node and the first node
is maintained.

===============================================================================
*/
