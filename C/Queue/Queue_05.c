/*
===============================================================================
Program Name    : Queue Using Singly Linear Linked List - Dequeue Operation
Program Number  : 005
File Name       : Queue_05.c

Description     : This program demonstrates the Dequeue operation of a
                  Queue using a Singly Linear Linked List in C.
                  The Dequeue operation removes the node from the
                  front of the queue and returns its value while
                  maintaining the FIFO principle.

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
6. Dequeue Operation

Key Learning Points:
- Remove a node from the front.
- Handle queue underflow.
- Free dynamically allocated memory.
- Maintain FIFO order.

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

int Dequeue(PPNODE first)
{
    int iValue = 0;
    PNODE temp = NULL;

    if(*first == NULL)
    {
        printf("Queue is Empty\n");
        return -1;
    }

    iValue = (*first)->data;

    temp = *first;
    *first = (*first)->next;

    free(temp);

    return iValue;
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
    int iRet = 0;

    Enqueue(&head,11);
    Enqueue(&head,21);
    Enqueue(&head,51);
    Enqueue(&head,101);

    Display(head);

    iRet = Dequeue(&head);

    printf("Removed Element : %d\n",iRet);

    Display(head);

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

|11| -> |21| -> |51| -> |101| -> NULL

Removed Element : 11

|21| -> |51| -> |101| -> NULL

===============================================================================
Memory Representation:
===============================================================================

Before Dequeue

Head
 │
 ▼
+----+------+     +----+------+     +----+------+     +-----+------+
| 11 |  •-------> | 21 |  •-------> | 51 |  •-------> |101 | NULL |
+----+------+     +----+------+     +----+------+     +-----+------+

Front -----------------------------------------------> Rear


After Dequeue

Head
 │
 ▼
+----+------+     +----+------+     +-----+------+
| 21 |  •-------> | 51 |  •-------> |101 | NULL |
+----+------+     +----+------+     +-----+------+

Front ---------------------------------------> Rear

===============================================================================
Algorithm:
===============================================================================

1. Check whether the queue is empty.
2. If empty, display an underflow message.
3. Store the data of the first node.
4. Move the Head pointer to the next node.
5. Delete the old first node.
6. Return the removed element.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
      Queue Empty?
        │           │
      Yes          No
       │            │
       ▼            ▼
Display Error  Store First Data
                    │
                    ▼
            Move Head Forward
                    │
                    ▼
             Delete Old Node
                    │
                    ▼
            Return Removed Data
                    │
                    ▼
                   Stop

===============================================================================
Time Complexity:
===============================================================================

Dequeue : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 005 demonstrates the Dequeue operation of a Queue using a
Singly Linear Linked List. The front node is removed efficiently,
its memory is released, and the next node becomes the new front of
the queue while maintaining the FIFO property.
===============================================================================
*/
