/*
===============================================================================
Program Name    : Stack - Count Operation
Program Number  : 006
File Name       : Stack_06.c
Description     : This program demonstrates the Count() operation of a Stack
                  using C. The Count operation traverses the Stack and
                  returns the total number of elements currently present
                  in the Stack.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Stack Traversal

Key Learning Points:
- Traverse the complete Stack.
- Count the total number of nodes.
- Return the total number of elements.
- Understand Stack traversal using pointers.

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
// Push (Insert First)
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
    int iCnt = 0;

    while(First != NULL)
    {
        iCnt++;
        First = First->next;
    }

    return iCnt;
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

    printf("\nNumber of elements are : %d\n",Count(First));

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

Number of elements are : 4

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

Count = 4

===============================================================================
Algorithm:
===============================================================================

1. Initialize the counter to 0.
2. Traverse the Stack from Top to Bottom.
3. Increment the counter for every node.
4. Continue until NULL is reached.
5. Return the total count.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
      Initialize Count = 0
               │
               ▼
      Pointer != NULL ?
        │            │
      Yes           No
       │             │
       ▼             ▼
 Increment Count   Return Count
       │             │
       ▼             ▼
 Move to Next Node Stop
       │
       └─────────────┘

===============================================================================
Time Complexity:
===============================================================================

Count() : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates the Count() operation of a Stack using C. The
program traverses the Stack from Top to Bottom and returns the total
number of elements currently present in the Stack.

===============================================================================
*/
