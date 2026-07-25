/*
===============================================================================
Program Name    : Doubly Linear Linked List - Display()
Program Number  : 004
File Name       : DoublyLL_04.cpp
Description     : This program demonstrates how to display all the nodes of a
                  Doubly Linear Linked List after inserting nodes at the
                  beginning.

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
6. Constructor

Key Learning Points:
- Traverse a Doubly Linear Linked List.
- Display all node values.
- Understand forward traversal.
- Display nodes from first to last.

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

    cout<<"NULL"<<endl;
}

int DoublyLL::Count()
{
    return iCount;
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

int main()
{
    DoublyLL dobj;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.Display();

    cout<<"Number of nodes are : "<<dobj.Count()<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> NULL

Number of nodes are : 3

===============================================================================
Memory Representation:
===============================================================================

first
 │
 ▼

NULL <- [11] <=> [21] <=> [51] -> NULL

===============================================================================
Algorithm:
===============================================================================

1. Create a temporary pointer.
2. Initialize it to first.
3. Traverse the linked list until NULL.
4. Display each node's data.
5. Move to the next node.
6. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
             │
             ▼
      temp = first
             │
             ▼
      temp != NULL ?
        │          │
      Yes         No
       │           │
       ▼           ▼
 Display Data     Stop
       │
       ▼
temp = temp->next
       │
       └──────────────►

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()      : O(1)

Display()          : O(n)

Count()            : O(1)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates the Display() operation of a Doubly Linear Linked
List. The program traverses the list from the first node to the last node
and displays each element in sequence using forward traversal.

===============================================================================
*/
