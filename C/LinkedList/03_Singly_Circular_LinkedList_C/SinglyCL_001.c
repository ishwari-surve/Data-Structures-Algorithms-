/*
===============================================================================
Program Name    : Singly Circular Linked List - Node Structure and Memory Size
Program Number  : 001
Description     : This program introduces the basic node structure used in a
                  Singly Circular Linked List. It demonstrates how a
                  self-referential structure is created and displays the
                  memory occupied by a single node using the sizeof operator.

Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer Declaration
4. typedef
5. sizeof Operator
6. Structure Packing using #pragma pack(1)
7. Circular Linked List Node

Key Learning Points:
- A node contains data and a pointer to the next node.
- In a Singly Circular Linked List, the last node points back to the first node.
- #pragma pack(1) removes padding bytes from the structure.
- sizeof() returns the total memory occupied by a node.
- typedef improves code readability.

===============================================================================
*/

#include<stdio.h>

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
    NODE obj;

    printf("Size of node is : %d\n",sizeof(obj));

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Size of node is : 12

(Note: Output may vary depending on compiler, system architecture,
and structure packing.)

===============================================================================
Memory Layout:
===============================================================================

                +------------+----------------------+
Node ---------> | data (4B)  | next pointer (8B)    |
                +------------+----------------------+

Total Size (with #pragma pack(1)) = 12 Bytes

Without #pragma pack(1):

                +------------+---------+----------------------+
Node ---------> | data (4B)  | Padding | next pointer (8B)    |
                +------------+---------+----------------------+

Total Size = 16 Bytes (Compiler Dependent)

===============================================================================
Pointer Explanation:
===============================================================================

struct node
{
    int data;
    struct node *next;
};

data
└── Stores the integer value.

next
└── Stores the address of the next node.

In a Singly Circular Linked List, the last node's next pointer stores the
address of the first node instead of NULL.

typedef Usage:

NODE
└── Represents struct node

PNODE
└── Pointer to a node

PPNODE
└── Pointer to pointer to a node

===============================================================================
Program Flow:
===============================================================================

Create Node Object
        │
        ▼
Calculate sizeof(node)
        │
        ▼
Display Node Size
        │
        ▼
Program Ends

===============================================================================
Time Complexity:
===============================================================================

sizeof()          : O(1)

Space Complexity  : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 introduces the basic node structure required for implementing a
Singly Circular Linked List in C. It explains the concept of a
self-referential structure, pointer declarations, typedef, and memory
allocation using the sizeof operator. This program serves as the foundation
for all subsequent Singly Circular Linked List operations.

===============================================================================
*/
