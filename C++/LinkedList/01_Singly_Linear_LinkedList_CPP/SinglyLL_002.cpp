/*
===============================================================================
Program Name    : Singly Linked List - Dynamic Memory Allocation
Program Number  : 002
Description     : This program demonstrates how to create a node dynamically
                  using the new operator. It initializes the node members,
                  accesses the stored data using the arrow (->) operator, and
                  releases the allocated memory using the delete operator.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Dynamic Memory Allocation
2. Self-Referential Structure
3. Pointer Declaration
4. new Operator
5. delete Operator
6. Arrow (->) Operator
7. Heap Memory Allocation

Key Learning Points:
- new allocates memory dynamically on the heap.
- The arrow operator (->) is used to access node members.
- Data members should be initialized immediately after allocation.
- delete releases dynamically allocated memory.
- Proper memory management prevents memory leaks.

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
typedef struct node **PPNODE;

int main()
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = 11;
    newn->next = NULL;

    cout<<"Data stored in node : "<<newn->data<<endl;

    delete newn;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Data stored in node : 11

===============================================================================
Memory Layout:
===============================================================================

Before Allocation:

newn
 │
 ▼
NULL

After Allocation:

newn
 │
 ▼
+------------+----------------------+
| data = 11  | next = NULL          |
+------------+----------------------+

After delete:

newn
 │
 ▼
(Dynamically allocated memory released)

===============================================================================
Pointer Explanation:
===============================================================================

PNODE newn;

newn
└── Pointer that stores the address of the dynamically allocated node.

new NODE
└── Allocates memory for one node on the heap.

newn->data
└── Stores the value inside the node.

newn->next
└── Stores the address of the next node.
    Currently initialized to NULL.

delete newn
└── Releases the dynamically allocated memory.

===============================================================================
Program Flow:
===============================================================================

Declare Pointer
        │
        ▼
Allocate Memory using new
        │
        ▼
Initialize Node Members
        │
        ▼
Display Stored Data
        │
        ▼
Release Memory using delete
        │
        ▼
Program Ends

===============================================================================
Time Complexity:
===============================================================================

Memory Allocation (new)    : O(1)
Data Access                : O(1)
Memory Deallocation        : O(1)
Space Complexity           : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 002 demonstrates dynamic memory allocation for a Singly Linked List
node using the new operator. The node is initialized, accessed using the
arrow operator, and finally released using delete. Understanding dynamic
memory allocation is essential because linked list nodes are created and
deleted at runtime rather than during compile time.

===============================================================================
*/
