/*
================================================================================
Program Name    : Singly Linked List - Setup for Function Implementation
Program Number  : 018 
Description     : This program provides the basic setup required for
                  implementing singly linked list functions. It defines
                  the node structure, typedef aliases, and initializes
                  the HEAD pointer to represent an empty linked list.
                  This serves as the foundation for implementing
                  individual linked list operations.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. typedef (NODE)
4. typedef (PNODE)
5. typedef (PPNODE)
6. HEAD Pointer
7. NULL Initialization
8. Basic Linked List Setup

Key Learning Points:
- Basic structure setup for linked list implementation
- Proper typedef definitions for clean code
- HEAD pointer initialized to NULL (empty list)
- Foundation for implementing linked list operations incrementally.
- Clean starting point for incremental development
================================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;              // 4 bytes - stores the value
    struct node *next;     // 8 bytes - pointer to next node
};

typedef struct node NODE;        // NODE is alias for struct node
typedef struct node* PNODE;      // PNODE is alias for pointer to NODE
typedef struct node** PPNODE;    // PPNODE is alias for pointer to pointer to NODE

int main()
{
    PNODE head = NULL;           // HEAD pointer - entry point to linked list

    return 0;
}

/*
================================================================================
Expected Output:
================================================================================
(No output - Setup program only)

================================================================================
Memory Diagram:
================================================================================

Stack:
┌─────────────────────────────┐
│ head (PNODE)                │
│ Value: NULL (0)             │
│ Represents: Empty list      │
└─────────────────────────────┘

Visual:
head → NULL (Empty list)

================================================================================
Pointer/Logic Explanation:
================================================================================

Structure Setup:
struct node contains:
- data (int): stores value
- next (struct node *): points to next node

Typedefs:
NODE:  struct node (the structure itself)
PNODE: struct node* (pointer to structure)
PPNODE: struct node** (pointer to pointer)

Initialization:
head = NULL indicates that the linked list is empty.
Since HEAD does not point to any node, insertion
functions will create the first node and update HEAD.

This setup prepares for function implementation:
- Structure is defined and ready
- Typedefs are established
- HEAD pointer is initialized
- Ready to add functions one by one

================================================================================
Time Complexity:
================================================================================
Initialization                 : O(1) - Only set pointer to NULL
Space Complexity               : O(1) - Single pointer on stack

================================================================================
Conclusion:
================================================================================

Program 018 establishes the basic framework required for implementing
a singly linked list. It defines the node structure, creates typedef
aliases (NODE, PNODE, and PPNODE), and initializes the HEAD pointer
to NULL, representing an empty list. This setup serves as the starting
point for implementing linked list operations such as insertion,
deletion, traversal, and counting.

================================================================================
*/
