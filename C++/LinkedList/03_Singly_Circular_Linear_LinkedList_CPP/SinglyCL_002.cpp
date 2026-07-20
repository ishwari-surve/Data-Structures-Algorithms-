/*
===============================================================================
Program Name    : Singly Circular Linked List - Creation of Two Nodes
Program Number  : 002
Description     : This program demonstrates how to create two nodes dynamically
                  in C++. It allocates memory using the new operator, stores
                  data in each node, and connects them to form the initial
                  circular linked list.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Dynamic Memory Allocation
2. Self-Referential Structure
3. Pointers
4. new Operator
5. Circular Node Linking
6. Pointer Assignment

Key Learning Points:
- Nodes can be created dynamically using the new operator.
- Each node stores data and the address of the next node.
- The last node points back to the first node.
- Circular linking eliminates the NULL pointer at the end.
- This is the simplest form of a Singly Circular Linked List.

===============================================================================
*/

#include<iostream>
using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

int main()
{
    PNODE first = NULL;
    PNODE second = NULL;

    first = new NODE;
    second = new NODE;

    first->data = 11;
    second->data = 21;

    first->next = second;
    second->next = first;

    cout<<"First Node Data  : "<<first->data<<endl;
    cout<<"Second Node Data : "<<second->data<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

First Node Data  : 11
Second Node Data : 21

===============================================================================
Memory Representation:
===============================================================================

                 first
                   │
                   ▼
        +-----------+-----------+
        |   11      |     •-----|------------------+
        +-----------+-----------+                  |
                                                   |
                                                   ▼
                                          +-----------+-----------+
                                          |   21      |     •-----|
                                          +-----------+-----------+
                                                   ▲
                                                   |
                                                   +----------------+

Both nodes form a circular chain.

===============================================================================
Pointer Explanation:
===============================================================================

first
└── Stores the address of the first node.

second
└── Stores the address of the second node.

first->next
└── Points to the second node.

second->next
└── Points back to the first node, completing the circle.

===============================================================================
Program Flow:
===============================================================================

Create First Node
        │
        ▼
Create Second Node
        │
        ▼
Store Data
        │
        ▼
Connect First → Second
        │
        ▼
Connect Second → First
        │
        ▼
Display Node Data

===============================================================================
Time Complexity:
===============================================================================

Node Creation      : O(1)
Node Linking       : O(1)
Display Data       : O(1)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 002 demonstrates the creation of two dynamically allocated nodes and
their circular connection. Unlike a Singly Linear Linked List, the last node
does not point to NULL; instead, it points back to the first node, forming a
closed circular structure. This is the first practical implementation of a
Singly Circular Linked List.

===============================================================================
*/
