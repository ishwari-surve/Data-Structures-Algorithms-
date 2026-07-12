/*
================================================================================
Program Name    : Singly Linked List - Complete Implementation (All 8 Functions)
Program Number  : 017
Description : This program demonstrates the complete implementation
              of a Singly Linked List by combining all fundamental
              operations including insertion, deletion, traversal,
              and counting. It serves as the foundation for
              implementing dynamic linked list data structures.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. typedef (NODE, PNODE, PPNODE)
4. Dynamic Memory Allocation (malloc)
5. Dynamic Memory Deallocation (free)
6. Head Pointer
7. Pointer to Pointer
8. Traversal
9. Insertion Operations
10. Deletion Operations
11. Position Validation
12. Function Calls
13. While Loop
14. For Loop
15. #pragma pack(1)

Key Learning Points:
- Complete linked list with all operations
- Dynamic memory allocation for nodes
- PPNODE parameter for modifying head pointer
- Code reusability through functions
- Display function for visualization
- Count function as helper in insert/delete
- Validation of positions before operations
- Proper memory deallocation
- Safe NULL pointer handling
- Foundation for advanced DSA concepts
- Demonstrates modular programming using reusable functions.
- Introduces complete implementation of a dynamic linked list.
================================================================================
*/

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;              // 4 bytes - stores the value
    struct node *next;     // 8 bytes - pointer to next node
};

typedef struct node NODE;        // NODE is alias for struct node
typedef struct node* PNODE;      // PNODE is alias for pointer to NODE
typedef struct node** PPNODE;    // PPNODE is alias for pointer to pointer to NODE

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    // Allocate memory for new node
    newn = (PNODE)malloc(sizeof(NODE));

    // Initialize new node
    newn->data = no;
    newn->next = NULL;

    // Link to list
    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    // Allocate memory for new node
    newn = (PNODE)malloc(sizeof(NODE));

    // Initialize new node
    newn->data = no;
    newn->next = NULL;

    // Check if list is empty
    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        // Traverse to last node
        temp = *first;

        while(temp->next != NULL)   
        {
            temp = temp->next;
        }

        // Link new node to last node
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    // Case 1: Empty list
    if(*first == NULL)
    {
        return;
    }
    // Case 2: Only one node
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    // Case 3: Multiple nodes
    else
    {
        temp = *first;

        *first = (*first)->next;

        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    // Case 1: Empty list
    if(*first == NULL)
    {
        return;
    }
    // Case 2: Only one node
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    // Case 3: Multiple nodes
    else
    {
        temp = *first;

        // Traverse to second-last node
        while(temp->next->next != NULL) 
        {
            temp = temp->next;
        }

        // Delete last node
        free(temp->next);
        temp->next = NULL;
    }
}

void Display(PNODE first)
{
    while(first != NULL)    
    {
        printf("| %d | -> ", first->data);
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

void InsertAtPos(PPNODE first, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    int iSize = 0;

    // Get list size
    iSize = Count(*first);

    // Validate position
    if((pos < 1) || (pos > iSize + 1))      
    {
        printf("Invalid position\n");
        return;
    }

    // Use existing functions for special cases
    if(pos == 1)
    {
        InsertFirst(first, no);
    }
    else if(pos == iSize + 1)
    {
        InsertLast(first, no);
    }
    else
    {
        // General case - traverse to position-1
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        // Link new node
        newn->next = temp->next;    
        temp->next = newn;          
    }
}

void DeleteAtPos(PPNODE first, int pos)
{
    int iSize = 0;
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    // Get list size
    iSize = Count(*first);

    // Validate position
    if((pos < 1) || (pos > iSize))      
    {
        printf("Invalid position\n");
        return;
    }

    // Use existing functions for special cases
    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        // General case - traverse to position-1
        temp = *first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        // Delete target node
        target = temp->next;

        temp->next = target->next;        
        free(target);                       
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    // Insert using InsertFirst
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);
    
    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    // Insert using InsertLast
    InsertLast(&head, 101);
    InsertLast(&head, 111);
    InsertLast(&head, 121);
    
    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    // Delete first node
    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    // Delete last node
    DeleteLast(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    // Insert at position
    InsertAtPos(&head, 105, 3);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);
    
    // Delete at position
    DeleteAtPos(&head, 3);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);
    
    return 0;
}

