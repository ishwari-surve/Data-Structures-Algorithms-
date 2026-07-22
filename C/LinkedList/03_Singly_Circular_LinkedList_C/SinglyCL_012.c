#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

///////////////////////////////////////////////////////////////////////////////
//
// Structure Definition
//
///////////////////////////////////////////////////////////////////////////////

struct node
{
    int data;
    struct node *next;
};

///////////////////////////////////////////////////////////////////////////////
//
// Type Definitions
//
///////////////////////////////////////////////////////////////////////////////

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

///////////////////////////////////////////////////////////////////////////////
//
// Function Declarations
//
///////////////////////////////////////////////////////////////////////////////

void Display(PNODE first, PNODE last);

int Count(PNODE first, PNODE last);

void InsertFirst(PPNODE first, PPNODE last, int iNo);

void InsertLast(PPNODE first, PPNODE last, int iNo);

void InsertAtPos(PPNODE first, PPNODE last, int iPos, int iNo);

void DeleteFirst(PPNODE first, PPNODE last);

void DeleteLast(PPNODE first, PPNODE last);

void DeleteAtPos(PPNODE first, PPNODE last, int iPos);

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays all nodes of the Singly Circular Linked List.
//
///////////////////////////////////////////////////////////////////////////////

void Display(PNODE first, PNODE last)
{
    if(first == NULL && last == NULL)
    {
        printf("Linked List is Empty.\n");
        return;
    }

    do
    {
        printf("| %d | -> ", first->data);
        first = first->next;

    }while(first != last->next);

    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Returns the total number of nodes in the linked list.
//
///////////////////////////////////////////////////////////////////////////////

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    if(first == NULL && last == NULL)
    {
        return 0;
    }

    do
    {
        iCount++;
        first = first->next;

    }while(first != last->next);

    return iCount;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Description   : Inserts a new node at the beginning of the linked list.
//
///////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }

    (*last)->next = *first;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts a new node at the end of the linked list.
//
///////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last)->next = newn;
        *last = newn;
    }

    (*last)->next = *first;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Description   : Inserts a new node at the specified position.
//
///////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first, PPNODE last, int iPos, int iNo)
{
    int i = 0;
    int iCount = Count(*first, *last);

    PNODE newn = NULL;
    PNODE temp = NULL;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first, last, iNo);
    }
    else if(iPos == (iCount + 1))
    {
        InsertLast(first, last, iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;

        temp = *first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Description   : Deletes the first node from the linked list.
//
///////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;
        *first = (*first)->next;

        free(temp);

        (*last)->next = *first;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Description   : Deletes the last node from the linked list.
//
///////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next != *last)
        {
            temp = temp->next;
        }

        free(*last);

        *last = temp;

        (*last)->next = *first;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Description   : Deletes a node from the specified position.
//
///////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{
    int i = 0;
    int iCount = Count(*first, *last);

    PNODE temp = NULL;
    PNODE target = NULL;

    if((iPos < 1) || (iPos > iCount))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first, last);
    }
    else if(iPos == iCount)
    {
        DeleteLast(first, last);
    }
    else
    {
        temp = *first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;

        free(target);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    int iChoice = 0;
    int iNo = 0;
    int iPos = 0;

    while(1)
    {
        printf("\n=================================================\n");
        printf("      Singly Circular Linked List\n");
        printf("=================================================\n");

        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert At Position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete At Position\n");
        printf("7. Display Linked List\n");
        printf("8. Count Nodes\n");
        printf("0. Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter data : ");
                scanf("%d",&iNo);
                InsertFirst(&head,&tail,iNo);
                break;

            case 2:
                printf("Enter data : ");
                scanf("%d",&iNo);
                InsertLast(&head,&tail,iNo);
                break;

            case 3:
                printf("Enter data : ");
                scanf("%d",&iNo);

                printf("Enter position : ");
                scanf("%d",&iPos);

                InsertAtPos(&head,&tail,iPos,iNo);
                break;

            case 4:
                DeleteFirst(&head,&tail);
                break;

            case 5:
                DeleteLast(&head,&tail);
                break;

            case 6:
                printf("Enter position : ");
                scanf("%d",&iPos);

                DeleteAtPos(&head,&tail,iPos);
                break;

            case 7:
                Display(head,tail);
                break;

            case 8:
                printf("Number of nodes are : %d\n",Count(head,tail));
                break;

            case 0:
                printf("\nThank You for Using the Program.\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

=================================================
      Singly Circular Linked List
=================================================

1. Insert First
2. Insert Last
3. Insert At Position
4. Delete First
5. Delete Last
6. Delete At Position
7. Display Linked List
8. Count Nodes
0. Exit

Enter your choice : 1

Enter data : 11

Enter your choice : 2

Enter data : 21

Enter your choice : 7

| 11 | -> | 21 | ->

Enter your choice : 8

Number of nodes are : 2

Enter your choice : 0

Thank You for Using the Program.

===============================================================================
Memory Representation:
===============================================================================

Initially

head = NULL
tail = NULL

        │
        ▼

Empty Linked List

--------------------------------------------------------

After Insertion

 head                         tail
  │                             │
  ▼                             ▼

+----+---+     +----+---+     +----+---+
| 11 | •-----> | 21 | •-----> | 51 | •--+
+----+---+     +----+---+     +----+---+ |
   ^                                      |
   |______________________________________|

The last node always points back to the first node, maintaining the
circular structure.

===============================================================================
Algorithm:
===============================================================================

1. Create an empty linked list.
2. Display the menu.
3. Read the user's choice.
4. Perform the selected operation.
5. Return to the menu.
6. Repeat until Exit is selected.

===============================================================================
Program Flow:
===============================================================================

               Start
                 │
                 ▼
        Create Empty List
                 │
                 ▼
          Display Menu
                 │
                 ▼
         Read User Choice
                 │
      ┌──────────┼──────────┐
      ▼          ▼          ▼
   Insert      Delete     Display
      │          │          │
      └──────────┼──────────┘
                 ▼
           Count Nodes
                 │
                 ▼
          Exit Selected?
            /        \
          No          Yes
          │            │
          └──────►  Stop

===============================================================================
Time Complexity:
===============================================================================

Display()          : O(n)

Count()            : O(n)

InsertFirst()      : O(1)

InsertLast()       : O(1)

InsertAtPos()      : O(n)

DeleteFirst()      : O(1)

DeleteLast()       : O(n)

DeleteAtPos()      : O(n)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 012 presents a complete Menu Driven implementation of a Singly
Circular Linked List in C. It provides an interactive interface through
which the user can perform insertion, deletion, display, and counting
operations. The program demonstrates modular programming, efficient
pointer manipulation, and proper maintenance of the circular linked list,
making it a comprehensive practical application of linked list concepts.

===============================================================================
*/
