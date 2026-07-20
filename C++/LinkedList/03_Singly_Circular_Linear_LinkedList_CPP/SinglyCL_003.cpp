/*
===============================================================================
Program Name    : Singly Circular Linked List - Creation of Three Nodes
Program Number  : 003
Description     : This program demonstrates the creation of three nodes using
                  dynamic memory allocation. The nodes are connected in a
                  circular manner where the last node points back to the
                  first node, forming a Singly Circular Linked List.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Dynamic Memory Allocation
2. Self-Referential Structure
3. Pointer Variables
4. Circular Node Linking
5. Node Traversal
6. new Operator

Key Learning Points:
- Creating multiple nodes dynamically.
- Connecting nodes in a circular fashion.
- Understanding the role of the last node.
- Difference between linear and circular linked lists.
- Accessing node data using pointers.

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
    PNODE third = NULL;

    first = new NODE;
    second = new NODE;
    third = new NODE;

    first->data = 11;
    second->data = 21;
    third->data = 51;

    first->next = second;
    second->next = third;
    third->next = first;

    cout<<"First Node  : "<<first->data<<endl;
    cout<<"Second Node : "<<second->data<<endl;
    cout<<"Third Node  : "<<third->data<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

First Node  : 11
Second Node : 21
Third Node  : 51

===============================================================================
Memory Representation:
===============================================================================

               first
                 │
                 ▼
      +---------+---------+      +---------+---------+
      |   11    |    •---------->|   21    |    •----------+
      +---------+---------+      +---------+---------+      |
                                                            |
                                                            ▼
                                                   +---------+---------+
                                                   |   51    |    •----+
                                                   +---------+---------+
                                                            │
                                                            │
                                                            └──────────────► first

Circular Connection:
first → second → third → first

===============================================================================
Pointer Explanation:
===============================================================================

first
└── Points to the first node.

second
└── Points to the second node.

third
└── Points to the third node.

third->next
└── Stores the address of the first node, making the list circular.

===============================================================================
Program Flow:
===============================================================================

Create First Node
        │
        ▼
Create Second Node
        │
        ▼
Create Third Node
        │
        ▼
Store Data
        │
        ▼
Connect First → Second
        │
        ▼
Connect Second → Third
        │
        ▼
Connect Third → First
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

Program 003 demonstrates how three nodes are dynamically created and linked
together to form a Singly Circular Linked List. The last node points back to
the first node instead of NULL, creating a continuous circular structure that
serves as the basis for traversal and insertion/deletion operations.

===============================================================================
*/
