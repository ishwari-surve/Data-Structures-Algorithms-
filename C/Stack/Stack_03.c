/*
===============================================================================
Program Name    : Stack - Pop Operation
Program Number  : 003
File Name       : Stack_03.c
Description     : This program demonstrates the Pop() operation of a Stack
                  using C. The Pop operation removes the topmost element
                  from the Stack following the LIFO principle.

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
- Remove an element from the top of the Stack.
- Return the deleted element.
- Free dynamically allocated memory.
- Understand deletion at the beginning.

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
    
}

//=========================================================
// Pop
//=========================================================

int Pop(PPNODE First)
{
    int iValue = 0;
    PNODE temp = NULL;

    if(*First == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }

    temp = *First;

    iValue = temp->data;

    *First = temp->next;

    free(temp);

    return iValue;
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

    int iRet = 0;

    Push(&First,11);
    Push(&First,21);
    Push(&First,51);
    Push(&First,101);

    iRet = Pop(&First);

    printf("Removed element is : %d\n",iRet);

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Removed element is : 101

===============================================================================
Memory Representation:
===============================================================================

Before Pop()

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

↓

After Pop()

                TOP
                 │
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

Deleted Node : 101

===============================================================================
Algorithm:
===============================================================================

1. Check whether the Stack is empty.
2. If empty, display an appropriate message.
3. Store the data of the top node.
4. Move the top pointer to the next node.
5. Delete the old top node.
6. Return the deleted element.

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
 Display Error   Store Top Data
                      │
                      ▼
             Move Top Pointer
                      │
                      ▼
               Delete Old Node
                      │
                      ▼
             Return Deleted Data
                      │
                      ▼
                     Stop

===============================================================================
Time Complexity:
===============================================================================

Pop() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 003 demonstrates the Pop() operation of a Stack using C. The
program removes the topmost element from the Stack, frees the allocated
memory, and returns the deleted element while maintaining the
Last-In-First-Out (LIFO) principle.

===============================================================================
*/

