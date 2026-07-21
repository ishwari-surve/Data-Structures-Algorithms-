/*
===============================================================================
Program Name    : DeleteFirst() in Singly Circular Linked List
Program Number  : 007
Description     : This program implements the DeleteFirst() function for a
                  Singly Circular Linked List. It deletes the first node while
                  maintaining the circular nature of the linked list.

Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Dynamic Memory Allocation
2. Circular Linked List
3. Head Pointer
4. Tail Pointer
5. Pointer Manipulation
6. Memory Deallocation using free()

Key Learning Points:
- Handles empty list.
- Handles single node list.
- Deletes the first node in a multi-node list.
- Updates the last node to point to the new first node.
- Frees the deleted node to avoid memory leaks.

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
// Function Name : InsertFirst
//
///////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

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
// Function Name : DeleteFirst
//
///////////////////////////////////////////////////////////////////////////////

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
        PNODE temp = *first;

        *first = (*first)->next;
        free(temp);

        (*last)->next = *first;
    }
}

///////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    printf("Linked List before deletion:\n");
    Display(head,tail);

    DeleteFirst(&head,&tail);

    printf("Linked List after deletion:\n");
    Display(head,tail);

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Linked List before deletion:
| 11 | -> | 21 | -> | 51 | ->

Linked List after deletion:
| 21 | -> | 51 | ->

===============================================================================
Memory Representation:
===============================================================================

Before Deletion

 head                            tail
  │                                │
  ▼                                ▼
+----+---+     +----+---+     +----+---+
|11  | •------>|21  | •------>|51  | •--+
+----+---+     +----+---+     +----+---+ |
  ^______________________________________|

After DeleteFirst()

 head                 tail
  │                     │
  ▼                     ▼
+----+---+     +----+---+
|21  | •------>|51  | •--+
+----+---+     +----+---+ |
  ^________________________|

===============================================================================
Algorithm:
===============================================================================

1. Check whether the list is empty.
2. If only one node is present:
      - Delete the node.
      - Make first and last NULL.
3. Otherwise:
      - Store first in a temporary pointer.
      - Move first to the next node.
      - Free the old first node.
      - Update last->next = first.

===============================================================================
Program Flow:
===============================================================================

Start
   │
   ▼
Is List Empty?
   │
 ┌─┴────────┐
 │          │
Yes        No
 │          │
 ▼          ▼
Return   Single Node?
             │
      ┌──────┴───────┐
      │              │
     Yes            No
      │              │
Delete Node     Move first
      │              │
      ▼              ▼
 first=NULL     Free Old First
 last=NULL           │
      │              ▼
      └──────► last->next = first
                     │
                     ▼
                    Stop

===============================================================================
Time Complexity:
===============================================================================

DeleteFirst()     : O(1)

Space Complexity  : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 007 implements the DeleteFirst() operation for a Singly Circular
Linked List. It efficiently removes the first node while maintaining the
circular connection between the last and first nodes. The operation executes
in constant time and correctly handles empty, single-node, and multi-node
lists.

===============================================================================
