/*
===============================================================================
Program Name    : Singly Circular Linked List - DeleteAtPos() Operation
Program Number  : 016
Description     : This program implements the DeleteAtPos() function in a
                  Singly Circular Linked List. It deletes a node from any
                  valid position while maintaining the circular structure of
                  the linked list.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class and Objects
2. Self-Referential Structure
3. Dynamic Memory Allocation
4. Pointer Traversal
5. Position Validation
6. DeleteFirst()
7. DeleteLast()
8. Pointer Manipulation
9. Circular Linked List

Key Learning Points:
- Validate the position before deletion.
- Reuse DeleteFirst() and DeleteLast() whenever possible.
- Traverse the list until the previous node of the node to be deleted.
- Delete the target node safely.
- Maintain the circular link after deletion.
- Update the node count correctly.

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

void SinglyCL::InsertAtPos(int iNo,int iPos)
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

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
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

///////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////

void SinglyCL::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = first;
        PNODE target = NULL;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;

        delete target;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyCL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj.DeleteFirst();

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj.DeleteLast();

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj.InsertAtPos(105,4);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj.DeleteAtPos(4);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}


/*
===============================================================================
Expected Output:
===============================================================================

Linked List :

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->

Number of nodes are : 6

Deleting node at Position 4...

Linked List after deletion :

| 11 | -> | 21 | -> | 51 | -> | 111 | -> | 121 | ->

Number of nodes are : 5

===============================================================================
Algorithm:
===============================================================================

1. Validate the given position.
2. If position is 1, call DeleteFirst().
3. If position is last position, call DeleteLast().
4. Otherwise,
      • Traverse to (Position - 1).
      • Store node to be deleted.
      • Update links.
      • Delete target node.
      • Decrement node count.

===============================================================================
Visualization:
===============================================================================

Before Deletion (Delete Position 4)

First
 │
 ▼
+----+    +----+    +----+    +-----+    +-----+    +-----+
| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 |
+----+    +----+    +----+    +-----+    +-----+    +-----+
  ^                                                       │
  └───────────────────────────────────────────────────────┘

After Deletion

First
 │
 ▼
+----+    +----+    +----+    +-----+    +-----+
| 11 | -> | 21 | -> | 51 | -> | 111 | -> | 121 |
+----+    +----+    +----+    +-----+    +-----+
  ^                                             │
  └─────────────────────────────────────────────┘

===============================================================================
Program Flow:
===============================================================================

Receive Position
       │
       ▼
Validate Position
       │
       ▼
Position = 1 ?
   │Yes      No
   ▼         │
DeleteFirst()│
             ▼
Position = Last ?
     │Yes        No
     ▼           ▼
DeleteLast()  Traverse List
                    │
                    ▼
           Locate Previous Node
                    │
                    ▼
            Delete Target Node
                    │
                    ▼
            Decrement Node Count
                    │
                    ▼
                 Return

===============================================================================
Time Complexity:
===============================================================================

Best Case  : O(1)
Worst Case : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 016 demonstrates deletion of a node from any valid position in a
Singly Circular Linked List. It efficiently handles deletion from the
beginning, end, and middle of the list while preserving the circular
structure and maintaining an accurate node count.

===============================================================================
*/
