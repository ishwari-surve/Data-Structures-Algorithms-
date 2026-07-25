/*
===============================================================================
Program Name    : Doubly Linear Linked List - InsertFirst()
Program Number  : 003
File Name       : DoublyLL_03.cpp
Description     : This program demonstrates how to insert a new node at the
                  beginning of a Doubly Linear Linked List using C++.

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
6. Constructor

Key Learning Points:
- Insert a node at the beginning of the linked list.
- Handle insertion into an empty linked list.
- Update next and previous pointers correctly.
- Increase the node count after successful insertion.

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

    cout<<"Nodes inserted successfully."<<endl;
    cout<<"Number of nodes are : "<<dobj.Count()<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Nodes inserted successfully.
Number of nodes are : 3

===============================================================================
Memory Representation:
===============================================================================

After InsertFirst(51)

NULL <- [51] -> NULL

-----------------------------------------

After InsertFirst(21)

NULL <- [21] <=> [51] -> NULL

-----------------------------------------

After InsertFirst(11)

NULL <- [11] <=> [21] <=> [51] -> NULL

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Store the given data in the node.
3. If the list is empty:
      Make the new node the first node.
4. Otherwise:
      Link the new node before the current first node.
      Update previous pointer of the old first node.
      Update first pointer.
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
      │        │
     Yes      No
      │        │
      ▼        ▼
 first=newn   Link Before First
      │        │
      └────┬───┘
           ▼
     Increment Count
           │
           ▼
          Stop

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()      : O(1)

Count()            : O(1)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 003 demonstrates the InsertFirst() operation of a Doubly Linear
Linked List. The program inserts a new node at the beginning of the list,
updates both next and previous pointers correctly, and maintains the total
number of nodes.

===============================================================================
*/
