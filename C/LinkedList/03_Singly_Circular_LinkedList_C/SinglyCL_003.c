/*
===============================================================================
Program Name    : Display() in Singly Circular Linked List
Program Number  : 003
Description     : This program implements the Display() function for a Singly
                  Circular Linked List. It traverses the circular linked list
                  from the first node to the last node and displays all the
                  node values.

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
6. Head and Tail Pointers

Key Learning Points:
- Traversal starts from the first node.
- Since the last node points back to the first node, a do-while loop is used.
- Traversal stops when the traversal pointer again reaches first.
- Every node is visited exactly once.

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
// Description   : Displays all nodes of the Singly Circular Linked List.
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

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    Display(head,tail);

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Linked List is Empty.

===============================================================================
Memory Representation:
===============================================================================

               head                  tail
                │                     │
                ▼                     ▼
              NULL                  NULL

No nodes are present.

===============================================================================
Algorithm:
===============================================================================

1. Check whether the linked list is empty.
2. If empty, display an appropriate message.
3. Otherwise start traversal from the first node.
4. Print each node.
5. Continue until traversal again reaches the first node.
6. Stop.

===============================================================================
Program Flow:
===============================================================================

Start
   │
   ▼
Is List Empty?
   │
 ┌─┴──────┐
 │         │
Yes       No
 │         │
 ▼         ▼
Print     Traverse using
Message   do-while Loop
 │         │
 └────┬────┘
      ▼
     Stop

===============================================================================
Time Complexity:
===============================================================================

Display()          : O(n)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 003 implements the Display() function for a Singly Circular Linked
List. The do-while loop ensures that every node is displayed exactly once,
making it the preferred traversal technique for circular linked lists.

===============================================================================
*/
