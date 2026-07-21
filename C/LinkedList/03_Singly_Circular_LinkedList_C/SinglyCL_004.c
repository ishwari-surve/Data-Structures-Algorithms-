/*
===============================================================================
Program Name    : Count() in Singly Circular Linked List
Program Number  : 004
Description     : This program implements the Count() function for a Singly
                  Circular Linked List. It traverses the entire circular linked
                  list and returns the total number of nodes present.

Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Circular Linked List
4. do-while Loop
5. Pointer Traversal
6. Counter Variable

Key Learning Points:
- Traversal begins from the first node.
- Every visited node increments the counter.
- Traversal stops after reaching the first node again.
- The function returns the total number of nodes.

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
// Function Name : Count
// Description   : Returns the total number of nodes.
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

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    int iRet = 0;

    iRet = Count(head,tail);

    printf("Number of nodes are : %d\n",iRet);

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Number of nodes are : 0

===============================================================================
Memory Representation:
===============================================================================

               head                  tail
                │                     │
                ▼                     ▼
              NULL                  NULL

No nodes are present in the linked list.

===============================================================================
Algorithm:
===============================================================================

1. Initialize counter to zero.
2. Check whether the linked list is empty.
3. If empty, return zero.
4. Traverse the circular linked list using do-while.
5. Increment counter for every node visited.
6. Return the counter.

===============================================================================
Program Flow:
===============================================================================

Start
   │
   ▼
Initialize Counter = 0
   │
   ▼
Is List Empty?
   │
 ┌─┴──────┐
 │         │
Yes       No
 │         │
 ▼         ▼
Return 0  Traverse List
           │
           ▼
     Increment Counter
           │
           ▼
     Return Count
           │
           ▼
         Stop

===============================================================================
Time Complexity:
===============================================================================

Count()            : O(n)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 004 implements the Count() function for a Singly Circular Linked List.
It traverses every node exactly once using a do-while loop and returns the
total number of nodes present in the circular linked list.

===============================================================================
*/
