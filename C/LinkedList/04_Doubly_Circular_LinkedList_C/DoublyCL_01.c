/*
===============================================================================
Program Name    : Doubly Circular Linked List - Node Structure and Memory Size
Program Number  : 001
Description     : This program introduces the basic node structure used in a
                  Doubly Circular Linked List. It demonstrates the creation
                  of a self-referential structure containing data, next, and
                  previous pointers, and displays the memory occupied by a
                  single node using the sizeof operator.

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
7. Doubly Circular Node Representation

Key Learning Points:
- A node contains data, next pointer, and previous pointer.
- next stores the address of the next node.
- prev stores the address of the previous node.
- #pragma pack(1) removes padding bytes.
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
    struct node *prev;
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

int main()
{
    NODE obj;

    printf("Size of node is : %d\n",(int)sizeof(obj));

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Size of node is : 20

(Note: Output may vary depending on the compiler, operating system,
system architecture, and structure packing.)

===============================================================================
Memory Representation:
===============================================================================

Node Structure

+------------+----------------------+----------------------+
| data (4B)  | next pointer (8B)    | prev pointer (8B)    |
+------------+----------------------+----------------------+

Total Size (with #pragma pack(1)) = 20 Bytes

Without #pragma pack(1)

+------------+---------+----------------------+----------------------+
| data (4B)  | Padding | next pointer (8B)    | prev pointer (8B)    |
+------------+---------+----------------------+----------------------+

Total Size = 24 Bytes (Compiler Dependent)

===============================================================================
Pointer Explanation:
===============================================================================

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

data
└── Stores the integer value.

next
└── Stores the address of the next node.

prev
└── Stores the address of the previous node.

typedef Usage

NODE
└── Represents struct node

PNODE
└── Pointer to a node

PPNODE
└── Pointer to pointer to a node

===============================================================================
Algorithm:
===============================================================================

1. Define the node structure.
2. Declare typedefs for easy usage.
3. Create one node object.
4. Calculate memory occupied using sizeof().
5. Display the node size.
6. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
            │
            ▼
  Define Node Structure
            │
            ▼
   Create Node Object
            │
            ▼
 Calculate sizeof(node)
            │
            ▼
 Display Node Size
            │
            ▼
           Stop

===============================================================================
Time Complexity:
===============================================================================

sizeof()             : O(1)

Space Complexity     : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 introduces the basic node structure required for implementing a
Doubly Circular Linked List in C. It demonstrates the use of a self-
referential structure containing data, next, and previous pointers, along
with typedef declarations and the sizeof operator to understand the memory
occupied by a node. This program forms the foundation for all subsequent
Doubly Circular Linked List operations.

===============================================================================
*/
