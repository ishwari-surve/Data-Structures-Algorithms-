/*
=============================================================================== 
Program Name    : Singly Circular Linked List - Count Function
Program Number  : 012
Description     : This program implements the Count() function for a Singly
                  Circular Linked List. It returns the total number of nodes
                  currently present in the list using the iCount data member.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Singly Circular Linked List
2. Count Function
3. Class Data Members
4. Node Counter
5. Display Operation

Key Learning Points:
- Maintaining the node count.
- Returning the total number of nodes.
- Using iCount instead of traversing the list.
- Efficient counting operation.
- Displaying the total nodes.

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
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->

Number of nodes are : 6

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

iCount = 6

===============================================================================
Program Flow:
===============================================================================

Insert Nodes
      │
      ▼
Increment iCount
      │
      ▼
Display List
      │
      ▼
Call Count()
      │
      ▼
Return iCount
      │
      ▼
Display Total Nodes

===============================================================================
Time Complexity:
===============================================================================

Count()              : O(1)

Space Complexity     : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 012 implements the Count() function for a Singly Circular Linked List.
The node count is maintained during insertion operations using the iCount data
member, allowing Count() to return the total number of nodes in constant time
without traversing the linked list.

===============================================================================
*/
