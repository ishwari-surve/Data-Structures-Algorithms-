/*
===============================================================================
Program Name    : Doubly Linear Linked List - Complete Implementation
Program Number  : 010
File Name       : DoublyLL_10.cpp
Description     : This program demonstrates the complete implementation of a
                  Doubly Linear Linked List using C++. It includes insertion,
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
7. Pointer Traversal
8. Position Validation
9. Constructor

Key Learning Points:
- Insert nodes at the beginning, end, and any position.
- Delete nodes from the beginning, end, and any position.
- Display all nodes.
- Count total nodes.
- Maintain correct next and previous links.
- Implement a complete Doubly Linear Linked List.

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

void DoublyLL::DeleteAtPos(int iPos)
{
    PNODE temp = first;
    int i = 0;

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
        for(i = 1; i < iPos - 1; i++)
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

    void DoublyLL::DeleteAtPos(int iPos)
{
    PNODE temp = first;
    int i = 0;

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
        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

Linked List :

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

Number of nodes are : 6

After InsertAtPos()

| 11 | <=> | 21 | <=> | 51 | <=> | 105 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

Number of nodes are : 7

After DeleteFirst()

| 21 | <=> | 51 | <=> | 105 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

Number of nodes are : 6

After DeleteLast()

| 21 | <=> | 51 | <=> | 105 | <=> | 101 | <=> | 111 | <=> NULL

Number of nodes are : 5

After DeleteAtPos()

| 21 | <=> | 51 | <=> | 105 | <=> | 111 | <=> NULL

Number of nodes are : 4

    return 0;
}

===============================================================================
Memory Representation:
===============================================================================

Initial List

NULL <- [11] <=> [21] <=> [51] <=> [101] <=> [111] <=> [121] -> NULL

↓

InsertAtPos(105,4)

NULL <- [11] <=> [21] <=> [51] <=> [105] <=> [101] <=> [111] <=> [121] -> NULL

↓

DeleteFirst()

NULL <- [21] <=> [51] <=> [105] <=> [101] <=> [111] <=> [121] -> NULL

↓

DeleteLast()

NULL <- [21] <=> [51] <=> [105] <=> [101] <=> [111] -> NULL

↓

DeleteAtPos(4)

NULL <- [21] <=> [51] <=> [105] <=> [111] -> NULL

===============================================================================
Algorithm:
===============================================================================

1. Insert nodes at the beginning.
2. Insert nodes at the end.
3. Display the linked list.
4. Count the nodes.
5. Insert a node at the specified position.
6. Delete the first node.
7. Delete the last node.
8. Delete a node from the specified position.
9. Display the updated linked list after each operation.
10. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
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
     InsertAtPos()
             │
             ▼
     DeleteFirst()
             │
             ▼
      DeleteLast()
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

InsertFirst()      : O(1)

InsertLast()       : O(n)

InsertAtPos()      : O(n)

DeleteFirst()      : O(1)

DeleteLast()       : O(n)

DeleteAtPos()      : O(n)

Display()          : O(n)

Count()            : O(n)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 010 demonstrates the complete implementation of a Doubly Linear
Linked List in C++. It integrates all insertion, deletion, display, and
counting operations into a single program while maintaining the correct
forward and backward links between nodes.

===============================================================================
*/
