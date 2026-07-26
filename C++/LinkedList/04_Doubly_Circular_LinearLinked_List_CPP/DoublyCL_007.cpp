/*
===============================================================================
Program Name    : Doubly Circular Linked List - DeleteFirst()
Program Number  : 007
File Name       : DoublyCL_07.cpp
Description     : This program demonstrates how to delete the first node from
                  a Doubly Circular Linked List while maintaining the circular
                  and doubly linked properties.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Dynamic Memory Deallocation using delete
5. Pointer Manipulation
6. Circular Linking
7. Constructor

Key Learning Points:
- Delete the first node from the linked list.
- Handle deletion from an empty linked list.
- Handle deletion when only one node exists.
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

        delete first->prev;

        last->next = first;
        first->prev = last;
    }

    iCount--;
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

    dobj.DeleteFirst();

    cout<<"\nAfter DeleteFirst()\n";

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

After DeleteFirst()

<=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>

Number of nodes are : 5

===============================================================================
Memory Representation:
===============================================================================

Before Deletion

    first
     │
     ▼

<=> |11| ⇄ |21| ⇄ |51| ⇄ |101| ⇄ |111| ⇄ |121| <=>
 ^                                                    │
 |____________________________________________________|

↓

DeleteFirst()

↓

    first
     │
     ▼

<=> |21| ⇄ |51| ⇄ |101| ⇄ |111| ⇄ |121| <=>
 ^                                             │
 |_____________________________________________|

last->next = first
first->prev = last

===============================================================================
Algorithm:
===============================================================================

1. Check whether the linked list is empty.
2. If empty, return.
3. If only one node exists:
      Delete the node.
      Make first and last NULL.
4. Otherwise:
      Move first to the second node.
      Delete the old first node.
      Update last->next.
      Update first->prev.
5. Decrement the node count.
6. Stop.

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
     Return   One Node?
                 │
            Yes      No
             │        │
             ▼        ▼
 Delete Node     Move first
 first=NULL      Delete old first
 last=NULL       Update Links
                 │
                 ▼
          Decrement Count
                 │
                 ▼
                Stop

===============================================================================
Time Complexity:
===============================================================================

DeleteFirst() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 007 demonstrates the DeleteFirst() operation of a Doubly Circular
Linked List. It deletes the first node while maintaining the correct forward
and backward circular links between the remaining nodes.

===============================================================================
*/
