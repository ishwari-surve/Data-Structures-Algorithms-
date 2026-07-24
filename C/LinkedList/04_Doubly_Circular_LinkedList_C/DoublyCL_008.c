/*
===============================================================================
Program Name    : Doubly Circular Linked List - DeleteLast()
Program Number  : 008
Description     : This program demonstrates how to delete the last node from
                  a Doubly Circular Linked List while maintaining the circular
                  and doubly linked properties.

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
7. Circular Linking
8. typedef

Key Learning Points:
- Delete the last node from the linked list.
- Handle deletion from an empty linked list.
- Handle deletion when only one node is present.
- Update both next and prev pointers correctly.
- Preserve the circular nature of the linked list.
- Release dynamically allocated memory using free().

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

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Linked List before DeleteLast() :

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>

Number of nodes are : 6

Linked List after DeleteLast() :

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>

Number of nodes are : 5

===============================================================================
Memory Representation:
===============================================================================

Before DeleteLast()

head                                                        tail
 │                                                           │
 ▼                                                           ▼

11 <=> 21 <=> 51 <=> 101 <=> 111 <=> 121
 ▲                                         │
 └─────────────────────────────────────────┘

----------------------------------------------------

After DeleteLast()

head                                                  tail
 │                                                     │
 ▼                                                     ▼

11 <=> 21 <=> 51 <=> 101 <=> 111
 ▲                                 │
 └─────────────────────────────────┘

The last node is deleted and the circular links are updated.

===============================================================================
Algorithm:
===============================================================================

1. Check whether the linked list is empty.
2. If only one node is present:
      Delete the node.
      Make first and last NULL.
3. Otherwise:
      Move last to the previous node.
      Delete the old last node.
      Update next and prev links.
4. Maintain the circular structure.
5. Stop.

===============================================================================
Program Flow:
===============================================================================

          Start
             │
             ▼
      Is List Empty?
        │        │
      Yes       No
        │        │
        ▼        ▼
      Return   Single Node?
                  │      │
                Yes      No
                  │       │
                  ▼       ▼
             Delete Node  Move Last
                           │
                           ▼
                    Delete Old Last
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

Display()            : O(n)

Count()              : O(n)

Space Complexity     : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 008 demonstrates the DeleteLast() operation of a Doubly Circular
Linked List. The program removes the last node while correctly updating
both the next and previous pointers and preserving the circular nature of
the linked list. It also handles empty and single-node linked lists safely.

===============================================================================
*/
