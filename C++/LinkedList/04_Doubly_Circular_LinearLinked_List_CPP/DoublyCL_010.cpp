/*
===============================================================================
Program Name    : Doubly Circular Linked List - Complete Implementation
Program Number  : 010
File Name       : DoublyCL_10.cpp
Description     : This program demonstrates the complete implementation of a
                  Doubly Circular Linked List using C++. It includes insertion,
                  deletion, display, counting, and position-based operations.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Dynamic Memory Allocation using new
5. Memory Deallocation using delete
6. Pointer Manipulation
7. Circular Linking
8. Position Validation
9. Constructor

Key Learning Points:
- Insert nodes at the beginning, end, and any position.
- Delete nodes from the beginning, end, and any position.
- Display all nodes.
- Count total nodes.
- Maintain correct next and previous links.
- Implement a complete Doubly Circular Linked List.

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
    if((iPos < 1) || (iPos > iCount))
    {
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

        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
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

    obj.DeleteAtPos(4);

    dobj.Display();

    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>

Number of nodes are : 6

<=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>

Number of nodes are : 5

<=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>

Number of nodes are : 4

<=> | 21 | <=> | 51 | <=> | 101 | <=> | 75 | <=> | 111 | <=>

Number of nodes are : 5

<=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>

Number of nodes are : 4

===============================================================================
Memory Representation:
===============================================================================

                 first
                   │
                   ▼

<=> |21| ⇄ |51| ⇄ |101| ⇄ |111| <=>
 ^                                      │
 |______________________________________|

last->next = first
first->prev = last

===============================================================================
Algorithm:
===============================================================================

1. Create an object of DoublyCL.
2. Insert nodes at the beginning.
3. Insert nodes at the end.
4. Display the linked list.
5. Count the total number of nodes.
6. Delete the first node.
7. Delete the last node.
8. Insert a node at a specified position.
9. Delete a node from a specified position.
10. Display the updated linked list after each operation.
11. Stop.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
      Create DoublyCL Object
               │
               ▼
        InsertFirst()
               │
               ▼
         InsertLast()
               │
               ▼
          Display()
               │
               ▼
           Count()
               │
               ▼
       DeleteFirst()
               │
               ▼
        DeleteLast()
               │
               ▼
       InsertAtPos()
               │
               ▼
       DeleteAtPos()
               │
               ▼
          Display()
               │
               ▼
             Stop

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)

InsertLast() : O(1)

InsertAtPos() : O(n)

DeleteFirst() : O(1)

DeleteLast() : O(1)

DeleteAtPos() : O(n)

Display() : O(n)

Count() : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 010 demonstrates the complete implementation of a Doubly Circular
Linked List in C++. It integrates all insertion, deletion, display, count,
and position-based operations while maintaining the correct forward,
backward, and circular links between nodes. This program serves as the
foundation for the menu-driven implementation in the next program.

===============================================================================
*/
