/*
===============================================================================
Program Name    : Stack - Menu Driven Implementation
Program Number  : 008
File Name       : Stack_08.c
Description     : This program demonstrates a menu-driven implementation of
                  Stack using C. It allows the user to perform Push(),
                  Pop(), Peep(), Display(), and Count() operations
                  interactively while following the Last-In-First-Out
                  (LIFO) principle.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Dynamic Memory Allocation
5. Menu Driven Programming
6. Stack (LIFO)

Key Learning Points:
- Implement all Stack operations.
- Perform Stack operations interactively.
- Understand Stack traversal.
- Apply dynamic memory allocation.
- Maintain the LIFO principle.

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
// Pop (Delete First)
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
// Peep (Top Element)
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
        printf("| %d |\n",First->data);
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

    int iChoice = 0;
    int iValue = 0;
    int iRet = 0;

    while(1)
    {
        printf("\n====================================================\n");
        printf("              Stack Operations\n");
        printf("====================================================\n");

        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Display\n");
        printf("5. Count\n");
        printf("6. Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter the element : ");
                scanf("%d",&iValue);

                Push(&First,iValue);
                break;

            case 2:
                iRet = Pop(&First);

                if(iRet != -1)
                {
                    printf("Removed element is : %d\n",iRet);
                }
                break;

            case 3:
                iRet = Peep(First);

                if(iRet != -1)
                {
                    printf("Top element is : %d\n",iRet);
                }
                break;

            case 4:
                printf("\nElements of Stack are :\n\n");
                Display(First);
                break;

            case 5:
                printf("Number of elements are : %d\n",Count(First));
                break;

            case 6:
                printf("\nThank you for using Stack.\n");
                return 0;

            default:
                printf("Invalid choice...\n");
                break;
        }
    }

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

====================================================
              Stack Operations
====================================================
1. Push
2. Pop
3. Peep
4. Display
5. Count
6. Exit

Enter your choice : 1
Enter the element : 11

Enter your choice : 1
Enter the element : 21

Enter your choice : 1
Enter the element : 51

Enter your choice : 4

Elements of Stack are :

| 51 |
| 21 |
| 11 |
NULL

Enter your choice : 3
Top element is : 51

Enter your choice : 2
Removed element is : 51

Enter your choice : 5
Number of elements are : 2

Enter your choice : 6

Thank you for using Stack.

===============================================================================
Memory Representation:
===============================================================================

                TOP
                 │
                 ▼
            +--------+
            |  51  | •──┐
            +--------+  │
                        ▼
            +--------+
            |  21  | •──┐
            +--------+  │
                        ▼
            +--------+
            |  11  | ───► NULL
            +--------+

Count = 3

===============================================================================
Algorithm:
===============================================================================

1. Create an empty Stack.
2. Display the menu.
3. Accept the user's choice.
4. Perform the selected Stack operation.
5. Display the result.
6. Repeat until the user selects Exit.
7. Stop.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
        Create Stack
               │
               ▼
        Display Menu
               │
               ▼
     Accept User Choice
               │
               ▼
      Perform Operation
               │
               ▼
      Continue ?
        │           │
      Yes          No
       │            │
       └──────────► Stop

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

Program 008 demonstrates the complete Menu-Driven implementation of a
Stack using C. It enables users to perform Push(), Pop(), Peep(),
Display(), and Count() operations interactively while maintaining the
Last-In-First-Out (LIFO) principle.

===============================================================================
*/
