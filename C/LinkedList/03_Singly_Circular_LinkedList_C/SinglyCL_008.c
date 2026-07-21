/*
===============================================================================
Program Name    : DeleteLast() in Singly Circular Linked List
Program Number  : 008
Description     : This program demonstrates the DeleteLast() operation in a
                  Singly Circular Linked List. It removes the last node while
                  maintaining the circular nature of the linked list.

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
6. Memory Deallocation using free()

Key Learning Points:
- Handles empty linked list.
- Handles single-node linked list.
- Deletes the last node from a multi-node circular linked list.
- Updates the last pointer correctly.
- Maintains the circular connection after deletion.

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
// Function Name : Display
// Description   : Displays all nodes of the linked list.
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
        printf("| %d | -> ",first->data);
        first = first->next;
    }while(first != last->next);

    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts a node at the end.
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
// Function Name : DeleteLast
// Description   : Deletes the last node.
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
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertLast(&head,&tail,11);
    InsertLast(&head,&tail,21);
    InsertLast(&head,&tail,51);
    InsertLast(&head,&tail,101);

    printf("Linked List before deletion :\n");
    Display(head,tail);

    DeleteLast(&head,&tail);

    printf("\nLinked List after deletion :\n");
    Display(head,tail);

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Linked List before deletion :

| 11 | -> | 21 | -> | 51 | -> | 101 | ->

Linked List after deletion :

| 11 | -> | 21 | -> | 51 | ->

===============================================================================
Memory Representation:
===============================================================================

Before DeleteLast()

 head                                              tail
  │                                                  │
  ▼                                                  ▼

+---------+------+     +---------+------+     +---------+------+     +---------+------+
| data=11 |  •-------->| data=21 |  •-------->| data=51 |  •-------->| data=101|  •----+
+---------+------+     +---------+------+     +---------+------+     +---------+------+ |
      ^                                                                                  |
      |__________________________________________________________________________________|


After DeleteLast()

 head                                   tail
  │                                       │
  ▼                                       ▼

+---------+------+     +---------+------+     +---------+------+
| data=11 |  •-------->| data=21 |  •-------->| data=51 |  •----+
+---------+------+     +---------+------+     +---------+------+ |
      ^                                                           |
      |___________________________________________________________|

The last node now points back to the first node.

===============================================================================
Algorithm:
===============================================================================

DeleteLast()

1. Check whether the linked list is empty.
2. If the list is empty, return.
3. If only one node is present:
      - Free the node.
      - Set first and last to NULL.
4. Otherwise:
      - Traverse the linked list until the second last node.
      - Free the last node.
      - Update last to the second last node.
      - Make last->next point to first.
5. Stop.

===============================================================================
Program Flow:
===============================================================================

                         Start
                           │
                           ▼
                Is Linked List Empty?
                     /            \
                   Yes            No
                   │               │
                   ▼               ▼
                Return      Is Only One Node?
                                 /      \
                               Yes      No
                               │         │
                               ▼         ▼
                     Delete Only Node   Traverse
                     first = NULL       to Second Last
                     last = NULL             │
                               │             ▼
                               │      Delete Last Node
                               │             │
                               │             ▼
                               │      last = Second Last
                               │             │
                               │             ▼
                               └────► last->next = first
                                             │
                                             ▼
                                            Stop

===============================================================================
Time Complexity:
===============================================================================

DeleteLast()          : O(n)

Space Complexity      : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 008 demonstrates the DeleteLast() operation in a Singly Circular
Linked List. The algorithm correctly handles all three cases: an empty list,
a single-node list, and a multi-node list. After deleting the last node,
the second last node becomes the new last node, and its next pointer is
updated to point to the first node, thereby preserving the circular
structure of the linked list.

===============================================================================
*/
