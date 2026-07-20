/*
===============================================================================
Program Name    : Singly Circular Linked List - Creation of Circular Linked List
Program Number  : 004
Description     : This program demonstrates the creation of a Singly Circular
                  Linked List using three dynamically allocated nodes. The
                  last node is connected back to the first node, forming a
                  circular linked list. It also displays the data stored in
                  each node along with the addresses stored in their next
                  pointers.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Dynamic Memory Allocation
2. Self-Referential Structure
3. Pointer Declaration
4. Circular Node Linking
5. Pointer Traversal
6. Address Representation

Key Learning Points:
- Three nodes are created dynamically using the new operator.
- The last node points back to the first node.
- A Singly Circular Linked List has no NULL at the end.
- Each next pointer stores the address of the next node.
- Pointer addresses help visualize the circular connection.

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
    PNODE first = new NODE;
    PNODE second = new NODE;
    PNODE third = new NODE;

    first->data = 11;
    first->next = second;

    second->data = 21;
    second->next = third;

    third->data = 51;
    third->next = first;

    cout<<"Data stored in the nodes:\n"<<endl;

    cout<<first->data<<endl;
    cout<<second->data<<endl;
    cout<<third->data<<endl;

    cout<<"\nAddresses stored in next pointers:\n"<<endl;

    cout<<first->next<<endl;
    cout<<second->next<<endl;
    cout<<third->next<<endl;

    delete first;
    delete second;
    delete third;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Data stored in the nodes:

11
21
51

Addresses stored in next pointers:

0x61ff10
0x61ff20
0x61ff00

(Note: Memory addresses will vary for every execution.)

===============================================================================
Memory Representation:
===============================================================================

                      first
                        │
                        ▼
          +------------+------------+
          | data = 11  | next ------|--------------------+
          +------------+------------+                    |
                                                        |
                                                        ▼
                              +------------+------------+
                              | data = 21  | next ------|--------------+
                              +------------+------------+              |
                                                                       |
                                                                       ▼
                                                   +------------+------------+
                                                   | data = 51  | next ------|
                                                   +------------+------------+
                                                            │
                                                            │
                                                            └──────────────► first

Circular Link:

first → second → third
  ▲                    │
  └────────────────────┘

===============================================================================
Pointer Explanation:
===============================================================================

first
└── Stores the address of the first node.

second
└── Stores the address of the second node.

third
└── Stores the address of the third node.

first->next
└── Points to second.

second->next
└── Points to third.

third->next
└── Points back to first, creating the circular link.

===============================================================================
Program Flow:
===============================================================================

Create Three Nodes
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
        │
        ▼
Display Pointer Addresses
        │
        ▼
Delete Nodes
        │
        ▼
Program Ends

===============================================================================
Time Complexity:
===============================================================================

Node Creation       : O(1)
Display Data        : O(1)
Display Addresses   : O(1)

Space Complexity    : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates how three dynamically allocated nodes are connected
to form a Singly Circular Linked List. Unlike a Singly Linear Linked List,
the last node does not point to NULL; instead, it points back to the first
node, creating a circular structure. Displaying the addresses stored in the
next pointers helps visualize how the circular connection is established.

===============================================================================
*/
