/*
===============================================================================
Program Name    : Doubly Linear Linked List - InsertAtPos()
Program Number  : 009
File Name       : DoublyLL_09.cpp
Description     : This program demonstrates how to insert a new node at a
                  specified position in a Doubly Linear Linked List using C++.

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
6. Position Validation
7. Pointer Traversal
8. Constructor

Key Learning Points:
- Insert a node at any valid position.
- Validate the specified position.
- Reuse InsertFirst() and InsertLast().
- Update next and previous pointers correctly.
- Maintain the linear doubly linked structure.

===============================================================================
*/
#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};

typedef class node NODE;
typedef class node *PNODE;

class DoublyLL
{
private:
    PNODE first;
    int iCount;

public:
    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(int);
    void InsertLast(int);
};

DoublyLL::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

void DoublyLL::Display()
{
    PNODE temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

int DoublyLL::Count()
{
    PNODE temp = first;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

void DoublyLL::InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    iCount++;
}

void DoublyLL::InsertLast(int no)
{
    PNODE newn = new NODE;
    PNODE temp = first;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

void DoublyLL::InsertAtPos(int no, int iPos)
{
    int i = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;

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
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(i = 1; i < iPos - 1; i++)
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

void DoublyLL::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        PNODE temp = first;

        first = first->next;
        first->prev = NULL;

        delete temp;
    }

    iCount--;
}

void DoublyLL::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        PNODE temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

int main()
{
    DoublyLL dobj;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();

    cout<<"Number of nodes are : "<<dobj.Count()<<endl;

    dobj.DeleteFirst();

    cout<<"\nLinked List after DeleteFirst() :\n";
    dobj.Display();

    cout<<"Number of nodes are : "<<dobj.Count()<<endl;

     dobj.DeleteLast();

    cout<<"\nLinked List after DeleteLast() :\n";
    dobj.Display();

    cout<<"Number of nodes are : "<<dobj.Count()<<endl;

    dobj.InsertAtPos(105,4);

    cout<<"\nLinked List after InsertAtPos() :\n";
    dobj.Display();

    cout<<"Number of nodes are : "<<dobj.Count()<<endl;

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Linked List before InsertAtPos() :

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

Number of nodes are : 6

Linked List after InsertAtPos() :

| 11 | <=> | 21 | <=> | 51 | <=> | 105 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

Number of nodes are : 7

===============================================================================
Memory Representation:
===============================================================================

Before InsertAtPos()

NULL <- [11] <=> [21] <=> [51] <=> [101] <=> [111] <=> [121] -> NULL

                           │
                           ▼

Insert 105 at Position 4

After InsertAtPos()

NULL <- [11] <=> [21] <=> [51] <=> [105] <=> [101] <=> [111] <=> [121] -> NULL

Only the surrounding node links are updated.

===============================================================================
Algorithm:
===============================================================================

1. Validate the specified position.
2. If position is 1:
      Call InsertFirst().
3. If position is Count()+1:
      Call InsertLast().
4. Otherwise:
      Create a new node.
      Traverse up to (Position-1).
      Update next pointer of new node.
      Update previous pointer of new node.
      Update surrounding node links.
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
               ▼
      Position == 1 ?
         │          │
       Yes         No
        │           │
 InsertFirst()      ▼
             Position == Last+1 ?
                 │           │
               Yes          No
                │            │
         InsertLast()        ▼
                     Traverse List
                           │
                           ▼
                    Insert New Node
                           │
                           ▼
                  Increment Count
                           │
                           ▼
                          Stop

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()      : O(1)

InsertLast()       : O(n)

InsertAtPos()      : O(n)

DeleteFirst()      : O(1)

DeleteLast()       : O(n)

Display()          : O(n)

Count()            : O(n)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 009 demonstrates the InsertAtPos() operation of a Doubly Linear
Linked List. The program validates the specified position, inserts a new
node at the desired location, updates both next and previous pointers
correctly, and maintains the integrity of the linked list.

===============================================================================
*/
