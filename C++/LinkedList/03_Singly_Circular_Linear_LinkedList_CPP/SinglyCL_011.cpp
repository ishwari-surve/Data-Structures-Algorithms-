/*
===============================================================================
Program Name    : Singly Circular Linked List - Display Function
Program Number  : 011
Description     : This program implements the Display() function for a Singly
                  Circular Linked List. It traverses the list from the first
                  node and displays all elements until it reaches the first 
                  node again.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Singly Circular Linked List
2. do-while Loop
3. Pointer Traversal
4. Display Operation
5. Circular Traversal

Key Learning Points:
- Traversing a circular linked list.
- Using do-while for circular traversal.
- Displaying all node elements.
- Stopping traversal after reaching the first node.
- Difference between linear and circular traversal.

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

int SinglyCL::Count()
{
    return iCount;
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

    sobj.Display();

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->

===============================================================================
Memory Representation:
===============================================================================

first                                            last
  │                                                │
  ▼                                                ▼

+------+ --> +------+ --> +------+ --> +------+ --> +------+ --> +------+
| 11   |     | 21   |     | 51   |     |101   |     |111   |     |121   |
+------+     +------+     +------+     +------+     +------+     +------+
    ^                                                                   |
    |___________________________________________________________________|

Display Traversal:

first
  │
  ▼
11 → 21 → 51 → 101 → 111 → 121
↑                              │
└──────────────────────────────┘

===============================================================================
Program Flow:
===============================================================================

Start from first
        │
        ▼
Display current node
        │
        ▼
Move to next node
        │
        ▼
Reached first again?
        │
   No ──┴── Yes
    │          │
    ▼          ▼
Repeat       Stop

===============================================================================
Time Complexity:
===============================================================================

Display()            : O(n)

Space Complexity     : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 011 demonstrates the Display() operation of a Singly Circular Linked
List. The do-while loop ensures that every node is visited exactly once before
the traversal stops when it reaches the first node again.

===============================================================================
*/
