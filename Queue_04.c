/*
===============================================================================
Program Name    : Queue Using Singly Linear Linked List - Count Operation
Program Number  : 004
File Name       : Queue_04.c

Description     : This program demonstrates the Count operation of a
                  Queue using a Singly Linear Linked List in C.
                  The Count operation traverses the queue and returns
                  the total number of nodes present.

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
- Count total nodes.
- Return queue size.
- Understand traversal logic.

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

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
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

    iRet = Count(head);

    printf("Number of Nodes : %d\n",iRet);

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

|11| -> |21| -> |51| -> |101| -> NULL

Number of Nodes : 4

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

Total Nodes = 4

===============================================================================
Algorithm:
===============================================================================

1. Initialize the count variable to 0.
2. Start from the first node.
3. Increment the count.
4. Move to the next node.
5. Repeat until NULL is reached.
6. Return the total count.

===============================================================================
Time Complexity:
===============================================================================

Count : O(n)

Space Complexity : O(1)

where,

n = Number of Nodes

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates the Count operation of a Queue using a Singly
Linear Linked List. The queue is traversed from front to rear, and the
total number of nodes present is returned.

===============================================================================
*/
