/*
===============================================================================
Program Name    : Singly Circular Linked List - InsertAtPos() Operation
Program Number  : 015
Description     : This program implements the InsertAtPos() function in a
                  Singly Circular Linked List. It allows insertion of a new
                  node at any valid position while maintaining the circular
                  link between the first and last nodes.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================
Concepts Used:
1. Class and Objects
2. Self-Referential Structure
3. Dynamic Memory Allocation (new)
4. Pointer Traversal
5. Position Validation
6. InsertFirst()
7. InsertLast()
8. Pointer Manipulation
9. Circular Linked List

Key Learning Points:
- Validate the insertion position before performing insertion.
- Reuse InsertFirst() and InsertLast() whenever possible.
- Traverse the list until the previous node of the desired position.
- Update links without breaking the circular structure.
- Increase node count after successful insertion.

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

    void DeleteFirst();
};

///////////////////////////////////////////////////////////////////////////

SinglyCL::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////

void SinglyCL::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    PNODE temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }while(temp != last->next);

    cout<<endl;
}

///////////////////////////////////////////////////////////////////////////

int SinglyCL::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////

void SinglyCL::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }

    iCount--;
}

void SinglyCL::DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        PNODE temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;
        last->next = first;
    }

    iCount--;
}
void SinglyCL::InsertAtPos(int iNo, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE newn = new NODE;
        PNODE temp = first;

        newn->data = iNo;
        newn->next = NULL;

        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyCL sobj;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    cout<<"Linked List before deletion:"<<endl;
    sobj.Display();

    cout<<"Count : "<<sobj.Count()<<endl;

    sobj.DeleteFirst();

    cout<<"\nLinked List after DeleteFirst():"<<endl;
    sobj.Display();

    cout<<"Count : "<<sobj.Count()<<endl;

    sobj.DeleteLast();

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

   sobj.InsertAtPos(105,4);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}
/*
===============================================================================
Algorithm:
===============================================================================

1. Check whether the given position is valid.
2. If position is 1, call InsertFirst().
3. If position is iCount + 1, call InsertLast().
4. Otherwise:
      • Create a new node.
      • Traverse to (Position - 1).
      • Connect the new node between two existing nodes.
      • Increment node count.

===============================================================================
Visualization:
===============================================================================

Before Insertion (Insert 105 at Position 4)

First
  │
  ▼
+----+    +----+    +----+    +-----+    +-----+
| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 |
+----+    +----+    +----+    +-----+    +-----+
   ^                                            │
   └────────────────────────────────────────────┘

After Insertion

First
  │
  ▼
+----+    +----+    +----+    +-----+    +-----+    +-----+
| 11 | -> | 21 | -> | 51 | -> | 105 | -> | 101 | -> | 111 |
+----+    +----+    +----+    +-----+    +-----+    +-----+
   ^                                                     │
   └─────────────────────────────────────────────────────┘

===============================================================================
Program Flow:
===============================================================================

Receive Data & Position
          │
          ▼
Validate Position
          │
          ▼
Position = 1 ?
     │Yes            No
     ▼               │
InsertFirst()        ▼
                 Position = Last + 1 ?
                     │Yes          No
                     ▼             ▼
                InsertLast()   Traverse List
                                     │
                                     ▼
                           Insert New Node
                                     │
                                     ▼
                             Increment Count
                                     │
                                     ▼
                                 Return

===============================================================================
Time Complexity:
===============================================================================

Best Case   : O(1)
Worst Case  : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 015 implements insertion at any valid position in a Singly Circular
Linked List. It efficiently handles insertion at the beginning, end, and middle
of the list while preserving the circular nature of the linked list and updating
the node count correctly.

===============================================================================
*/
