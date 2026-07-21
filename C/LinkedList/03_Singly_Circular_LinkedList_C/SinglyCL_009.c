/*
===============================================================================
Program Name    : InsertAtPos() in Singly Circular Linked List
Program Number  : 009
Description     : This program demonstrates the InsertAtPos() operation in a
                  Singly Circular Linked List. It inserts a new node at the
                  specified position while maintaining the circular structure
                  of the linked list.

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
6. Position Validation

Key Learning Points:
- Validates the insertion position.
- Uses InsertFirst() when position is 1.
- Uses InsertLast() when position is Count + 1.
- Inserts the node between two existing nodes.
- Maintains the circular structure after insertion.

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
// Function Name : Count
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
// Function Name : InsertLast
//
///////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first, PPNODE last, int iNo)
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
        (*last)->next = newn;
        *last = newn;
    }

    (*last)->next = *first;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
//
///////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first, PPNODE last, int iPos, int iNo)
{
    int iCount = Count(*first,*last);

    if((iPos < 1) || (iPos > iCount + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first,last,iNo);
    }
    else if(iPos == (iCount + 1))
    {
        InsertLast(first,last,iNo);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));
        PNODE temp = *first;
        int i = 0;

        newn->data = iNo;
        newn->next = NULL;

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
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    printf("Linked List before insertion :\n");
    Display(head,tail);

    InsertAtPos(&head,&tail,4,101);

    printf("\nLinked List after insertion :\n");
    Display(head,tail);

    printf("\nTotal Nodes : %d\n",Count(head,tail));

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Linked List before insertion :

| 11 | -> | 21 | -> | 51 | ->

Linked List after insertion :

| 11 | -> | 21 | -> | 51 | -> | 101 | ->

Total Nodes : 4

===============================================================================
Memory Representation:
===============================================================================

Before InsertAtPos()

 head                                    tail
  │                                        │
  ▼                                        ▼

+---------+------+     +---------+------+     +---------+------+
| data=11 |  •-------->| data=21 |  •-------->| data=51 |  •----+
+---------+------+     +---------+------+     +---------+------+ |
      ^                                                         |
      |_________________________________________________________|


InsertAtPos(4,101)


After InsertAtPos()

 head                                                     tail
  │                                                         │
  ▼                                                         ▼

+---------+------+     +---------+------+     +---------+------+     +---------+------+
| data=11 |  •-------->| data=21 |  •-------->| data=51 |  •-------->|data=101 |  •----+
+---------+------+     +---------+------+     +---------+------+     +---------+------+ |
      ^                                                                                 |
      |_________________________________________________________________________________|

The newly created node is inserted at the specified position while
maintaining the circular link.

===============================================================================
Algorithm:
===============================================================================

InsertAtPos()

1. Calculate the total number of nodes.
2. Validate the given position.
3. If position is 1:
      Call InsertFirst().
4. Else if position is Count + 1:
      Call InsertLast().
5. Otherwise:
      Create a new node.
      Traverse to (Position - 1).
      Insert the new node.
6. Stop.

===============================================================================
Program Flow:
===============================================================================

                         Start
                           │
                           ▼
                  Calculate Node Count
                           │
                           ▼
                 Is Position Valid?
                     /          \
                   No            Yes
                   │              │
                   ▼              ▼
            Print Invalid     Position == 1 ?
              Position         /         \
                             Yes         No
                              │           │
                              ▼           ▼
                      InsertFirst()   Position==Count+1?
                                         /          \
                                       Yes          No
                                        │            │
                                        ▼            ▼
                                 InsertLast()   Traverse to
                                                Position-1
                                                     │
                                                     ▼
                                             Create New Node
                                                     │
                                                     ▼
                                              Adjust Pointers
                                                     │
                                                     ▼
                                                    Stop

===============================================================================
Time Complexity:
===============================================================================

Count()              : O(n)

InsertAtPos()        : O(n)

Space Complexity     : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 009 demonstrates the InsertAtPos() operation in a Singly Circular
Linked List. The function first validates the given position and then
inserts the new node at the required location. Special cases such as
insertion at the beginning and insertion at the end are handled using
InsertFirst() and InsertLast(), while insertion in the middle is
performed by updating the appropriate pointers. The circular structure
of the linked list is preserved after every insertion.

===============================================================================
*/
