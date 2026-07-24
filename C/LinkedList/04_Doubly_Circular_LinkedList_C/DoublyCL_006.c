/*
===============================================================================
Program Name    : Doubly Circular Linked List - InsertLast()
Program Number  : 006
Description     : This program demonstrates how to insert a new node at the
                  end of a Doubly Circular Linked List while maintaining the
                  circular and doubly linked properties.

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
6. Circular Linking
7. typedef

Key Learning Points:
- Insert a node at the end of the linked list.
- Handle insertion into an empty linked list.
- Maintain next and prev links.
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

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>

Number of nodes are : 6

===============================================================================
Memory Representation:
===============================================================================

head                                                            tail
 │                                                               │
 ▼                                                               ▼

+----+---+---+  +----+---+---+  +----+---+---+  +-----+---+---+
| 11 | • | • |<=>| 21 | • | • |<=>| 51 | • | • |<=>|101 | • | • |
+----+---+---+  +----+---+---+  +----+---+---+  +-----+---+---+
                                                        │
                                                        ▼
                                                 +-----+---+---+
                                                 |111 | • | • |
                                                 +-----+---+---+
                                                        │
                                                        ▼
                                                 +-----+---+---+
                                                 |121 | • | • |
                                                 +-----+---+---+
                                                        │
                                                        ▼
                                                        head

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Store the given data.
3. If the list is empty:
      Make first and last point to the new node.
4. Otherwise:
      Link the new node after the last node.
      Update the previous pointer.
      Make the new node the last node.
5. Connect last with first.
6. Stop.

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
     │        │
    Yes      No
     │        │
     ▼        ▼
first=last   Insert After Last
     │        │
     └────┬───┘
          ▼
Update Circular Links
          │
          ▼
         Stop

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()       : O(1)

InsertLast()        : O(1)

Display()           : O(n)

Count()             : O(n)

Space Complexity    : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates the InsertLast() operation of a Doubly Circular
Linked List. The program inserts new nodes at the end while correctly
maintaining the next and previous links and preserving the circular
structure of the linked list.

===============================================================================
*/
