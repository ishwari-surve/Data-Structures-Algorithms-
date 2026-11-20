/*
===============================================================================
Program Name    : InsertFirst() in Singly Circular Linked List
Program Number  : 005
Description     : This program implements the InsertFirst() function for a
                  Singly Circular Linked List. It inserts a new node at the
                  beginning of the list while maintaining the circular link.

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
- A new node is created using malloc().
- If the list is empty, both first and last point to the new node.
- Otherwise, the new node is inserted before the first node.
- The last node always points to the first node to maintain circularity.

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
// Function Name : InsertFirst
// Description   : Inserts a new node at the beginning.
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

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

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

              first                          last
                │                              │
                ▼                              ▼
        +---------+------+     +---------+------+     +---------+------+
        |   11    |   •-------->|   21    |   •-------->|   51    |   •--+
        +---------+------+     +---------+------+     +---------+------+  |
              ^                                                          |
              |__________________________________________________________|

Last node points back to the first node.

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Store the given data in the node.
3. If the list is empty:
      - first = new node
      - last = new node
4. Otherwise:
      - new node points to first
      - first becomes the new node
5. Make last->next point to first.

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
 ┌─┴─────────┐
 │           │
Yes         No
 │           │
 ▼           ▼
first=last  Insert Before First
 │           │
 └─────┬─────┘
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

InsertFirst()     : O(1)

Space Complexity  : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 005 demonstrates insertion at the beginning of a Singly Circular
Linked List. The new node becomes the first node, and the last node is updated
to point back to the new first node, preserving the circular structure.

===============================================================================
