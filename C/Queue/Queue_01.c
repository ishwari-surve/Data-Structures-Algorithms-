/*
===============================================================================
Program Name    : Queue Using Singly Linear Linked List - Node Structure
Program Number  : 001
File Name       : Queue_01.c

Description     : This program demonstrates the basic node structure
                  required to implement a Queue using a Singly Linear
                  Linked List in C. It defines the node structure,
                  pointer typedefs, and initializes the queue.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Typedef

Key Learning Points:
- Define a queue node.
- Create pointer typedefs.
- Initialize an empty queue.
- Understand node representation.

===============================================================================
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

int main()
{
    PNODE head = NULL;

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

The Queue has been initialized successfully.

===============================================================================
Memory Representation:
===============================================================================

Initially

Head
 │
 ▼
NULL

Queue is Empty

===============================================================================
Algorithm:
===============================================================================

1. Define a self-referential node structure.
2. Create typedefs for the node and pointers.
3. Initialize the Head pointer to NULL.
4. Terminate the program.

===============================================================================
Program Flow:
===============================================================================

        Start
           │
           ▼
 Create Node Structure
           │
           ▼
Create Pointer Typedefs
           │
           ▼
Initialize Head = NULL
           │
           ▼
          Stop

===============================================================================
Time Complexity:
===============================================================================

Initialization : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 demonstrates the basic node structure required for
implementing a Queue using a Singly Linear Linked List in C. It forms
the foundation for implementing queue operations in subsequent programs.

===============================================================================
*/
