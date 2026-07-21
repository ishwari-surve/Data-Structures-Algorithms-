/*
===============================================================================
Program Name    : DeleteAtPos() in Singly Circular Linked List
Program Number  : 010
Description     : This program demonstrates the DeleteAtPos() operation in a
                  Singly Circular Linked List. It deletes a node from the
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
- Validates the deletion position.
- Uses DeleteFirst() when deleting the first node.
- Uses DeleteLast() when deleting the last node.
- Deletes a node from the middle of the linked list.
- Preserves the circular structure after deletion.

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

void InsertLast(PPNODE first, PPNODE last,int iNo)
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

void DeleteFirst(PPNODE first,PPNODE last)
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

void DeleteLast(PPNODE first,PPNODE last)
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
//
///////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first,PPNODE last,int iPos)
{
    int iCount = Count(*first,*last);

    if((iPos < 1) || (iPos > iCount))
    {
        printf("Invalid Position\n");
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
        PNODE temp = *first;
        PNODE target = NULL;
        int i = 0;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}

///////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertLast(&head,&tail,11);
    InsertLast(&head,&tail,21);
    InsertLast(&head,&tail,51);
    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);

    printf("Linked List before deletion :\n");
    Display(head,tail);

    DeleteAtPos(&head,&tail,3);

    printf("\nLinked List after deletion :\n");
    Display(head,tail);

    printf("\nTotal Nodes : %d\n",Count(head,tail));

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Linked List before deletion :

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | ->

Linked List after deletion :

| 11 | -> | 21 | -> | 101 | -> | 111 | ->

Total Nodes : 4

===============================================================================
Memory Representation:
===============================================================================

Before DeleteAtPos()

 head                                                          tail
  │                                                              │
  ▼                                                              ▼

+---------+------+     +---------+------+     +---------+------+     +---------+------+     +---------+------+
| data=11 |  •-------->| data=21 |  •-------->| data=51 |  •-------->|data=101 |  •-------->|data=111 |  •----+
+---------+------+     +---------+------+     +---------+------+     +---------+------+     +---------+------+ |
      ^                                                                                                        |
      |________________________________________________________________________________________________________|


DeleteAtPos(3)

                    Node Deleted
                         │
                         ▼

+---------+------+     +---------+------+          +---------+------+     +---------+------+
| data=11 |  •-------->| data=21 |  •---------------->|data=101 |  •-------->|data=111 |  •----+
+---------+------+     +---------+------+          +---------+------+     +---------+------+ |
      ^                                                                                      |
      |______________________________________________________________________________________|

The node containing data 51 is removed and the previous node is linked
directly to the next node, preserving the circular structure.

===============================================================================
Algorithm:
===============================================================================

DeleteAtPos()

1. Calculate the total number of nodes.
2. Validate the given position.
3. If position is 1:
      Call DeleteFirst().
4. Else if position is equal to Count:
      Call DeleteLast().
5. Otherwise:
      Traverse to the node just before the given position.
      Store the node to be deleted.
      Adjust the next pointer.
      Free the deleted node.
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
                      /            \
                    No              Yes
                    │                │
                    ▼                ▼
             Print Invalid      Position == 1 ?
               Position          /         \
                               Yes         No
                                │           │
                                ▼           ▼
                        DeleteFirst()   Position==Count?
                                            /        \
                                          Yes        No
                                           │          │
                                           ▼          ▼
                                   DeleteLast()   Traverse to
                                                  Position-1
                                                       │
                                                       ▼
                                               Store Target Node
                                                       │
                                                       ▼
                                            Adjust next Pointer
                                                       │
                                                       ▼
                                               Free Target Node
                                                       │
                                                       ▼
                                                      Stop

===============================================================================
Time Complexity:
===============================================================================

Count()             : O(n)

DeleteAtPos()       : O(n)

Space Complexity    : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 010 demonstrates the DeleteAtPos() operation in a Singly Circular
Linked List. The function first validates the specified position and then
deletes the node safely. Special cases such as deleting the first node and
the last node are handled using DeleteFirst() and DeleteLast(), while
deletion from the middle is performed by updating the appropriate pointers
and freeing the removed node. The circular property of the linked list is
maintained throughout the operation.

===============================================================================
*/
