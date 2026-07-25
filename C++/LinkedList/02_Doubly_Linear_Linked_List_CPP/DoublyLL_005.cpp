/*
===============================================================================
Program Name    : Doubly Linear Linked List - Count()
Program Number  : 005
File Name       : DoublyLL_05.cpp
Description     : This program demonstrates how to count the total number of
                  nodes present in a Doubly Linear Linked List by traversing
                  the linked list.

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
6. Counter Variable
7. Constructor

Key Learning Points:
- Traverse a Doubly Linear Linked List.
- Count the total number of nodes.
- Understand how counting is performed manually.
- Return the total node count.

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

Traversal:

temp
 │
 ▼
11 → 21 → 51 → NULL

Count = 3

===============================================================================
Algorithm:
===============================================================================

1. Create a temporary pointer and initialize it to first.
2. Initialize a counter variable to 0.
3. Traverse the linked list until NULL.
4. Increment the counter for every node visited.
5. Return the counter value.

===============================================================================
Program Flow:
===============================================================================

          Start
             │
             ▼
      temp = first
             │
             ▼
     Initialize Count = 0
             │
             ▼
      temp != NULL ?
        │          │
      Yes         No
       │           │
       ▼           ▼
Increment Count   Return Count
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

Count()            : O(n)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 005 demonstrates the Count() operation of a Doubly Linear Linked
List. The program traverses the entire linked list, counts each node, and
returns the total number of nodes present in the list.

===============================================================================
*/
