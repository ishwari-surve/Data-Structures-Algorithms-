/*
===============================================================================
Program Name    : Doubly Circular Linked List - Count()
Program Number  : 005
Description     : This program demonstrates how to count the total number of
                  nodes present in a Doubly Circular Linked List using the
                  Count() function.

Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Doubly Circular Linked List
4. Pointer Traversal
5. do-while Loop
6. Counter Variable
7. typedef

Key Learning Points:
- Traverse the complete linked list.
- Count every node exactly once.
- Return the total number of nodes.
- Understand traversal in a circular linked list.

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
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

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

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    int iRet = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("Number of nodes are : %d\n",iRet);

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

<=> | 11 | <=> | 21 | <=> | 51 | <=>

Number of nodes are : 3

===============================================================================
Memory Representation:
===============================================================================

head                                      tail
 │                                          │
 ▼                                          ▼

+----+---+---+   +----+---+---+   +----+---+---+
| 11 | • | • |<=>| 21 | • | • |<=>| 51 | • | • |
+----+---+---+   +----+---+---+   +----+---+---+
 ▲                                                │
 └────────────────────────────────────────────────┘

Display() traverses every node.
Count() also traverses every node and increments the counter.

===============================================================================
Algorithm:
===============================================================================

1. Create an empty Doubly Circular Linked List.
2. Insert nodes using InsertFirst().
3. Display the linked list.
4. Initialize counter to zero.
5. Traverse the list using a do-while loop.
6. Increment the counter for every node visited.
7. Return the total count.
8. Display the count.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
      Create Empty List
               │
               ▼
      InsertFirst() Nodes
               │
               ▼
        Display List
               │
               ▼
        Call Count()
               │
               ▼
 Traverse Complete List
               │
               ▼
      Return Node Count
               │
               ▼
      Display Total Count
               │
               ▼
              Stop

===============================================================================
Time Complexity:
===============================================================================

Display()            : O(n)

Count()              : O(n)

InsertFirst()        : O(1)

Space Complexity     : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 005 demonstrates the Count() operation of a Doubly Circular Linked
List. The program traverses the complete linked list, counts every node
exactly once, and returns the total number of nodes present in the list.

===============================================================================
*/
