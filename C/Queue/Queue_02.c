/*
===============================================================================
Program Name    : Queue Using Singly Linear Linked List - Enqueue Operation
Program Number  : 002
File Name       : Queue_02.c

Description     : This program demonstrates the Enqueue operation of a
                  Queue using a Singly Linear Linked List in C.
                  The Enqueue operation inserts a new node at the
                  rear (end) of the queue.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Dynamic Memory Allocation
5. Queue
6. Enqueue Operation

Key Learning Points:
- Insert a node at the rear.
- Allocate memory dynamically.
- Traverse the linked list.
- Build a Queue using linked list.

===============================================================================
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Enqueue(PPNODE first,int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}

int main()
{
    PNODE head = NULL;

    Enqueue(&head,11);
    Enqueue(&head,21);
    Enqueue(&head,51);

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

Queue after Enqueue:

11 -> 21 -> 51 -> NULL

===============================================================================
Memory Representation:
===============================================================================

Head
 │
 ▼
+----+------+     +----+------+     +----+------+
| 11 |  •-------> | 21 |  •-------> | 51 | NULL |
+----+------+     +----+------+     +----+------+

Front -------------------------------> Rear

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Store the given data in the node.
3. Set the next pointer to NULL.
4. If the queue is empty, make the new node the first node.
5. Otherwise, traverse to the last node.
6. Attach the new node at the end of the queue.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
      Create New Node
               │
               ▼
      Queue Empty ?
        │           │
      Yes          No
       │            │
       ▼            ▼
 Insert First   Traverse Last
       │            │
       └──────┬─────┘
              ▼
      Insert at Rear
              │
              ▼
             Stop

===============================================================================
Time Complexity:
===============================================================================

Enqueue : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 002 demonstrates the Enqueue operation of a Queue using a
Singly Linear Linked List. A new node is dynamically created and
inserted at the rear of the queue while maintaining the FIFO property.

===============================================================================
*/
