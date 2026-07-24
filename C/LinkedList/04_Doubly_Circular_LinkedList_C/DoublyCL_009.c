/*
===============================================================================
Program Name    : Doubly Circular Linked List - InsertAtPos()
Program Number  : 009
Description     : This program demonstrates how to insert a new node at a
                  specified position in a Doubly Circular Linked List while
                  maintaining the circular and doubly linked properties.

Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Doubly Circular Linked List
4. Dynamic Memory Allocation
5. Pointer Manipulation
6. Position Validation
7. Circular Linking
8. typedef

Key Learning Points:
- Insert a node at any valid position.
- Validate the given position.
- Reuse InsertFirst() and InsertLast().
- Update next and prev pointers correctly.
- Preserve the circular nature of the linked list.

===============================================================================
*/
#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Display(PNODE first, PNODE last)
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    printf("<=> ");

    do
    {
        printf("| %d | <=> ",first->data);
        first = first->next;

    }while(first != last->next);

    printf("\n");
}

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

void InsertFirst(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }

    (*last)->next = *first;
    (*first)->prev = *last;
}

void InsertLast(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last)->next = newn;
        newn->prev = *last;
        *last = newn;
    }

    (*last)->next = *first;
    (*first)->prev = *last;
}

void InsertAtPos(PPNODE first, PPNODE last, int iNo, int iPos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    int i = 0;
    int iCount = 0;

    iCount = Count(*first,*last);

    if(iPos < 1 || iPos > iCount + 1)
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first,last,iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(first,last,iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

void DeleteFirst(PPNODE first, PPNODE last)
{
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
        *first = (*first)->next;

        free((*first)->prev);

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{
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
        *last = (*last)->prev;

        free((*last)->next);

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

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

    Display(head,tail);

    iRet = Count(head,tail);

    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&head,&tail);
    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes are : %d\n",iRet);

    DeleteLast(&head,&tail);
    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes are : %d\n",iRet);
    
    InsertAtPos(&head,&tail,105,4);
    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes are : %d\n",iRet);

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Linked List before InsertAtPos() :

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>

Number of nodes are : 6

Linked List after InsertAtPos() :

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 105 | <=> | 101 | <=> | 111 | <=> | 121 | <=>

Number of nodes are : 7

===============================================================================
Memory Representation:
===============================================================================

Before InsertAtPos()

11 <=> 21 <=> 51 <=> 101 <=> 111 <=> 121

                     │
                     ▼

Insert 105 at Position 4

After InsertAtPos()

11 <=> 21 <=> 51 <=> 105 <=> 101 <=> 111 <=> 121

Only the surrounding node links are modified.

===============================================================================
Algorithm:
===============================================================================

1. Count the total number of nodes.
2. Validate the given position.
3. If position is 1:
      Call InsertFirst().
4. If position is Count()+1:
      Call InsertLast().
5. Otherwise:
      Traverse up to (Position-1).
      Create a new node.
      Update next and prev links.
6. Maintain the circular structure.
7. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
             │
             ▼
     Validate Position
             │
             ▼
      Position == 1 ?
        │          │
      Yes         No
       │           │
 InsertFirst()     ▼
          Position == Last+1 ?
               │          │
             Yes         No
              │           │
      InsertLast()        ▼
                   Traverse List
                         │
                         ▼
                  Insert New Node
                         │
                         ▼
                        Stop

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()        : O(1)

InsertLast()         : O(1)

InsertAtPos()        : O(n)

Display()            : O(n)

Count()              : O(n)

Space Complexity     : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 009 demonstrates the InsertAtPos() operation of a Doubly Circular
Linked List. The program validates the given position, inserts the new node
at the desired location, correctly updates both next and previous pointers,
and preserves the circular structure of the linked list.

===============================================================================
*/
