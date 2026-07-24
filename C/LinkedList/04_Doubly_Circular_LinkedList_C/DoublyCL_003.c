/*
===============================================================================
Program Name    : Doubly Circular Linked List - InsertFirst()
Program Number  : 003
Description     : This program demonstrates the insertion of a new node at the
                  beginning of a Doubly Circular Linked List. It handles both
                  empty and non-empty linked lists while maintaining the
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
6. typedef

Key Learning Points:
- Insert a node at the beginning of the list.
- Handle insertion into an empty linked list.
- Maintain both next and prev links.
- Preserve the circular structure.

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

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

Three nodes are inserted successfully at the beginning of the
Doubly Circular Linked List.

===============================================================================
Memory Representation:
===============================================================================

After InsertFirst(51)

 head
  │
  ▼

+----+---+---+
| 51 | • | • |
+----+---+---+
   ▲       │
   └───────┘

------------------------------------------------------------

After InsertFirst(21)

 head                    tail
  │                       │
  ▼                       ▼

+----+---+---+      +----+---+---+
| 21 | • | • | <==> | 51 | • | • |
+----+---+---+      +----+---+---+
   ▲                        │
   └────────────────────────┘

------------------------------------------------------------

After InsertFirst(11)

 head                                  tail
  │                                     │
  ▼                                     ▼

+----+---+---+   +----+---+---+   +----+---+---+
| 11 | • | • |<=>| 21 | • | • |<=>| 51 | • | • |
+----+---+---+   +----+---+---+   +----+---+---+
   ▲                                             │
   └─────────────────────────────────────────────┘

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Store the given data.
3. If the list is empty:
      Make first and last point to the new node.
4. Otherwise:
      Link the new node before the first node.
      Update the previous pointer.
      Make the new node the first node.
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
first=last   Insert Before First
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

Space Complexity    : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 003 demonstrates the implementation of the InsertFirst() operation
for a Doubly Circular Linked List. The program correctly inserts nodes at
the beginning while maintaining both the next and previous links and
preserving the circular nature of the linked list.

===============================================================================
*/
