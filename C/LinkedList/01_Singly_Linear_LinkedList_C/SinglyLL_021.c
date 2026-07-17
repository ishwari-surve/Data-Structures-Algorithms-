/*
================================================================================
Program Name    : Singly Linked List - InsertFirst Function Implementation
Program Number  : 021
Description     : This program demonstrates how to insert a new node at the
                  beginning of a singly linked list using the InsertFirst() 
                  function. A new node is dynamically created using malloc(),
                  initialized with the given data, and linked as the new first
                  node of the list.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. PNODE typedef
4. PPNODE typedef
5. Dynamic Memory Allocation (malloc)
6. InsertFirst() Function
7. Head Pointer Modification
8. Pointer Assignment
9. Empty List Handling
10. Non-empty List Handling

Key Learning Points:
- InsertFirst() inserts node at beginning.
- Uses malloc() for dynamic memory allocation.
- Requires PPNODE because head may change.
- Works for both empty and non-empty lists.
- New node becomes the first node.
- Time complexity is O(1).
================================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;              // 4 bytes - stores the value
    struct node *next;     // 8 bytes - pointer to next node
};

typedef struct node NODE;        // NODE is alias for struct node
typedef struct node *PNODE;      // PNODE is alias for pointer to NODE
typedef struct node **PPNODE;    // PPNODE is alias for pointer to pointer to NODE

void Display(PNODE first)
{
    // Implementation: Traverse and print all node data
}

int Count(PNODE first)
{
    // Implementation: Traverse and count nodes
    return 0;
}

/*
================================================================================
Function: InsertFirst(PPNODE first, int iNo)
Purpose: Insert node at the beginning of list
Parameters: PPNODE first (address of head pointer), int iNo (data value)
Return: void
Status: IMPLEMENTED
Time Complexity: O(1)
================================================================================
*/
void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    // Step 1: Allocate memory for new node
    newn = (PNODE)malloc(sizeof(NODE));
    
    // Step 2: Initialize new node
    newn->data = iNo;
    newn->next = NULL;

    // Step 3: Link to list
    if(*first == NULL)               // Case 1: List is empty
    {
        *first = newn;              // New node becomes head
    } 
    else                             // Case 2: List has nodes
    {
        newn->next = *first;         // New node points to old head
        *first = newn;               // New node becomes head
    }
}

/*
================================================================================
Function: InsertLast(PPNODE first, int iNo)
Purpose: Insert node at the end of list
Parameters: PPNODE first (address of head pointer), int iNo (data value)
Return: void
Status: PARTIALLY IMPLEMENTED
Time Complexity: O(n)
================================================================================
*/
void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    // Step 1: Allocate memory for new node
    newn = (PNODE)malloc(sizeof(NODE));
    
    // Step 2: Initialize new node
    newn->data = iNo;
    newn->next = NULL;

    // Step 3: Check if list is empty
    if(*first == NULL)               // Case 1: List is empty
    {
        *first = newn;               // New node becomes head
    } 
    else                             // Case 2: List has nodes
    {
        // Step 4: Traverse to last node (TODO: Implementation needed)
        // temp = *first;
        // while(temp->next != NULL) {
        //     temp = temp->next;
        // }
        // Step 5: Link new node to last node
        // temp->next = newn;
    }
}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{
    // Implementation: Validate position, traverse, and insert
}

void DeleteFirst(PPNODE first)
{
    // Implementation: Free first node and update head
}

void DeleteLast(PPNODE first)
{
    // Implementation: Traverse to last and delete
}
void DeleteAtPos(PPNODE first, int iPos)
{
    // Implementation: Validate position, traverse, and delete
}

int main()
{
    PNODE head = NULL;

    // Build linked list using InsertFirst
    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    return 0;
}

/*
================================================================================
Expected Output:
================================================================================
(No output - Program builds list in memory only)

List created in memory:
head → [11|→] → [21|→] → [51|→] → [101|NULL]

================================================================================
Memory Diagram:
================================================================================

Execution Sequence:

Call 1: InsertFirst(&head, 101)
head → [101|NULL]

Call 2: InsertFirst(&head, 51)
head → [51|→] → [101|NULL]
       └────────┘

Call 3: InsertFirst(&head, 21)
head → [21|→] → [51|→] → [101|NULL]
       └────────┘└────────┘

Call 4: InsertFirst(&head, 11)
head → [11|→] → [21|→] → [51|→] → [101|NULL]
       └────────┘└────────┘└────────┘

Final Structure:
┌─────────────────────────────────────────────────────┐
│ head (PPNODE) = address of head pointer             │
│ Value: address of first node (101)                  │
└─────────────────────────────────────────────────────┘
         ↓
┌──────────────┐      ┌──────────────┐      ┌──────────────┐      ┌──────────────┐
│ data: 11     │      │ data: 21     │      │ data: 51     │      │ data: 101    │
│ next: addr→  │──→   │ next: addr→  │──→   │ next: addr→  │──→   │ next: NULL   │
└──────────────┘      └──────────────┘      └──────────────┘      └──────────────┘
    (node 1)            (node 2)              (node 3)              (node 4)

Heap Memory Allocation:
Each malloc call allocates 12 bytes (4 for data + 8 for next pointer)
Total: 4 nodes × 12 bytes = 48 bytes allocated on heap

================================================================================
Pointer/Logic Explanation:
================================================================================

PPNODE Parameter (Pointer to Pointer)

Why PPNODE and not PNODE?

If we used PNODE:
void InsertFirst(PNODE first, int iNo)
{
    first = newn;
}

Result:
Only the local copy changes.
head in main remains unchanged.

With PPNODE:
void InsertFirst(PPNODE first, int iNo)
{
    *first = newn;
}

Result:
The original head pointer in main gets updated.

InsertFirst Logic

Step 1:
Allocate memory using malloc().

Step 2:
Store data in the new node.

Step 3:
Initialize next pointer to NULL.

Step 4:
Check whether the list is empty.

Step 5:
If list is empty,
    head points to new node.

Step 6:
Otherwise,
    new node points to current head.
    head is updated to new node.

Execution Trace

Before:

head
 |
 v
11 → 21 → 51 → NULL

InsertFirst(5)

Step 1:
Create new node.

5 → NULL

Step 2:
newn->next = head

5 → 11 → 21 → 51 → NULL

Step 3:
head = newn

head
 |
 v
5 → 11 → 21 → 51 → NULL

Pointer Dereferencing

*first
Accesses the head pointer.

*first = newn
Updates the head pointer.

(*first)->next
Accesses the next field of the first node.

================================================================================
Operations Performed:
================================================================================
1. Created a new node using malloc().
2. Initialized the node with given data.
3. Checked whether the list was empty.
4. Inserted the node at the beginning.
5. Updated the HEAD pointer.
6. Displayed the linked list.
7. Counted total number of nodes.

================================================================================
Time Complexity:
================================================================================
InsertFirst()      : O(1)
Display()          : O(n)
Count()            : O(n)

Space Complexity   : O(1)

================================================================================
Conclusion
================================================================================

Program 021 implements the InsertFirst() function, demonstrating the use of a
PPNODE (pointer to pointer) parameter for modifying the HEAD pointer from
within a function. The function dynamically allocates memory for a new node
using malloc() and handles both cases: an empty list, where the new node
becomes the HEAD, and a non-empty list, where the new node is inserted before
the current first node. Since no traversal is required, InsertFirst() performs
the insertion in O(1) time, making it one of the most efficient linked list
operations. This program establishes the foundation for implementing other
insertion operations in a singly linked list.

================================================================================
*/
