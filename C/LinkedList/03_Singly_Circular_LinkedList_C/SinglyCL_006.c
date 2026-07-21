/*
===============================================================================
Program Name    : InsertLast() in Singly Circular Linked List
Program Number  : 006
Description     : This program implements the InsertLast() function for a
                  Singly Circular Linked List. It inserts a new node at the
                  end of the list while maintaining the circular link.

Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Dynamic Memory Allocation
2. Self-Referential Structure
3. Circular Linked List
4. Head Pointer
5. Tail Pointer
6. Pointer Manipulation

Key Learning Points:
- A new node is inserted at the end of the linked list.
- The last pointer is updated to the newly inserted node.
- The new last node points back to the first node.
- The circular structure is preserved after every insertion.

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

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts a new node at the end.
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

void Display(PNODE first, PNODE last)
{
    if(first == NULL && last == NULL)
    {
        printf("Linked List is Empty.\n");
        return;
    }

    do
    {
        printf("| %d | -> ",first->data);
        first = first->next;
    }while(first != last->next);

    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertLast(&head,&tail,11);
    InsertLast(&head,&tail,21);
    InsertLast(&head,&tail,51);

    Display(head,tail);

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

| 11 | -> | 21 | -> | 51 | ->

===============================================================================
Memory Representation:
===============================================================================

             first                           last
               │                               │
               ▼                               ▼
       +---------+------+     +---------+------+     +---------+------+
       |   11    |   •-------->|   21    |   •-------->|   51    |   •--+
       +---------+------+     +---------+------+     +---------+------+  |
             ^                                                         |
             |_________________________________________________________|

Last node points back to the first node.

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Store the given data.
3. If the list is empty:
      - first = new node
      - last = new node
4. Otherwise:
      - last->next = new node
      - last = new node
5. Update last->next = first.

===============================================================================
Program Flow:
===============================================================================

Start
   │
   ▼
Create New Node
   │
   ▼
Is List Empty?
   │
 ┌─┴──────────┐
 │            │
Yes          No
 │            │
 ▼            ▼
first=last   Attach Node at End
 │            │
 └─────┬──────┘
       ▼
Update last
       │
       ▼
last->next = first
       │
       ▼
Display List
       │
       ▼
Stop

===============================================================================
Time Complexity:
===============================================================================

InsertLast()      : O(1)

Space Complexity  : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates insertion at the end of a Singly Circular Linked
List. The last pointer is updated to the newly inserted node, and its next
pointer is linked back to the first node, preserving the circular nature of
the linked list.

===============================================================================
*/
