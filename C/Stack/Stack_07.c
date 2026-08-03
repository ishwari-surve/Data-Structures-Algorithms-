/*
===============================================================================
Program Name    : Stack - Complete Implementation
Program Number  : 007
File Name       : Stack_07.c
Description     : This program demonstrates the complete implementation of a
                  Stack using C. It performs all fundamental Stack
                  operations including Push(), Pop(), Peep(), Display(),
                  and Count() while following the Last-In-First-Out (LIFO)
                  principle.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Dynamic Memory Allocation
5. Stack Operations
6. LIFO (Last-In-First-Out)

Key Learning Points:
- Implement the complete Stack using a linked list.
- Perform Push(), Pop(), Peep(), Display(), and Count() operations.
- Understand insertion and deletion at the top of the Stack.
- Maintain the LIFO property throughout all operations.
- Develop a foundation for a Menu-Driven Stack application.

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

    int iRet = 0;

    Push(&First,11);
    Push(&First,21);
    Push(&First,51);
    Push(&First,101);

    printf("Current Stack is :\n\n");
    Display(First);

    printf("\nNumber of elements are : %d\n",Count(First));

    iRet = Peep(First);
    printf("\nTop element is : %d\n",iRet);

    iRet = Pop(&First);
    printf("\nRemoved element is : %d\n",iRet);

    printf("\nStack after Pop() operation :\n\n");
    Display(First);

    printf("\nNumber of elements are : %d\n",Count(First));

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Current Stack is :

| 101 |
| 51 |
| 21 |
| 11 |
NULL

Number of elements are : 4

Top element is : 101

Removed element is : 101

Stack after Pop() operation :

| 51 |
| 21 |
| 11 |
NULL

Number of elements are : 3

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

===============================================================================
Algorithm:
===============================================================================

1. Create an empty Stack.
2. Insert elements using Push().
3. Display the Stack.
4. Count the total elements.
5. Retrieve the top element using Peep().
6. Remove the top element using Pop().
7. Display the updated Stack.
8. Display the updated count.
9. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
             │
             ▼
      Create Stack
             │
             ▼
     Push Elements
             │
             ▼
      Display Stack
             │
             ▼
      Display Count
             │
             ▼
      Peep Top Element
             │
             ▼
       Pop Top Element
             │
             ▼
   Display Updated Stack
             │
             ▼
   Display Updated Count
             │
             ▼
            Stop

===============================================================================
Time Complexity:
===============================================================================

Push()    : O(1)
Pop()     : O(1)
Peep()    : O(1)
Display() : O(n)
Count()   : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 007 demonstrates the complete implementation of a Stack using C.
It successfully performs all fundamental Stack operations including
Push(), Pop(), Peep(), Display(), and Count(), while maintaining the
Last-In-First-Out (LIFO) principle.

===============================================================================
*/
