/*
===============================================================================
Program Name    : Stack - Peep Operation
Program Number  : 005
File Name       : Stack_05.c
Description     : This program demonstrates the Peep() operation of a Stack
                  using C. The Peep operation returns the topmost element
                  of the Stack without removing it, thereby maintaining
                  the Last-In-First-Out (LIFO) principle.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Stack (LIFO)

Key Learning Points:
- Retrieve the top element of the Stack.
- Understand Stack underflow condition.
- Access the top element without deleting it.
- Preserve the Stack structure after Peep().

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
    if(First == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return First->data;
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

///=========================================================
// Main
//=========================================================

int main()
{
    PNODE First = NULL;

    int iRet = 0;

    Push(&First,11);
    Push(&First,21);
    Push(&First,51);
    Push(&First,101);

    Display(First);

    iRet = Peep(First);

    printf("\nTop element is : %d\n",iRet);

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

| 101 |
| 51 |
| 21 |
| 11 |
NULL

Top element is : 101

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

Peep() returns : 101

===============================================================================
Algorithm:
===============================================================================

1. Check whether the Stack is empty.
2. If empty, display an appropriate message.
3. Otherwise, return the data of the top node.
4. Stop.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
      Is Stack Empty?
        │            │
      Yes           No
       │             │
       ▼             ▼
 Display Error   Return Top Data
       │             │
       └──────► Stop ◄──────┘

===============================================================================
Time Complexity:
===============================================================================

Peep() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 005 demonstrates the Peep() operation of a Stack using C. The
program returns the topmost element without removing it from the Stack,
thereby preserving the Stack structure and maintaining the LIFO principle.

===============================================================================
*/

