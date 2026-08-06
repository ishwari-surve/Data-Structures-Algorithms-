/*
===============================================================================
Program Name    : Queue Using Singly Linear Linked List - Menu Driven
Program Number  : 006
File Name       : Queue_06.c

Description     : This program implements a complete Menu Driven Queue
                  using a Singly Linear Linked List in C.
                  It supports Enqueue, Dequeue, Display and Count
                  operations while following the FIFO
                  (First In First Out) principle.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Dynamic Memory Allocation
5. Queue
6. Menu Driven Programming
7. Queue Operations

Key Learning Points:
- Insert elements using Enqueue.
- Remove elements using Dequeue.
- Display queue contents.
- Count queue elements.
- Build a menu driven application.

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

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Enqueue
// Description   : Insert element at Last
//
///////////////////////////////////////////////////////////////////////////////

void Enqueue(PPNODE first,int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Dequeue
// Description   : Delete element from First
//
///////////////////////////////////////////////////////////////////////////////

int Dequeue(PPNODE first)
{
    PNODE temp = NULL;
    int iValue = 0;

    if(*first == NULL)
    {
        printf("Queue is Empty\n");
        return -1;
    }

    iValue = (*first)->data;

    temp = *first;

    *first = (*first)->next;

    free(temp);

    return iValue;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Display Queue
//
///////////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    printf("\nQueue Elements :\n");

    while(first != NULL)
    {
        printf("|%d| -> ",first->data);
        first = first->next;
    }

    printf("NULL\n");
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Count number of nodes
//
///////////////////////////////////////////////////////////////////////////////

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;

    int iChoice = 0;
    int iValue = 0;
    int iRet = 0;

    printf("-------------------------------------------------\n");
    printf("          Queue Menu Driven Application\n");
    printf("-------------------------------------------------\n");

    while(1)
    {
        printf("\n-------------------------------------------------\n");
        printf("\n---------------------QUEUE-----------------------\n");
        printf("\n-------------------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Count\n");
        printf("5. Exit\n");
        printf("-------------------------------------------------\n");

        printf("Enter your choice : ");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:

                printf("Enter the data : ");
                scanf("%d",&iValue);

                Enqueue(&head,iValue);

                printf("Element inserted successfully\n");
                break;

            case 2:

                iRet = Dequeue(&head);

                if(iRet != -1)
                {
                    printf("Removed Element : %d\n",iRet);
                }
                break;

            case 3:

                Display(head);
                break;

            case 4:

                iRet = Count(head);

                printf("Number of Elements : %d\n",iRet);
                break;

            case 5:

                printf("Thank you for using Queue Application\n");
                return 0;

            default:

                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

-------------------------------------------------
          Queue Menu Driven Application
-------------------------------------------------

---------------------QUEUE-----------------------

1. Enqueue
2. Dequeue
3. Display
4. Count
5. Exit

Enter your choice : 1
Enter the data : 11
Element inserted successfully

Enter your choice : 1
Enter the data : 21
Element inserted successfully

Enter your choice : 3

Queue Elements :

|11| -> |21| -> NULL

Enter your choice : 2
Removed Element : 11

Enter your choice : 4
Number of Elements : 1

Enter your choice : 5
Thank you for using Queue Application

===============================================================================
Memory Representation:
===============================================================================

After Enqueue Operations

Head
 │
 ▼
+----+------+     +----+------+     +----+------+
| 11 |  •-------> | 21 |  •-------> | 51 | NULL |
+----+------+     +----+------+     +----+------+

Front -------------------------------> Rear


After One Dequeue

Head
 │
 ▼
+----+------+     +----+------+
| 21 |  •-------> | 51 | NULL |
+----+------+     +----+------+

Front -----------------------> Rear

===============================================================================
Algorithm:
===============================================================================

1. Display the menu.
2. Accept the user's choice.
3. Perform the selected operation:
   - Enqueue
   - Dequeue
   - Display
   - Count
4. Repeat until the user selects Exit.

===============================================================================
Program Flow:
===============================================================================

              Start
                 │
                 ▼
          Display Menu
                 │
                 ▼
         Read User Choice
                 │
     ┌───────────┼────────────┐
     │           │            │
     ▼           ▼            ▼
 Enqueue     Dequeue      Display
     │           │            │
     └──────┬────┴─────┬──────┘
            │          │
            ▼          ▼
         Count      Exit?
            │          │
            └──────┬───┘
                   ▼
              Repeat Menu

===============================================================================
Time Complexity:
===============================================================================

Enqueue : O(n)
Dequeue : O(1)
Display : O(n)
Count   : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates a complete Menu Driven Queue implementation
using a Singly Linear Linked List in C. It provides all the basic
queue operations including Enqueue, Dequeue, Display and Count while
maintaining the FIFO principle.

===============================================================================
*/
