/*
===============================================================================
Program Name    : Doubly Circular Linked List - InsertAtPos()
Program Number  : 009
File Name       : DoublyCL_09.cpp
Description     : This program demonstrates how to insert a new node at a
                  specified position in a Doubly Circular Linked List while
                  maintaining the circular and doubly linked properties.

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
7. Position Validation
8. Constructor

Key Learning Points:
- Insert a node at any valid position.
- Validate the position before insertion.
- Reuse InsertFirst() and InsertLast() functions.
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

void DoublyCL::InsertAtPos(int no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;
        PNODE temp = first;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
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
        last = last->prev;

        delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
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

    dobj.InsertAtPos(75,4);

    cout<<"\nAfter InsertAtPos()\n";

    dobj.Display();

    cout<<"Number of nodes are : "<<dobj.Count()<<endl;

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>

Number of nodes are : 5

After InsertAtPos()

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 75 | <=> | 101 | <=> | 111 | <=>

Number of nodes are : 6

===============================================================================
Memory Representation:
===============================================================================

Before Insertion

                 first
                   │
                   ▼

<=> |11| ⇄ |21| ⇄ |51| ⇄ |101| ⇄ |111| <=>
 ^                                          │
 |__________________________________________|

↓

Insert 75 at Position 4

↓

                          first
                           │
                           ▼

<=> |11| ⇄ |21| ⇄ |51| ⇄ |75| ⇄ |101| ⇄ |111| <=>
 ^                                                    │
 |____________________________________________________|

last->next = first
first->prev = last

===============================================================================
Algorithm:
===============================================================================

1. Validate the given position.
2. If position is 1, call InsertFirst().
3. If position is last + 1, call InsertLast().
4. Otherwise:
      Create a new node.
      Traverse up to the previous node of the given position.
      Update next pointers.
      Update previous pointers.
5. Increment the node count.
6. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
             │
             ▼
     Validate Position
             │
     ┌───────┼────────┐
     ▼       ▼        ▼
Position=1  Last+1   Middle
     │       │        │
     ▼       ▼        ▼
InsertFirst InsertLast Create Node
                      │
                      ▼
              Traverse List
                      │
                      ▼
             Update Links
                      │
                      ▼
            Increment Count
                      │
                      ▼
                     Stop

===============================================================================
Time Complexity:
===============================================================================

InsertAtPos() : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 009 demonstrates the InsertAtPos() operation of a Doubly Circular
Linked List. It inserts a new node at the specified valid position while
maintaining the correct forward, backward, and circular links between nodes.

===============================================================================
*/
