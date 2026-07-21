/*
===============================================================================
Program Name    : Singly Circular Linked List - Skeleton Program
Program Number  : 002
Description     : This program provides the basic skeleton for implementing a
                  Singly Circular Linked List in C. It defines the node
                  structure, function prototypes, and initializes the head
                  and tail pointers. No linked list operations are implemented
                  in this program.

Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. typedef
4. Function Prototypes
5. Pointer to Pointer
6. Head and Tail Pointers
7. Modular Programming

Key Learning Points:
- A Singly Circular Linked List maintains two pointers:
  • head → Points to the first node.
  • tail → Points to the last node.
- The last node always points back to the first node.
- Function prototypes improve code organization.
- Operations are implemented separately for better modularity.
- This program serves as the base for all future Singly Circular Linked List
  implementations.

===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Display(PNODE first, PNODE last)
{}

int Count(PNODE first, PNODE last)
{
    return 0;
}

void InsertFirst(PPNODE first, PPNODE last, int iNo)
{}

void InsertLast(PPNODE first, PPNODE last, int iNo)
{}

void InsertAtPos(PPNODE first, PPNODE last, int iNo, int iPos)
{}

void DeleteFirst(PPNODE first, PPNODE last)
{}

void DeleteLast(PPNODE first, PPNODE last)
{}

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

This program only demonstrates the basic structure of a Singly Circular
Linked List.

===============================================================================
Memory Representation:
===============================================================================

                  head                     tail
                   │                        │
                   ▼                        ▼
                 NULL                     NULL

No nodes are created in this program.

===============================================================================
Function Overview:
===============================================================================

Display()
└── Displays all nodes of the linked list.

Count()
└── Returns the total number of nodes.

InsertFirst()
└── Inserts a node at the beginning.

InsertLast()
└── Inserts a node at the end.

InsertAtPos()
└── Inserts a node at the specified position.

DeleteFirst()
└── Deletes the first node.

DeleteLast()
└── Deletes the last node.

DeleteAtPos()
└── Deletes a node from the specified position.

===============================================================================
Algorithm:
===============================================================================

1. Define the node structure.
2. Create typedefs for better readability.
3. Declare all linked list function prototypes.
4. Initialize head and tail pointers to NULL.
5. End the program.

===============================================================================
Program Flow:
===============================================================================

Start
   │
   ▼
Define Node Structure
   │
   ▼
Declare Function Prototypes
   │
   ▼
Create Head & Tail Pointers
   │
   ▼
Initialize to NULL
   │
   ▼
Program Ends

===============================================================================
Time Complexity:
===============================================================================

Initialization      : O(1)

Space Complexity    : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 002 introduces the complete framework required for implementing a
Singly Circular Linked List in C. It defines the node structure, function
prototypes, and head and tail pointers while leaving the implementation of
individual operations for subsequent programs. This modular approach improves
code readability, maintainability, and serves as the foundation for all
future linked list operations.

===============================================================================
*/
