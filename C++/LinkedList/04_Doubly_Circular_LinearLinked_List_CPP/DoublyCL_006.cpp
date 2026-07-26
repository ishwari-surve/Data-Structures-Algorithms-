/*
===============================================================================
Program Name    : Doubly Circular Linked List - InsertLast()
Program Number  : 006
File Name       : DoublyCL_06.cpp
Description     : This program demonstrates how to insert a new node at the
                  end of a Doubly Circular Linked List while maintaining the
                  circular and doubly linked properties.

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
- Insert a node at the end of the linked list.
- Handle insertion into an empty linked list.
- Maintain next and prev links.
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
        last->next = newn;
        newn->prev = last;
        last = newn;
    }

    last->next = first;
    first->prev = last;

    iCount++;
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

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();

    cout<<"Number of nodes are : "<<dobj.Count()<<endl;

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>

Number of nodes are : 6

===============================================================================
Memory Representation:
===============================================================================

                 first
                   │
                   ▼

<=> |11| ⇄ |21| ⇄ |51| ⇄ |101| ⇄ |111| ⇄ |121| <=>
 ^                                                    │
 |____________________________________________________|

last->next = first
first->prev = last

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Store the given data in the node.
3. If the linked list is empty:
      Make first and last point to the new node.
4. Otherwise:
      Link the new node after the last node.
      Update the last pointer.
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
 first=last     Insert After Last
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

InsertLast() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates the InsertLast() operation of a Doubly Circular
Linked List. It inserts a new node at the end while correctly maintaining
both forward and backward circular links between the first and last nodes.

===============================================================================
*/
