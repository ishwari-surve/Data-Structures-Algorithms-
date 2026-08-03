/*
===============================================================================
Program Name    : Stack - Display Operation
Program Number  : 004
File Name       : Stack_04.c
Description     : This program demonstrates the Display() operation of a
                  Stack using C. The Display operation traverses the Stack
                  from Top to Bottom and displays all the elements currently
                  present in the Stack without modifying its contents.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Linked List Traversal
5. Stack (LIFO)

Key Learning Points:
- Traverse the Stack from Top to Bottom.
- Display all Stack elements.
- Understand Stack traversal using pointers.
- Observe the LIFO ordering of elements.

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

//=========================================================
// Function Prototypes
//=========================================================

void Push(PPNODE First, int iNo);
int Pop(PPNODE First);
int Peep(PNODE First);
void Display(PNODE First);
int Count(PNODE First);

//=========================================================
// Push
//=========================================================

void Push(PPNODE First, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = *First;

    *First = newn;
}
//=========================================================
// Pop
//=========================================================

int Pop(PPNODE First)
{
    return 0;
}

//=========================================================
// Peep
//=========================================================

int Peep(PNODE First)
{
    return 0;
}

//=========================================================
// Display
//=========================================================

void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("| %d |\n", First->data);
        First = First->next;
    }

    printf("NULL\n");
}

//=========================================================
// Count
//=========================================================

int Count(PNODE First)
{
    return 0;
}

//=========================================================
// Main
//=========================================================

int main()
{
    PNODE First = NULL;

    Push(&First,11);
    Push(&First,21);
    Push(&First,51);
    Push(&First,101);

    printf("Elements of Stack are :\n\n");
    Display(First);

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Elements of Stack are :

| 101 |
| 51 |
| 21 |
| 11 |
NULL

===============================================================================
Memory Representation:
===============================================================================

                TOP
                 │
                 ▼
            +--------+
            | 101 | •──┐
            +--------+ │
                       ▼
            +--------+
            |  51 | •──┐
            +--------+ │
                       ▼
            +--------+
            |  21 | •──┐
            +--------+ │
                       ▼
            +--------+
            |  11 | ───► NULL
            +--------+

===============================================================================
Algorithm:
===============================================================================

1. Initialize a pointer to the top of the Stack.
2. Traverse the Stack until NULL is reached.
3. Display the data of each node.
4. Move to the next node.
5. Display NULL.
6. Stop.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
        Initialize Pointer
               │
               ▼
      Pointer != NULL ?
        │             │
      Yes            No
       │              │
       ▼              ▼
   Display Data     Print NULL
       │              │
       ▼              ▼
 Move to Next Node   Stop
       │
       └──────────────┘

===============================================================================
Time Complexity:
===============================================================================

Display() : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates the Display() operation of a Stack using C. The
program traverses the Stack from top to bottom and displays all elements
in Last-In-First-Out (LIFO) order.

===============================================================================
*/



