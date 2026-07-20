/*
===============================================================================
Program Name    : Singly Circular Linked List - Traversal using do-while Loop
Program Number  : 006
Description     : This program demonstrates how to traverse a Singly Circular
                  Linked List using a do-while loop. Since the last node points
                  back to the first node, traversal continues until the first
                  node is encountered again.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Singly Circular Linked List
2. Self-Referential Structure
3. Dynamic Memory Allocation
4. do-while Loop
5. Pointer Traversal
6. Temporary Pointer

Key Learning Points:
- do-while loop is ideal for traversing circular linked lists.
- Traversal starts from the first node.
- The loop terminates when the traversal reaches the first node again.
- Every node is visited exactly once.

===============================================================================
*/

#include<iostream>
using namespace std;

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
    PNODE temp = NULL;

    // Allocate memory
    first = new NODE;
    second = new NODE;
    third = new NODE;

    // Store data
    first->data = 11;
    second->data = 21;
    third->data = 51;

    // Connect nodes
    first->next = second;
    second->next = third;
    third->next = first;

    temp = first;

    cout<<"Elements of Singly Circular Linked List : "<<endl;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    while(temp != first);

    cout<<"FIRST"<<endl;

    delete first;
    delete second;
    delete third;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Elements of Singly Circular Linked List :

| 11 | -> | 21 | -> | 51 | -> FIRST

===============================================================================
Memory Representation:
===============================================================================

                 first,temp
                      │
                      ▼
      +-----------+     +-----------+     +-----------+
      |    11     | --> |    21     | --> |    51     |
      +-----------+     +-----------+     +-----------+
            ▲                                     │
            └─────────────────────────────────────┘

Traversal:

11 → 21 → 51 → FIRST

===============================================================================
Pointer Explanation:
===============================================================================

first
└── Stores the address of the first node.

temp
└── Used to traverse the linked list.

temp = temp->next
└── Moves the traversal to the next node.

Loop Condition:

while(temp != first)

The loop stops when temp reaches the first node again.

===============================================================================
Program Flow:
===============================================================================

Create Three Nodes
        │
        ▼
Connect Nodes Circularly
        │
        ▼
Assign temp = first
        │
        ▼
Display Current Node
        │
        ▼
Move temp to Next Node
        │
        ▼
Repeat Until temp == first
        │
        ▼
Traversal Complete

===============================================================================
Time Complexity:
===============================================================================

Traversal         : O(n)

Space Complexity  : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates the standard method of traversing a Singly Circular
Linked List using a do-while loop. Unlike a linear linked list, traversal
continues until the temporary pointer returns to the first node, ensuring that
every node is visited exactly once.

===============================================================================
*/