/*
================================================================================
Expected Output:
================================================================================
| 11 | -> | 21 | -> | 51 | -> NULL
Number of nodes are : 3

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | -> NULL
Number of nodes are : 6

| 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | -> NULL
Number of nodes are : 5

| 21 | -> | 51 | -> | 101 | -> | 111 | -> NULL
Number of nodes are : 4

| 21 | -> | 51 | -> | 105 | -> | 101 | -> | 111 | -> NULL
Number of nodes are : 5

| 21 | -> | 51 | -> | 101 | -> | 111 | -> NULL
Number of nodes are : 4

================================================================================
Memory Diagram:
================================================================================

After InsertFirst (11, 21, 51):
head → [11|→] → [21|→] → [51|NULL]

After InsertLast (101, 111, 121):
head → [11|→] → [21|→] → [51|→] → [101|→] → [111|→] → [121|NULL]

After DeleteFirst:
head → [21|→] → [51|→] → [101|→] → [111|→] → [121|NULL]

After DeleteLast:
head → [21|→] → [51|→] → [101|→] → [111|NULL]

After InsertAtPos(105, 3):
head → [21|→] → [51|→] → [105|→] → [101|→] → [111|NULL]

After DeleteAtPos(3):
head → [21|→] → [51|→] → [101|→] → [111|NULL]

================================================================================
Pointer/Logic Explanation:
================================================================================

PPNODE vs PNODE:

PNODE Parameter (Display, Count):
- Used for read-only traversal
- Cannot change head pointer
- Suitable for viewing operations

PPNODE Parameter (Insert, Delete):
- Used when head pointer needs modification
- Can change head using *first
- Essential for insert/delete operations
- *first dereferences to actual head pointer

Code Reusability Pattern:

InsertAtPos uses existing functions:
├─ if(pos == 1) → calls InsertFirst
├─ if(pos == size+1) → calls InsertLast
└─ else → custom logic

DeleteAtPos uses existing functions:
├─ if(pos == 1) → calls DeleteFirst
├─ if(pos == size) → calls DeleteLast
└─ else → custom logic

This prevents code duplication and improves maintainability.

Dynamic Memory Flow:

Insertion:
1. malloc allocates memory on heap
2. Initialize node data and next
3. Link to existing structure
4. Node persists in memory

Deletion:
1. Locate target node
2. Unlink from structure
3. free deallocates memory
4. Pointer becomes invalid

Validation:

All operations validate position:
if((pos < 1) || (pos > size))
- Prevents accessing invalid positions
- Returns error if position invalid
- Protects list integrity

Count() as Helper Function:

Used in InsertAtPos and DeleteAtPos:
- Determines valid position range
- O(n) operation for each call
- Trade-off between simplicity and efficiency

================================================================================
Operations Performed
================================================================================

1. Created an initially empty linked list.
2. Inserted nodes at the beginning using InsertFirst().
3. Displayed all nodes using Display().
4. Counted the total number of nodes using Count().
5. Inserted nodes at the end using InsertLast().
6. Deleted the first node using DeleteFirst().
7. Deleted the last node using DeleteLast().
8. Inserted a node at a specified position using InsertAtPos().
9. Deleted a node from a specified position using DeleteAtPos().
10. Validated positions before insertion and deletion.
11. Allocated memory dynamically using malloc().
12. Released memory using free() after deletion.
13. Reused existing functions to avoid code duplication.

================================================================================
Time Complexity
================================================================================

InsertFirst()      : O(1) - Insert at beginning
InsertLast()       : O(n) - Traverse to last node
DeleteFirst()      : O(1) - Remove first node
DeleteLast()       : O(n) - Traverse to second-last node
InsertAtPos()      : O(n) - Traverse to given position
DeleteAtPos()      : O(n) - Traverse to given position
Display()          : O(n) - Visit each node once
Count()            : O(n) - Visit each node once

Space Complexity   : O(1)

================================================================================
Conclusion:
================================================================================

This program combines all fundamental Singly Linked List operations
into a single implementation. It demonstrates insertion, deletion,
traversal, counting, dynamic memory allocation, memory deallocation,
and position-based operations using reusable functions. This program
serves as the foundation for implementing advanced linked list
variations such as Doubly Linked List and Circular Linked List.
================================================================================
*/
