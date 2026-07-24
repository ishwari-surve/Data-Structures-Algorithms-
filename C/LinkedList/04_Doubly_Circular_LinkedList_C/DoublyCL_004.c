/*
===============================================================================
Program Name    : Doubly Circular Linked List - Display()
Program Number  : 004
Description     : This program demonstrates how to display all the nodes of a
                  Doubly Circular Linked List after inserting nodes using the
                  InsertFirst() function.

Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Doubly Circular Linked List
4. Dynamic Memory Allocation
5. Pointer Traversal
6. do-while Loop
7. typedef

Key Learning Points:
- Traverse a Doubly Circular Linked List.
- Display every node exactly once.
- Understand why do-while is used in circular linked lists.
- Handle empty linked list traversal.

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

<=> | 11 | <=> | 21 | <=> | 51 | <=>

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

Each node is connected to both its next and previous node.
The last node points back to the first node, maintaining
the circular structure.

===============================================================================
Algorithm:
===============================================================================

1. Create an empty Doubly Circular Linked List.
2. Insert nodes using InsertFirst().
3. Check whether the list is empty.
4. Traverse the list using a do-while loop.
5. Display each node.
6. Stop when traversal reaches the first node again.

===============================================================================
Program Flow:
===============================================================================

           Start
              │
              ▼
      Create Empty List
              │
              ▼
     Insert Nodes at First
              │
              ▼
      Call Display()
              │
              ▼
    Traverse Using do-while
              │
              ▼
      Display Every Node
              │
              ▼
             Stop

===============================================================================
Time Complexity:
===============================================================================

Display()           : O(n)

Space Complexity    : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates the Display() operation of a Doubly Circular Linked
List. The program traverses the list using a do-while loop and prints each
node exactly once while preserving the circular nature of the linked list.

===============================================================================
*/
