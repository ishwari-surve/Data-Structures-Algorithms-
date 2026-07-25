/*
===============================================================================
Program Name    : Doubly Linear Linked List - DeleteFirst()
Program Number  : 007
File Name       : DoublyLL_07.cpp
Description     : This program demonstrates how to delete the first node
                  from a Doubly Linear Linked List using C++.

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
7. Constructor

Key Learning Points:
- Delete the first node of the linked list.
- Handle deletion from an empty linked list.
- Handle deletion when only one node is present.
- Update next and previous pointers correctly.
- Release dynamically allocated memory using delete.

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

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Linked List before DeleteFirst() :

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

Number of nodes are : 6

Linked List after DeleteFirst() :

| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

Number of nodes are : 5

===============================================================================
Memory Representation:
===============================================================================

Before DeleteFirst()

first
 │
 ▼

NULL <- [11] <=> [21] <=> [51] <=> [101] <=> [111] <=> [121] -> NULL

----------------------------------------------------

After DeleteFirst()

first
 │
 ▼

NULL <- [21] <=> [51] <=> [101] <=> [111] <=> [121] -> NULL

The first node is deleted and the previous pointer of the new first node
is updated to NULL.

===============================================================================
Algorithm:
===============================================================================

1. Check whether the linked list is empty.
2. If only one node is present:
      Delete the node.
      Make first NULL.
3. Otherwise:
      Store the first node in a temporary pointer.
      Move first to the next node.
      Make previous pointer of first NULL.
      Delete the old first node.
4. Decrement the node count.
5. Stop.

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
     Return   Single Node?
                  │      │
                Yes      No
                 │        │
                 ▼        ▼
           Delete Node   Move First
                           │
                           ▼
                    Delete Old First
                           │
                           ▼
                  Decrement Count
                           │
                           ▼
                          Stop

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()      : O(1)

InsertLast()       : O(n)

DeleteFirst()      : O(1)

Display()          : O(n)

Count()            : O(n)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 007 demonstrates the DeleteFirst() operation of a Doubly Linear
Linked List. The program deletes the first node, updates the first pointer
and previous pointer correctly, releases the allocated memory using delete,
and maintains the integrity of the linked list.

===============================================================================
*/
