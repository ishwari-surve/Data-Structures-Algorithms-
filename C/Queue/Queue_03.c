/*
===============================================================================
Program Name    : Queue Using Singly Linear Linked List - Display Operation
Program Number  : 003
File Name       : Queue_03.c

Description     : This program demonstrates the Display operation of a
                  Queue using a Singly Linear Linked List in C.
                  The Display operation traverses the queue from the
                  front node to the rear node and displays all elements.

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
6. Queue Traversal

Key Learning Points:
- Traverse the queue.
- Display all queue elements.
- Understand front-to-rear traversal.
- Verify queue contents.

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

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("|%d| -> ",first->data);
        first = first->next;
    }

    printf("NULL\n");
}

int main()
{
    PNODE head = NULL;

    Enqueue(&head,11);
    Enqueue(&head,21);
    Enqueue(&head,51);
    Enqueue(&head,101);

    Display(head);

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

|11| -> |21| -> |51| -> |101| -> NULL

===============================================================================
Memory Representation:
===============================================================================

Head
 │
 ▼
+----+------+     +----+------+     +----+------+     +-----+------+
| 11 |  •-------> | 21 |  •-------> | 51 |  •-------> |101 | NULL |
+----+------+     +----+------+     +----+------+     +-----+------+

Front -----------------------------------------------> Rear

Display Output

|11| -> |21| -> |51| -> |101| -> NULL

===============================================================================
Algorithm:
===============================================================================

1. Start from the first node.
2. Display the data of the current node.
3. Move to the next node.
4. Repeat until NULL is reached.
5. Display NULL.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
      Start from Head
               │
               ▼
      Current Node NULL?
        │             │
      Yes            No
       │              │
       ▼              ▼
   Display NULL   Display Data
                       │
                       ▼
                 Move to Next
                       │
                       └───────────────┐
                                       │
                                       ▼
                              Current Node NULL?

===============================================================================
Time Complexity:
===============================================================================

Display : O(n)

Space Complexity : O(1)

where,

n = Number of Nodes  

===============================================================================
Conclusion:
===============================================================================

Program 003 demonstrates the Display operation of a Queue using a
Singly Linear Linked List. The queue is traversed from the front node
to the rear node, and all elements are displayed in FIFO order.

===============================================================================
*/

