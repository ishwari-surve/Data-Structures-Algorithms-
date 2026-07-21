/*
===============================================================================
Program Name    : Complete Singly Circular Linked List
Program Number  : 011
Description     : This program demonstrates the complete implementation of a
                  Singly Circular Linked List. It includes all insertion,
                  deletion and utility operations such as Display() and
                  Count(). The circular property of the linked list is
                  maintained after every operation.

Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Circular Linked List
4. Dynamic Memory Allocation
5. Pointer Manipulation
6. Function Based Programming
7. Position Validation
8. Memory Management using malloc() and free()

Key Learning Points:
- Understanding the complete implementation of a Singly Circular Linked List.
- Maintaining the circular link after every insertion and deletion.
- Position-based insertion and deletion.
- Proper handling of empty and single-node linked lists.
- Reusing functions for better modularity.

===============================================================================
*/

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

    int iRet = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);

    printf("Linked List after InsertFirst() and InsertLast() :\n");
    Display(head,tail);

    iRet = Count(head,tail);
    printf("\nNumber of nodes are : %d\n",iRet);

    InsertAtPos(&head,&tail,4,75);

    printf("\nAfter InsertAtPos() :\n");
    Display(head,tail);

    DeleteFirst(&head,&tail);

    printf("\nAfter DeleteFirst() :\n");
    Display(head,tail);

    DeleteLast(&head,&tail);

    printf("\nAfter DeleteLast() :\n");
    Display(head,tail);

    DeleteAtPos(&head,&tail,3);

    printf("\nAfter DeleteAtPos() :\n");
    Display(head,tail);

    iRet = Count(head,tail);

    printf("\nFinal Number of Nodes : %d\n",iRet);

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Linked List after InsertFirst() and InsertLast() :

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->

Number of nodes are : 6

After InsertAtPos() :

| 11 | -> | 21 | -> | 51 | -> | 75 | -> | 101 | -> | 111 | -> | 121 | ->

After DeleteFirst() :

| 21 | -> | 51 | -> | 75 | -> | 101 | -> | 111 | -> | 121 | ->

After DeleteLast() :

| 21 | -> | 51 | -> | 75 | -> | 101 | -> | 111 | ->

After DeleteAtPos() :

| 21 | -> | 51 | -> | 101 | -> | 111 | ->

Final Number of Nodes : 4

===============================================================================
Memory Representation:
===============================================================================

Initial Linked List

 head                                                                    tail
  │                                                                        │
  ▼                                                                        ▼

+----+---+     +----+---+     +----+---+     +-----+---+     +-----+---+     +-----+---+
| 11 | •-----> | 21 | •-----> | 51 | •-----> | 101 | •-----> | 111 | •-----> | 121 | •--+
+----+---+     +----+---+     +----+---+     +-----+---+     +-----+---+     +-----+---+ |
   ^                                                                                       |
   |_______________________________________________________________________________________|


After InsertAtPos(4,75)

+----+---+     +----+---+     +----+---+     +----+---+     +-----+---+     +-----+---+     +-----+---+
| 11 | •-----> | 21 | •-----> | 51 | •-----> | 75 | •-----> | 101 | •-----> | 111 | •-----> | 121 | •--+
+----+---+     +----+---+     +----+---+     +----+---+     +-----+---+     +-----+---+     +-----+---+ |
   ^                                                                                                        |
   |________________________________________________________________________________________________________|


After DeleteFirst()

+----+---+     +----+---+     +----+---+     +-----+---+     +-----+---+     +-----+---+
| 21 | •-----> | 51 | •-----> | 75 | •-----> | 101 | •-----> | 111 | •-----> | 121 | •--+
+----+---+     +----+---+     +----+---+     +-----+---+     +-----+---+     +-----+---+ |
   ^                                                                                       |
   |_______________________________________________________________________________________|


After DeleteLast()

+----+---+     +----+---+     +----+---+     +-----+---+     +-----+---+
| 21 | •-----> | 51 | •-----> | 75 | •-----> | 101 | •-----> | 111 | •--+
+----+---+     +----+---+     +----+---+     +-----+---+     +-----+---+ |
   ^                                                                       |
   |_______________________________________________________________________|


After DeleteAtPos(3)

+----+---+     +----+---+     +-----+---+     +-----+---+
| 21 | •-----> | 51 | •-----> | 101 | •-----> | 111 | •--+
+----+---+     +----+---+     +-----+---+     +-----+---+ |
   ^                                                       |
   |_______________________________________________________|

The circular connection is preserved after every insertion and deletion.

===============================================================================
Algorithm:
===============================================================================

1. Create an empty Singly Circular Linked List.
2. Insert nodes at the beginning using InsertFirst().
3. Insert nodes at the end using InsertLast().
4. Display the linked list.
5. Count the total number of nodes.
6. Insert a node at the specified position.
7. Delete the first node.
8. Delete the last node.
9. Delete the node at the specified position.
10. Display the final linked list.
11. Display the final node count.
12. Stop.

===============================================================================
Program Flow:
===============================================================================

                         Start
                           │
                           ▼
                 Create Empty Linked List
                           │
                           ▼
                  InsertFirst() Operations
                           │
                           ▼
                   InsertLast() Operations
                           │
                           ▼
                      Display List
                           │
                           ▼
                       Count Nodes
                           │
                           ▼
                     InsertAtPos()
                           │
                           ▼
                     DeleteFirst()
                           │
                           ▼
                      DeleteLast()
                           │
                           ▼
                     DeleteAtPos()
                           │
                           ▼
                     Display Final List
                           │
                           ▼
                    Display Final Count
                           │
                           ▼
                          Stop

===============================================================================
Time Complexity:
===============================================================================

Display()            : O(n)

Count()              : O(n)

InsertFirst()        : O(1)

InsertLast()         : O(1)

InsertAtPos()        : O(n)

DeleteFirst()        : O(1)

DeleteLast()         : O(n)

DeleteAtPos()        : O(n)

Space Complexity     : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 011 presents the complete implementation of a Singly Circular Linked
List in C. It combines all insertion, deletion, display, and counting
operations into a single application. The program correctly handles empty,
single-node, and multi-node linked lists while preserving the circular
structure after every operation. This program serves as the foundation for
the next step, the Menu Driven Singly Circular Linked List application.

===============================================================================
*/
