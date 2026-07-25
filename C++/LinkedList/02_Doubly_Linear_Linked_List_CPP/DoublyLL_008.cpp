/*
===============================================================================
Program Name    : Doubly Linear Linked List - DeleteLast()
Program Number  : 008
File Name       : DoublyLL_08.cpp
Description     : This program demonstrates how to delete the last node
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
6. Pointer Traversal
7. Pointer Manipulation
8. Constructor

Key Learning Points:
- Delete the last node of the linked list.
- Handle deletion from an empty linked list.
- Handle deletion when only one node is present.
- Traverse to the last node.
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

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Linked List before DeleteLast() :

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

Number of nodes are : 6

Linked List after DeleteLast() :

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL

Number of nodes are : 5

===============================================================================
Memory Representation:
===============================================================================

Before DeleteLast()

first
 │
 ▼

NULL <- [11] <=> [21] <=> [51] <=> [101] <=> [111] <=> [121] -> NULL

------------------------------------------------------

After DeleteLast()

first
 │
 ▼

NULL <- [11] <=> [21] <=> [51] <=> [101] <=> [111] -> NULL

The last node is deleted and the next pointer of the new last node
is updated to NULL.

===============================================================================
Algorithm:
===============================================================================

1. Check whether the linked list is empty.
2. If only one node is present:
      Delete the node.
      Make first NULL.
3. Otherwise:
      Traverse to the second last node.
      Delete the last node.
      Make next pointer of second last node NULL.
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
            Delete Node  Traverse
                            │
                            ▼
                  Delete Last Node
                            │
                            ▼
               Update Last Node Link
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

DeleteLast()       : O(n)

Display()          : O(n)

Count()            : O(n)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 008 demonstrates the DeleteLast() operation of a Doubly Linear
Linked List. The program traverses to the second last node, deletes the
last node, updates the next pointer correctly, releases the allocated
memory using delete, and maintains the integrity of the linked list.

===============================================================================
*/
