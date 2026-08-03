/*
===============================================================================
Program Name    : Stack - Basic Structure
Program Number  : 001
File Name       : Stack_01.c
Description     : This program demonstrates the basic structure of a Stack
                  using C. It defines the node structure, initializes the
                  Stack, and declares function prototypes for Stack
                  operations.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Dynamic Memory Allocation (Preparation)

Key Learning Points:
- Understand the basic structure of a Stack.
- Learn how a Stack is represented using a linked list.
- Declare Stack operations using function prototypes.
- Initialize an empty Stack.

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
typedef struct node * PNODE;
typedef struct node ** PPNODE;

// Function Prototypes

void Push(PPNODE First, int iNo);
int Pop(PPNODE First);
int Peep(PNODE First);
void Display(PNODE First);
int Count(PNODE First);

//=========================================================
// Main
//=========================================================

int main()
{
    PNODE First = NULL;

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

The program only creates an empty Stack and declares
the function prototypes.

===============================================================================
Memory Representation:
===============================================================================

          First
            │
            ▼
          NULL

Stack is Empty

===============================================================================
Algorithm:
===============================================================================

1. Define the node structure.
2. Create pointer typedefs.
3. Declare function prototypes.
4. Initialize the Stack pointer to NULL.
5. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
             │
             ▼
    Define Node Structure
             │
             ▼
   Create Pointer Typedefs
             │
             ▼
 Declare Function Prototypes
             │
             ▼
 Initialize Stack to NULL
             │
             ▼
            Stop

===============================================================================
Time Complexity:
===============================================================================

No Stack operation is performed.

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 introduces the basic structure of a Stack using C.
It defines the node structure, pointer typedefs, and function
prototypes required for implementing Stack operations. This
program serves as the foundation for subsequent Stack programs.

===============================================================================
*/
