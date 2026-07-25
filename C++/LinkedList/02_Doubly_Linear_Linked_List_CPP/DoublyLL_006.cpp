/*
===============================================================================
Program Name    : Doubly Linear Linked List - InsertLast()
Program Number  : 006
File Name       : DoublyLL_06.cpp
Description     : This program demonstrates how to insert a new node at the
                  end of a Doubly Linear Linked List using C++.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Dynamic Memory Allocation using new
5. Pointer Traversal
6. Pointer Manipulation
7. Constructor

Key Learning Points:
- Insert a node at the end of the linked list.
- Handle insertion into an empty linked list.
- Traverse to the last node.
- Update next and previous pointers correctly.

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

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

Number of nodes are : 6

===============================================================================
Memory Representation:
===============================================================================

Before InsertLast()

NULL <- [11] <=> [21] <=> [51] -> NULL

InsertLast(101)

NULL <- [11] <=> [21] <=> [51] <=> [101] -> NULL

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Store the given data.
3. If the linked list is empty:
      Make the new node the first node.
4. Otherwise:
      Traverse to the last node.
      Link the new node after the last node.
      Update the previous pointer.
5. Increment the node count.
6. Stop.

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
        │         │
      Yes        No
       │          │
       ▼          ▼
 first=newn   Traverse to Last
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

Display()          : O(n)

Count()            : O(n)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates the InsertLast() operation of a Doubly Linear
Linked List. The program traverses the linked list to the last node,
inserts a new node at the end, updates the next and previous pointers,
and maintains the linked list correctly.

===============================================================================
*/
