/*
===============================================================================
Program Name    : Doubly Circular Linked List - DeleteAtPos()
Program Number  : 010
Description     : This program demonstrates how to delete a node from a
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
5. Memory Deallocation using free()
6. Pointer Manipulation
7. Position Validation
8. Circular Linking
9. typedef

Key Learning Points:
- Delete a node from any valid position.
- Validate the given position.
- Reuse DeleteFirst() and DeleteLast().
- Update next and prev pointers correctly.
- Preserve the circular nature of the linked list.
- Release dynamically allocated memory.

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

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{
    PNODE temp = NULL;
    int i = 0;
    int iCount = 0;

    iCount = Count(*first,*last);

    if(iPos < 1 || iPos > iCount)
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(iPos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
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

    DeleteAtPos(&head,&tail,4);
    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes are : %d\n",iRet);

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Linked List before DeleteAtPos() :

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>

Number of nodes are : 6

Linked List after DeleteAtPos() :

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 111 | <=> | 121 | <=>

Number of nodes are : 5

===============================================================================
Memory Representation:
===============================================================================

Before DeleteAtPos()

11 <=> 21 <=> 51 <=> 101 <=> 111 <=> 121

                     │
                     ▼

Delete Position 4 (101)

After DeleteAtPos()

11 <=> 21 <=> 51 <=> 111 <=> 121

Only the surrounding node links are modified and
the deleted node memory is released.

===============================================================================
Algorithm:
===============================================================================

1. Count the total number of nodes.
2. Validate the given position.
3. If position is 1:
      Call DeleteFirst().
4. If position is the last position:
      Call DeleteLast().
5. Otherwise:
      Traverse up to (Position-1).
      Delete the required node.
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
        │            │
      Yes           No
       │             │
DeleteFirst()        ▼
             Position == Last ?
                │           │
              Yes          No
               │            │
        DeleteLast()        ▼
                    Traverse List
                          │
                          ▼
                  Delete Required Node
                          │
                          ▼
                 Update Circular Links
                          │
                          ▼
                         Stop

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()        : O(1)

InsertLast()         : O(1)

DeleteFirst()        : O(1)

DeleteLast()         : O(1)

DeleteAtPos()        : O(n)

Display()            : O(n)

Count()              : O(n)

Space Complexity     : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 010 demonstrates the DeleteAtPos() operation of a Doubly Circular
Linked List. The program validates the specified position, deletes the node
from the desired location, correctly updates both next and previous pointers,
releases the allocated memory, and preserves the circular structure of the
linked list.

===============================================================================
*/
