/*
===============================================================================
Program Name    : Doubly Circular Linked List - DeleteFirst()
Program Number  : 007
Description     : This program demonstrates how to delete the first node from
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
- Delete the first node from the linked list.
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

    return 0;
}

/*
==============================================================================
Expected Output:
===============================================================================
Linked List before DeleteFirst() :

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>

Number of nodes are : 6

Linked List after DeleteFirst() :

<=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>

Number of nodes are : 5

===============================================================================
Memory Representation:
===============================================================================
Before DeleteFirst()

head                                                        tail
 │                                                           │
 ▼                                                           ▼

11 <=> 21 <=> 51 <=> 101 <=> 111 <=> 121
 ▲                                         │
 └─────────────────────────────────────────┘

----------------------------------------------------

After DeleteFirst()

head                                                  tail
 │                                                     │
 ▼                                                     ▼

21 <=> 51 <=> 101 <=> 111 <=> 121
 ▲                                 │
 └─────────────────────────────────┘

The first node is deleted and the circular links are updated.

===============================================================================
Algorithm:
===============================================================================

1. Check whether the linked list is empty.
2. If only one node is present:
      Delete the node.
      Make first and last NULL.
3. Otherwise:
      Move first to the second node.
      Delete the old first node.
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
             Delete Node  Move First
                           │
                           ▼
                    Delete Old First
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

Display()            : O(n)

Count()              : O(n)

Space Complexity     : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 007 demonstrates the DeleteFirst() operation of a Doubly Circular
Linked List. The program removes the first node while correctly updating
both the next and previous pointers and preserving the circular nature of
the linked list. It also handles empty and single-node linked lists safely.

===============================================================================
*/
