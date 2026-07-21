/*
===============================================================================
Program Name    : Singly Circular Linked List - DeleteLast Operation
Program Number  : 014
Description     : This program implements the DeleteLast() function for a
                  Singly Circular Linked List. It removes the last node,
                  updates the last pointer, reconnects the circular link,
                  and maintains the node count.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================
Concepts Used:
1. Singly Circular Linked List
2. DeleteLast()
3. Dynamic Memory Deallocation
4. Pointer Traversal
5. Circular Link Maintenance
6. Class and Objects

Key Learning Points:
- Delete the last node of a circular linked list.
- Traverse to the second last node.
- Update the last pointer correctly.
- Maintain the circular link.
- Handle empty and single-node lists.

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
    void DeleteLast();

    void InsertAtPos(int,int){}
    void DeleteAtPos(int){}
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

    cout<<"\n";
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
        first = last = newn;
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
        first = last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }

    last->next = first;

    iCount++;
}

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

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 |

Number of nodes are : 6

| 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 |

Number of nodes are : 5

| 21 | -> | 51 | -> | 101 | -> | 111 |

Number of nodes are : 4

-Before DeleteLast()
===============================================================================
Memory Representation:
===============================================================================

first                                              last
  │                                                  │
  ▼                                                  ▼

+------+ --> +------+ --> +------+ --> +------+ --> +------+ --> +------+
| 21   |     | 51   |     |101   |     |111   |     |121   |     |131   |
+------+     +------+     +------+     +------+     +------+     +------+
    ^                                                                     |
    |_____________________________________________________________________|

DeleteLast()

-After DeleteLast()
first                                   last
  │                                       │
  ▼                                       ▼

+------+ --> +------+ --> +------+ --> +------+
| 21   |     | 51   |     |101   |     |111   |
+------+     +------+     +------+     +------+
    ^                                                   |
    |___________________________________________________|

Deleted Node : 121

===============================================================================
Algorithm:
===============================================================================

DeleteLast()

1. Check whether the list is empty.
2. If only one node is present:
      Delete the node.
      Set first and last to NULL.
3. Otherwise:
      Traverse to the second last node.
      Delete the last node.
      Update last = second last node.
      Update last->next = first.
4. Decrement iCount.

===============================================================================
Program Flow:
===============================================================================

Create List
      │
      ▼
Insert Nodes
      │
      ▼
Display List
      │
      ▼
DeleteFirst()
      │
      ▼
Display List
      │
      ▼
DeleteLast()
      │
      ▼
Traverse to Second Last Node
      │
      ▼
Delete Last Node
      │
      ▼
Update last Pointer
      │
      ▼
Update last->next = first
      │
      ▼
Display Updated List

===============================================================================
Time Complexity:
===============================================================================

DeleteFirst() : O(1)

DeleteLast()  : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 014 extends the Singly Circular Linked List by implementing the
DeleteLast() operation. The list is traversed to locate the second last
node, after which the last node is removed and the circular link is
restored. This program demonstrates proper pointer manipulation while
maintaining the integrity of the circular linked list.

===============================================================================
*/
