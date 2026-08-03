/*
===============================================================================
Program Name    : Stack - Push Operation
Program Number  : 002
File Name       : Stack_02.c
Description     : This program demonstrates the Push() operation of a Stack
                  using C. The Push operation inserts a new element at the
                  top of the Stack following the LIFO principle.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Dynamic Memory Allocation
5. Stack (LIFO)

Key Learning Points:
- Insert an element at the top of the Stack.
- Allocate memory dynamically using malloc().
- Understand insertion at the beginning.
- Follow the LIFO principle.

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

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

===============================================================================
Memory Representation:
===============================================================================
The program performs Push() operations and inserts elements into the Stack.
The inserted elements will be displayed in the next program.

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
1. Allocate memory for a new node.
2. Store the given data.
3. Link the new node to the current top.
4. Update the top pointer.
5. Stop.

===============================================================================
Program Flow:
===============================================================================
Start
   │
   ▼
Create New Node
   │
   ▼
Store Data
   │
   ▼
Link with Top
   │
   ▼
Update Top
   │
   ▼
Stop

===============================================================================
Time Complexity:
===============================================================================
Push() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================
Program 002 demonstrates the Push() operation of a Stack using C.
It inserts new elements at the top of the Stack using dynamic
memory allocation while following the LIFO principle.

===============================================================================
*/

